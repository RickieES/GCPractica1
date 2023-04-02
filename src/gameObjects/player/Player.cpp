#include "Player.h"
#include "ofMain.h"
#include "../bullet/Bullet.h"


void Player::initMembers(int ca) {
	this->rotationSpeed = 2;
	this->radius = 50;
    this->cannonLength = 50;
    this->cannonWidth = 8;
    this->cannonAngle = ca;

	// La posición de la forma ofPath influye en su dibujo
	// this->cannonBase.lineTo(0, 0);
	// ofPoint point2(radius * 2, 0);
	this->cannonBase.lineTo(0 - radius * 2, 0);
	ofPoint point2(0, 0);
	this->cannonBase.arc(point2, radius, radius, 0, 180);
	this->cannonBase.setColor(this->getColor());

	// cout << "Player ID: " << this->getId() << "\n";
	// cout << "facing: " << ((this->facing == Player::Orientation::NORTH) ? "North" : "South") << "\n";
	// cout << "xCenter, yCenter: " << this->getRefPointX()<< ", " << this->getRefPointY() << "\n";
	// cout << "Cannon l, w, a: " << this->getCannonLength() << ", " << this->getCannonWidth() << ", " << this->getCannonAngle() << "\n";
	// cout << "Color r, g, b: " << this->getColor().r << ", " << this->getColor().g << ", " << this->getColor().b << "\n";
}

// Constructor vacío
Player::Player() {
}

// Constructor con tipos simples
//*************************************************************
Player::Player(int xCenter, int yCenter, int cannonAngle, int r, int g, int b,
				Orientation initFacing) {
	this->facing = initFacing;
	this->setRefPointX(xCenter);
	this->setRefPointY(yCenter);
	this->setColor(r, g , b);
	initMembers(cannonAngle);
}

// Constructor con tipos reales
//*************************************************************
Player::Player(ofPoint playerPos, int cannonAngle, ofColor mainColor,
				Orientation initFacing) {
	this->facing = initFacing;
	this->setRefPoint(playerPos);
    this->setColor(mainColor);
	initMembers(cannonAngle);
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
	ofPushMatrix();
	{ // Desplazamiento de la base del cañón, el nuevo 0, 0 es el centro
		ofTranslate(this->getRefPointX(), this->getRefPointY(), 0);
		ofSetColor(ofColor::lightYellow);
		ofDrawCircle(0, 0, 15);

		// Por defecto dibujamos hacia abajo. La orientación norte gira 180º
		if (this->facing == Orientation::NORTH) {
			ofRotateDeg(180);
		}

		ofPushMatrix();
		{ // Desplazamiento del cañón en sí
			ofTranslate(0, radius - 5, 0);
			ofRotateDeg(this->cannonAngle, 0, 0, 1);
			ofSetColor(this->altColor);
			ofFill();
			ofDrawRectangle(0 - (cannonWidth / 2), 0, cannonWidth, cannonLength);
		}
		ofPopMatrix();

		ofSetColor(this->getColor());
		this->cannonBase.draw();
	}
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
	int sign = (facing == Orientation::NORTH) ? -1 : 1;
	ofPoint bulletInitial = ofPoint(this->getRefPointX() + radius,
									this->getRefPointY() + (sign * (radius + cannonLength)), 0);
	
	float sx = sin(cannonAngle);
	float sy = cos(cannonAngle);

	sx = sign * sx;
	sy = sign * sy;

	Bullet *b = new Bullet(bulletInitial, sx, sy);
	b->setColor(ofColor::white);
	return b;
}
