#pragma once
#include <string>
#include "ofMain.h"
#include "../abstractEnemy.h"
using namespace std;

class TriangleEnemy : public AbstractEnemy
{

private:
	long longSide;

public:
	TriangleEnemy(int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight, SpeedType nSpeed, SizeType nSize,
				  GameObject::ColorType nColor, unsigned nWidth, unsigned nHeight) :
				  AbstractEnemy(nLimitUp, nLimitDown, nLimitLeft, nLimitRight, nColor, nSpeed, nSize)
	{
		this->setPosX(nLimitRight);
		this->setPosY(rand() % (nLimitDown - nLimitUp) + nLimitDown);
	}

	virtual void setup() override;
	virtual void draw() override;
	virtual void update() override;
	virtual vector<ofRectangle> getEnclosingRectangleList() override;

	long getLongSide();
	void setLongSide(long value);
};
