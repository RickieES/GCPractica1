#pragma once
#include <string>
#include "ofMain.h"
#include "gameObject.h"
#include "../enemyProperties.h"
using namespace std;

class AbstractEnemy : public GameObject
{

private:
	SizeType sizeType;
	SpeedType speedType;
	int speed;

	int posX;
	int posY;
	int limitUp;
	int limitDown;
	int limitLeft;
	int limitRight;

public:
	AbstractEnemy() : GameObject(){};

	AbstractEnemy(int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight,
				  GameObject::ColorType nColor, SpeedType nSpeed, SizeType nSize) : GameObject()
	{

		this->setColorType(nColor);
		this->setSpeed(nSpeed);

		this->setLimitUp(nLimitUp);
		this->setLimitDown(nLimitDown);
		this->setLimitRight(nLimitRight);
		this->setLimitLeft(nLimitLeft);
	}

	virtual void setup() override;
	virtual void draw() override;
	virtual void update() override;

	int getSpeed();
	void setSpeed(SpeedType st);
	SpeedType getSpeedType();

	void setSizeType(SizeType st);
	SizeType getSizeType();

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
