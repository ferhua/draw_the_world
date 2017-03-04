#pragma once

#include "ofApp.h"
#include "baseScene.h"

class Scene6 : public baseScene {

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
	float mouseX,mouseY;
	vector <ofImage> rainbow;
	vector<ofRectangle> areas;
	ofRectangle areaback;
	vector<ofColor> colors;
	vector<bool> getcolors;
	bool moving;
	int Paint;
	int index;//��¼�ƶ�������һ��
	EffectCollect effCollect;
	EffectBat effBat;
};