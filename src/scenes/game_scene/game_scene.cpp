#include "game_scene.h" 
 

        //SetupScene function
    //*****************************************************
    void Game_scene::setupScene(){

        RectangleEnemy *enemy = new RectangleEnemy(100, 1500, 0, ofGetWidth(), 1, 200, 100);
        gameObjectList.push_back( enemy );
    
        for (auto go: gameObjectList){
            go->setup();
        }
        return;
    }




        //UpdateScene function
    //*****************************************************
    void Game_scene::updateScene(){
     


    }


        //DrawScene function
    //*****************************************************
    void Game_scene::drawScene(){
    
        ofSetBackgroundColor(118);
        ofSetColor(123, 123, 123);
        for (auto go: gameObjectList){
            go->draw();
        }

        return;
    }