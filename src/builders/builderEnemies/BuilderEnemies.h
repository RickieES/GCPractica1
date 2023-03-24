#pragma once
#include "ofMain.h"
#include "../AbstractBuilder.h"
#include "../../gameObjects/gameObject.h"
#include "../../gameObjects/abstractEnemy/RectangleEnemy/rectangleEnemy.h"

class BuilderEnemies: public AbstractBuilder {
    
    public:
        virtual list<GameObject*> setupBuilder(list<GameObject*> actualGameObjects) override;




};