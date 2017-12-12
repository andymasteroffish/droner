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
    void updateAudio(float originalPlaybackPrc);
    
    void draw(int orderPos, float totalTimelineDuration);
    void updateExternalDisplayInfo();
    
    void addCycle();
    void removeCycle();
    void combineCycles(int id);
    void breakCycle(int id);
    void updateCycles();
    
    void scrollSelectedCycle(int dir);
    
    
    bool mousePressed(int x, int y, int button);
    
    void keyPress(int key, bool shiftIsHeld, bool commandIsHeld);
    
    void deselect();
    void invertAllMute();
    void muteAllExcept(int cycleToLeaveOn);
    
    void shiftStartPoint(int dir);
    
    void cleanUp();
    
    
    maxiSample sample;
    float sampleDuration;
    
    bool killMe;
    
    //brekaing the sound into sycles
    vector<Cycle> cycles;
    int totalCycles;
    
    int curCycle;
    float curSamplePrc;
    
    float startPrcShift;
    
    
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
    
    
    //fft shit
    ofxMaxiFFT fft;
    ofxMaxiFFTOctaveAnalyzer oct;
    
    
    //external display
    int pixelPos;
    int numPixelSteps;
    double ampToMovePixel;
    double ampLeftToMovePixelPos;
    ofColor pixelCurColor;
    float pixelS, pixelB;
    int biggestFFTLastFrame;
    int framesWithTheSameFFT;   //sometimes the FFT needs to be reset
    
    
};

#endif /* Sound_hpp */
