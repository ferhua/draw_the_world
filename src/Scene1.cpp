#include "Scene1.h"

//--------------------------------------------------------------


void Scene1::setup(){
		p.setup();
		p.intializeP();
		ofBackground(255,255,255); 
		ofSetCircleResolution(64);

		//载入初始背景
		Background.loadImage("Scenes/Scene1/Scene1.jpg");

		River.loadSound("Sounds/River.wav");

		Fade.loadSound("Sounds/Fade.wav");
		
		riverIndex=0;

		typeStr = "";
		
		
		//中间点
		Area_Blue.setFromCenter(ofPoint(665,510),40,40);

		Area_Sky.set(ofPoint(0,0),1080,250);

		Area_River.set(ofPoint(861,472),400,420);

		

		ADD_SKY=false;
		ADD_RIVER=false;

		Area_Palette.set(ofPoint(1023,656),70,74);
		
		Area_STONE.set(ofPoint(474,707),50,40);
		ADD_STONE=false;

		//判断变量
		MOVING_BLUE=false;

		ADD_PALETTE=false;

		//初始化
		initSequenceRiver();

		
	
}

//--------------------------------------------------------------
void Scene1::update(){
	//全局时间变量
	TIME=ofGetElapsedTimef();
	//实时更新屏幕中心的颜色
	COLOR_CLOTH = Background.getColor(Area_Blue.getCenter().x,Area_Blue.getCenter().y);

	effectCollect.update();
	p.update();
	typeStr = "天空-河流-种子";
}

//--------------------------------------------------------------
void Scene1::draw(){
	ofSetColor(255);
	Background.draw(0,0);
	

	//取衣服颜色跟随鼠标
	if(MOVING_BLUE){
			ofSetColor(ofColor(82,209,215,255));
			effectCollect.draw();
	}

	//阶段1:将蓝色放入天空
	if(ADD_SKY)
		if(TIME>=1.00f&&TIME<=1.20f){
			Background.loadImage("Scenes/Scene1/Scene1.jpg");
			ADD_SKY=false;
		}
	//阶段2:载入水流动画
	if (ADD_RIVER)
			drawSequenceRiver();
	//阶段3：加载调色板
	if(ADD_PALETTE)
		p.draw(0,0);
}

//--------------------------------------------------------------
void Scene1::keyPressed(int key){


	
}

//--------------------------------------------------------------
void Scene1::keyReleased(int key){
	
}

//--------------------------------------------------------------
void Scene1::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void Scene1::mouseDragged(int x, int y, int button){

	mouseX=x;
	mouseY=y;
	if(ADD_PALETTE)
		p.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void Scene1::mousePressed(int x, int y, int button){
	//保存坐标
	mouseX=x;
	mouseY=y;
	effectCollect.mousePressed(x,y,button);

	//取到蓝色
	if(control.intersect(x,y,Area_Blue))
		if(COLOR_CLOTH==ofColor(82,209,215,255)){
			effectCollect.setup();
			MOVING_BLUE=true;
			Background.loadImage("Scenes/Scene1/Scene1Middle.jpg");
		}

	if(ADD_PALETTE)
		p.mousePressed(x,y,button);




}

//--------------------------------------------------------------
void Scene1::mouseReleased(int x, int y, int button){
	effectCollect.mouseReleased(x,y,button);
	

	//取衣服原点
	if(MOVING_BLUE){
		Background.loadImage("Scenes/Scene1/Scene1.jpg");
		if(control.intersect(x,y,Area_Sky))
			ADD_SKY=true;
		if(control.intersect(x,y,Area_River))
			ADD_RIVER=true;
	}
		
	MOVING_BLUE=false;

	//阶段1，把蓝色放入天空
	if(ADD_SKY){
		ofResetElapsedTimeCounter();
		Fade.play();
		Background.loadImage("Scenes/Scene1/Scene1Sky.jpg");
	}
	//阶段2,把蓝色放入河流
	if(ADD_RIVER){
		River.play();
		Background.loadImage("Scenes/Scene1/Scene1Middle.jpg");
		ofResetElapsedTimeCounter();
		//棕色的初始化，放在下面的化相当于一直为棕色，我们只需要初始化一次
		ColorP[1]=ofColor::saddleBrown;
		ADD_STONE=true;
		if(control.intersect(x,y,Area_Palette))
			ADD_PALETTE=true;
			
	}
	//阶段3,获取河中的调色板
	//bool值此后一直为真
	if(ADD_PALETTE){
		ADD_RIVER=false;
	}
	//阶段4,将棕色赋给种子
	if(ADD_STONE){
		Background.loadImage("Scenes/Scene1/Scene1River.jpg");
		if (control.intersect(x,y,Area_STONE)){
			ofImage img;
			img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
			if(img.getColor(x,y)==ofColor::saddleBrown){
				Background.loadImage("Scenes/Scene1/Scene1Plant.jpg");
				ADD_STONE=false;
				p.setSuccess();
				/****
				转入场景2
				***/
				ofApp::currentScene++;
			}
		}
	}

	//鼠标判断放在最后
	if(ADD_PALETTE)
		p.mouseReleased(x,y,button);
}

//--------------------------------------------------------------
void Scene1::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Scene1::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Scene1::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void Scene1::initSequenceRiver(){ 
	ofDirectory dir;
	int nFiles = dir.listDir("Scenes/Scene1/River");
	if(nFiles&&rivers.size()==0)
		for(int i=0; i<dir.numFiles(); i++) { 
			string filePath = dir.getPath(i);
			rivers.push_back(ofImage());
			rivers.back().loadImage(filePath);
		}

	
}
//--------------------------------------------------------------
void Scene1::drawSequenceRiver()
{
		
		riverIndex = (int)(ofGetElapsedTimef()*5);
		if (riverIndex<rivers.size())
			rivers[riverIndex].draw(0, 0);
		else {
			rivers[4].draw(0, 0);
		}
}
