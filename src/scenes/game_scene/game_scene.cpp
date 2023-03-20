#include "game_scene.h" 
 

        //SetupScene function
    //*****************************************************
    void Game_scene::setupScene(){
        AbstractScene::setupScene();

        this->setLimitGameUp((ofGetHeight()/25)*100);
        this->setLimitGameDown((ofGetHeight()/75)*100);
        this->setLimitGameLeft(0);
        this->setLimitGameRight(ofGetWidth());
        return;
    }




        //UpdateScene function
    //*****************************************************
    void Game_scene::updateScene(){
        AbstractScene::updateScene();
/* 
        RectangleEnemy *enemy = new RectangleEnemy(100, 1500, 0, ofGetWidth(), 1, 200, 100);
        gameObjectList.push_back( enemy ); */
        return;
    }


        //DrawScene function
    //*****************************************************
    void Game_scene::drawScene(){
        AbstractScene::drawScene();
 
        ofSetBackgroundColor(118);
        ofSetColor(255, 255, 255);
        ofDrawRectangle(this->limitGameLeft, this->limitGameUp, ofGetWidth(), this->limitGameUp);
       // ofDrawRectangle(this->limitGameLeft, this->limitGameDown);

        return;
    }



    //*****************************************************
        // ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
    //*****************************************************

	int Game_scene::getLimitGameUp(){
        return this->limitGameUp;
    }
	void Game_scene::setLimitGameUp(int value){
        this->limitGameUp = value;
        return;
    }

	int Game_scene::getLimitGameDown(){
        return this->limitGameDown;
    }
	void Game_scene::setLimitGameDown(int value){
        this->limitGameDown = value;
        return;
    }

	int Game_scene::getLimitGameLeft(){
        return this->limitGameLeft;
    }
	void Game_scene::setLimitGameLeft(int value){
        this->limitGameLeft = value;
        return;
    }

	int Game_scene::getLimitGameRight(){
        return this->limitGameRight;
    }
	void Game_scene::setLimitGameRight(int value){
        this->limitGameRight = value;
        return;
    }