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
        percepts[0] = false;
        percepts[1] = false;
        percepts[2] = false;
        percepts[3] = false;
        percepts[4] = false;
        safe = false;
//        breeze = false;
//        glitter = false;
//        pit = false;
//        stench = false;
//        wumpus = false;
        location = std::pair<int, int>(0, 0);
    };
    
    // Change the status of the five states.
    void setBreeze(bool input) { percepts[0] = input; };
    void setGlitter(bool input) { percepts[1] = input; };
    void setPit(bool input) { percepts[2] = input; };
    void setStench(bool input) { percepts[3] = input; };
    void setWumpus(bool input) { percepts[4] = input; };
    void setLocation(int first, int second) { location = std::pair<int, int>(first, second); };
    void setSafety();
    
    // Return the status of the particular state.
    bool isBreeze() const { return this->percepts[0] == true; };
    bool isGlitter() const { return this->percepts[1] == true;};
    bool isPit() const { return this->percepts[2] == true; };
    bool isStench() const { return this->percepts[3] == true; };
    bool isWumpus() const { return this->percepts[4] == true; };
    bool isSafe() const { return this->safe == true; };
};
#endif /* State_hpp */
