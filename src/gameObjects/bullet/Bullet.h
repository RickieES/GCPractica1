#pragma once
#include "ofMain.h"
#include "../gameObject.h"

class Bullet: public GameObject {
    private:
        float speedX;
        float speedY;
        float floatPosX;
        float floatPosY;
    
    public:
        Bullet(ofPoint initialPos, float speedX, float speedY);

        void setSpeedX(float sx);
        float getSpeedX();
        void setSpeedY(float sy);
        float getSpeedY();
        void draw();
        void update();
        ofColor getMainColor();
};