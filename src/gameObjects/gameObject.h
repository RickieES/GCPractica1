#pragma once
#include <string>
#include "ofMain.h"
using namespace std;

class GameObject {
	
	private: 
		string id;

	public:
		GameObject(){
			this->setId("pepe");
		}

		virtual void setup();
		virtual void draw();
		virtual void update();

		string getId();
		void setId(string value);
};
