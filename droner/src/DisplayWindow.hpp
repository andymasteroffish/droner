//
//  DisplayWindow.hpp
//  droner
//
//  Created by Andrew Wallace on 12/12/17.
//
//

#ifndef DisplayWindow_hpp
#define DisplayWindow_hpp

#include "ofMain.h"
#include "Sound.hpp"

class DisplayWindow: public ofBaseApp{
public:
    
    void setup();
    
    void update();
    
    void draw();
    
    vector<Sound *> *sounds;
};

#endif /* DisplayWindow_hpp */
