#include "EffectBat.h"

//--------------------------------------------------------------
void EffectBat::setup(){
	ofSetFrameRate(60);
	/*flock = new Flock();*/
	for (int i = 0; i < 20; i++) {
		Boid b = Boid(ofRandom(ofGetWidth()*2/5,ofGetWidth()*3/5),ofRandom(ofGetHeight()*2/5,ofGetHeight()*3/5));
		//Boid b = Boid(ofGetWidth()*2/5,ofGetHeight()*2/5);

		flock.addBoid(b);
	}
}

//--------------------------------------------------------------
void EffectBat::update(){

	flock.update();
	

}

//--------------------------------------------------------------
void EffectBat::draw(){
	flock.run();
}


//--------------------------------------------------------------
void EffectBat::mouseDragged(int x, int y, int button){
	if (0 == button)
	{
		flock.addBoid(Boid(mouseX,mouseY));
	}
	
	
}

