#include "Scene2.h"

void Scene2::setup(){
	Background.loadImage("Scenes/Scene2/Background.jpg");

	AreaUp.set(ofPoint(605,271),97,131);

	AreaLeft.set(ofPoint(325,283),137,110);

	AreaRight.set(ofPoint(767,224),130,108);

	ClimbAni=false;

	climbIndex=0;

	HasClimb=false;

	Tree.loadSound("Sounds/Tree.wav");

	//Ԥ������������
	initSequenceClimb();

	effect_Tree.setup();
}

//--------------------------------------------------------------
void Scene2::update(){
	p.update();
	typeStr="ɫ�ʵ���������ǧ����";
}

//--------------------------------------------------------------
void Scene2::draw(){
	ofSetColor(255,255,255);
	Background.draw(0,0);
	p.draw(0,0);

	if(HasClimb)
	effect_Tree.draw();

	if(ClimbAni)
		drawSequenceClimb();
}

//--------------------------------------------------------------
void Scene2::keyPressed(int key){

}

//--------------------------------------------------------------
void Scene2::keyReleased(int key){

}

//--------------------------------------------------------------
void Scene2::mouseMoved(int x, int y){
	p.mouseMoved(x, y);
	effect_Tree.mouseMoved(x,y);
}

//--------------------------------------------------------------
void Scene2::mouseDragged(int x, int y, int button){
	p.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void Scene2::mousePressed(int x, int y, int button){
	p.mousePressed(x,y,button);

}

//--------------------------------------------------------------
void Scene2::mouseReleased(int x, int y, int button){
	p.mouseReleased(x, y, button);
	//�������������ϵļ�ͷ
	if(control.intersect(x,y,AreaUp)){
		p.setSuccess();
		ofResetElapsedTimeCounter();
		Tree.play();
		ClimbAni=true;
	}

	//����Ѿ����ض����������������Ҽ�ͷ
	if(control.intersect(x,y,AreaLeft))
		//���ͷ���볡��3
		ofApp::currentScene++;


	else if(control.intersect(x,y,AreaRight))
		//�Ҽ�ͷ���볡��4
		ofApp::currentScene+=2;

	

}

//--------------------------------------------------------------
void Scene2::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Scene2::initSequenceClimb(){ 

	ofDirectory dir;

	int nFiles = dir.listDir("Scenes/Scene2/climb");
	if(nFiles&&climb.size()==0) 
		for(int i=0; i<dir.numFiles(); i++) { 
			string filePath = dir.getPath(i);
			climb.push_back(ofImage());
			climb.back().loadImage(filePath);
		}
}
//--------------------------------------------------------------
void Scene2::drawSequenceClimb()
{
	climbIndex = (int)(ofGetElapsedTimef()*8);
	if (climbIndex<climb.size())
		climb[climbIndex].draw(0, 0);
	else {
		Background.loadImage("Scenes/Scene2/GoToSky.jpg");
		ClimbAni=false;
		HasClimb=true;
	}
}
