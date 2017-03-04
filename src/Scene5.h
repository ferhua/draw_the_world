#pragma once

#include "ofApp.h"
#include "baseScene.h"

class Scene5 : public baseScene {

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
	void drawSequence();
	void initFallSequence();
	void initOrSequence();
	void initFlowerSequence();
private:
	ofImage Background;//µÚÒ»ÕÅ±³¾°

	ofRectangle AreaGreen,AreaBrown,AreaBack,AreaOrange,AreaFlower;

	bool MovingGreen,MovingBrown,MovingOrange,MovingFlower;

	bool AddedFall,AddedBrown,AddedOrange,AddedFlower;

	int Paint;

	vector <ofImage> aniFallDown,aniOrange,aniFlower,aniStone;
	bool Ani_FallD,Ani_Or,Ani_Flower;
	int aniIndex;

	ofColor brown,orange;

	ofImage birdImg,orangeImg;
	EffectCollect effCollect;

	float mouseX;
	float mouseY;
};