#include "Player.h"
#include "ofMain.h"

// Constructor vacío
Player::Player() {
}

// Constructor con tipos simples
//*************************************************************
Player::Player(int xCenter, int yCenter, int canyonAngle, int r, int g, int b) {
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
	this->canyonLength = max(150, cl);
}

int Player::getCanyonLength() {
	return this->canyonLength;
}

/**
 * Sets canyon width to a maximum of 300
*/
void Player::setCanyonWidth(int cw) {
	this->canyonWidth = max(300, cw);
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
	// ofPushMatrix();
	// ofTranslate(this->bodyPos.x, this->bodyPos.y, 0);
	ofSetColor(this->mainColor);
    // TODO: hacer un degradado de color;
	ofFill();
	// this->canyonBase.draw();
    // ofDrawCircle(bodyPos, radius);
    // TODO: incluir en una matriz de transformación
	// ofPushMatrix();
	// ofRotateDeg(this->canyonAngle, 0, 0, 1);
	// ofPopMatrix();
	// ofPopMatrix();
	this->canyonBase.lineTo(bodyPos.x, bodyPos.y);
	ofPoint point2(bodyPos.x + radius, bodyPos.y);
	this->canyonBase.arc(point2, radius, radius, 0, 180);
	ofSetColor(mainColor);
	ofFill();
	this->canyonBase.draw();
	ofSetColor(this->altColor);
	ofFill();
	ofDrawRectangle(bodyPos.x + radius - (canyonWidth / 2), bodyPos.y + radius - 5,
					canyonWidth, canyonLength);
	cout << "Body pos x, y: " << bodyPos.x << " - " << bodyPos.y << "\n";
	cout << "Canyon width and length, radius: " << canyonWidth << " - " << canyonLength << " - " << radius << "\n";
	return;
}


// pmUpdate Function
//*************************************************************
void Player::update(){
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
