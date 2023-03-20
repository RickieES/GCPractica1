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

	private:
		int limitGameUp;
		int limitGameDown;
		int limitGameLeft;
		int limitGameRight;

	public:
		virtual void setupScene() override;
		virtual void drawScene() override;
		virtual void updateScene() override;
		int getLimitGameUp();
		void setLimitGameUp(int value);
		int getLimitGameDown();
		void setLimitGameDown(int value);
		int getLimitGameLeft();
		void setLimitGameLeft(int value);
		int getLimitGameRight();
		void setLimitGameRight(int value);


};
