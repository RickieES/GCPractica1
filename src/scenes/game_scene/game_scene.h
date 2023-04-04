#pragma once
#include <string>
#include <list>
#include "ofMain.h"
#include "../../gameObjects/gameObject.h"
#include "../../gameObjects/abstractEnemy/abstractEnemy.h"
#include "../../gameObjects/abstractEnemy/RectangleEnemy/rectangleEnemy.h"
#include "../../gameObjects/player/Player.h"
#include "../abstractScene.h"
#include "../../builders/builderEnemies/BuilderEnemies.h"
using namespace std;

class Game_scene: public AbstractScene {
	private:
		unsigned limitGameUp;
		unsigned limitGameDown;
		unsigned limitGameLeft;
		unsigned limitGameRight;
		
		ofPoint lifeBarCoords;
		unsigned lifeBarWidth;
		unsigned lifeBarHeight;

        Player player_up;
        Player player_down;

		BuilderEnemies spawner{ BuilderEnemies(ofColor::green, ofColor::purple, ofGetHeight()*0.2, ofGetHeight()*0.8, 0, ofGetWidth()*0.8) };
		vector<RectangleEnemy> enemyList;

	public:
		const string nameScene{ "Game_scene" };

		virtual void setupScene() override;
		virtual void drawScene() override;
		virtual void updateScene() override;

        void drawPlayers();
        void drawUI();

		unsigned getLimitGameUp();
		void setLimitGameUp(unsigned value);
		unsigned getLimitGameDown();
		void setLimitGameDown(unsigned value);
		unsigned getLimitGameLeft();
		void setLimitGameLeft(unsigned value);
		unsigned getLimitGameRight();
		void setLimitGameRight(unsigned value);

		ofPoint getLifeBarCoords();
		void setLifeBarCoords(ofPoint value);
		void setLifeBarCoords(int x, int y, int z);
		unsigned getLifeBarWidth();
		void setLifeBarWidth(unsigned value);
		unsigned getLifeBarHeight();
		void setLifeBarHeight(unsigned value);


};
