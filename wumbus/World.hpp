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
    
    // Print the world.
    void printWorld() {
        std::cout << std::endl;
        std::cout << "  ";
        for (int count = 0; count < 4; count++) {
            std::cout << count << " ";
        }
        std::cout << std::endl;
        
        for (int i = 0; i < 4; i++) {
            std::cout << i << " ";
            for (int j = 0; j < 4; j++) {
                std::cout << "-" << " ";
            }
            std::cout << std::endl;
        }
    };
    
    State returnState(std::pair<int, int> coord) { return board[coord.first][coord.second]; };
};

#endif /* World_hpp */
