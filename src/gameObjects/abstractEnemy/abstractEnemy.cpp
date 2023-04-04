#include "abstractEnemy.h" 
 
        //Setup function
    //*****************************************************
    void AbstractEnemy::setup(){
        return;
    }

        //Draw function
    //*****************************************************
    void AbstractEnemy::draw(){
        return;
    }

        //Update function
    //*****************************************************
    void AbstractEnemy::update(){
		posX -= getSpeed();
        return;
    }


    //*****************************************************
        // ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
    //*****************************************************
    int AbstractEnemy::getSpeed(){
        return this->speed;
    }
    void AbstractEnemy::setSpeed(int value){
        this->speed = value;
        return;
    }

    ofColor AbstractEnemy::getColor(){
        return this->color;
    }
    void AbstractEnemy::setColor(ofColor value){
        this->color = value;
        return;
    }



    int AbstractEnemy::getPosX(){
        return this->posX;
    }
    void AbstractEnemy::setPosX(int value){
        this->posX = value;
        return;
    }

	int AbstractEnemy::getPosY(){
        return this->posY;
    }
    void AbstractEnemy::setPosY(int value){
        this->posY = value;
        return;
    }

	int AbstractEnemy::getLimitUp(){
        return this->limitUp;
    }
	void AbstractEnemy::setLimitUp(int value){
        this->limitUp = value;
        return;
    }

	int AbstractEnemy::getLimitDown(){
        return this->limitDown;
    }
	void AbstractEnemy::setLimitDown(int value){
        this->limitDown = value;
        return;
    }

	int AbstractEnemy::getLimitLeft(){
        return this->limitLeft;
    }
	void AbstractEnemy::setLimitLeft(int value){
        this->limitLeft = value;
        return;
    }

	int AbstractEnemy::getLimitRight(){
        return this->limitRight;
    }
	void AbstractEnemy::setLimitRight(int value){
        this->limitRight = value;
        return;
    }

