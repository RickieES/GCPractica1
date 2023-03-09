#include "Player.h"
#include "ofMain.h"


// Constructor con tipos simples
//*************************************************************
Player::Player(int x, int y, int canyonAngle, int r, int g, int b) {
	this->bodyPos.x = x;
	this->bodyPos.y = y;
    this->canyonAngle = canyonAngle;
    this->mainColor = ofColor(r % 256, g % 256, b % 256);
}

// Constructor con tipos reales
//*************************************************************
Player::Player(ofPoint playerPos, int canyonAngle, ofColor mainColor) {
	this->bodyPos = playerPos;
    this->canyonAngle = canyonAngle;
    this->mainColor = mainColor;
}

// pmDraw Function
//*************************************************************
void Player::draw(){
    // TODO: incluir en una matriz de transformación
	ofSetColor(this->mainColor);
    // TODO: hacer un degradado de color;
	ofFill();
    ofDrawCircle(bodyPos, radius);
    // TODO: incluir en una matriz de transformación
	ofDrawRectangle(0, 0 - this->canyonWidth / 2, this->canyonLength, this->canyonWidth / 2);
	return;
}


// pmUpdate Function
//*************************************************************
void Player::update(){
	

	return;
}


// MoveLeft Function
//*************************************************************
void Player::moveLeft(){
    this->bodyPos.x = this->bodyPos.x - this->rotationSpeed;
	return;
}


// MoveRight Function
//*************************************************************
void Player::moveRight(){
	this->bodyPos.x = this->bodyPos.x + this->rotationSpeed;
	return;
};
