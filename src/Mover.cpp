#include "EffectCollect.h"
#include "Mover.h"

Mover::Mover(float x, float y){
	location = ofVec2f(x, y);
	r = ofRandom(4,8);
	maxspeed = 20;
	maxforce = 2;
	acceleration = ofVec2f(0, 0);
	velocity = ofVec2f(0, 0);

	flag = FALSE;
}

ofVec2f Mover::seek(ofVec2f target) {
	ofVec2f desired = target - location; 

	desired.normalize();
	desired *= maxspeed;

	ofVec2f steer = desired - velocity;
	steer.limit(maxforce*20);  


	return steer;
}
void Mover::applyForce(ofVec2f force){

	acceleration += force*2;
}
void Mover::applyBehaviors(){

	ofVec2f seekForce = seek(ofVec2f(ofGetMouseX(),ofGetMouseY()));

	seekForce *= 1;

	applyForce(seekForce); 
}

//--------------------------------------------------------------
void Mover::update(){


	velocity += acceleration;
	location += velocity;
	acceleration *= 0;

	if (((location.x - ofGetMouseX()) < 0.1)&&((location.y -ofGetMouseY()) < 0.1))
		flag = TRUE;

}

//--------------------------------------------------------------
void Mover::draw(){
	//ofPushStyle();
	//ofSetColor(250,0,0);
	ofCircle(location.x,location.y,r);
	//ofPopStyle();

}