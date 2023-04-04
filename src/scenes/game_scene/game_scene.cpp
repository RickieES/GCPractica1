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

        player_up = Player(ofPoint(ofGetWidth()*0.3, 0), 0, ofColor::red);
        player_up.facing = Player::Orientation::SOUTH;
        player_down = Player(ofPoint(ofGetWidth()*0.3, ofGetHeight()), 0, ofColor::blue);
		// player_down.facing = Player::Orientation::NORTH;

		// spawner = BuilderEnemies;

        return;
    }




        //UpdateScene function
    //*****************************************************
    void Game_scene::updateScene(){
        AbstractScene::updateScene();

		// Generar enemigos
		if (objectList.size() < 10){
			RectangleEnemy * e = spawner.build(BuilderEnemies::ColorType::color1, 
											BuilderEnemies::EnemyType::square,
											BuilderEnemies::SizeType::small,
											BuilderEnemies::SpeedType::normal);

			objectList.push_back(e);
		}

		// https://stackoverflow.com/questions/30926577/c-call-a-childs-method-from-a-vector-of-parents
		for (auto e : objectList)
		{
			e->update();
		}

        // TODO: Pasar a funcion (simplemente encapsular)
		// Jugador up
        if (ofGetKeyPressed('a')){
            player_up.moveLeft();
        }

        if (ofGetKeyPressed('d')){
            player_up.moveRight();
        }

		if (ofGetKeyPressed('s')) {
			objectList.push_back(player_up.shoot());
		}

		// Jugador down
        if (ofGetKeyPressed('j')){
            player_down.moveLeft();
        }

        if (ofGetKeyPressed('l')){
            player_down.moveRight();
        }

		if (ofGetKeyPressed('k')) {
			objectList.push_back(player_down.shoot());
		}



        return;
    }


        //DrawScene function
    //*****************************************************
    void Game_scene::drawScene(){
        AbstractScene::drawScene();
		
		for each (auto e in objectList)
		{
			e->draw();
		}
		
//        ofSetColor(0);
//        ofDrawRectangle(this->getLimitGameLeft(), 0, ofGetWidth(), this->getLimitGameUp());
//        ofDrawRectangle(this->getLimitGameLeft(), this->getLimitGameDown(), ofGetWidth(), ofGetHeight()-this->getLimitGameDown());

//        ofSetColor(255, 0, 0);g//        ofDrawRectangle(this->getLifeBarCoords().x, this->getLifeBarCoords().y, this->getLifeBarWidth(), this->getLifeBarHeight());

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
