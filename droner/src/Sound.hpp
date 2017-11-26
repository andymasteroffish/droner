//
//  Sound.hpp
//  droner
//
//  Created by Andrew Wallace on 11/25/17.
//
//

#ifndef Sound_hpp
#define Sound_hpp

#include "ofMain.h"
#include "ofxMaxim.h"

#include "Cycle.hpp"

class Sound{
public:
    
    Sound(string filePath, string fileName);
    void loadSound(string filePath, string fileName);
    void updateAudio(float playbackPrc);
    
    void addCycle();
    void removeCycle();
    void combineCycles(int id);
    void breakCycle(int id);
    void updateCycles();
    
    
    void draw(int orderPos, float totalTimelineDuration);
    
    bool mousePressed(int x, int y, int button);
    
    void keyPress(int key);
    
    void cleanUp();
    
    
    maxiSample sample;
    float sampleDuration;
    
    bool killMe;
    
    //brekaing the sound into sycles
    vector<Cycle> cycles;
    int totalCycles;
    //int cyclesPerPeriod;
    int curCycle;
    float curSamplePrc;
    
    //#define MAX_NUM_CYCLES 100
    //bool skipCycle[MAX_NUM_CYCLES];
    
    //output values
    double baseAudioValue;
    double audioValue;
    
    bool isActive;
    
    //modifying shit
    bool isSelected;
    double masterVolume;
    
    //getting info form otehr sounds
    Sound * volumeModSound;
    
    //display
    string sampleFileName;
    
    ofColor normalColor, selectedColor;
    ofColor bgColorNorm, bgColorOff;
    ofColor cycleSelectedColor;
    
    ofRectangle clickBox;
    
    
    
};

#endif /* Sound_hpp */
