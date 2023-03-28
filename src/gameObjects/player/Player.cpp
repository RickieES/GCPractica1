#include "Player.h"
#include "ofMain.h"
#include "../bullet/Bullet.h"

// Constructor vacío
Player::Player() {
}

// Constructor con tipos simples
//*************************************************************
Player::Player(int xCenter, int yCenter, int canyonAngle, int r, int g, int b,
				Orientation initFacing) {
	this->facing = initFacing;
	this->rotationSpeed = 2;
	this->radius = 50;
    this->canyonLength = 50;
    this->canyonWidth = 8;
	this->setRefPointX(xCenter);
	this->setRefPointY(yCenter);
    this->canyonAngle = canyonAngle;
	this->setColor(r, g , b);

	this->canyonBase.lineTo(0, 0);
	ofPoint point2(radius, 0);
	this->canyonBase.arc(point2, radius, radius, 0, 180);
	this->canyonBase.setColor(this->getColor());
}

// Constructor con tipos reales
//*************************************************************
Player::Player(ofPoint playerPos, int canyonAngle, ofColor mainColor,
				Orientation initFacing) {
	this->facing = initFacing;
	this->setRefPoint(playerPos);
    this->canyonAngle = canyonAngle;
    this->setColor(mainColor);

	ofPoint point2(this->getRefPointX(), this->getRefPointY());
	canyonBase.arc(point2, 100, 100, 0, 180, 100);
}

/**
 * Sets the rotation speed (to a maximum of 5)
*/
void Player::setRotationSpeed(int rs) {
	this->rotationSpeed = min(5, rs);
}

int Player::getRotationSpeed() {
	return this->rotationSpeed;
};

void Player::setRadius(int r) {
	this->radius = min(359, max(0, r));
}

int Player::getRadius() {
	return this->radius;
}

/**
 * Sets canyon length to a maximum of 100
*/
void Player::setCanyonLength(int cl) {
	this->canyonLength = max(30, min(100, cl));
}

int Player::getCanyonLength() {
	return this->canyonLength;
}

/**
 * Sets canyon width to a maximum of 30
*/
void Player::setCanyonWidth(int cw) {
	this->canyonWidth = max(8, min(30, cw));
}

int Player::getCanyonWidth() {
	return this->canyonWidth;
}

void Player::setAltColor(ofColor ac) {
	this->altColor = ac;
}

ofColor Player::getAltColor() {
	return this->altColor;
}

void Player::setCanyonAngle(int ca) {
	this->canyonAngle = ca;
}

int Player::getCanyonAngle() {
	return this->canyonAngle;
}

// pmDraw Function
//*************************************************************
void Player::draw() {
    // TODO: hacer un degradado de color;
	ofPushMatrix();
	ofTranslate(this->getRefPointX(), this->getRefPointY(), 0);
	if (this->facing == Orientation::NORTH) {
	 	ofRotateDeg(180);
	}

 	ofPushMatrix();
	ofTranslate(radius, radius - 5, 0);
	ofRotateDeg(this->canyonAngle, 0, 0, 1);
 	ofSetColor(this->altColor);
	ofFill();
	ofDrawRectangle(0 - (canyonWidth / 2), 0,
					canyonWidth, canyonLength);
	ofPopMatrix();

	ofSetColor(this->getColor());
	// this->canyonBase.lineTo(0, 0);
	// ofPoint point2(radius, 0);
	// this->canyonBase.arc(point2, radius, radius, 0, 180);
	// this->canyonBase.setColor(this->getColor());
	// ofFill();
	this->canyonBase.draw();
	ofPopMatrix();
}


// pmUpdate Function
//*************************************************************
void Player::update(){

}


// MoveLeft Function
//*************************************************************
void Player::moveLeft(){
    this->canyonAngle =  max(-80, this->canyonAngle - this->getRotationSpeed());
}


// MoveRight Function
//*************************************************************
void Player::moveRight(){
    this->canyonAngle =  min(80, this->canyonAngle + this->getRotationSpeed());
};

Bullet * Player::shoot() {
	ofPoint bulletInitial = ofPoint(this->getRefPointX() + radius, radius + canyonLength - 5, 0);
	
	Bullet *b = new Bullet(bulletInitial, 1, 1);
	return b;
}
