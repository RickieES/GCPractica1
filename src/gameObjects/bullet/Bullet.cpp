#include "Bullet.h"
#include "ofMain.h"

Bullet::Bullet(ofPoint initialPos, float speedX, float speedY) {
    this->setRefPointX(initialPos.x);
    this->setRefPointY(initialPos.y);
    floatPosX = initialPos.x;
    floatPosY = initialPos.y;
    this->setSpeedX(speedX);
    this->setSpeedY(speedY);
}

void Bullet::setSpeedX(float sx) {
    this->speedX = sx;
}

float Bullet::getSpeedX() {
    return this->speedX;
};

void Bullet::setSpeedY(float sy) {
    this->speedY = sy;
}

float Bullet::getSpeedY() {
    return this->speedY;
};

void Bullet::update() {
    this->floatPosX += this->speedX;
    this->floatPosY += this->speedY;

    this->setRefPointX((int) this->floatPosX);
    this->setRefPointY((int) this->floatPosY);
}

// pmDraw Function
//*************************************************************
void Bullet::draw() {
	ofPushMatrix();
	ofTranslate(this->getRefPointX(), this->getRefPointY(), 0);

	ofSetColor(this->getColor());
	ofFill();
    // Please keep in mind that drawing circle with different outline color and fill
    // requires calling ofNoFill and ofSetColor for drawing stroke and ofFill and
    // again ofSetColor for filled solid color circle.
    ofDrawCircle(0, 0 , 10);
	ofPopMatrix();
}
