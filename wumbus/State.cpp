//
//  State.cpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/3/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include "State.hpp"

// Prompt the user to set the percepts for the state.
void State::setBreeze() {
    bool choice;
    std::cout << "Breeze(True:1, False: 0)\n";
    std::cin >> choice;
    percepts[0] = choice;
};

void State::setGlitter() {
    bool choice;
    std::cout << "Glitter(True:1, False: 0)\n";
    std::cin >> choice;
    percepts[1] = choice;
};

void State::setPit() {
    if (this->isWumpus()) {
        std::cout << "A pit and a wumpus cannot exist in the same state!\n";
    } else {
        bool choice;
        std::cout << "Pit(True:1, False: 0)\n";
        std::cin >> choice;
        percepts[2] = choice;
    }
};

void State::setStench() {
    bool choice;
    std::cout << "Stench(True:1, False: 0)\n";
    std::cin >> choice;
    percepts[3] = choice;
};

void State::setWumpus() {
    if (this->isPit()) {
        std::cout << "A pit and a wumpus cannot exist in the same state!\n";
    } else {
        bool choice;
        std::cout << "Wumpus(True:1, False: 0)\n";
        std::cin >> choice;
        percepts[4] = choice;
    }
};

// Set the safety of the state.
void State::setSafety() {
    int count = 0;
    for ( ; count < 5; count++) {
        if (percepts[count] == true) {
            break;
        }
    }
    
    if (count == 5) {
        safe = true;
    }
}
