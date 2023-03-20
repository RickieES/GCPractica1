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
        ofDrawRectangle(this->getLimitGameLeft(), this->getLimitGameUp(), ofGetWidth(), this->getLimitGameUp());
        ofDrawRectangle(this->getLimitGameLeft(), this->getLimitGameDown(), ofGetWidth(), ofGetHeight()-this->getLimitGameDown());

        return;
    }



    //*****************************************************
        // ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
    //*****************************************************

	unsigned Game_scene::getLimitGameUp(){
        return this->limitGameUp;
    }
	void Game_scene::setLimitGameUp(unsigned value){
        this->limitGameUp = value;
        return;
    }

	unsigned Game_scene::getLimitGameDown(){
        return this->limitGameDown;
    }
	void Game_scene::setLimitGameDown(unsigned value){
        this->limitGameDown = value;
        return;
    }

	unsigned Game_scene::getLimitGameLeft(){
        return this->limitGameLeft;
    }
	void Game_scene::setLimitGameLeft(unsigned value){
        this->limitGameLeft = value;
        return;
    }

	unsigned Game_scene::getLimitGameRight(){
        return this->limitGameRight;
    }
	void Game_scene::setLimitGameRight(unsigned value){
        this->limitGameRight = value;
        return;
    }

	unsigned Game_scene::getLifeBarWidth(){
        return this->limitGameRight;
    }
	void Game_scene::setLifeBarWidth(unsigned value){
        this->limitGameRight = value;
        return;
    }
    
	unsigned Game_scene::getLifeBarHeight(){
        return this->limitGameRight;
    }
	void Game_scene::setLifeBarHeight(unsigned value){
        this->limitGameRight = value;
        return;
    }