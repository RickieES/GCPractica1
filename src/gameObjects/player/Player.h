#pragma once
#include "ofMain.h"

class Player {
	public:
		const int rotationSpeed = 2;
		const int radius = 80;
        const int canyonLength = 50;
        const int canyonWidth = 8;

        ofColor mainColor;
        ofColor altColor;
        ofPoint bodyPos;
        ofPoint canyonEdgePos;
        int canyonAngle;

        Player(int x, int y, int canyonAngle, int r, int g, int b);
		Player(ofPoint playerPos, int canyonAngle, ofColor = ofColor::blue);
		void draw();
		void update();
		void moveLeft();
		void moveRight();
};
