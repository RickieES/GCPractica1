#include "rectangleEnemy.h" 


        //Setup function
    //*****************************************************
    void RectangleEnemy::setup() {
        this->setPosX(this->getPosX()-this->getSpeed());
        if(this->getPosX() + this->getWidth() <= this->getLimitLeft()){
            //TODO lanzar excepción llegada al final
        }

        return;
    }


        //Draw function
    //*****************************************************
    void RectangleEnemy::draw(){
        printf("HOLA RectangleEnemy Draw\n");
 
        ofSetColor(255, 0, 0);
        ofNoFill();
        
        ofPushMatrix();
            ofTranslate(this->getPosX(), this->getPosY());
            ofDrawRectangle(this->getPosX(), this->getPosY(), this->getWidth(), this->getHeight());
        ofPopMatrix();
        

        return;
    }


        //Update function
    //*****************************************************
    void RectangleEnemy::update(){
        return;
    }



    //*****************************************************
        // ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
    //*****************************************************
    float RectangleEnemy::getWidth(){
        return this->width;
    }
    void RectangleEnemy::setWidth(float value){
        this->width = value;
        return;
    }

    float RectangleEnemy::getHeight(){
        return this->heigth;
    }
    void RectangleEnemy::setHeight(float value){
        this->heigth = value;
        return;
    }