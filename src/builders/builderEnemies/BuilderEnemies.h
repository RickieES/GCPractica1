#pragma once
#include "ofMain.h"
#include "../../gameObjects/gameObject.h"
#include "../../gameObjects/abstractEnemy/RectangleEnemy/rectangleEnemy.h"

class BuilderEnemies {

	public:
		enum class EnemyType {square, triangle, circle};
		enum class ColorType {color1, color2};
		enum class SizeType {small, medium, large};
		enum class SpeedType {low, normal, fast};

		BuilderEnemies(ofColor nColor1, ofColor nColor2, int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight){
			
			this->setLimitUp(nLimitUp);
			this->setLimitDown(nLimitDown);
			this->setLimitRight(nLimitRight);
			this->setLimitLeft(nLimitLeft);			
		}
	
	private:
		ofColor color1;
		ofColor color2;
		int limitUp;
		int limitDown;
		int limitLeft;
		int limitRight;

		ofColor selectColor(ColorType colourType);
		
		const int squareSize_small_width = 10;
		const int squareSize_medium_width = 20;
		const int squareSize_large_width = 30;
		int selectSquareSize_width(SizeType sizeType);

		const int squareSize_small_height = 5;
		const int squareSize_medium_height = 10;
		const int squareSize_large_height = 25;
		int selectSquareSize_height(SizeType sizeType);

		const int speed_low = 2;
		const int speed_normal = 4;
		const int speed_fast = 6;
		int selectSpeed(SpeedType speedType);
		
    public:
        GameObject build();
        GameObject build(ColorType colourType, EnemyType enemyType, SizeType sizeType, SpeedType speedType);

		ofColor getColor1();
		void setColor1(ofColor value);	
		ofColor getColor2();
		void setColor2(ofColor value);	

		int getLimitUp();
		void setLimitUp(int value);
		int getLimitDown();
		void setLimitDown(int value);
		int getLimitLeft();
		void setLimitLeft(int value);
		int getLimitRight();
		void setLimitRight(int value);


};