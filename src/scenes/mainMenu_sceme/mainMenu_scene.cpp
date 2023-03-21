#include "mainMenu_scene.h"
 

        //SetupScene function
    //*****************************************************
    void MainMenu_scene::setupScene(){

        //startGame_button.addListener(this, &MainMenu_scene::test);

        mainPanel.setup();
        mainPanel.add(startGame_button.setup("start", 200, 200));


        this->signTitleWidht = 5*(ofGetWidth()/10);
        this->signTitleHeight = 1*(ofGetHeight()/10);
        this->signTitlePosX = 2.5*(ofGetWidth()/10);
        this->signTitlePosY = 1*(ofGetHeight()/10);
        this->title="DEFEND DEATH START";
        this->titleFont.load("verdana.ttf", 30, true, true);
        this->titleFont.setLineHeight(34.0f);
        this->titleFont.setLetterSpacing(1.035);

        this->signMenuWidht = 4*(ofGetWidth()/10);
        this->signMenuHeight = 5*(ofGetHeight()/10);
        this->signMenuPosX = 3*(ofGetWidth()/10);
        this->signMenuPosY = 3*(ofGetHeight()/10);

            this->buttonFont.load("verdana.ttf", 18, true, true);
            this->buttonFont.setLineHeight(34.0f);
            this->buttonFont.setLetterSpacing(1.035);

            this->playButton = "Scenary";
			this->signPlayButtonWidht = 3*(ofGetWidth()/10);
			this->signPlayButtonHeight = 0.5*(ofGetHeight()/10);
			this->signPlayButtonPosX = 3.5*(ofGetWidth()/10);
			this->signPlayButtonPosY = 3.5*(ofGetHeight()/10);

            this->pauseButton = "Enemy";
			this->signPauseButtonWidht = 3*(ofGetWidth()/10);
			this->signPauseButtonHeight = 0.5*(ofGetHeight()/10);
			this->signPauseButtonPosX = 3.5*(ofGetWidth()/10);
			this->signPauseButtonPosY = 4.0*(ofGetHeight()/10);

            this->scoreButton = "Player";
			this->signScoreButtonWidht = 3*(ofGetWidth()/10);
			this->signScoreButtonHeight = 0.5*(ofGetHeight()/10);
			this->signScoreButtonPosX = 3.5*(ofGetWidth()/10);
			this->signScoreButtonPosY = 4.5*(ofGetHeight()/10);

        return;
    }


        //DrawScene function
    //*****************************************************
    void MainMenu_scene::drawScene(){
        mainPanel.draw();
//        ofSetColor(ofColor::red);
//        ofDrawRectangle(0, 0, 200, 200);


//        ofBackground(114, 156, 212);
//        ofFill();
//        ofSetColor(160, 171, 43);
//        ofDrawRectangle(this->signTitlePosX, this->signTitlePosY, this->signTitleWidht, this->signTitleHeight);
//        ofDrawRectangle(this->signMenuPosX, this->signMenuPosY, this->signMenuWidht, this->signMenuHeight);
        
//        ofSetColor(145, 65, 12);
//        ofDrawRectangle(this->signPlayButtonPosX, this->signPlayButtonPosY, this->signPlayButtonWidht, this->signPlayButtonHeight);
//        ofDrawRectangle(this->signPauseButtonPosX, this->signPauseButtonPosY, this->signPauseButtonWidht, this->signPauseButtonHeight);
//        ofDrawRectangle(this->signScoreButtonPosX, this->signScoreButtonPosY, this->signScoreButtonWidht, this->signScoreButtonHeight);
       
//        ofSetColor(0,0,0);
//        this->titleFont.drawString(this->title, this->signTitlePosX + this->signTitlePosX/10, this->signTitlePosY + this->signTitleHeight/1.5 );
//        this->titleFont.drawString(this->playButton, this->signPlayButtonPosX, this->signPlayButtonPosY + this->signPlayButtonHeight);
//        this->titleFont.drawString(this->pauseButton, this->signPauseButtonPosX, this->signPauseButtonPosY + this->signPauseButtonWidht);
//        this->titleFont.drawString(this->scoreButton, this->signScoreButtonPosX, this->signScoreButtonPosY + this->signScoreButtonHeight);

        return;
    }


        //UpdateScene function
    //*****************************************************
    void MainMenu_scene::updateScene(){
        
    }


    void MainMenu_scene::test(){
        ofBackground(ofColor::red);
    }
