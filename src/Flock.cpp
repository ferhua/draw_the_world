#include "Flock.h"



//--------------------------------------------------------------
Flock::Flock(){
	  //vector<Boid> boids; // Initialize the ArrayList
}

void Flock::run() {
	for (auto b : boids) {
		b.run(boids);  // Passing the entire list of boids to each boid individually
	}
}

void Flock::addBoid(Boid b) {
	boids.push_back(b);
}

// --------------------------------------------------------------
void Flock::update(){
	for (int i=0;i<boids.size();i++) {

		boids[i].update();		
	}
}

