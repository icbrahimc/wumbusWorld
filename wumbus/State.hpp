//
//  State.hpp
//  wumpus
//
//  Created by Ibrahim Conteh on 4/3/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <iostream>
#include <stdio.h>

enum status { NO = -1, POSS = 0, YES = 1};

class State {
private:
    bool breeze;
    bool glitter;
    bool pit;
    bool stench;
    bool wumpus;
    std::pair<int, int> location;
    
public:
    // Constructor.
    State() {
        breeze = NO;
        glitter = NO;
        pit = NO;
        stench = NO;
        wumpus = NO;
        location = std::pair<int, int>(0, 0);
    };
    
    // Change the status of the five states.
    void setBreeze(bool input) { breeze = input; };
    void setGlitter(bool input) { glitter = input; };
    void setPit(bool input) { pit = input; };
    void setStench(bool input) { stench = input; };
    void setwumpus(bool input) { wumpus = input; };
    void setLocation(int first, int second) { location = std::pair<int, int>(first, second); };
    
    // Return the status of the particular state.
    bool isBreeze() const { return this->breeze == true; };
    bool isGlitter() const { return this->glitter == true;};
    bool isPit() const { return this->pit == true; };
    bool isStench() const { return this->stench == true; };
    bool iswumpus() const { return this->wumpus == true; };
};
#endif /* State_hpp */
