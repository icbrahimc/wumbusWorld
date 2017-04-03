//
//  State.hpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/3/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>

enum status { NO = -1, POSS = 0, YES = 1};

class State {
private:
    status breeze;
    status glitter;
    status pit;
    status stench;
    status wumbus;
public:
    // Constructor.
    State();
    
    // Change the status of the five states.
    void setBreeze(status input) { breeze = input; };
    void setGlitter(status input) { glitter = input; };
    void setPit(status input) { pit = input; };
    void setStench(status input) { stench = input; };
    void setWumbus(status input) { wumbus = input; };
    
    // Return the status of the particular state.
    bool isBreeze() const { return this->breeze == YES; };
    bool isGlitter() const { return this->glitter == YES;};
    bool isPit() const { return this->pit == YES; };
    bool isStench() const { return this->stench == YES; };
    bool isWumbus() const { return this->wumbus == YES; };
};
#endif /* State_hpp */
