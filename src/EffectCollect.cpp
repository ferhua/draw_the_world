#include "EffectCollect.h"
#include "Mover.h"


//--------------------------------------------------------------
void EffectCollect::setup(){
	ofSetFrameRate(100);
	for (int i = 0; i < 10; i++) {
		m.push_back(new Mover(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()))); 
	}
}

//--------------------------------------------------------------
void EffectCollect::update(){
	u.update();
	for (int i = 0; i < m.size(); i++) 
		
		if ((m[i]->flag))
			m.erase(m.begin()+i);

	

	for (int i = 0; i < m.size(); i++) 
		m[i]->update();



}

//--------------------------------------------------------------
void EffectCollect::draw(){
	if (mouse_pressed[0]){
		u.draw();
	for (int i = 0; i < m.size(); i++) {
		m[i]->applyBehaviors();
		m[i]->draw(); 
	}
	}
}

void EffectCollect::mousePressed(int x, int y, int button){

	if (0 == button){
		mouse_pressed[0]=TRUE;
	}
}

//--------------------------------------------------------------
void EffectCollect::mouseReleased(int x, int y, int button){
	for (int i = 0; i < m.size(); i++) 
		if (0 == button)
			mouse_pressed[0]=FALSE;

}


