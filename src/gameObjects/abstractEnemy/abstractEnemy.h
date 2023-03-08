#pragma once
#include <string>
#include "ofMain.h"
using namespace std;

class AbstractEnemy {
	
	private: 
		string id;
		int posX;
		int posY;
		int limitUp;
		int limitDown;
		int limitLeft;
		int limitRight;
		unsigned speed;


	public:
		AbstractEnemy(int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight, unsigned nSpeed){
			this->limitUp = nLimitUp;
			this->limitDown = nLimitDown;
			this->limitLeft = nLimitLeft;
			this->limitRight = nLimitRight;
			this->speed = nSpeed;
		}

		virtual void setup();
		virtual void draw();
		virtual void update();

		string getId();
		void setId(string value);
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
		unsigned setSpeed(unsigned value);




	



};
