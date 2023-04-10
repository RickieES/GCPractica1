#pragma once
#include "ofMain.h"
#include "../../gameObjects/gameObject.h"
#include "../../gameObjects/abstractEnemy/RectangleEnemy/rectangleEnemy.h"
#include "../enemyProperties.h"

class BuilderEnemies
{

public:

	BuilderEnemies(ofColor nColor1, ofColor nColor2, int nLimitUp, int nLimitDown,
				   int nLimitLeft, int nLimitRight)
	{
		GameObject::setMainColor(GameObject::ColorType::Color1, nColor1);
		GameObject::setMainColor(GameObject::ColorType::Color2, nColor2);

		setLimitUp(nLimitUp);
		setLimitDown(nLimitDown);
		setLimitRight(nLimitRight);
		setLimitLeft(nLimitLeft);
	}

private:
	int limitUp;
	int limitDown;
	int limitLeft;
	int limitRight;

	// ofColor selectColor(GameObject::ColorType colourType);

	const int squareSize_small_width = 10;
	const int squareSize_medium_width = 20;
	const int squareSize_large_width = 30;
	int selectSquareSize_width(SizeType sizeType);

	const int squareSize_small_height = 5;
	const int squareSize_medium_height = 10;
	const int squareSize_large_height = 25;
	int selectSquareSize_height(SizeType sizeType);

	const int speed_slow = 2;
	const int speed_normal = 4;
	const int speed_fast = 6;
	int selectSpeed(SpeedType speedType);

public:
	// FIXME: constructor por defecto comentado porque no devuelve objeto
	// GameObject build();
	AbstractEnemy *build(GameObject::ColorType colourType, EnemyType enemyType, SizeType sizeType, SpeedType speedType);

	int getLimitUp();
	void setLimitUp(int value);
	int getLimitDown();
	void setLimitDown(int value);
	int getLimitLeft();
	void setLimitLeft(int value);
	int getLimitRight();
	void setLimitRight(int value);
};
