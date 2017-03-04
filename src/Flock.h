#pragma once

#include "ofMain.h"
#include "Boid.h"

class Flock : public ofBaseApp{

	public:
		Flock();
		void run();
 		void addBoid(Boid b);

		void update();
// 		void draw();

		
		/*vector<Boid> boids;*/
		vector<Boid> boids; 
		
};
