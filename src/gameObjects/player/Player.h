#pragma once
#include "ofMain.h"

class Player {
        ofPolyline canyonBase;
		int rotationSpeed = 2;
		int radius = 50;
        int canyonLength = 50;
        int canyonWidth = 8;

        ofColor mainColor;
        ofColor altColor;
        ofPoint bodyPos;
        ofPoint canyonEdgePos;
        int canyonAngle;

	public:
        Player();
        Player(int x, int y, int canyonAngle, int r, int g, int b);
		Player(ofPoint playerPos, int canyonAngle, ofColor = ofColor::blue);

        void setRotationSpeed(int rs);
        int getRotationSpeed();
        void setRadius(int r);
        int getRadius();
        void setCanyonLength(int cl);
        int getCanyonLength();
        void setCanyonWidth(int cw);
        int getCanyonWidth();
        void setMainColor(ofColor mc);
        ofColor getMainColor();
        void setAltColor(ofColor ac);
        ofColor getAltColor();
        void setBodyPos(ofPoint bp);
        void setBodyPosX(int x);
        void setBodyPosY(int y);
        ofPoint getBodyPos();
        int getBodyPosX();
        int getBodyPosY();
        void setCanyonEdgePos(ofPoint cep);
        void setCanyonEdgePosX(int x);
        void setCanyonEdgePosY(int y);
        ofPoint getCanyonEdgePos();
        int getCanyonEdgePosX();
        int getCanyonEdgePosY();
        void setCanyonAngle(int ca);
        int getCanyonAngle();

		void draw();
		void update();
		void moveLeft();
		void moveRight();

        enum class Orientation {NORTH, SOUTH} facing;
};
