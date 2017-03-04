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
	ofImage Background;//��һ�ű���

	ofRectangle AreaLeft;

	ofRectangle AreaCloud;

	ofRectangle AreaSun;

	vector <ofImage> cloud;
	bool CloudAni;

	bool CanGetSun;

	bool MOVING_SUN;//��ҷ̫��

	bool GET_SUN;//��̫���Ž���ɫ��

	int PaintSun;

	void initSequence();
	void drawSequence();
	int aniIndex;
	vector<ofImage> ani;

	EffectCollect effCollect;
	
	float mouseX;
	float mouseY;
};