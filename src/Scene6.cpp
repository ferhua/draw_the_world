#include "Scene6.h"

void Scene6::setup(){

	if(sound.isLoaded())
		sound.unloadSound();
	
		
	//载入初始音乐
	sound.loadSound("Sounds/BackMusic.mp3");
	sound.setVolume(0.6f);
	sound.setLoop(true);
	sound.play();

	Background.loadImage("Scenes/Scene6/backgroundColor.jpg");
	
	index=0;

	Paint=0;

	moving=false;

	effBat.setup();
	rainbow.clear();
	getcolors.clear();
	for(int i=0;i<7;i++){
		rainbow.push_back("Scenes/Scene6/moving"+control.intTostring(i)+".png");
		getcolors.push_back(false);
	}
	areas.clear();
	areas.push_back(ofRectangle(1052,393,33,51));
	areas.push_back(ofRectangle(1010,422,27,33));
	areas.push_back(ofRectangle(983,448,29,38));
	areas.push_back(ofRectangle(990,497,29,38));
	areas.push_back(ofRectangle(1018,482,33,45));
	areas.push_back(ofRectangle(1049,458,51,53));
	areas.push_back(ofRectangle(1089,416,33,54));

	areaback=ofRectangle(13,124,155,118);
	colors.clear();
	colors.push_back(ofColor::red);
	colors.push_back(ofColor(255,127,0,255));
	colors.push_back(ofColor::yellow);
	colors.push_back(ofColor::green);
	colors.push_back(ofColor::cyan);
	colors.push_back(ofColor(36,62,89,255));
	colors.push_back(ofColor(128,49,177,255));
}

//--------------------------------------------------------------
void Scene6::update(){
	p.update();
	effCollect.update();
	effBat.update();
	typeStr="彩虹";
}

//--------------------------------------------------------------
void Scene6::draw(){
	

	Background.draw(0,0);

	p.draw(0,0);
		

	if(moving){
		ofPushStyle();
		ofSetColor(colors[index]);
		effCollect.draw();
		ofPopStyle();

		rainbow[index].draw(0,0);
	}

	for(int i=0;i<getcolors.size();i++)
		if(getcolors[i])
			rainbow[i].draw(0,0);

	effBat.draw();
}

//--------------------------------------------------------------
void Scene6::keyPressed(int key){

}

//--------------------------------------------------------------
void Scene6::keyReleased(int key){

}

//--------------------------------------------------------------
void Scene6::mouseMoved(int x, int y){
	p.mouseMoved(x, y);
	mouseX=x;
	mouseY=y;
}

//--------------------------------------------------------------
void Scene6::mouseDragged(int x, int y, int button){
	p.mouseDragged(x,y,button);
	mouseX=x;
	mouseY=y;
}

//--------------------------------------------------------------
void Scene6::mousePressed(int x, int y, int button){
	p.mousePressed(x,y,button);
	effCollect.mousePressed(x,y,button);
	mouseX=x;
	mouseY=y;

	for(int i=0;i<areas.size();i++){
		if(!getcolors[i])
		if(control.intersect(x,y,areas[i])){
			index=i;
			effCollect.setup();
			moving=true;
		}
	}

	if(control.intersect(x,y,areaback))
		ofApp::currentScene--;


}

//--------------------------------------------------------------
void Scene6::mouseReleased(int x, int y, int button){
	p.mouseReleased(x, y, button);
	effCollect.mouseReleased(x,y,button);
	mouseX=x;
	mouseY=y;


	if(moving){
		if (p.InAreas(x,y)){
			//将颜色放入调色板
			for(int j=0;j<7;j++)
				if(control.intersect(x,y,p.Area[j])){
					Paint=j;
					getcolors[index]=true;
					//在这里将花瓣图片置为黑，再在draw中画出color【index】
					rainbow[index].loadImage("Scenes/Scene6/moving"+control.intTostring(index)+".png");
				}
			ColorP[Paint]=colors[index];
		}

		moving=false;
	}

	
			
}

//--------------------------------------------------------------
void Scene6::windowResized(int w, int h){

}





