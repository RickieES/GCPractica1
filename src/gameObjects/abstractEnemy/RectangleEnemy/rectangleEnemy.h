#pragma once
#include <string>
#include "ofMain.h"
#include "../abstractEnemy.h"
using namespace std;

class RectangleEnemy: public AbstractEnemy{
	
	private: 
		float width;
		float heigth;

	public:
		RectangleEnemy() : AbstractEnemy() {};

		RectangleEnemy(int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight, ofColor nColor, int nSpeed, float nWidth, float nHeight):
			AbstractEnemy(nLimitUp, nLimitDown, nLimitLeft, nLimitRight, nColor, nSpeed){
				
			this->setId("Rect");

			this->setPosX(nLimitRight);
			this->setPosY(rand() % (nLimitDown - nLimitUp) + nLimitDown);

			this->setHeight(nHeight);
			this->setWidth(nWidth);
		}

		virtual void setup() override;
		virtual void draw() override;
		virtual void update() override;

		float getWidth();
		void setWidth(float value);
		float getHeight();
		void setHeight(float value);





	



};
