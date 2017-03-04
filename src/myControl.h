#pragma once

#include "ofMain.h"


class myControl{
public:
	bool intersect(int x,int y,ofRectangle r);//Ä³µãÓërectangleµÄÅÐ¶Ï
	myControl();
	void initSequenceRiver(string path,vector<ofImage>ani);
	string intTostring(int i);
	float WIDTH,HEIGHT;
};