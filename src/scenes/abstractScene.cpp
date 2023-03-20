#include "abstractScene.h"
 
        //Setup function
    //*****************************************************
    void AbstractScene::setupScene(){
        for (auto go: gameObjectList){
            go->setup();
        }
        return;
    }


        //Update function
    //*****************************************************
    void AbstractScene::updateScene(){
        for (auto go: gameObjectList){
            go->update();
        }
        return;
    }


        //Draw function
    //*****************************************************
    void AbstractScene::drawScene(){
        for (auto go: gameObjectList){
            go->draw();
        }
        return;
    }
