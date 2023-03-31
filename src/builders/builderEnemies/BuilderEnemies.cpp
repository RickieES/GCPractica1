#include "BuilderEnemies.h"


	// FIXME: constructor por defecto comentado porque no devuelve objeto
    //setupBuilder function 1
    //*****************************************************
    // GameObject BuilderEnemies::build() {
    // 
    // }


        //setupBuilder function 2
    //*****************************************************
    GameObject BuilderEnemies::build(ColorType colorType, EnemyType enemyType, SizeType sizeType, SpeedType speedType) {
        
        GameObject *result;
        
        switch (enemyType){
            case EnemyType::square:
                // FIXME: el builder siempre debe devolver un objeto,
                // por lo que hasta que se complete comento el break
                // break;
            default:
                result = new RectangleEnemy(this->getLimitUp(), this->getLimitDown(), this->getLimitLeft(), this->getLimitRight(),
                                            this->selectColor(colorType), this->selectSpeed(speedType), this->selectSquareSize_width(sizeType), this->selectSquareSize_height(sizeType));
                break;
        }

        return *result;
    }


        //Function selectColor
    //*****************************************************  
    ofColor BuilderEnemies::selectColor(ColorType colourType){
        ofColor result=0;
        switch (colourType){
            case ColorType::color1:
                result = this->color1;
                break;
            case ColorType::color2:
                result = this->color2;
                break;
            default:
                result = this->color1;
                break;
        }
        return result;
    }


        //Function getSquareSize_width
    //*****************************************************  
    int BuilderEnemies::selectSquareSize_width(SizeType sizeType){
        int result=0;
        switch (sizeType){
            case SizeType::small:
                result = this->squareSize_small_width;
                break;
            case SizeType::medium:
                result = this->squareSize_medium_width;
                break;
            case SizeType::large:
                result = this->squareSize_large_width;
                break;
            default:
                result = this->squareSize_medium_width;
                break;
        }
        return result;
    }


        //Function getSquareSize_height
    //*****************************************************  
    int BuilderEnemies::selectSquareSize_height(SizeType sizeType){
        int result=0;
        switch (sizeType){
            case SizeType::small:
                result = this->squareSize_small_height;
                break;
            case SizeType::medium:
                result = this->squareSize_medium_height;
                break;
            case SizeType::large:
                result = this->squareSize_large_height;
                break;
            default:
                result = this->squareSize_medium_height;
                break;
        }
        return result;
    }


        //Function selectSpeed
    //*****************************************************    
    int BuilderEnemies::selectSpeed(SpeedType speedType){     
        int result=0;
        switch (speedType){
            case SpeedType::low:
                result = this->speed_low;
                break;
            case SpeedType::normal:
                result = this->speed_normal;
                break;
            case SpeedType::fast:
                result = this->speed_fast;
                break;
            default:
                result = this->speed_normal;
                break;
        }
        return result;
    }



    //*****************************************************
        // ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
    //*****************************************************
    ofColor BuilderEnemies::getColor1(){
        return this->color1;
    }
    void BuilderEnemies::setColor1(ofColor value){
        this->color2 = value;
    }

    ofColor BuilderEnemies::getColor2(){
        return this->color2;
    }
    void BuilderEnemies::setColor2(ofColor value){
        this->color2 = value;
    }



	int BuilderEnemies::getLimitUp(){
        return this->limitUp;
    }
	void BuilderEnemies::setLimitUp(int value){
        this->limitUp = value;
        return;
    }

	int BuilderEnemies::getLimitDown(){
        return this->limitDown;
    }
	void BuilderEnemies::setLimitDown(int value){
        this->limitDown = value;
        return;
    }

	int BuilderEnemies::getLimitLeft(){
        return this->limitLeft;
    }
	void BuilderEnemies::setLimitLeft(int value){
        this->limitLeft = value;
        return;
    }

	int BuilderEnemies::getLimitRight(){
        return this->limitRight;
    }
	void BuilderEnemies::setLimitRight(int value){
        this->limitRight = value;
        return;
    }