#pragma once

#include "ofApp.h"
#include "baseScene.h"


class Opening : public baseScene {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

private:
	ofImage Background;//µÚÒ»ÕÅ±³¾°

	ofRectangle AreaStart,AreaExit;
	EffectCollect _effectCollect;


	float mouseX;
	float mouseY;


};