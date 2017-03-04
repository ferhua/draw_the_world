#include "Scene5.h"

void Scene5::setup(){
	Background.loadImage("Scenes/Scene5/Background.jpg");

	AreaGreen.set(ofPoint(444,287),248,319);
	AreaBrown.set(ofPoint(1115,456),144,65);
	AreaOrange.set(ofPoint(286,416),85,85);
	AreaFlower.set(ofPoint(979,726),109,133);
	AreaBack.set(ofPoint(906,445),141,113);

	brown=ofColor(72,41,12,255);
	orange=ofColor(255,127,0,255);

	Paint=0;
	aniIndex=0;

	//动画相关变量
	AddedFall=false;
	AddedBrown=false;
	AddedOrange=false;
	AddedFlower=false;
	MovingGreen=false;
	MovingBrown=false;
	MovingOrange=false;
	MovingFlower=false;

	Ani_FallD=false;
	Ani_Or=false;
	Ani_Flower=false;

	birdImg.loadImage("Scenes/Scene5/birdInit.png");

	orangeImg.loadImage("Scenes/Scene5/orangeBlack.png");

	initFallSequence();
	initFlowerSequence();
	initOrSequence();
}

//--------------------------------------------------------------
void Scene5::update(){
	p.update();
	effCollect.update();
	typeStr="橙子-鸟儿-花朵";
}

//--------------------------------------------------------------
void Scene5::draw(){
	Background.draw(0,0);

	birdImg.draw(0,0);

	orangeImg.draw(0,0);

	p.draw(0,0);

	if(MovingGreen){
		ofPushStyle();
		ofSetColor(ofColor::green);
		effCollect.draw();
		ofPopStyle();
	}

	if(MovingBrown){
		ofPushStyle();
		ofSetColor(brown);
		effCollect.draw();
		ofPopStyle();
	}

	if(MovingOrange){
		ofPushStyle();
		ofSetColor(orange);
		effCollect.draw();
		ofPopStyle();
	}

	if(Ani_FallD||Ani_Or||Ani_Flower)
		drawSequence();
}

//--------------------------------------------------------------
void Scene5::keyPressed(int key){

}

//--------------------------------------------------------------
void Scene5::keyReleased(int key){

}

//--------------------------------------------------------------
void Scene5::mouseMoved(int x, int y){
	p.mouseMoved(x, y);
	mouseX=x;
	mouseY=y;
}

//--------------------------------------------------------------
void Scene5::mouseDragged(int x, int y, int button){
	p.mouseDragged(x,y,button);
	mouseX=x;
	mouseY=y;
}

//--------------------------------------------------------------
void Scene5::mousePressed(int x, int y, int button){
	p.mousePressed(x,y,button);
	effCollect.mousePressed(x,y,button);
	mouseX=x;
	mouseY=y;

	if(Background.getColor(460,376).g!=0)
			if(control.intersect(x,y,AreaGreen)){
				Background.loadImage("Scenes/Scene5/NoGreen.jpg");
				MovingGreen=true;
				effCollect.setup();
			}


	//移动鸟上的棕色是要在加载橙子或花朵之后的
	if((AddedBrown==false)&&(AddedOrange||AddedFlower))
		if(control.intersect(x,y,AreaBrown)){
			//这里改成draw部分的
			MovingBrown=true;
			effCollect.setup();
			birdImg.loadImage("Scenes/Scene5/nobirdblack.png");
		}

	if((AddedOrange))
		if(control.intersect(x,y,AreaOrange)&&orangeImg.getColor(324,423).r!=0){
			//这里改成draw部分的
			MovingOrange=true;
			effCollect.setup();
			orangeImg.loadImage("Scenes/Scene5/orangeBlack.png");
		}

	if(control.intersect(x,y,AreaBack))
		ofApp::currentScene-=2;

}

//--------------------------------------------------------------
void Scene5::mouseReleased(int x, int y, int button){
	p.mouseReleased(x, y, button);
	effCollect.mouseReleased(x,y,button);
	mouseX=x;
	mouseY=y;

	if(MovingGreen){
		if (p.InAreas(x,y)){
			//将颜色放入调色板
			for(int i=0;i<7;i++)
				if(control.intersect(x,y,p.Area[i]))
					Paint=i;
			
			ColorP[Paint]=ofColor::green;
		}

		else Background.loadImage("Scenes/Scene5/Background.jpg");
		
		MovingGreen=false;
	}

	if(MovingBrown){
		if (p.InAreas(x,y)){
			//将颜色放入调色板
			for(int i=0;i<7;i++)
				if(control.intersect(x,y,p.Area[i])){
					Paint=i;
					AddedBrown=true;
				}
			ColorP[Paint]=brown;
		}
		else birdImg.loadImage("Scenes/Scene5/nobirdbrown.png");

		MovingBrown=false;
	}

	if(MovingOrange){
		if (p.InAreas(x,y)){
			//将颜色放入调色板
			for(int i=0;i<7;i++)
				if(control.intersect(x,y,p.Area[i]))
					Paint=i;
		
				ColorP[Paint]=orange;
		}
		else orangeImg.loadImage("Scenes/Scene5/orangeInit.png");

		MovingOrange=false;
	}


	//如果还没将黄色赋给叶子，可以加载动画
	if (control.intersect(x,y,AreaGreen)){
		ofImage img;
		img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
		if(img.getColor(x,y)==ofColor::yellow){
			Ani_FallD=true;
			ofResetElapsedTimeCounter();
			p.setSuccess();
		}
	}

	//如果鸟还没有移动，将橙色赋给橙子，可以加载动画
	if ((!AddedFlower)&&control.intersect(x,y,AreaOrange)){
		ofImage img;
		img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
		if(img.getColor(x,y)==orange){
			Ani_Or=true;
			birdImg.loadImage("Scenes/Scene5/nobirdbrown.png");
			ofResetElapsedTimeCounter();
			p.setSuccess();
		}
	}

	//如果鸟还没有移动，将黄色赋给花朵，可以加载动画
	if ((!AddedOrange)&&control.intersect(x,y,AreaFlower)){
		ofImage img;
		img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
		if(img.getColor(x,y)==ofColor::yellow){
			Ani_Flower=true;
			birdImg.loadImage("Scenes/Scene5/nobirdbrown.png");
			ofResetElapsedTimeCounter();
			p.setSuccess();
		}
	}

	if(AddedStone)
		Background.loadImage("Scenes/Scene5/addedstone.png");

	if ((AddedStone||AddedFall)&&control.intersect(x,y,AreaGreen))
		ofApp::currentScene++;

	
			
}

//--------------------------------------------------------------
void Scene5::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Scene5::initFallSequence()
{
	ofDirectory dir1;
	int nFiles_Fall= dir1.listDir("Scenes/Scene5/Falldown");
	if(nFiles_Fall&&aniFallDown.size()==0) 
		for(int i=0; i<dir1.numFiles(); i++) { 
			string filePath = dir1.getPath(i);
			aniFallDown.push_back(ofImage());
			aniFallDown.back().loadImage(filePath);
		}
}
void Scene5::initOrSequence(){
	ofDirectory dir2;
	int nFiles_Or=dir2.listDir("Scenes/Scene5/Oranges");
	if(nFiles_Or&&aniOrange.size()==0)
		for(int i=0; i<dir2.numFiles(); i++) { 
			string filePath = dir2.getPath(i);
			aniOrange.push_back(ofImage());
			aniOrange.back().loadImage(filePath);
		}
}
		
void Scene5::initFlowerSequence(){
	ofDirectory dir3;
	int nFiles_Flower = dir3.listDir("Scenes/Scene5/flower");
	if(nFiles_Flower&&aniFlower.size()==0)
		for(int i=0; i<dir3.numFiles(); i++) { 
			string filePath = dir3.getPath(i);
			aniFlower.push_back(ofImage());
			aniFlower.back().loadImage(filePath);
	}

}

//--------------------------------------------------------------
void Scene5::drawSequence()
{
	aniIndex = (int)(ofGetElapsedTimef()*5);

	if(Ani_FallD){
		if (aniIndex<aniFallDown.size())
			aniFallDown[aniIndex].draw(0, 0);
		else {
			Background.loadImage("Scenes/Scene5/Falldown/5.jpg");
			Ani_FallD=false;
			AddedFall=true;
			if(sound.isLoaded())
				sound.unloadSound();
			sound.loadSound("Sounds/back2.mp3");sound.setLoop(true);sound.play();
		}
	}

	else if(Ani_Or){
		if (aniIndex<aniOrange.size())
			aniOrange[aniIndex].draw(0, 0);
		else {
			Ani_Or=false;
			AddedOrange=true;
			orangeImg.loadImage("Scenes/Scene5/orangeInit.png");
			if(sound.isLoaded())
				sound.unloadSound();
			sound.loadSound("Sounds/back2.mp3");sound.setLoop(true);sound.play();
		}
	}

	else if(Ani_Flower){
		if (aniIndex<aniFlower.size())
			aniFlower[aniIndex].draw(0, 0);
		else {
			Ani_Flower=false;
			AddedFlower=true;
			if(sound.isLoaded())
				sound.unloadSound();
			sound.loadSound("Sounds/back2.mp3");sound.setLoop(true);sound.play();
		}
	}
}

