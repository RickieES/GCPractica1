#include "end_scene.h" 
 

        //SetupScene function
    //*****************************************************
    void End_scene::setupScene(){
		ofBackground(ofColor::black);

		this->gameOverFont.load("V5PRC.TTF", 200, true, true);
		this->gameOverFont.setLineHeight(70.0f);
		this->gameOverFont.setLetterSpacing(1.035);

		this->gameOverBgFont.load("V5PRC.TTF", 150, true, true);
		this->gameOverBgFont.setLineHeight(55.0f);
		this->gameOverBgFont.setLetterSpacing(1.035);
    }


        //DrawScene function
    //*****************************************************
    void End_scene::drawScene(){
        
		drawBackground();
    }


        //UpdateScene function
    //*****************************************************
    void End_scene::updateScene(){
        
    }


	void End_scene::drawBackground() {
		int stringWidth = gameOverBgFont.stringWidth(" GAME OVER ");
		int stringHeight = gameOverBgFont.stringHeight(" GAME OVER ");

		int counter = (int) (ofGetElapsedTimeMillis() / 5.0) % (ofGetWidth() + stringWidth + 100);

		ofPushMatrix();

		ofColor bgtest = bgSecondary;
		bgtest.setBrightness(bgSecondary.getBrightness() + 2);

		ofSetColor(bgtest);

		for (int j = 0; j < ((float)ofGetHeight()) / stringHeight + 1; j++) {
			for (int i = 0; i < ((float) ofGetWidth()) / stringWidth + 1; i++) {
				gameOverBgFont.drawString(" GAME OVER ", ((int)(counter * (1 + j/5.0)) + j * 50 + i * stringWidth) % (ofGetWidth() + stringWidth) - stringWidth, j * (stringHeight + 20));
			}
		}

		ofSetColor(ofColor::white);
		int stringWidthMain = gameOverFont.stringWidth("GAME OVER");
		int stringHeightMain = gameOverFont.stringHeight("GAME OVER");
		gameOverFont.drawString("GAME OVER", ofGetWidth() / 2 - stringWidthMain / 2, ofGetHeight() / 2 - stringHeightMain / 2);

		ofPopMatrix();

		return;
	}