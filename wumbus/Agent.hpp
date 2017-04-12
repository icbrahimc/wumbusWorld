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
#include "Symbol.hpp"
#include "KnowledgeBase.hpp"
#include <vector>

enum direction { left = 0, right = 1, up = 2, down = 3 };

// Agent class.
//  - Represents the agent passing through the board.
//  - Contains the arrow bool which represents whether the agent has an arrow or not.
//  - Contains a map that has all the adjacent tiles.
//  - Contains the coordinates to the users locations.
//  - Contains the coordinates to visited locations.
//  - Contains the hash map for established symbols from the game.

class Agent: public KnowledgeBase {
private:
    bool arrow;
//  delete direction eventually. Probably don't need it.
    direction look;
    std::vector<std::pair<int, int>> adjacency;
//    std::map<direction, std::pair<int, int>> adjacency;
    std::pair<int, int> location;
    std::vector<bool> agentPercepts;
    std::vector<std::string> kb;
    std::map<std::string, bool> subsitutions;
//    bool agentPercepts[5];
    std::map<std::pair<int, int>, bool> visited;
    
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
    void setVisited();
    
    // Knowledge based methods.
    void tellBreezeSentence();
    
    // Getters.
    direction returnDirection() const { return look; };
    std::pair<int, int> returnLocation() const { return location; };
    
    // Agent based moves.
    void turnAgent();
    void makeAMove(std::pair<int, int> newTile);
    
};
#endif /* Agent_hpp */
