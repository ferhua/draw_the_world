#pragma once

#include "ofMain.h"
#include <iostream>
#include <vector>

class Mover : public ofBaseApp{

	public:
		Mover(float x, float y);
		void update();
		void draw();

		ofVec2f seek(ofVec2f target);
		void applyForce(ofVec2f force);
		void applyBehaviors();

		ofVec2f location;
//private:
	
	ofVec2f velocity;
	ofVec2f acceleration;
	bool flag;

	float r;
	float maxforce;   
	float maxspeed;   
		
};
