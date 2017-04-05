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
#include <map>
#include <stdio.h>
#include <vector>

enum direction { left = 0, right = 1, up = 2, down = 3 };

// Agent class.
//  - Represents the agent passing through the board.
//  - Contains the arrow bool which represents whether the agent has an arrow or not.
//  - Contains a map that has all the adjacent tiles.
//  - Contains the coordinates to the users locations.

class Agent {
private:
    bool arrow;
    direction look;
    std::map<direction, std::pair<int, int>> adjacency;
    std::pair<int, int> location;
public:
    // Constructor.
    Agent() {
        arrow = true;
        look = right;
        location = std::pair<int, int>(3, 0);
    };
    
    // Setters.
    void setDirection(direction input) { look = input; };
    void setLocation(int first, int last) { location = std::pair<int, int>(first, last); };
    void setAdjacency();
    
    // Getters.
    direction returnDirection() const { return look; };
    std::pair<int, int> returnLocation() const { return location; };
};
#endif /* Agent_hpp */
