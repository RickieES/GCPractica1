#include "Player.h"
#include "ofMain.h"
#include "../bullet/Bullet.h"

// Constructor vacío
Player::Player() {
}

// Constructor con tipos simples
//*************************************************************
Player::Player(int xCenter, int yCenter, int cannonAngle, int r, int g, int b,
				Orientation initFacing) {
	this->facing = initFacing;
	this->rotationSpeed = 2;
	this->radius = 50;
    this->cannonLength = 50;
    this->cannonWidth = 8;
	this->setRefPointX(xCenter);
	this->setRefPointY(yCenter);
    this->cannonAngle = cannonAngle;
	this->setColor(r, g , b);

	this->cannonBase.lineTo(0, 0);
	ofPoint point2(radius, 0);
	this->cannonBase.arc(point2, radius, radius, 0, 180);
	this->cannonBase.setColor(this->getColor());
}

// Constructor con tipos reales
//*************************************************************
Player::Player(ofPoint playerPos, int cannonAngle, ofColor mainColor,
				Orientation initFacing) {
	this->facing = initFacing;
	this->setRefPoint(playerPos);
    this->cannonAngle = cannonAngle;
    this->setColor(mainColor);

	ofPoint point2(this->getRefPointX(), this->getRefPointY());
	cannonBase.arc(point2, 100, 100, 0, 180, 100);
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

/**
 * Sets radius (to a minimum of 0 and a maximum of 359)
*/
void Player::setRadius(int r) {
	this->radius = min(359, max(0, r));
}

int Player::getRadius() {
	return this->radius;
}

void Player::setAltColor(ofColor ac) {
	this->altColor = ac;
}

ofColor Player::getAltColor() {
	return this->altColor;
}

/**
 * Sets cannon length to a minimum of 30 and a maximum of 100
*/
void Player::setCannonLength(int cl) {
	this->cannonLength = max(30, min(100, cl));
}

int Player::getCannonLength() {
	return this->cannonLength;
}

/**
 * Sets cannon width to a minimum of 8 and a maximum of 30
*/
void Player::setCannonWidth(int cw) {
	this->cannonWidth = max(8, min(30, cw));
}

int Player::getCannonWidth() {
	return this->cannonWidth;
}

/**
 * Sets cannon angle
*/
void Player::setCannonAngle(int ca) {
	this->cannonAngle = ca;
}

int Player::getCannonAngle() {
	return this->cannonAngle;
}

[[deprecated]]
void Player::setCanyonLength(int cl) {
	this->setCannonLength(cl);
}

[[deprecated]]
int Player::getCanyonLength() {
	return this->getCannonLength();
}

[[deprecated]]
void Player::setCanyonWidth(int cw) {
	this->setCannonWidth(cw);
}

[[deprecated]]
int Player::getCanyonWidth() {
	return this->getCannonWidth();
}

[[deprecated]]
void Player::setCanyonAngle(int ca) {
	this->setCannonAngle(ca);
}

[[deprecated]]
int Player::getCanyonAngle() {
	return this->getCannonAngle();
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
	ofRotateDeg(this->cannonAngle, 0, 0, 1);
 	ofSetColor(this->altColor);
	ofFill();
	ofDrawRectangle(0 - (cannonWidth / 2), 0,
					cannonWidth, cannonLength);
	ofPopMatrix();

	ofSetColor(this->getColor());
	// this->canyonBase.lineTo(0, 0);
	// ofPoint point2(radius, 0);
	// this->canyonBase.arc(point2, radius, radius, 0, 180);
	// this->canyonBase.setColor(this->getColor());
	// ofFill();
	this->cannonBase.draw();
	ofPopMatrix();
}


// pmUpdate Function
//*************************************************************
void Player::update(){

}


// MoveLeft Function
//*************************************************************
void Player::moveLeft(){
    this->cannonAngle =  max(-80, this->cannonAngle - this->getRotationSpeed());
}


// MoveRight Function
//*************************************************************
void Player::moveRight(){
    this->cannonAngle =  min(80, this->cannonAngle + this->getRotationSpeed());
};

Bullet * Player::shoot() {
	ofPoint bulletInitial = ofPoint(this->getRefPointX() + radius, radius + cannonLength - 5, 0);
	
	Bullet *b = new Bullet(bulletInitial, 1, 1);
	return b;
}
