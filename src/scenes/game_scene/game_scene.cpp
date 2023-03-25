#include "game_scene.h" 
 

        //SetupScene function
    //*****************************************************
    void Game_scene::setupScene(){
        AbstractScene::setupScene();

        ofSetBackgroundColor(118);

        this->setLimitGameUp((ofGetHeight()*25)/100);
        this->setLimitGameDown((ofGetHeight()*75)/100);
        this->setLimitGameLeft(0);
        this->setLimitGameRight(ofGetWidth());

        this->setLifeBarCoords((ofGetWidth()*10)/100, (ofGetHeight()*10)/100, 0 );
        this->setLifeBarWidth((ofGetWidth()*30)/100);
        this->setLifeBarHeight((ofGetHeight()*5)/100);

        player_up = Player(ofPoint(ofGetWidth()*0.3, 0), -90, ofColor::red);
        player_up.facing = Player::Orientation::SOUTH;
        player_down = Player(ofPoint(ofGetWidth()*0.3, ofGetHeight()), 90, ofColor::blue);
//        player_down.facing = Player::Orientation::NORTH;

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


 

//        ofSetColor(0);
//        ofDrawRectangle(this->getLimitGameLeft(), 0, ofGetWidth(), this->getLimitGameUp());
//        ofDrawRectangle(this->getLimitGameLeft(), this->getLimitGameDown(), ofGetWidth(), ofGetHeight()-this->getLimitGameDown());

//        ofSetColor(255, 0, 0);
//        ofDrawRectangle(this->getLifeBarCoords().x, this->getLifeBarCoords().y, this->getLifeBarWidth(), this->getLifeBarHeight());

        drawPlayers();
//        drawUI();

        ofSetColor(ofColor::white);
        ofDrawBitmapString(ofGetFrameRate(), 20, 20);

        return;
    }


    void Game_scene::drawPlayers(){
        player_up.draw();
        player_down.draw();
    }


    void Game_scene::drawUI(){

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


	ofPoint Game_scene::getLifeBarCoords(){
        return this->lifeBarCoords;
    }
	void Game_scene::setLifeBarCoords(ofPoint value){
        this->lifeBarCoords = value;
        return;
    }
	void Game_scene::setLifeBarCoords(int x, int y, int z){
        this->lifeBarCoords = ofPoint(x, y, 0);
        return;
    }


	unsigned Game_scene::getLifeBarWidth(){
        return this->lifeBarWidth;
    }
	void Game_scene::setLifeBarWidth(unsigned value){
        this->lifeBarWidth = value;
        return;
    }
    
	unsigned Game_scene::getLifeBarHeight(){
        return this->lifeBarHeight;
    }
	void Game_scene::setLifeBarHeight(unsigned value){
        this->lifeBarHeight = value;
        return;
    }
