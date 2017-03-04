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

	ofImage Background;//��һ�ű���

	ofImage BackHappyEnd;

	EffectCollect effCollect;

	ofColor brown;

	bool GET_FLOWER;//�����Ž���ɫ��

	bool MOVING_FLOWER;//��ҷ��

	bool YouCanGo,Ani_HE,Ani_Stone;//�õ��ƻ������Է��غ�ǰ��

	ofColor ColorFlower;

	ofRectangle AreaFlower,AreaDown,AreaRight,AreaStone;//���������

	int PaintFlower;

	vector <ofImage> aniStone;


	//�ʺ����
	vector<ofImage> rainbow;
	vector<ofRectangle> areas;
	vector<ofColor> colors;
	vector<bool> added;
	vector <ofImage> aniHappyend;

	int aniIndex;
};