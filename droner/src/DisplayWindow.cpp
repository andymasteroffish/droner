//
//  DisplayWindow.cpp
//  droner
//
//  Created by Andrew Wallace on 12/12/17.
//
//

#include "DisplayWindow.hpp"

void DisplayWindow::setup(){
    ofSetBackgroundAuto(false);
    ofClear(0);
}

void DisplayWindow::update(){

}

void DisplayWindow::draw(){
    
    int cols = 40;
    int rows = 40;
    
    float cellW = ofGetWidth()/(float)cols;
    float cellH = ofGetHeight()/(float)rows;
    
    for (int s=0; s<sounds->size(); s++){
        //update the sound
        sounds->at(s)->updateExternalDisplayInfo();
        
        //is this the firts time this sound has come up? if so, give it a ranodm pos
        if (sounds->at(s)->pixelPos == -1){
            sounds->at(s)->pixelPos = ofRandom(0, cols*rows);
        }
        
        for (int i=0; i<sounds->at(s)->numPixelSteps; i++){
            sounds->at(s)->pixelPos++;
            
            if (sounds->at(s)->pixelPos >= cols*rows){
                sounds->at(s)->pixelPos = 0;
            }
            
            int xPos = sounds->at(s)->pixelPos % cols;
            int yPos = floor(sounds->at(s)->pixelPos / cols);
            
            ofSetColor(sounds->at(s)->pixelCurColor);
            ofFill();
            ofDrawRectangle(xPos*cellW, yPos*cellH, cellW, cellH);
            
            //spillage
            float spillRangeX = cellW * 0.25;
            float spillRangeY = cellH * 0.25;
            int spillX = ofRandom(xPos*cellW-spillRangeX, xPos*cellW+cellW+spillRangeX);
            int spillY = ofRandom(yPos*cellH-spillRangeY, yPos*cellH+cellH+spillRangeY);
            int spillH = ofRandom(cellH*0.1,cellH*0.75);
            ofDrawRectangle(spillX, spillY-spillH/2, 1, spillH);
            
        }
    }
}
