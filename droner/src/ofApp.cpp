#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    sampleRate 	= 44100;
    bufferSize	= 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */
    
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    ofBackground(80);
    
    timelineLength = 9;
    
    shiftIsHeld = false;
    commandIsHeld = false;
    
    
    ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4); /* this has to happen at the end of setup - it switches on the DAC */
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    
    /* Stick your maximilian 'play()' code in here ! Declare your objects in testApp.h.
     For information on how maximilian works, take a look at the example code at
     http://www.maximilian.strangeloop.co.uk
     under 'Tutorials'.
     */
    
    for (int b = 0; b < bufferSize; b++){
        double sampleOut = 0;
        playbackPrc = timer.phasor(1.0/timelineLength);
        
        for (int i=0; i<sounds.size(); i++){
            sounds[i]->updateAudio(playbackPrc);
        }
        
        for (int i=0; i<sounds.size(); i++){
            sampleOut += sounds[i]->audioValue;
        }
        
        
        output[b*nChannels    ] = sampleOut;
        output[b*nChannels + 1] = sampleOut;
    }
    
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    for(int i = 0; i < bufferSize; i++){
        /* you can also grab the data out of the arrays*/
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    
    //other info
    ofSetColor(255);
    ofDrawBitmapString("period: "+ofToString(timelineLength)+" seconds", 20, 20);
    
    //samples
    for (int i=0; i<sounds.size(); i++){
        sounds[i]->draw(i, timelineLength);
    }
    
    ofDisableAlphaBlending();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout<<"key:"<<key<<endl;
    
    if (key == 2304){
        shiftIsHeld = true;
    }
    if (key == 4352){
        commandIsHeld = true;
    }
    
    if (key == '-'){
        timelineLength -= 0.2f;
    }
    if (key == '='){
        timelineLength += 0.2f;
    }
    
    //up arrow
    if (key == 357 && !commandIsHeld){
        scrollSelectedSound(-1);
    }
    //down arrow
    if (key == 359 && !commandIsHeld){
        scrollSelectedSound(1);
    }
    
    //check all sounds
    for (int i=sounds.size()-1; i>=0; i--){
        sounds[i]->keyPress(key, shiftIsHeld, commandIsHeld);
        if (sounds[i]->killMe){
            sounds[i]->cleanUp();
            delete sounds[i];
            sounds.erase(sounds.begin()+i);
        }
    }
    
    //testing
    if (key == 't'){
        sounds[1]->volumeModSound=sounds[0];
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 2304){
        shiftIsHeld = false;
    }
    if (key == 4352){
        commandIsHeld = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for (int i=sounds.size()-1; i>=0; i--){
        sounds[i]->mousePressed(x, y, button);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    if (dragInfo.files.size() > 0){
        for(int i = 0; i < dragInfo.files.size(); i++){
            ofFile file;
            file.open(dragInfo.files[i]);
            if (file.exists()){
                if (file.isFile()){
                    if (file.getExtension() == "wav"){
                        addSound(file.getAbsolutePath(), file.getFileName());
                    }
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::addSound(string filePath, string fileName){
    //deselect everything
    for (int i=0; i<sounds.size(); i++){
        sounds[i]->isSelected = false;
    }
    
    //make the new one
    Sound * sound = new Sound(filePath, fileName);
    sound->isSelected = true;
    
    //split it up to roughly fit
    int startingCycles = timelineLength/sound->sampleDuration;
    for (int i=1; i<startingCycles; i++){
        sound->addCycle();
    }
    
    sounds.push_back(sound);
}

//--------------------------------------------------------------
void ofApp::scrollSelectedSound(int dir){
    int curSelected = -1;
    for (int i=0; i<sounds.size(); i++){
        if (sounds[i]->isSelected){
            curSelected = i;
            sounds[i]->deselect();
        }
    }
    
    curSelected += dir;
    if (curSelected<0)              curSelected = sounds.size()-1;
    if (curSelected>=sounds.size()) curSelected = 0;
    sounds[curSelected]->isSelected = true;
    sounds[curSelected]->cycles[0].isSelected = true;
}
