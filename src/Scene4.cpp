#include "Scene4.h"

void Scene4::setup(){
	Background.loadImage("Scenes/Scene4/Background.jpg");

	AreaLeft.set(ofPoint(24,226),177,113);

	AreaCloud.set(ofPoint(356,166),744,443);


	AreaSun.set(ofPoint(691,349),247,209);

	
	GET_SUN=false;
	MOVING_SUN=false;

	PaintSun=0;

	CloudAni=false;
	CanGetSun=true;
	aniIndex=0;
	initSequence();
}

//--------------------------------------------------------------
void Scene4::update(){
	p.update();
	effCollect.update();
	typeStr="乌云";
}

//--------------------------------------------------------------
void Scene4::draw(){
	Background.draw(0,0);
	p.draw(0,0);

	if(CloudAni)
		drawSequence();


	if(MOVING_SUN){
		ofPushStyle();
		ofSetColor(ofColor::red);
		effCollect.draw();
		ofPopStyle();
	}


	
}

//--------------------------------------------------------------
void Scene4::keyPressed(int key){

}

//--------------------------------------------------------------
void Scene4::keyReleased(int key){

}

//--------------------------------------------------------------
void Scene4::mouseMoved(int x, int y){
	p.mouseMoved(x, y);
	mouseX=x;
	mouseY=y;
}

//--------------------------------------------------------------
void Scene4::mouseDragged(int x, int y, int button){
	p.mouseDragged(x,y,button);
	mouseX=x;
	mouseY=y;
}

//--------------------------------------------------------------
void Scene4::mousePressed(int x, int y, int button){
	p.mousePressed(x,y,button);
	effCollect.mousePressed(x,y,button);
	mouseX=x;
	mouseY=y;

	if (control.intersect(mouseX,mouseY,AreaCloud)&&CanGetSun){
		ofResetElapsedTimeCounter();
		CloudAni=true;
	}

	//如果太阳还没被取走
	if(Background.getColor(812,452).r!=0)
		//鼠标点击太阳时
			if(control.intersect(x,y,AreaSun)){
				Background.loadImage("Scenes/Scene4/NoSun.jpg");
				MOVING_SUN=true;
				effCollect.setup();
			}

	//回到场景2
			if (control.intersect(mouseX,mouseY,AreaLeft))
				ofApp::currentScene-=2;
			

}

//--------------------------------------------------------------
void Scene4::mouseReleased(int x, int y, int button){
	p.mouseReleased(x, y, button);
	effCollect.mouseReleased(x,y,button);
	mouseX=x;
	mouseY=y;

	

	if(MOVING_SUN)
		if (p.InAreas(x,y)){
			//将颜色放入调色板
			for(int i=0;i<7;i++){
				if(control.intersect(x,y,p.Area[i]))
					PaintSun=i;
			}
			ColorP[PaintSun]=ofColor::red;
			GET_SUN=true;
			MOVING_SUN=false;
		}

		else{ 
			MOVING_SUN=false;
			Background.loadImage("Scenes/Scene4/Cloud/6.jpg");
		}


}

//--------------------------------------------------------------
void Scene4::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Scene4::initSequence()
{
	ofDirectory dir;

	int nFiles = dir.listDir("Scenes/Scene4/Cloud");
	if(nFiles) 
		for(int i=0; i<dir.numFiles(); i++) { 
			string filePath = dir.getPath(i);
			ani.push_back(ofImage());
			ani.back().loadImage(filePath);
		}


	else printf("Could not find folder\n");
}

//--------------------------------------------------------------
void Scene4::drawSequence()
{
	aniIndex = (int)(ofGetElapsedTimef()*8);
	if (aniIndex<ani.size())
		ani[aniIndex].draw(0, 0);
	else {
		Background.loadImage("Scenes/Scene4/Cloud/6.jpg");
		CloudAni=false;
		CanGetSun=false;
	}
}
