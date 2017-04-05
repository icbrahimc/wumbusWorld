//
//  World.hpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/3/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef World_hpp
#define World_hpp

#include "Agent.hpp"
#include "State.hpp"
#include <map>
#include <stdio.h>
#include <vector>

std::map<std::pair<int, int>, std::map<direction, std::pair<int, int>>> adjMap;

class World {
private:
    State board[4][4];
public:
    // Constructor.
    World() {
        // Generate the world based upon certain criteria.
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                board[i][j].setLocation(i, j);
            }
        }
    };
};

#endif /* World_hpp */
