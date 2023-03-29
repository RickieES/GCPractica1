#pragma once
#include <string>
#include "ofMain.h"
#include "../gameObject.h"
using namespace std;

class AbstractEnemy: public GameObject {
	
	private: 
		ofColor color;
		int speed;

		int posX;
		int posY;
		int limitUp;
		int limitDown;
		int limitLeft;
		int limitRight;


	public:
		AbstractEnemy(int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight, ofColor nColor, int nSpeed):
			GameObject(){

			this->setColor(nColor);
			this->setSpeed(nSpeed);

			this->setLimitUp(nLimitUp);
			this->setLimitDown(nLimitDown);
			this->setLimitRight(nLimitRight);
			this->setLimitLeft(nLimitLeft);
		}

		virtual void setup() override;
		virtual void draw() override;
		virtual void update() override;

		ofColor getColor();
		void setColor(ofColor value);
		int getSpeed();
		void setSpeed(int value);

		int getPosX();
		void setPosX(int value);
		int getPosY();
		void setPosY(int value);
		int getLimitUp();
		void setLimitUp(int value);
		int getLimitDown();
		void setLimitDown(int value);
		int getLimitLeft();
		void setLimitLeft(int value);
		int getLimitRight();
		void setLimitRight(int value);




	



};
