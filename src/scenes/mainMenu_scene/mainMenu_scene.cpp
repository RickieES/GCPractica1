#include "mainMenu_scene.h"
 

        //SetupScene function
    //*****************************************************
    void MainMenu_scene::setupScene(){

		ofBackground(bgMain);

        this->title="Defend\nDeath Star";
        this->titleFont.load("V5PRC.TTF", 60, true, true);
        this->titleFont.setLineHeight(70.0f);
        this->titleFont.setLetterSpacing(1.035);

		this->startTextFont.load("V5PRC.TTF", 30, true, true);
		this->startTextFont.setLineHeight(40.0f);
		this->startTextFont.setLetterSpacing(1.035);

        return;
    }


        //DrawScene function
    //*****************************************************
    void MainMenu_scene::drawScene(){
		this->drawBackground();

		this->drawTitle();

		startTextFont.drawString("Press any\n   key to play", 100, 450);

        return;
    }


        //UpdateScene function
    //*****************************************************
    void MainMenu_scene::updateScene(){
		if (ofGetKeyPressed()) {
			int targetScene = 1;
			ofNotifyEvent(onStartGame, targetScene);
		}
    }


	void MainMenu_scene::drawBackground() {
		int halfWidth = (int) (ofGetWidth() / 2.0);
		float counter = ((int)(ofGetElapsedTimeMillis() / 3.0) % halfWidth) / (float)halfWidth;
		float nStrips = 2;

		ofSetColor(bgSecondary);

		ofPushMatrix();

		ofTranslate(ofGetWidth() / 2.0, 0);
		for (int i = 0; i < nStrips; i++) {

			float shift = i / nStrips;
			float widthShift = shift + 1 /(2*nStrips);

			float pos = (counter + shift) - floor(counter + shift);
			float nextPos = counter + widthShift-floor(counter + widthShift);

			int initPos = (int)(halfWidth * (pow(pos, 2)));
			int widthStrip = (int)(halfWidth * (pow(nextPos, 2)) - initPos);

			if (nextPos < pos) {
				widthStrip = halfWidth;
			}

			ofDrawRectangle(initPos, 0, widthStrip, ofGetHeight());

			ofScale(-1, 1);
			ofDrawRectangle(initPos, 0, widthStrip, ofGetHeight());
			ofScale(-1, 1);

		}

		ofPopMatrix();

	}


	void MainMenu_scene::drawTitle() {

		float counter = ofGetElapsedTimeMillis() / 20.0;

		ofSetColor(bgMain);
		titleFont.drawString(title, 100, 130 + 5 * sin((counter + 2) / (2 * 3.14)));
		ofSetColor(ofColor::white);
		titleFont.drawString(title, 100, 125 + 5 * sin(counter / (2 * 3.14)));

	}