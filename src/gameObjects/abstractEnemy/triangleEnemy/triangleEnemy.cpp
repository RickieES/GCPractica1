#include "triangleEnemy.h" 


        //Setup function
    //*****************************************************
    void TriangleEnemy::setup() {
        this->setPosX(this->getPosX()-this->getSpeed());
        if(this->getPosX() + this->getLongSide() <= this->getLimitLeft()){
            //TODO lanzar excepción llegada al final
        }

        return;
    }


        //Draw function
    //*****************************************************
    void TriangleEnemy::draw(){
        printf("HOLA RectangleEnemy Draw\n");
 
        ofSetColor(255, 0, 0);
        ofNoFill();
        
        ofPushMatrix();
            ofTranslate(this->getPosX(), this->getPosY());
            //TODO Pintar triangulo
        ofPopMatrix();
        

        return;
    }


        //Update function
    //*****************************************************
    void TriangleEnemy::update(){
        return;
    }



    //*****************************************************
        // ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
    //*****************************************************
    long TriangleEnemy::getLongSide(){
        return this->longSide;
    }
    void TriangleEnemy::setLongSide(long value){
        this->longSide = value;
        return;
    }
