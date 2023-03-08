#pragma once
#include <string>
#include "ofMain.h"
#include "../abstractEnemy.h"
using namespace std;

class RectangleEnemy: public AbstractEnemy{
	
	private: 
		long width;
		long heigth;


	public:
		RectangleEnemy(int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight, unsigned nSpeed, unsigned nWidth, unsigned nHeight):
			AbstractEnemy(nLimitUp, nLimitDown, nLimitLeft, nLimitRight, nSpeed){
					
				this->setPosX(nLimitRight);
				this->setPosY(rand() % (nLimitDown - nLimitUp) + nLimitDown);          		
		}

		virtual void setup() override;
		virtual void draw() override;
		virtual void update() override;

		long getWidth();
		void setWidth(long value);
		long getHeight();
		void setHeight(long value);





	



};
