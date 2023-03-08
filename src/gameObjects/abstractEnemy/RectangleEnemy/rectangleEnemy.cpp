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
    long RectangleEnemy::getWidth(){
        return this->width;
    }
    void RectangleEnemy::setWidth(long value){
        this->width = value;
        return;
    }

    long RectangleEnemy::getHeight(){
        return this->heigth;
    }
    void RectangleEnemy::setHeight(long value){
        this->heigth = value;
        return;
    }