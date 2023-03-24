#pragma once
#include "ofMain.h"
#include "../gameObjects/gameObject.h"

class AbstractBuilder{
    
    public:
        virtual list<GameObject*> setupBuilder(list<GameObject*> actualGameObjects);
};