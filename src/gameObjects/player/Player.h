#pragma once
#include "ofMain.h"
#include "../gameObject.h"
#include "../bullet/Bullet.h"

class Player: public GameObject {
        ofPath canyonBase;
		int rotationSpeed = 2;
		int radius = 50;
        int canyonLength = 50;
        int canyonWidth = 8;

        ofColor altColor;
        int canyonAngle;

	public:
        enum class Orientation {NORTH, SOUTH} facing;

        Player();
        Player(int x, int y, int canyonAngle, int r, int g, int b, Orientation initFacing = Orientation::NORTH);
		Player(ofPoint playerPos, int canyonAngle, ofColor, Orientation initFacing = Orientation::NORTH);

        void setRotationSpeed(int rs);
        int getRotationSpeed();
        void setRadius(int r);
        int getRadius();
        void setCanyonLength(int cl);
        int getCanyonLength();
        void setCanyonWidth(int cw);
        int getCanyonWidth();
        void setAltColor(ofColor ac);
        ofColor getAltColor();
        void setCanyonAngle(int ca);
        int getCanyonAngle();

		void draw();
		void update();
		void moveLeft();
		void moveRight();
        Bullet * shoot();
};
