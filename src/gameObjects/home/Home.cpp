#include "Home.h"


void Home::draw() {
	float shift = abs(sin(ofGetElapsedTimeMillis() / 200.0));
	auto hue = baseColor.getHue()*shift + altColor.getHue()*(1 - shift);
	//auto sat = baseColor.getSaturation()*shift + altColor.getSaturation()*(1 - shift);
	ofColor drawColor = baseColor;

	drawColor.setHue(hue);

	ofSetColor(drawColor);
	ofDrawRectangle(0, 0, homeWidth, ofGetHeight());
}

vector<ofRectangle> Home::getEnclosingRectangleList() {
	vector<ofRectangle> vRect;

	ofRectangle homeHurtbox = ofRectangle(0, 0, homeWidth, ofGetHeight());
	vRect.push_back(homeHurtbox);

	return vRect;
}