#pragma once

#include "ofMain.h"

#include "ofxMaxim.h"

#include "Sound.hpp"
#include "DisplayWIndow.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void audioIn(float * input, int bufferSize, int nChannels);
    void audioOut(float * output, int bufferSize, int nChannels);
    
    void addSound(string filePath, string fileName);
    
    void scrollSelectedSound(int dir);
    
    //alternate window
    shared_ptr<DisplayWindow> displayWindow;
    
    //sound strreams
    ofSoundStream soundStreamOut, soundStreamIn;
    
    //maxim stuff
    int		bufferSize;
    int		sampleRate;
    
    maxiOsc timer;
    
    
    //marking playback
    float timelineLength;
    double playbackPrc;
    
    double basePlaybackPrc;
    double playbackPrcOffset;   //only being used to adjust the syn with the korg
    
    //samples
    vector<Sound *> sounds;
    
    //input
    bool shiftIsHeld, commandIsHeld;
    
    //testing controlling the timeline via korg syn out
    bool useKorgSync;
    int korgHitsPerTimeline;
    bool canHit;
    int hitCount;
    float lastHitTime;
    vector<float> timesBetweenHits;
    
    
};
