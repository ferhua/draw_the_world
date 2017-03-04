#pragma once
#include "ofMain.h"
#include "Palette.h"
#include "myControl.h"
#include "EffectCollect.h"
class baseScene {
public: 

	virtual void setup(){};
	virtual void update(){};
	virtual void draw(){};
	virtual void keyPressed  (int key){};
	virtual void keyReleased(int key){};
	virtual void mouseMoved(int x, int y ){};
	virtual void mouseDragged(int x, int y, int button){};
	virtual void mousePressed(int x, int y, int button){};
	virtual void mouseReleased(int x, int y, int button){};
	virtual void windowResized(int w, int h){};
	myControl control;
	Palette p;

};
