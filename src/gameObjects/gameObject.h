#pragma once
#include <string>
#include "ofMain.h"
using namespace std;

class GameObject {
	
	private: 
		string id;
		ofPoint refPoint;

	public:
		GameObject(){
			this->setId("pepe");
		}

		virtual void setup();
		virtual void draw();
		virtual void update();

		string getId();
		void setId(string value);
        void setRefPoint(ofPoint rp);
        void setRefPointX(int x);
        void setRefPointY(int y);
        ofPoint getRefPoint();
        int getRefPointX();
        int getRefPointY();

		virtual bool collidesWith(GameObject ogo);
};
