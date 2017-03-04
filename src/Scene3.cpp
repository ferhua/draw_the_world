#include "Scene3.h"

//-----------------------------------
void Scene3::setup(){
	Background.loadImage("Scenes/Scene3/Background.jpg");

	AreaFlower.set(ofPoint(629,608),152,104);

	AreaDown.set(ofPoint(861,455),107,118);

	AreaRight.set(ofPoint(1008,64),139,118);

	AreaStone.set(ofPoint(1074,495),197,158);

	ColorFlower=Background.getColor(665,648);

	ColorFlower=ofColor::yellow;

	GET_FLOWER=false;

	MOVING_FLOWER=false;

	YouCanGo=false;

	PaintFlower=0;

	Ani_HE=false;

	aniIndex=0;

	brown=ofColor(72,41,12,255);

	AddedStone=false;

	Ani_Stone=false;

	BackHappyEnd.loadImage("Scenes/Scene3/backHappy.jpg");

	//彩虹相关
	rainbow.clear();
	added.clear();
	for(int i=0;i<7;i++){
		rainbow.push_back("Scenes/Scene3/rainbow/"+control.intTostring(i)+".png");
		added.push_back(false);
	}
	
	areas.clear();
	areas.push_back(ofRectangle(16,24,239,41));
	areas.push_back(ofRectangle(406,14,423,37));
	areas.push_back(ofRectangle(408,61,355,27));
	areas.push_back(ofRectangle(411,101,333,38));
	areas.push_back(ofRectangle(417,149,354,50));
	areas.push_back(ofRectangle(438,205,349,44));
	areas.push_back(ofRectangle(453,257,325,43));
	colors.clear();
	colors.push_back(ofColor::red);
	colors.push_back(ofColor(255,127,0,255));
	colors.push_back(ofColor::yellow);
	colors.push_back(ofColor::green);
	colors.push_back(ofColor::cyan);
	colors.push_back(ofColor(36,62,89,255));
	colors.push_back(ofColor(128,49,177,255));


	initHeSequence();
	initStoneSequence();
	
}

//--------------------------------------------------------------
void Scene3::update(){
	p.update();
	effCollect.update();
	typeStr="石头-彩虹";
}

//--------------------------------------------------------------
void Scene3::draw(){
	Background.draw(0,0);
	p.draw(0,0);

	if(MOVING_FLOWER){
		ofPushStyle();
		ofSetColor(ColorFlower);
		effCollect.draw();
		ofPopStyle();
	}
	if (GET_FLOWER){
		ColorP[PaintFlower]=ColorFlower;
		
		MOVING_FLOWER=false;
		Background.loadImage("Scenes/Scene3/NoFlowerArrow.jpg");
		YouCanGo=true;
		GET_FLOWER=false;
	}

	for(int i=0;i<added.size();i++)
		if(added[i])
			rainbow[i].draw(0,0);

	if(Ani_HE){
		drawAniHappy();
		typeStr="";
	}
	else typeStr="石头";
		
	
	if(Ani_Stone)
		drawAniStone();
}

//--------------------------------------------------------------
void Scene3::keyPressed(int key){

}

//--------------------------------------------------------------
void Scene3::keyReleased(int key){

}

//--------------------------------------------------------------
void Scene3::mouseMoved(int x, int y){
	
	mouseX=x;
	mouseY=y;
}

//--------------------------------------------------------------
void Scene3::mouseDragged(int x, int y, int button){
	
	mouseX=x;
	mouseY=y;
	p.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void Scene3::mousePressed(int x, int y, int button){

	mouseX=x;
	mouseY=y;
	p.mousePressed(x,y,button);
	effCollect.mousePressed(x,y,button);

	//如果花还没被取走
	if(Background.getColor(665,648).r!=0)
		//鼠标点击花时
			if(control.intersect(x,y,AreaFlower)){
					Background.loadImage("Scenes/Scene3/NoFlower.jpg");
					MOVING_FLOWER=true;
					effCollect.setup();
			}

	if(YouCanGo)
		if (control.intersect(x,y,AreaDown))
			ofApp::currentScene+=2;
			
			
		else if(control.intersect(x,y,AreaRight))
			ofApp::currentScene--;

				
}

//--------------------------------------------------------------
void Scene3::mouseReleased(int x, int y, int button){

	mouseX=x;
	mouseY=y;
	p.mouseReleased(x, y, button);
	effCollect.mouseReleased(x,y,button);
	
	if(MOVING_FLOWER)
			if (p.InAreas(x,y)){
				//将颜色放入调色板
				
				for(int i=0;i<7;i++){
					if(control.intersect(x,y,p.Area[i]))
						PaintFlower=i;
				}

				GET_FLOWER=true;
				MOVING_FLOWER=false;
				}

			else{ 
				MOVING_FLOWER=false;
				Background.loadImage("Scenes/Scene3/Background.jpg");
			}

			//彩虹相关
			for(int i=0;i<areas.size();i++){
				//每次取颜色判断
				if (control.intersect(x,y,areas[i])){
					ofImage img;
					img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
					if(img.getColor(x,y)==colors[i]){
						added[i]=true;
						p.setSuccess();
					}
				}
			}
			int addNumber=0;
			for(int i=0;i<areas.size();i++){
				if(added[i])
					addNumber++;
				if(addNumber==7){
					//进入happy ending
					if(sound.isLoaded())
					sound.unloadSound();
					sound.loadSound("Sounds/he.mp3");sound.setLoop(true);sound.play();
					ofResetElapsedTimeCounter();
					Ani_HE=true;
				}
					
			}
			
		if(!AddedStone)
			if(control.intersect(x,y,AreaStone)){
				ofImage img;
				img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
				if(img.getColor(x,y)==brown){
					Ani_Stone=true;
					ofResetElapsedTimeCounter();
					p.setSuccess();
				}
			}		
}

//--------------------------------------------------------------
void Scene3::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Scene3::initHeSequence()
{
	ofDirectory dir;

	int nFilesHe = dir.listDir("Scenes/Scene3/he");
	if(nFilesHe&&aniHappyend.size()==0) 
		for(int i=0; i<dir.numFiles(); i++) { 
			string filePath = dir.getPath(i);
			aniHappyend.push_back(ofImage());
			aniHappyend.back().loadImage(filePath);
		}
}

void Scene3::initStoneSequence()
{
	ofDirectory dir;
	int nFilesStone = dir.listDir("Scenes/Scene3/stone");
	if(nFilesStone&&aniStone.size()==0) 
		for(int i=0; i<dir.numFiles(); i++) { 
			string filePath = dir.getPath(i);
			aniStone.push_back(ofImage());
			aniStone.back().loadImage(filePath);
		}
}

//--------------------------------------------------------------
void Scene3::drawAniHappy()
{
	BackHappyEnd.draw(0,0);
	aniIndex = (int)(ofGetElapsedTimef()*5);
	if (aniIndex<aniHappyend.size()){
		aniHappyend[aniIndex].draw(0, 0);
		
	}
	else {
			ofApp::currentScene=0;
			for(int i=0;i<scenes.size();i++)
				scenes[i]->setup();
		}
}

//--------------------------------------------------------------
void Scene3::drawAniStone()
{

	aniIndex = (int)(ofGetElapsedTimef()*5);
	if (aniIndex<aniStone.size())
		aniStone[aniIndex].draw(0, 0);
	else {
		Background.loadImage("Scenes/Scene3/addedstone.jpg");
		Ani_Stone=false;
		AddedStone=true;
		if(sound.isLoaded())
		sound.unloadSound();
		sound.loadSound("Sounds/back2.mp3");sound.setLoop(true);sound.play();
	}
}


