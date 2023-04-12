#pragma once
#include <string>
#include "ofMain.h"
#include "game_colorPalette.h"
using namespace std;


class End_scene {
	public:

		const string nameScene="end_scene";

		void setupScene();
		void drawScene();
		void updateScene();

		void drawBackground();

		ofTrueTypeFont gameOverFont;
		ofTrueTypeFont gameOverBgFont;
};