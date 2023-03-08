#pragma once
#include <string>
#include "ofMain.h"
#include "../../gameObjects/abstractEnemy/abstractEnemy.h"
#include "../../gameObjects/abstractEnemy/RectangleEnemy/rectangleEnemy.h"
using namespace std;

class Game_scene {
	public:

		const string nameScene="Game_scene";
		
		void setupScene();
		void drawScene();
		void updateScene();

		RectangleEnemy enemy;

};
