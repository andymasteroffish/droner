#include "ofMain.h"
#include "ofApp.h"

//========================================================================
/*
int main( ){
	ofSetupOpenGL(1024,1000,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
 */


int main( ){
    ofGLFWWindowSettings settings;
    
    settings.width = 1024;
    settings.height = 1000;
    settings.setPosition(ofVec2f(300,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.width = 300;
    settings.height = 300;
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> displayWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<DisplayWindow> displayApp(new DisplayWindow);
    mainApp->displayWindow = displayApp;
    
    ofRunApp(displayWindow, displayApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
    
}
