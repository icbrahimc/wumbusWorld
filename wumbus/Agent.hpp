//
//  Agent.hpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/3/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef Agent_hpp
#define Agent_hpp

#include <iostream>
#include <stdio.h>

enum direction { left = 0, right = 1, up = 2, down = 3 };

class Agent {
private:
    bool arrow;
    direction look;
    std::pair<int, int> location;
public:
    // Constructor.
    Agent() {
        arrow = true;
    };
    
    // Setters.
    void setDirection(direction input) { look = input; };
    void setLocation(int first, int last) { location = std::pair<int, int>(first, last); };
    
    // Getters.
    direction returnDirection() const { return look; };
    std::pair<int, int> returnLocation() const { return location; };
};
#endif /* Agent_hpp */
