#include "Opening.h"

void Opening::setup(){

	Background.loadImage("Scenes/Opening.jpg");

	AreaStart.set(ofPoint(322,615),215,85);
	AreaExit.set(ofPoint(784,615),217,87);


}

//--------------------------------------------------------------
void Opening::update(){
}

//--------------------------------------------------------------
void Opening::draw(){
	ofSetColor(255,255,255);
	Background.draw(0,0);
	
}

//--------------------------------------------------------------
void Opening::keyPressed(int key){

}

//--------------------------------------------------------------
void Opening::keyReleased(int key){

}

//--------------------------------------------------------------
void Opening::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void Opening::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void Opening::mousePressed(int x, int y, int button){
	if(control.intersect(x,y,AreaStart))
		ofApp::currentScene++;
		

	if(control.intersect(x,y,AreaExit))
		exit(0);

}

//--------------------------------------------------------------
void Opening::mouseReleased(int x, int y, int button){
	_effectCollect.mouseReleased(x,y,button);
}

//--------------------------------------------------------------
void Opening::windowResized(int w, int h){

}
