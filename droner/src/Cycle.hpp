//
//  Cycle.hpp
//  droner
//
//  Created by Andrew Wallace on 11/26/17.
//
//

#ifndef Cycle_hpp
#define Cycle_hpp

#include "ofMain.h"
#include "ofxMaxim.h"

class Cycle{
public:
    
    void setup();
    
    
    int duration;
    float startPrc, endPrc;
    
    bool muteCycle;
    bool isSelected;
    
    
    
};

#endif /* Cycle_hpp */
