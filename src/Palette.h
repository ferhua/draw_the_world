#pragma once

#include "ofMain.h"
#include "myControl.h"
#include "EffectCollect.h"
#include "EffectBat.h"
#include "EffectTree.h"

extern vector<ofColor> ColorP;

class Palette:public ofImage{
public:

	Palette();

	~Palette();
	void setup();
	void draw(int x,int y);
	void update();

	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);


	ofRectangle Area[7];//调色板的7个区域

	bool InAreas(int x,int y);//判断某点在周围6个区域中的任意一个

	void setSuccess(bool s=true);

	void whenChangeScene();

	void intializeP();
	

private:
	
	ofImage P;//调色板图片

	vector<ofImage > pieces;

	ofRectangle AreaButton;

	float mouseX;
	float mouseY;
	int colorNum;

	int Paint;//color现在在的位置，初始值必须大于7

	ofColor MixColor();
	void clear();
	

	myControl control;

	ofSoundPlayer  CollectIn,CollectOut,Success;

	bool Moving_Paint;

	bool success;

	//点击时索引是哪块颜色版
	int Index;

	EffectCollect effCollect;

};