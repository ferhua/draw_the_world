#pragma once

#include "ofMain.h"


class myControl{
public:
	bool intersect(int x,int y,ofRectangle r);//ĳ����rectangle���ж�
	myControl();
	void initSequenceRiver(string path,vector<ofImage>ani);
	string intTostring(int i);
	float WIDTH,HEIGHT;
};