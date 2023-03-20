#pragma once
#include <string>
#include "ofMain.h"
using namespace std;

class GameObject {
	
	private: 
		string id;
		ofPoint refPoint;
		ofColor color;

	public:
		GameObject(){
			this->setId("pepe");
		}

		virtual void setup();
		virtual void draw();
		virtual void update();

		string getId();
		void setId(string value);

        ofPoint getRefPoint();
        void setRefPoint(ofPoint rp);
        int getRefPointX();
        void setRefPointX(int x);
        int getRefPointY();
        void setRefPointY(int y);

		ofColor getColor();
		void setColor(ofColor value);
		void setColor(int r, int g, int b);

		virtual bool collidesWith(GameObject ogo);

		
};
