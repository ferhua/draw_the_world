#include "EffectCollect.h"
#include "Mouse.h"

Mouse::Mouse(){
	location = ofVec2f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
	r = 10;
	velocity = ofVec2f(0,0);
	topspeed = 20;
	
}

//--------------------------------------------------------------
void Mouse::update(){
	location = ofVec2f(ofGetMouseX(),ofGetMouseY());



}

//--------------------------------------------------------------
void Mouse::draw(){
	//ofPushStyle();
	//ofSetColor(250,0,0);
	ofCircle(ofGetMouseX(),ofGetMouseY(),r);
	//ofPopStyle();

}


