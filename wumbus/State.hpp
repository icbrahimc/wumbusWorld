
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
#include <vector>

class State {
private:
    std::vector<bool> percepts;
//    bool percepts[5];
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
        // Instantiate the five percepts in the particular state.
        for (int count = 0; count <  5; count++) {
            percepts.push_back(false);
        }
        safe = false;
        location = std::pair<int, int>(0, 0);
    };
    
    // Change the status of the five states.
    void setBreeze();
    void setGlitter();
    void setPit();
    void setStench();
    void setWumpus();
    void setLocation(int first, int second) { location = std::pair<int, int>(first, second); };
    void setSafety();
    
    // Return the status of the particular state.
    bool isBreeze() const { return this->percepts[0] == true; };
    bool isGlitter() const { return this->percepts[1] == true;};
    bool isPit() const { return this->percepts[2] == true; };
    bool isStench() const { return this->percepts[3] == true; };
    bool isWumpus() const { return this->percepts[4] == true; };
    bool isSafe() const { return this->safe == true; };
    
    std::vector<bool> returnPercepts() { return percepts; };
    
    
};
#endif /* State_hpp */
