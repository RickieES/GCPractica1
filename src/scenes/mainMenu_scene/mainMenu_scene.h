#pragma once
#include <string>
#include "ofMath.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "game_colorPalette.h"
using namespace std;

//typedef void (ofApp::*changeScene)();

class MainMenu_scene {
	public:

		const string nameScene = "mainMenu_scene";

		ofEvent<int> onStartGame;

		void setupScene();
		void drawScene();
		void updateScene();

		void drawBackground();
		void drawTitle();

		string title;
		ofTrueTypeFont titleFont;
		ofTrueTypeFont startText;

};
