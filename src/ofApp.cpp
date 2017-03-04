#include "ofApp.h"


//--------------------------------------------------------------
int ofApp::currentScene=0;

ofSoundPlayer sound;

vector <baseScene *> scenes;

string typeStr="";

bool AddedStone=false;
//--------------------------------------------------------------
void ofApp::setup(){
	WIDTH=ofGetWidth();

	HEIGHT=ofGetHeight();

	text.loadFont("Font/xixinkaijian.ttf", 30,true,true);

	baseScene * opening = new Opening();
	scenes.push_back(opening);

	baseScene * s1 = new Scene1();
	scenes.push_back(s1);

	baseScene * s2 = new Scene2();
	scenes.push_back(s2);

	baseScene * s3 = new Scene3();
	scenes.push_back(s3);

	baseScene * s4 = new Scene4();
	scenes.push_back(s4);

	baseScene * s5 = new Scene5();
	scenes.push_back(s5);

	baseScene * s6 = new Scene6();
	scenes.push_back(s6);

	//全部初始化
	for(int i=0;i<scenes.size();i++)
		scenes[i]->setup();
}



//--------------------------------------------------------------
void ofApp::update(){
	scenes[currentScene]->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	scenes[currentScene]->draw();

	ofPushMatrix();
	ofSetColor(ofColor::white);
	text.drawString(typeStr, 10, 40);
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//作弊码
	switch (key) {
	case 's':
		ofApp::currentScene++;
		break;
	case 'w':
		ofApp::currentScene--;
		break;
	}
	scenes[currentScene]->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	scenes[currentScene]->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	scenes[currentScene]->mouseMoved(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	scenes[currentScene]->mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	scenes[currentScene]->mousePressed(x,y,button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	scenes[currentScene]->mouseReleased(x,y,button);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	WIDTH=w;HEIGHT=h;
	scenes[currentScene]->windowResized(w,h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
