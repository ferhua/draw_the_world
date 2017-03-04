#pragma once

#include "ofApp.h"
#include "baseScene.h"
#include "EffectCollect.h"



class Scene3 : public baseScene {

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
	void drawAniHappy();
	void drawAniStone();
	void initHeSequence();
	void initStoneSequence();
	float mouseX;
	float mouseY;

	ofImage Background;//第一张背景

	ofImage BackHappyEnd;

	EffectCollect effCollect;

	ofColor brown;

	bool GET_FLOWER;//将花放进调色盘

	bool MOVING_FLOWER;//拖曳花

	bool YouCanGo,Ani_HE,Ani_Stone;//拿到黄花，可以返回和前进

	ofColor ColorFlower;

	ofRectangle AreaFlower,AreaDown,AreaRight,AreaStone;//花朵的区域

	int PaintFlower;

	vector <ofImage> aniStone;


	//彩虹相关
	vector<ofImage> rainbow;
	vector<ofRectangle> areas;
	vector<ofColor> colors;
	vector<bool> added;
	vector <ofImage> aniHappyend;

	int aniIndex;
};