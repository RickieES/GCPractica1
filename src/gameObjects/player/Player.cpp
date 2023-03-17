#include "Player.h"
#include "ofMain.h"

// Constructor vacío
Player::Player() {
}

// Constructor con tipos simples
//*************************************************************
Player::Player(int xCenter, int yCenter, int canyonAngle, int r, int g, int b) {
	this->facing = Orientation::NORTH;
	this->rotationSpeed = 2;
	this->radius = 50;
    this->canyonLength = 50;
    this->canyonWidth = 8;
	this->bodyPos.x = xCenter;
	this->bodyPos.y = yCenter;
    this->canyonAngle = canyonAngle;
    this->mainColor = ofColor(r % 256, g % 256, b % 256);

	ofPoint point2(this->bodyPos.x, this->bodyPos.y);
	canyonBase.arc(point2, 100, 100, 0, 180, 100);
	cout << "Constructor Body pos x, y: " << bodyPos.x << " - " << bodyPos.y << "\n";
	cout << "Constructor Canyon width and length, radius: " << canyonWidth << " - " << canyonLength << " - " << radius << "\n";
}

// Constructor con tipos reales
//*************************************************************
Player::Player(ofPoint playerPos, int canyonAngle, ofColor mainColor) {
	this->bodyPos = playerPos;
    this->canyonAngle = canyonAngle;
    this->mainColor = mainColor;

	ofPoint point2(this->bodyPos.x, this->bodyPos.y);
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
 * Sets canyon length to a maximum of 150
*/
void Player::setCanyonLength(int cl) {
	cout << "set Canyon Length, cl: " << cl << "\n";
	this->canyonLength = max(50, min(150, cl));
	cout << "set Canyon width and length, radius: " << canyonWidth << " - " << canyonLength << " - " << radius << "\n";
}

int Player::getCanyonLength() {
	return this->canyonLength;
}

/**
 * Sets canyon width to a maximum of 300
*/
void Player::setCanyonWidth(int cw) {
	cout << "set Canyon Width, cw: " << cw << "\n";
	this->canyonWidth = max(8, min(300, cw));
	cout << "set Canyon width and length, radius: " << canyonWidth << " - " << canyonLength << " - " << radius << "\n";
}

int Player::getCanyonWidth() {
	return this->canyonWidth;
}

void Player::setMainColor(ofColor mc) {
	this->mainColor = mc;
}

ofColor Player::getMainColor() {
	return this->mainColor;
}

void Player::setAltColor(ofColor ac) {
	this->altColor = ac;
}

ofColor Player::getAltColor() {
	return this->altColor;
}

void Player::setBodyPos(ofPoint bp) {
	this->bodyPos = bp;
}

void Player::setBodyPosX(int x) {
	this->bodyPos.x = x;
}

void Player::setBodyPosY(int y) {
	this->bodyPos.y = y;
}

ofPoint Player::getBodyPos() {
	return this->bodyPos;
}

int Player::getBodyPosX() {
	return this->bodyPos.x;
}

int Player::getBodyPosY() {
	return this->bodyPos.y;
}

void Player::setCanyonEdgePos(ofPoint cep) {
	this->canyonEdgePos = cep;
}

void Player::setCanyonEdgePosX(int cepx) {
	this->canyonEdgePos.x = cepx;
}

void Player::setCanyonEdgePosY(int cepy) {
	this->canyonEdgePos.y = cepy;
}

ofPoint Player::getCanyonEdgePos() {
	return this->canyonEdgePos;
}

int Player::getCanyonEdgePosX() {
	return this->canyonEdgePos.x;
}

int Player::getCanyonEdgePosY() {
	return this->canyonEdgePos.y;
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
    // TODO: incluir en una matriz de transformación
    // TODO: hacer un degradado de color;
	ofPushMatrix();
	ofTranslate(this->bodyPos.x, this->bodyPos.y, 0);
	if (this->facing == Orientation::NORTH) {
	 	ofRotateDeg(180);
	}
	ofSetColor(this->mainColor);
	this->canyonBase.lineTo(0, 0);
	ofPoint point2(radius, 0);
	this->canyonBase.arc(point2, radius, radius, 0, 180);
	ofSetColor(mainColor);
	ofFill();
	this->canyonBase.draw();

    // TODO: incluir en una matriz de transformación
	// ofPushMatrix();
	// ofRotateDeg(this->canyonAngle, 0, 0, 1);
	ofSetColor(this->altColor);
	ofFill();
	ofDrawRectangle(radius - (canyonWidth / 2), radius - 5,
					canyonWidth, canyonLength);
	// ofPopMatrix();
	ofPopMatrix();
}


// pmUpdate Function
//*************************************************************
void Player::update(){

}


// MoveLeft Function
//*************************************************************
void Player::moveLeft(){
	if (this->facing == Orientation::NORTH) {
	    this->canyonAngle =  max(200, this->canyonAngle - radius);
	} else {
	    this->canyonAngle =  min(160, this->canyonAngle + radius);
	}
}


// MoveRight Function
//*************************************************************
void Player::moveRight(){
	if (this->facing == Orientation::NORTH) {
	    this->canyonAngle =  max(20, this->canyonAngle - radius);
	} else {
	    this->canyonAngle -=  min(340, this->canyonAngle + radius);
	}
};
