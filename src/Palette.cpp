#include "Palette.h"

vector<ofColor> ColorP;



/*
 *	��ʼ��
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
	//��������жϵ�����
	Area[0].set(ofPoint(145,608),91,146);
	Area[1].set(ofPoint(238,606),78,72);
	Area[2].set(ofPoint(148,534),89,70);
	Area[3].set(ofPoint(60,600),83,73);
	Area[4].set(ofPoint(63,684),76,69);
	Area[5].set(ofPoint(149,757),78,67);
	Area[6].set(ofPoint(246,685),68,69);



	AreaButton.set(ofPoint(58,506),88,94);
	//��ʼ��7���������ɫ
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
	//���յĵ�ɫ��
	P.draw(x,y);

	//��ÿ���������ɫ
	for(int i=0;i<pieces.size();i++){
		ofPushStyle();
		ofSetColor(ColorP[i]);
		pieces[i].draw(x,y);
		ofPopStyle();
	}

	if(Moving_Paint){
	//ȡɫ,СԲ�������
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
				//�����ƶ�piece
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
				//��������ɫ����
				for(int i=1;i<pieces.size();i++)
					if(control.intersect(x,y,Area[i]))
						if(ColorP[i]==ofColor(0,0,0,0)&&ColorP[Paint]!=ofColor(0,0,0,255)){
							//��������piece��color
							ColorP[i]=ColorP[Paint];
							ColorP[Paint]=ofColor(0,0,0,0);
							CollectIn.play();
						}

						if (control.intersect(x,y,Area[0])){
							//�����ɫ���е���ɫ����1�֣���ɫ����Ȼ����ԭʼ��ɫ
							//�е�С���⣬��Ӱ���ɫ
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
		//����ͷ����ʱ�ڰ���,���������
	else 	
			ColorP[Index]=ColorP[Paint];
		}
		
	
		Moving_Paint=false;
	
}

/*
 *	�ж�ĳ���Ƿ���7�������ĳһ����
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



//�����м��ɫ������
ofColor Palette::MixColor(){
	ofColor c;
	ofColor red=ofColor::red;
	ofColor green=ofColor::green;
	ofColor blue=ofColor::blue;

	//��ԭɫֱ�����
	if((ColorP[Paint]==red||ColorP[Paint]==green||ColorP[Paint]==blue)&&(ColorP[0]==red||ColorP[0]==green||ColorP[0]==blue))
		c=ColorP[Paint]+ColorP[0];
	//������ɫȡ������һ��
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

