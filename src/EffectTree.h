#pragma once

#include "ofMain.h"

class EffectTree : public ofBaseApp{

	public:
		void setup();
		void draw();
		void mouseMoved(int x, int y );
private:
	float theta;  
	float _scale;
	void branch(float len);
};
