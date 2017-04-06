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

// Store the percepts as a vector.
// b = breeze, g = glitter, p = pit, s = stench, w = wumpus.
enum percept { b = 0, g = 1, p = 2, s = 3, w = 4};

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
        percepts[b] = false;
        percepts[g] = false;
        percepts[p] = false;
        percepts[s] = false;
        percepts[w] = false;
        safe = true;
//        breeze = false;
//        glitter = false;
//        pit = false;
//        stench = false;
//        wumpus = false;
        location = std::pair<int, int>(0, 0);
    };
    
    // Change the status of the five states.
    void setBreeze(bool input) { percepts[b] = input; };
    void setGlitter(bool input) { percepts[g] = input; };
    void setPit(bool input) { percepts[p] = input; };
    void setStench(bool input) { percepts[s] = input; };
    void setWumpus(bool input) { percepts[w] = input; };
    void setLocation(int first, int second) { location = std::pair<int, int>(first, second); };
    void setSafety();
    
    // Return the status of the particular state.
    bool isBreeze() const { return this->percepts[b] == true; };
    bool isGlitter() const { return this->percepts[g] == true;};
    bool isPit() const { return this->percepts[p] == true; };
    bool isStench() const { return this->percepts[s] == true; };
    bool isWumpus() const { return this->percepts[w] == true; };
    bool isSafe() const { return this->safe == true; };
};
#endif /* State_hpp */
