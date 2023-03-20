#include "gameObject.h"

        //Setup function
    //*****************************************************
    void GameObject::setup(){
        return;
    }

        //Draw function
    //*****************************************************
    void GameObject::draw(){
        return;
    }

        //Update function
    //*****************************************************
    void GameObject::update(){
        return;
    }



    //*****************************************************
        // ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
    //*****************************************************
    string GameObject::getId(){
        return this->id;
    }
    void GameObject::setId(string value){
        this->id = value;
        return;
    }

    void GameObject::setRefPoint(ofPoint rp) {
        this->refPoint = rp;
    }

    void GameObject::setRefPointX(int x) {
        this->refPoint.x = x;
    }

    void GameObject::setRefPointY(int y) {
        this->refPoint.y = y;
    }

    ofPoint GameObject::getRefPoint() {
        return this->refPoint;
    }

    int GameObject::getRefPointX() {
        return this->refPoint.x;
    }

    int GameObject::getRefPointY() {
        return this->refPoint.y;
    }

    bool GameObject::collidesWith(GameObject ogo) {
        return ((this->refPoint.x == ogo.getRefPointX()) && (this->refPoint.y == ogo.getRefPointY()));
    }

    ofColor GameObject::getColor(){
        return this->color;
    }

    void GameObject::setColor(ofColor value){
        this->color = value;
        return;
    }
    void GameObject::setColor(int r, int g, int b){
        this->color = ofColor(r%256, g%256, b%256);
        return;
    }
