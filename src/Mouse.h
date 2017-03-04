#pragma once

#include "ofMain.h"
#include <iostream>
#include <vector>

class Mouse : public ofBaseApp{

	public:
		Mouse();
		void update();
		void draw();
		
		ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	float topspeed;

	
	float r;
		
};
