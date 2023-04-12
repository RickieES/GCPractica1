#pragma once
#include "ofMain.h"
#include "gameObject.h"

class Home : public GameObject
{
	private:
		const ofColor baseColor{ ofColor::orangeRed };
		const ofColor altColor{ ofColor::red };

		const double homeWidth{ ofGetWidth()*0.1 };

		int health;

	public:
		Home() : GameObject() {
			this->setHealth(100);
		};

		virtual void draw() override;
		
		/*
		virtual void update() override;
		*/

		virtual vector<ofRectangle> getEnclosingRectangleList() override;

		void setHealth(int hp);
		int getHealth();

		void takeDamage(int dmg);

};

