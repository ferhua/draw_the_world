#include "Palette.h"

vector<ofColor> ColorP;



/*
 *	初始化
 */

Palette::Palette(){
	P.loadImage("Palette/Empty.png");

	Paint=8;

	Index=0;

	success=false;

	CollectOut.loadSound("Sounds/Collect.wav");
	Success.loadSound("Sounds/Tree.wav");
	CollectIn.loadSound("Sounds/Palette.wav");


	Moving_Paint=false;
	for(int i=0;i<7;i++){
		ofImage piece;
		piece.loadImage("Palette/Area"+ofToString(i)+".png");
		pieces.push_back(piece);
	}
	//用于鼠标判断的区域
	Area[0].set(ofPoint(145,608),91,146);
	Area[1].set(ofPoint(238,606),78,72);
	Area[2].set(ofPoint(148,534),89,70);
	Area[3].set(ofPoint(60,600),83,73);
	Area[4].set(ofPoint(63,684),76,69);
	Area[5].set(ofPoint(149,757),78,67);
	Area[6].set(ofPoint(246,685),68,69);



	AreaButton.set(ofPoint(58,506),88,94);
	//初始化7个区域的颜色
	for(int i=0;i<7;i++)
		ColorP.push_back(ofColor(0,0,0,0));
}

void Palette::setup(){



		
}

void Palette::intializeP(){
	for(int i=0;i<ColorP.size();i++)
		ColorP[i]=ofColor(0,0,0,0);
}

Palette::~Palette(){
	P.clear();
	cout<<"Palette Clear!";
}

void Palette::draw(int x,int y){
	//画空的调色板
	P.draw(x,y);

	//画每个区域的颜色
	for(int i=0;i<pieces.size();i++){
		ofPushStyle();
		ofSetColor(ColorP[i]);
		pieces[i].draw(x,y);
		ofPopStyle();
	}

	if(Moving_Paint){
	//取色,小圆跟随鼠标
	ofPushStyle();
	ofSetColor(ColorP[Paint]);
	effCollect.draw();
	ofPopStyle();

	}

}

void Palette::mousePressed(int x, int y, int button){
	mouseX=x;
	mouseY=y;

	effCollect.mousePressed(x,y,button);

	if (InAreas(x,y)){
		for(int i=0;i<pieces.size();i++)
			if(control.intersect(x,y,Area[i])&&ColorP[i]!=ofColor(0,0,0,0)){
				CollectOut.play();
				effCollect.setup();
				Index=i;
				ColorP[Paint]=ColorP[i];
				ColorP[i]=ofColor(0,0,0,0);
				//可以移动piece
				Moving_Paint=true;
			}
	}




}

void Palette::mouseMoved(int x, int y){
	mouseX=x;
	mouseY=y;
}

void Palette::mouseDragged(int x, int y, int button){
	mouseX=x;
	mouseY=y;

}

void Palette::mouseReleased(int x, int y, int button){
		mouseX=x;
		mouseY=y;

		effCollect.mouseReleased(x,y,button);
		if(Moving_Paint){
			if(InAreas(x,y)){
				//不包含混色区域
				for(int i=1;i<pieces.size();i++)
					if(control.intersect(x,y,Area[i]))
						if(ColorP[i]==ofColor(0,0,0,0)&&ColorP[Paint]!=ofColor(0,0,0,255)){
							//交换两个piece的color
							ColorP[i]=ColorP[Paint];
							ColorP[Paint]=ofColor(0,0,0,0);
							CollectIn.play();
						}

						if (control.intersect(x,y,Area[0])){
							//如果调色板中的颜色大于1种，混色，不然返回原始颜色
							//有点小问题，不影响调色
							int colorNum=0;
							for(int i=0;i<pieces.size();i++)
								if(ColorP[i]!=ofColor(0,0,0,0)&&ColorP[i]!=ofColor(0,0,0,255)){}
									colorNum++;
									if(colorNum>0&&ColorP[0]!=ofColor(0,0,0,0)&&ColorP[0]!=ofColor(0,0,0,255)){
										ColorP[0]=MixColor();
										Success.play();
									}
								
							else { 
								ColorP[0]=ColorP[Paint]; 
								ColorP[Paint]=ofColor(0,0,0,0);
							}
						}	
			}
		//如果释放鼠标时在板外,这句有问题
	else 	
			ColorP[Index]=ColorP[Paint];
		}
		
	
		Moving_Paint=false;
	
}

/*
 *	判断某点是否在7个区域的某一个中
 */
bool Palette::InAreas(int x,int y){
	if (control.intersect(x,y,Area[1])||control.intersect(x,y,Area[2])||
		control.intersect(x,y,Area[3])||control.intersect(x,y,Area[4])||
		control.intersect(x,y,Area[5])||control.intersect(x,y,Area[6])
		||control.intersect(x,y,Area[0]))
			return true;
	else 
		return false;
	
}



//返回中间混色的区域
ofColor Palette::MixColor(){
	ofColor c;
	ofColor red=ofColor::red;
	ofColor green=ofColor::green;
	ofColor blue=ofColor::blue;

	//三原色直接相加
	if((ColorP[Paint]==red||ColorP[Paint]==green||ColorP[Paint]==blue)&&(ColorP[0]==red||ColorP[0]==green||ColorP[0]==blue))
		c=ColorP[Paint]+ColorP[0];
	//其他颜色取分量的一半
	else{
	c.r=0.5*(ColorP[0].r+ColorP[Paint].r);
	c.g=0.5*(ColorP[0].g+ColorP[Paint].g);
	c.b=0.5*(ColorP[0].b+ColorP[Paint].b);
	}


	return c;
}

void Palette::setSuccess(bool s)
{
	ColorP[8]=ofColor(0,0,0,0);
	ColorP[Index]=ofColor(0,0,0,0);
	
	Success.play();
}

void Palette::whenChangeScene()
{
	//ColorP[8]=ofColor(0,0,0,0);
	if(ColorP[0]!=ofColor(0,0,0,0)&&ColorP[0]!=ofColor(0,0,0,255))
		for(int i=0;i<7;i++)
			if(ColorP[i]==ofColor(0,0,0,0)||ColorP[i]==ofColor(0,0,0,255)){
				ColorP[i]=ColorP[0];
				ColorP[0]=ofColor(0,0,0,0);
				break;
			}
	
}

void Palette::update()
{
	effCollect.update();
}

