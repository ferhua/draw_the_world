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
	ofImage Background;//��һ�ű���

	ofRectangle AreaUp;//���ϵļ�ͷλ��

	ofRectangle AreaLeft;//����ļ�ͷλ��

	ofRectangle AreaRight;//���ҵļ�ͷλ��

	vector <ofImage> climb;

	int climbIndex;

	bool ClimbAni,HasClimb;

	ofSoundPlayer  Tree;

	EffectTree effect_Tree;
};