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
		float mouseX;	//���Xλ��
		float mouseY;	//���Yλ��

		ofColor COLOR_CLOTH;
		bool MOVING_BLUE;//�����ƶ���ɫ

		
		bool ADD_SKY;//�ɹ��������

		bool ADD_PALETTE;//�ɹ��������

		EffectCollect effectCollect;

		
		bool ADD_RIVER;//���غ���
		int riverIndex;
		vector <ofImage > rivers;

		ofRectangle Area_STONE;//��յ�����
		bool ADD_STONE;

		//ͼƬ
		ofImage Background;
		



		//����
		ofSoundPlayer  Fade;//��ɫ
		ofSoundPlayer  River;//��������

		//������������Ļ�ϵľ���λ��
		ofRectangle Area_Sky;//��յ�����
		ofRectangle Area_River;//����������
		ofRectangle Area_Blue;//��ɫ�·�������
		ofRectangle Area_Palette;//���е�ɫ�������

		float TIME;

		
};
