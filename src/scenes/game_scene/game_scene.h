#pragma once
#include <string>
#include <list>
#include "ofMain.h"
#include "../../gameObjects/gameObject.h"
#include "../../gameObjects/abstractEnemy/abstractEnemy.h"
#include "../../gameObjects/abstractEnemy/RectangleEnemy/rectangleEnemy.h"
#include "../abstractScene.h"
using namespace std;

class Game_scene: public AbstractScene {
	public:
		const string nameScene="Game_scene";
		unsigned lifeBarWidth;
		unsigned lifeBarHeight;

	private:
		unsigned limitGameUp;
		unsigned limitGameDown;
		unsigned limitGameLeft;
		unsigned limitGameRight;
		

	public:
		virtual void setupScene() override;
		virtual void drawScene() override;
		virtual void updateScene() override;

		unsigned getLimitGameUp();
		void setLimitGameUp(unsigned value);
		unsigned getLimitGameDown();
		void setLimitGameDown(unsigned value);
		unsigned getLimitGameLeft();
		void setLimitGameLeft(unsigned value);
		unsigned getLimitGameRight();
		void setLimitGameRight(unsigned value);
		unsigned getLifeBarWidth();
		void setLifeBarWidth(unsigned value);
		unsigned getLifeBarHeight();
		void setLifeBarHeight(unsigned value);


};
