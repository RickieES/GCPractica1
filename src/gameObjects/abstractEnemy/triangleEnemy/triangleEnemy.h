#pragma once
#include <string>
#include "ofMain.h"
#include "../abstractEnemy.h"
using namespace std;

class TriangleEnemy : public AbstractEnemy
{

private:
	float heigth;

public:
	TriangleEnemy(int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight,
				  GameObject::ColorType nColor,int nSpeed, float nHeight) :
				  AbstractEnemy(nLimitUp, nLimitDown, nLimitLeft, nLimitRight, nColor, nSpeed)
	{
		this->setId("TriangleEnemy");
	}

	virtual void setup() override;
	virtual void draw() override;
	virtual void update() override;
	virtual vector<ofRectangle> getEnclosingRectangleList() override;

	long getLongSide();
	void setLongSide(long value);
};
