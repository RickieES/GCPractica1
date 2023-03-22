#include "Bullet.h"
#include "ofMain.h"


void Bullet::setSpeed(int s) {
    this->speed = s;
}

int Bullet::getSpeed() {
    return this->speed;
};

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
