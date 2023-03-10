#pragma once
#include <string>
#include "ofMain.h"
#include "../gameObject.h"
using namespace std;

class AbstractEnemy: public GameObject {
	
	private: 

		int posX;
		int posY;
		int limitUp;
		int limitDown;
		int limitLeft;
		int limitRight;
		unsigned speed;


	public:
		AbstractEnemy(int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight, unsigned nSpeed):
			GameObject(){
			this->setLimitUp(nLimitUp);
			this->setLimitDown(nLimitDown);
			this->setLimitRight(nLimitRight);
			this->setLimitLeft(nLimitLeft);
		}

		virtual void setup() override;
		virtual void draw() override;
		virtual void update() override;

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
		unsigned getSpeed();
		void setSpeed(unsigned value);




	



};
