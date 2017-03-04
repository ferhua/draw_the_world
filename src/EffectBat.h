#pragma once

#include "ofMain.h"
#include "Flock.h"
#include "Boid.h"

class EffectBat : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


		void mouseDragged(int x, int y, int button);

private:
	Flock flock;
		
};
