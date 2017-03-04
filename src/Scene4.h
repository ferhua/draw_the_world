#pragma once

#include "ofApp.h"
#include "baseScene.h"

class Scene4 : public baseScene {

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
	ofImage Background;//第一张背景

	ofRectangle AreaLeft;

	ofRectangle AreaCloud;

	ofRectangle AreaSun;

	vector <ofImage> cloud;
	bool CloudAni;

	bool CanGetSun;

	bool MOVING_SUN;//拖曳太阳

	bool GET_SUN;//将太阳放进调色盘

	int PaintSun;

	void initSequence();
	void drawSequence();
	int aniIndex;
	vector<ofImage> ani;

	EffectCollect effCollect;
	
	float mouseX;
	float mouseY;
};