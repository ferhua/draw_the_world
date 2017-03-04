#pragma once

#include "ofApp.h"
#include "baseScene.h"

class Scene2 : public baseScene {

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
	void initSequenceClimb();
	void drawSequenceClimb();
private:
	ofImage Background;//第一张背景

	ofRectangle AreaUp;//向上的箭头位置

	ofRectangle AreaLeft;//向左的箭头位置

	ofRectangle AreaRight;//向右的箭头位置

	vector <ofImage> climb;

	int climbIndex;

	bool ClimbAni,HasClimb;

	ofSoundPlayer  Tree;

	EffectTree effect_Tree;
};