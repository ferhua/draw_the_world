/*---------------------------------------
全局变量：
extern vector <baseScene *> scenes;  场景

extern ofSoundPlayer sound;  声音

extern string typeStr;提示字符串

palette类中的 vector<ofColor> ColorP;

Scene3中的bool addedStone
-----------------------------------------*/
#pragma once

#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"
#include "Palette.h"
#include "baseScene.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
#include "Scene4.h"
#include "Scene5.h"
#include "Scene6.h"
#include "Opening.h"

extern vector <baseScene *> scenes;
extern ofSoundPlayer sound;
extern string typeStr;
extern bool AddedStone;


class ofApp : public ofBaseApp{
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
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		int WIDTH;	//屏幕高宽
		int HEIGHT;
		static int currentScene;

		//字体
		ofxTrueTypeFontUC text;
};


