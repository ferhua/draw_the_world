#include "EffectTree.h"



//--------------------------------------------------------------
void EffectTree::setup(){
	_scale=10;
}

//--------------------------------------------------------------
void EffectTree::draw(){
	theta = ofMap(mouseX,0,ofGetWidth(),-PI,PI);
	ofPushMatrix();
	ofTranslate(1118, 378);
	branch(60);
	ofTranslate(-1118, -378);
	ofPopMatrix();
}

//--------------------------------------------------------------
void EffectTree::branch(float len) {
	ofSetColor(ofColor::white);
	ofSetLineWidth(3);
	ofLine(0, 0, 0, -len);
	// Move to the end of that line
	ofTranslate(0, -len);

	len *= 0.66;
	// All recursive functions must have an exit condition!!!!
	// Here, ours is when the length of the branch is 2 pixels or less
	if (len > 2) {
		ofPushMatrix();    // Save the current state of transformation (i.e. where are we now)
		ofRotate(_scale*theta);   // Rotate by theta
		branch(len);       // Ok, now call myself to draw two new branches!!
		ofPopMatrix();     // Whenever we get back here, we "pop" in order to restore the previous matrix state

		// Repeat the same thing, only branch off to the "left" this time!
		ofPushMatrix();
		ofRotate(_scale*-theta);
		branch(len);
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
void EffectTree::mouseMoved(int x, int y ){
	mouseX=x; mouseY=y;
}