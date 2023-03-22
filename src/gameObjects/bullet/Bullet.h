#pragma once
#include "ofMain.h"
#include "../gameObject.h"

class Bullet: public GameObject {
    private:
        int speed;
    
    public:
        void setSpeed(int s);
        int getSpeed();
        void draw();
};