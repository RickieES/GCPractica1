#include "game_scene.h"
 

        //SetupScene function
    //*****************************************************
    void Game_scene::setupScene(){
        AbstractScene::setupScene();

        ofBackground(bgMain);

        this->setLimitGameUp((ofGetHeight()*25)/100);
        this->setLimitGameDown((ofGetHeight()*75)/100);
        this->setLimitGameLeft(0);
        this->setLimitGameRight(ofGetWidth());

        this->setLifeBarCoords(ofGetWidth()*0.55, ofGetHeight()*0.02, 0);
        this->setLifeBarWidth((ofGetWidth()*30)/100);
        this->setLifeBarHeight((ofGetHeight()*5)/100);

		healthPoints = 100;

        playerUp = Player(ofPoint(ofGetWidth()*0.3, 0), 0, ofColor::red);
        playerUp.facing = Player::Orientation::SOUTH;
        playerDown = Player(ofPoint(ofGetWidth()*0.3, ofGetHeight()), 0, ofColor::blue);
		// player_down.facing = Player::Orientation::NORTH;

		// spawner = BuilderEnemies;

		lastEnemyWave = ofGetElapsedTimeMillis();
		lastPressedShootDown = ofGetElapsedTimeMillis();
		lastPressedShootUp = ofGetElapsedTimeMillis();

        return;
    }




        //UpdateScene function
    //*****************************************************
    void Game_scene::updateScene(){
        AbstractScene::updateScene();

		// Generar enemigos
		if (ofGetElapsedTimeMillis() - lastEnemyWave > 2000) {

			// Reinicia el "timer"
			lastEnemyWave = ofGetElapsedTimeMillis();

			int nEnemies = rand() % 5 + 1;
		
			// TODO: Generar aleatoriamente todas las propiedades de los ememigos (en cada wave)

			for (int i = 0; i < nEnemies; i++) {
				AbstractEnemy * e = spawner.build(BuilderEnemies::ColorType::color1, 
												  BuilderEnemies::EnemyType::square,
												  BuilderEnemies::SizeType::small,
												  BuilderEnemies::SpeedType::normal);

				objectList.push_back(e);
			}
		}

		// https://stackoverflow.com/questions/30926577/c-call-a-childs-method-from-a-vector-of-parents
		for (auto e : objectList){
			e->update();
			//checkOutOfBounds(e);
		}

		for (int i = 0; i < objectList.size(); i++) {
			if (checkOutOfBounds(objectList[i])) {
				objectList.erase(objectList.begin() + i);
			}
		}
		

        // TODO: Pasar a funcion (simplemente encapsular)
		// Jugador up
        if (ofGetKeyPressed('a')){
            playerUp.moveLeft();
        }

        if (ofGetKeyPressed('d')){
            playerUp.moveRight();
        }

		/* Disparo semiautomatico:
			- Dispara una vez cada vez que se pulsa la tecla (s en este caso)
			- Dispara cada x segundos si se mantiene pulsado
		*/
		if (ofGetKeyPressed('s')) {
			if (!shootingPlayerUp) {
				shootingPlayerUp = true;
				objectList.push_back(playerUp.shoot());
			} 
			else if (ofGetElapsedTimeMillis() - lastPressedShootUp > 500) 
			{
				lastPressedShootUp = ofGetElapsedTimeMillis();
				objectList.push_back(playerUp.shoot());
			}
		}
		else 
		{
			shootingPlayerUp = false;
			lastPressedShootUp = ofGetElapsedTimeMillis();
		}

		// Jugador down
        if (ofGetKeyPressed('j')){
            playerDown.moveLeft();
        }

        if (ofGetKeyPressed('l')){
            playerDown.moveRight();
        }

		if (ofGetKeyPressed('k')) {
			if (!shootingPlayerDown) {
				shootingPlayerDown = true;
				objectList.push_back(playerDown.shoot());
			}
			else if (ofGetElapsedTimeMillis() - lastPressedShootDown > 500)
			{
				lastPressedShootDown = ofGetElapsedTimeMillis();
				objectList.push_back(playerDown.shoot());
			}
		}
		else
		{
			shootingPlayerDown = false;
			lastPressedShootDown = ofGetElapsedTimeMillis();
		}



        return;
    }


        //DrawScene function
    //*****************************************************
    void Game_scene::drawScene(){
        AbstractScene::drawScene();
	
		drawBackground();
		
		for (auto e : objectList){
			e->draw();
		}
		
        drawPlayers();
	    drawUI();

        return;
    }


    void Game_scene::drawPlayers(){
        playerUp.draw();
        playerDown.draw();
    }


	void Game_scene::drawUI() {
		
		// Barra de vida
		ofSetColor(ofColor::black);
		ofDrawRectangle(lifeBarCoords.x - 10, lifeBarCoords.y + 10, lifeBarWidth*(healthPoints / 100), lifeBarHeight);

		if (healthPoints < 20) {
			ofSetColor(ofColor::red);
		} else {
			ofSetColor(ofColor::green);
		}

		ofDrawRectangle(lifeBarCoords.x, lifeBarCoords.y, lifeBarWidth*(healthPoints / 100), lifeBarHeight);

		ofSetColor(ofColor::white);
		// Puntuacion
		ofDrawBitmapString(score, ofGetWidth() - 50, 20);

		// Framerate (opcional)
		ofDrawBitmapString(ofGetFrameRate(), 20, 20);
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

	bool Game_scene::checkOutOfBounds(GameObject * object) {
		int oPosX = object->getRefPointX();
		int oPosY = object->getRefPointY();

		// FIXME: Revisar inconsistencia entre limites del juego y de la ventana
		return (oPosX < (int)getLimitGameLeft() - boundsMargin ||
				oPosX > (int)getLimitGameRight() + boundsMargin ||
				oPosY < - boundsMargin ||
				oPosY > ofGetHeight() + boundsMargin);
	}

	void Game_scene::drawBackground() {
		// TODO: Hacer relativo
		ofSetColor(bgSecondary);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()*0.2);
		ofDrawRectangle(0, ofGetHeight()*0.8, ofGetWidth(), ofGetHeight()*0.2);

		ofSetColor(bgTertiary);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()*0.1);
		ofDrawRectangle(0, ofGetHeight()*0.9, ofGetWidth(), ofGetHeight()*0.1);
	}
