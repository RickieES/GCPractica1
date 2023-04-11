#include "triangleEnemy.h"

// Setup function
//*****************************************************
void TriangleEnemy::setup(){}

// Draw function
//*****************************************************
void TriangleEnemy::draw()
{
    printf("HOLAAAAA\n");
    ofSetColor(this->getMainColor());
    ofFill();

    ofPushMatrix();
        ofTranslate(this->getPosX(), this->getPosY());
        ofDrawTriangle(this->getPosX(), this->getPosY(), 
                        this->getPosX()+this->heigth, this->getPosY()-this->heigth, 
                        this->getPosX()+this->heigth, this->getPosY()+this->heigth);
    ofPopMatrix();

    return;
}

// Update function
//*****************************************************
void TriangleEnemy::update()
{
    AbstractEnemy::update();
    return;
}

vector<ofRectangle> TriangleEnemy::getEnclosingRectangleList() {
    vector<ofRectangle> l;
    ofRectangle box = ofRectangle(this->getRefPointX(), this->getRefPointY(),
                                  this->getLongSide(), this->getLongSide());
    l.insert(l.begin(), box);
    return l;
}


//*****************************************************
// ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
//*****************************************************
long TriangleEnemy::getLongSide()
{
    return this->heigth;
}

void TriangleEnemy::setLongSide(long value)
{
    this->heigth = value;
    return;
}
