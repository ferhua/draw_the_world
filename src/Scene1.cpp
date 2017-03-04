#include "Scene1.h"

//--------------------------------------------------------------


void Scene1::setup(){
		p.setup();
		p.intializeP();
		ofBackground(255,255,255); 
		ofSetCircleResolution(64);

		//�����ʼ����
		Background.loadImage("Scenes/Scene1/Scene1.jpg");

		River.loadSound("Sounds/River.wav");

		Fade.loadSound("Sounds/Fade.wav");
		
		riverIndex=0;

		typeStr = "";
		
		
		//�м��
		Area_Blue.setFromCenter(ofPoint(665,510),40,40);

		Area_Sky.set(ofPoint(0,0),1080,250);

		Area_River.set(ofPoint(861,472),400,420);

		

		ADD_SKY=false;
		ADD_RIVER=false;

		Area_Palette.set(ofPoint(1023,656),70,74);
		
		Area_STONE.set(ofPoint(474,707),50,40);
		ADD_STONE=false;

		//�жϱ���
		MOVING_BLUE=false;

		ADD_PALETTE=false;

		//��ʼ��
		initSequenceRiver();

		
	
}

//--------------------------------------------------------------
void Scene1::update(){
	//ȫ��ʱ�����
	TIME=ofGetElapsedTimef();
	//ʵʱ������Ļ���ĵ���ɫ
	COLOR_CLOTH = Background.getColor(Area_Blue.getCenter().x,Area_Blue.getCenter().y);

	effectCollect.update();
	p.update();
	typeStr = "���-����-����";
}

//--------------------------------------------------------------
void Scene1::draw(){
	ofSetColor(255);
	Background.draw(0,0);
	

	//ȡ�·���ɫ�������
	if(MOVING_BLUE){
			ofSetColor(ofColor(82,209,215,255));
			effectCollect.draw();
	}

	//�׶�1:����ɫ�������
	if(ADD_SKY)
		if(TIME>=1.00f&&TIME<=1.20f){
			Background.loadImage("Scenes/Scene1/Scene1.jpg");
			ADD_SKY=false;
		}
	//�׶�2:����ˮ������
	if (ADD_RIVER)
			drawSequenceRiver();
	//�׶�3�����ص�ɫ��
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
	//��������
	mouseX=x;
	mouseY=y;
	effectCollect.mousePressed(x,y,button);

	//ȡ����ɫ
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
	

	//ȡ�·�ԭ��
	if(MOVING_BLUE){
		Background.loadImage("Scenes/Scene1/Scene1.jpg");
		if(control.intersect(x,y,Area_Sky))
			ADD_SKY=true;
		if(control.intersect(x,y,Area_River))
			ADD_RIVER=true;
	}
		
	MOVING_BLUE=false;

	//�׶�1������ɫ�������
	if(ADD_SKY){
		ofResetElapsedTimeCounter();
		Fade.play();
		Background.loadImage("Scenes/Scene1/Scene1Sky.jpg");
	}
	//�׶�2,����ɫ�������
	if(ADD_RIVER){
		River.play();
		Background.loadImage("Scenes/Scene1/Scene1Middle.jpg");
		ofResetElapsedTimeCounter();
		//��ɫ�ĳ�ʼ������������Ļ��൱��һֱΪ��ɫ������ֻ��Ҫ��ʼ��һ��
		ColorP[1]=ofColor::saddleBrown;
		ADD_STONE=true;
		if(control.intersect(x,y,Area_Palette))
			ADD_PALETTE=true;
			
	}
	//�׶�3,��ȡ���еĵ�ɫ��
	//boolֵ�˺�һֱΪ��
	if(ADD_PALETTE){
		ADD_RIVER=false;
	}
	//�׶�4,����ɫ��������
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
				ת�볡��2
				***/
				ofApp::currentScene++;
			}
		}
	}

	//����жϷ������
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
