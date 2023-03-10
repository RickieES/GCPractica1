#pragma once
#include <string>
#include "ofMain.h"
#include "../abstractEnemy.h"
using namespace std;

class TriangleEnemy: public AbstractEnemy{
	
	private: 
		long longSide;


	public:
		TriangleEnemy(int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight, unsigned nSpeed, unsigned nWidth, unsigned nHeight):
			AbstractEnemy(nLimitUp, nLimitDown, nLimitLeft, nLimitRight, nSpeed){
					
				this->setPosX(nLimitRight);
				this->setPosY(rand() % (nLimitDown - nLimitUp) + nLimitDown);          		
		}

		virtual void setup() override;
		virtual void draw() override;
		virtual void update() override;

		long getLongSide();
		void setLongSide(long value);




	



};
