//
//  State.hpp
//  wumpus
//
//  Created by Ibrahim Conteh on 4/3/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include "Constants.cpp"
#include <iostream>
#include <stdio.h>

class State {
private:
    bool percepts[5];
    bool safe;
//    bool breeze;
//    bool glitter;
//    bool pit;
//    bool stench;
//    bool wumpus;
    std::pair<int, int> location;
    
public:
    // Constructor.
    State() {
        percepts[B] = false;
        percepts[G] = false;
        percepts[P] = false;
        percepts[S] = false;
        percepts[W] = false;
        safe = true;
//        breeze = false;
//        glitter = false;
//        pit = false;
//        stench = false;
//        wumpus = false;
        location = std::pair<int, int>(0, 0);
    };
    
    // Change the status of the five states.
    void setBreeze(bool input) { percepts[B] = input; };
    void setGlitter(bool input) { percepts[G] = input; };
    void setPit(bool input) { percepts[P] = input; };
    void setStench(bool input) { percepts[S] = input; };
    void setWumpus(bool input) { percepts[W] = input; };
    void setLocation(int first, int second) { location = std::pair<int, int>(first, second); };
    void setSafety();
    
    // Return the status of the particular state.
    bool isBreeze() const { return this->percepts[B] == true; };
    bool isGlitter() const { return this->percepts[G] == true;};
    bool isPit() const { return this->percepts[P] == true; };
    bool isStench() const { return this->percepts[S] == true; };
    bool isWumpus() const { return this->percepts[W] == true; };
    bool isSafe() const { return this->safe == true; };
};
#endif /* State_hpp */
