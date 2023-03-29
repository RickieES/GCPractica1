#pragma once
#include "ofMain.h"
#include "../AbstractBuilder.h"
#include "../../gameObjects/gameObject.h"
#include "../../gameObjects/abstractEnemy/RectangleEnemy/rectangleEnemy.h"

class BuilderEnemies: public AbstractBuilder {
    
    public:
        virtual GameObject setupBuilder() override;

		enum class enemyType {
			square,         // Enemigo cuadrado
			triangle,       // Enemigo triangulo
			circle,         // Enemigo circulo
		};
        
		enum class colourType {
			color1,         // Color correspondiento con el player 1
			color2,         // Color correspondiento con el player 1
		};

};