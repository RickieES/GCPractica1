#include "rectangleEnemy.h"

// Setup function
//*****************************************************
void RectangleEnemy::setup()
{
    this->setPosX(this->getPosX() - this->getSpeed());
    if (this->getPosX() + this->getWidth() <= this->getLimitLeft())
    {
        // TODO lanzar excepción llegada al final
    }

    return;
}

// Draw function
//*****************************************************
void RectangleEnemy::draw()
{

    ofSetColor(this->getMainColor());
    ofFill();

    ofPushMatrix();
    ofTranslate(this->getPosX(), this->getPosY());
    ofDrawRectangle(0, 0, this->getWidth(), this->getHeight());
    ofPopMatrix();

    return;
}

// Update function
//*****************************************************
void RectangleEnemy::update()
{
    AbstractEnemy::update();
    return;
}

vector<ofRectangle> RectangleEnemy::getEnclosingRectangleList() {
    vector<ofRectangle> l;
    ofRectangle box = ofRectangle(this->getRefPointX(), this->getRefPointY(),
                                  this->getWidth(), this->getHeight());
    l.insert(l.begin(), box);
    return l;
}



//*****************************************************
// ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
//*****************************************************
float RectangleEnemy::getWidth()
{
    return this->width;
}

void RectangleEnemy::setWidth(float value)
{
    this->width = value;
    return;
}

float RectangleEnemy::getHeight()
{
    return this->heigth;
}

void RectangleEnemy::setHeight(float value)
{
    this->heigth = value;
    return;
}