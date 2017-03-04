#pragma once

#include "baseScene.h"
#include "ofApp.h"


class Scene1 : public baseScene{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void drawSequenceRiver();
		void initSequenceRiver();
	private:
		float mouseX;	//鼠标X位置
		float mouseY;	//鼠标Y位置

		ofColor COLOR_CLOTH;
		bool MOVING_BLUE;//正在移动蓝色

		
		bool ADD_SKY;//成功放入天空

		bool ADD_PALETTE;//成功放入天空

		EffectCollect effectCollect;

		
		bool ADD_RIVER;//加载河流
		int riverIndex;
		vector <ofImage > rivers;

		ofRectangle Area_STONE;//天空的区域
		bool ADD_STONE;

		//图片
		ofImage Background;
		



		//声音
		ofSoundPlayer  Fade;//褪色
		ofSoundPlayer  River;//河流流动

		//各种区域在屏幕上的矩形位置
		ofRectangle Area_Sky;//天空的区域
		ofRectangle Area_River;//河流的区域
		ofRectangle Area_Blue;//蓝色衣服的区域
		ofRectangle Area_Palette;//河中调色板的区域

		float TIME;

		
};
