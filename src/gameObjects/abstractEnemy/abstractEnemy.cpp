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
        return;
    }


    //*****************************************************
        // ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
    //*****************************************************

    string AbstractEnemy::getId(){
        return this->id;
    }
    void AbstractEnemy::setId(string value){
        this->id = value;
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

    unsigned AbstractEnemy::getSpeed(){
        return this->speed;
    }
    unsigned AbstractEnemy::setSpeed(unsigned value){
        this->speed = value;
        return;
    }