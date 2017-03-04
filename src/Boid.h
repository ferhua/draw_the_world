#pragma once

#include "ofMain.h"

class Boid : public ofBaseApp{

	public:
		Boid(float x, float y);
		Boid();
		void update();
		/*void draw();*/

		void run(vector<Boid> boids);
		void applyForce(ofVec2f force);
		void flock(vector<Boid> boids);
		ofVec2f seek(ofVec2f target);
		void render();
		void borders();
		ofVec2f separate (vector<Boid> boids);
		ofVec2f align (vector<Boid> boids);
		ofVec2f cohesion (vector<Boid> boids);


		ofVec2f location;
		ofVec2f velocity;
		ofVec2f acceleration;
		float r;
		float maxforce;    // Maximum steering force
		float maxspeed;    // Maximum speed
		
};
