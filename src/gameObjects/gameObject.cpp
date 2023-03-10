#include "gameObject.h"

        //Setup function
    //*****************************************************
    void GameObject::setup(){
        return;
    }

        //Draw function
    //*****************************************************
    void GameObject::draw(){
        printf("DRAW GameObject\n");
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
