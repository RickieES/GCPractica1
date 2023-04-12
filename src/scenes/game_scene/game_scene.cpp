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

        playerUp = Player(ofPoint(ofGetWidth()*0.3, 0), 0, GameObject::ColorType::Color1);
        playerUp.facing = Player::Orientation::SOUTH;
        playerDown = Player(ofPoint(ofGetWidth()*0.3, ofGetHeight()), 0, GameObject::ColorType::Color2);
		// player_down.facing = Player::Orientation::NORTH;

		lastEnemyWave = ofGetElapsedTimeMillis();
		lastPressedShootDown = ofGetElapsedTimeMillis();
		lastPressedShootUp = ofGetElapsedTimeMillis();

		loadSounds();

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

			// Genera de 1 a 5 enemigos
			int nEnemies = rand() % nMaxEnemy + 1;

			for (int i = 0; i < nEnemies; i++) {

				// Si se quieren añadir mas propiedades a los enemigos o añadir tipos, esto no sirve
				GameObject::ColorType randColor = (GameObject::ColorType) (rand() % 2);
				BuilderEnemies::EnemyType randEnemy = (BuilderEnemies::EnemyType) (rand() % 3);
				BuilderEnemies::SizeType randSize = (BuilderEnemies::SizeType) (rand() % 3);
				BuilderEnemies::SpeedType randSpeed = (BuilderEnemies::SpeedType) (rand() % 3);

				AbstractEnemy * e = spawner.build(randColor, randEnemy, randSize, randSpeed);

				enemyList.push_back(e);
			}
		}

		// Actualizar la posicion de todos los objetos en la lista
		// https://stackoverflow.com/questions/30926577/c-call-a-childs-method-from-a-vector-of-parents
		updateGameObjectVector(&bulletList);
		updateGameObjectVector(&enemyList);		

		// TODO: Creo que se puede reducir el numero de bucles entre las colisiones y el recibir daño

		// Colisiones
		for (int i = 0; i < enemyList.size(); i++) {
			GameObject * enem = enemyList[i];

			for (int j = 0; j < bulletList.size(); j++) {
				GameObject * bullet = bulletList[j];

				if (enem->getColorType() == bullet->getColorType() && enem->collidesWith(*bullet)) {

					// FIXME: Problema random al quitar elementos del vector
					enemyList.erase(enemyList.begin() + i);
					bulletList.erase(bulletList.begin() + j);

					soundPlayer[2]->play();

					// TODO: Añadir puntuacion segun tamaño y demás
					score += 1;
				}
			}
		}

		// Recibir daño
		for (int i = 0; i < enemyList.size(); i++) {
			GameObject * enem = enemyList[i];

			if (home.collidesWith(*enem)) {
				enemyList.erase(enemyList.begin() + i);

				soundPlayer[3]->play();

				// TODO: Comprobar tamaño del enemigo para recibir mas o menos daño
				healthPoints = max(0, healthPoints - 5);

				if (healthPoints == 0) {
					int targetScene = 2;
					ofNotifyEvent(onDeath, targetScene);
				}
			}
		}

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
				bulletList.push_back(playerUp.shoot());

				soundPlayer[1]->play();
			} 
			else if (ofGetElapsedTimeMillis() - lastPressedShootUp > 500) 
			{
				lastPressedShootUp = ofGetElapsedTimeMillis();
				bulletList.push_back(playerUp.shoot());

				soundPlayer[1]->play();
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
				bulletList.push_back(playerDown.shoot());

				soundPlayer[1]->play();
			}
			else if (ofGetElapsedTimeMillis() - lastPressedShootDown > 500)
			{
				lastPressedShootDown = ofGetElapsedTimeMillis();
				bulletList.push_back(playerDown.shoot());

				soundPlayer[1]->play();
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
		
		drawGameObjectVector(&bulletList);
		drawGameObjectVector(&enemyList);
		
        drawPlayers();
		home.draw();
	    drawUI();

        return;
    }


    void Game_scene::drawPlayers(){
        playerUp.draw();
        playerDown.draw();
    }


	void Game_scene::drawUI() {
		float percentageHP = healthPoints / 100.0;

		// Barra de vida
		ofSetColor(ofColor::black);
		//int offset = 10; // Por si fuese necesario en un futuro
		ofDrawRectangle(lifeBarCoords.x, lifeBarCoords.y, lifeBarWidth, lifeBarHeight);

		if (healthPoints < 20) {
			ofSetColor(ofColor::red);
		} else {
			ofSetColor(ofColor::green);
		}

		ofDrawRectangle(lifeBarCoords.x, lifeBarCoords.y, lifeBarWidth*percentageHP, lifeBarHeight);

		ofSetColor(ofColor::black);
		ofDrawBitmapString(healthPoints, lifeBarCoords.x + 10, lifeBarCoords.y + 20);

		ofSetColor(ofColor::white);

		// Puntuacion
		ofDrawBitmapString(score, ofGetWidth() - 50, 20);

		// Framerate (opcional)
		ofDrawBitmapString(ofGetFrameRate(), 20, 20);
    }


	void Game_scene::loadSounds() {
		// Cargar sonidos y efectos
		ofSoundPlayer * soundtrack = new ofSoundPlayer();
		soundtrack->load("audio/soundtracks/vvvvvv_positive_force.mp3", true);
		soundtrack->setLoop(true);
		soundtrack->play();

		soundPlayer.push_back(soundtrack);

		// cañon
		ofSoundPlayer * cannon_shoot = new ofSoundPlayer();
		cannon_shoot->load("audio/sound_effects/cannon_shoot.wav");
		cannon_shoot->setMultiPlay(true);

		soundPlayer.push_back(cannon_shoot);

		// eliminar enemigo
		ofSoundPlayer * enemy_destroyed = new ofSoundPlayer();
		enemy_destroyed->load("audio/sound_effects/enemy_destroyed.wav");
		enemy_destroyed->setMultiPlay(true);

		soundPlayer.push_back(enemy_destroyed);

		// recibir daño
		ofSoundPlayer * home_damage = new ofSoundPlayer();
		home_damage->load("audio/sound_effects/home_damage.wav");
		home_damage->setMultiPlay(true);

		soundPlayer.push_back(home_damage);
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

	void Game_scene::updateGameObjectVector(vector<GameObject*>* objList) {
		//for (auto e : objList) {
		//	e->update();
		//}

		// Actualiza y comprueba si esta fuera de la pantalla
		for (int i = 0; i < objList->size(); i++) {
			(*objList)[i]->update();

			if (checkOutOfBounds((*objList)[i])) {
				objList->erase(objList->begin() + i);
			}
		}
	}

	void Game_scene::drawGameObjectVector(vector<GameObject*>* objList) {
		for (auto e : (*objList)) {
			e->draw();
		}
	}

	void Game_scene::drawBackground() {
		// TODO: Hacer relativo
		ofSetColor(bgSecondary);
		int counter = - ((int)(ofGetElapsedTimeMillis()/10.0) % 200);
		int bgSectionWidth = 100;

		for (int i = 0; i <= ofGetWidth()/200 + 1; i++) {
			ofDrawRectangle(counter + i*(bgSectionWidth*2), 0, bgSectionWidth, ofGetHeight());
		}

		/*
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()*0.2);
		ofDrawRectangle(0, ofGetHeight()*0.8, ofGetWidth(), ofGetHeight()*0.2);*/

/*
		ofSetColor(bgTertiary);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()*0.1);
		ofDrawRectangle(0, ofGetHeight()*0.9, ofGetWidth(), ofGetHeight()*0.1);*/
	}
