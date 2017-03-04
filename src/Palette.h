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


	ofRectangle Area[7];//��ɫ���7������

	bool InAreas(int x,int y);//�ж�ĳ������Χ6�������е�����һ��

	void setSuccess(bool s=true);

	void whenChangeScene();

	void intializeP();
	

private:
	
	ofImage P;//��ɫ��ͼƬ

	vector<ofImage > pieces;

	ofRectangle AreaButton;

	float mouseX;
	float mouseY;
	int colorNum;

	int Paint;//color�����ڵ�λ�ã���ʼֵ�������7

	ofColor MixColor();
	void clear();
	

	myControl control;

	ofSoundPlayer  CollectIn,CollectOut,Success;

	bool Moving_Paint;

	bool success;

	//���ʱ�������Ŀ���ɫ��
	int Index;

	EffectCollect effCollect;

};