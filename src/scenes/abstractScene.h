#pragma once
#include <string>
#include "ofMain.h"
#include "../gameObjects/gameObject.h"


using namespace std;

class AbstractScene {
	
	private: 
		list<GameObject*> gameObjectList;

	public:
		virtual void setupScene();
		virtual void drawScene();
		virtual void updateScene();


	public:


};
