#pragma once
#include <string>
#include "ofMain.h"
using namespace std;

class MainMenu_scene {
	public:

		const string nameScene = "mainMenu_scene";

		void setupScene();
		void drawScene();
		void updateScene();

		string title;
		ofTrueTypeFont	titleFont;
		int signTitleWidht;
		int signTitleHeight;
		int signTitlePosX;
		int signTitlePosY;

		int signMenuWidht;
		int signMenuHeight;
		int signMenuPosX;
		int signMenuPosY;

			ofTrueTypeFont buttonFont;

			string playButton;
			int signPlayButtonWidht;
			int signPlayButtonHeight;
			int signPlayButtonPosX;
			int signPlayButtonPosY;
			ofEvent<glm::vec2> playButton_clicEvent;

			string pauseButton;
			int signPauseButtonWidht;
			int signPauseButtonHeight;
			int signPauseButtonPosX;
			int signPauseButtonPosY;
			ofEvent<glm::vec2> pauseButton_clicEvent;

			string scoreButton;
			int signScoreButtonWidht;
			int signScoreButtonHeight;
			int signScoreButtonPosX;
			int signScoreButtonPosY;
			ofEvent<glm::vec2> scoreButton_clicEvent;



};
