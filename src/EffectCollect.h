#pragma once

#include "ofMain.h"
#include "Mover.h"
#include "Mouse.h"
#include <iostream>
#include <map>



class EffectCollect : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);

	
	//private:
	vector<Mover*> m;
	Mouse u;
	map<int,BOOL> mouse_pressed;
};
