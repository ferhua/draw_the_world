#include "Boid.h"

//--------------------------------------------------------------
Boid::Boid(float x, float y){
	acceleration = ofVec2f(0,0);
	velocity = ofVec2f(ofRandom(-5,5),ofRandom(-5,5));
	location = ofVec2f(x,y);
	r = 3.0;
	maxspeed = 10;
	maxforce = 0.5;
}

Boid::Boid()
{

}


void Boid::run(vector<Boid> boids){
	flock(boids);
	/*update();*/
	borders();
	render();
}

void Boid::applyForce(ofVec2f force){
	// We could add mass here if we want A = F / M
	acceleration += force;
}

// We accumulate a new acceleration each time based on three rules
void Boid::flock(vector<Boid> boids) {
	ofVec2f sep = separate(boids);   // Separation
	ofVec2f ali = align(boids);      // Alignment
	ofVec2f coh = cohesion(boids);   // Cohesion
	// Arbitrarily weight these forces
	sep *= 1.5;
	ali *= 1.0;
	coh *= 1.0;
	// Add the force vectors to acceleration
	applyForce(sep);
	applyForce(ali);
	applyForce(coh);
	
}


//--------------------------------------------------------------
void Boid::update(){
	// Update velocity
	velocity += acceleration;
	// Limit speed
	//velocity.limit(maxspeed);
	location += velocity;
	// Reset acceleration to 0 each cycle
	acceleration *= 0;
	
}

ofVec2f Boid::seek(ofVec2f target) {
	ofVec2f desired = ofVec2f(target - location);  // A vector pointing from the location to the target
	// Normalize desired and scale to maximum speed
	desired.normalize();
	desired *= maxspeed;
	// Steering = Desired minus Velocity
	ofVec2f steer = ofVec2f(desired - velocity);
	steer.limit(maxforce);  // Limit to maximum steering force
	return steer;
}

void Boid::render() {

	float theta = atan(velocity.y/velocity.x);
 	if(velocity.x>0)
		theta += PI;

	ofPushMatrix();
	ofTranslate(location.x,location.y);
	ofRotate((theta+30)*180.0f/PI);
	ofTriangle(0,-r*2,-r,r*2,r,r*2);
	ofPopMatrix();
}

// Wraparound
void Boid::borders() {
	if (location.x < 0){
		
		velocity.x *= -1;
		location.x = -r;
	}
	if (location.y < 0) {
		
		velocity.y *= -1;
		location.y = -r;
	}
	if (location.x > ofGetWidth()) {
		
		velocity.x *= -1;
		location.x = ofGetWidth()+r;
	}
	if (location.y > ofGetHeight()){
		
		velocity.y *= -1;
		location.y = ofGetHeight()+r;
	}
}

// Separation
// Method checks for nearby boids and steers away
ofVec2f Boid::separate (vector<Boid> boids) {
	float desiredseparation = 25.0f;
	ofVec2f steer = ofVec3f(0,0,0);
	int count = 0;
	// For every boids in the system, check if it's too close
	for (auto other : boids) {
		float d = ofDist(location.x,location.y,other.location.x,other.location.y);
		// If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
		if ((d > 0) && (d < desiredseparation)) {
			// Calculate vector pointing away from neighbor
			ofVec2f diff = ofVec2f(location - other.location);
			diff.normalize();
			diff /= d;        // Weight by distance
			steer += diff;
			count++;            // Keep track of how many
		}
	}
	// Average -- divide by how many
	if (count > 0) {
		steer /= (float)count;
	}
	float mag = sqrt(steer.x*steer.x + steer.y*steer.y);
	// As long as the vector is greater than 0
	if (mag > 0) {
		// Implement Reynolds: Steering = Desired - Velocity
		steer.normalize();
		steer *= maxspeed;
		steer -= velocity;
		steer.limit(maxforce);
	}
	return steer;
}

// Alignment
// For every nearby boids in the system, calculate the average velocity
ofVec2f Boid::align (vector<Boid> boids) {
	float neighbordist = 50;
	ofVec2f sum = ofVec2f(0,0);
	int count = 0;
	for (auto other : boids) {
		float d = ofDist(location.x,location.y,other.location.x,other.location.y);
		if ((d > 0) && (d < neighbordist)) {
			sum += other.velocity;
			count++;
		}
	}
	if (count > 0) {
		sum /= (float)count;
		sum.normalize();
		sum *= maxspeed;
		ofVec2f steer = ofVec2f(sum - velocity);
		steer.limit(maxforce);
		return steer;
	} else {
		return ofVec2f(0,0);
	}
}

// Cohesion
// For the average location (i.e. center) of all nearby boids, calculate steering vector towards that location
ofVec2f Boid::cohesion (vector<Boid> boids) {
	float neighbordist = 50;
	ofVec2f sum = ofVec2f(0,0);   // Start with empty vector to accumulate all locations
	int count = 0;
	for (auto other : boids) {
		float d = ofDist(location.x,location.y,other.location.x,other.location.y);
		if ((d > 0) && (d < neighbordist)) {
			sum += other.location; // Add location
			count++;
		}
	}
	if (count > 0) {
		sum /= count;
		return seek(sum);  // Steer towards the location
	} else {
		return ofVec2f(0,0);
	}
}

