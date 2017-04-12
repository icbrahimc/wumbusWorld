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

// Set the adjacency pairs for the particular agent in at a coordinate.
void State::setAdjacency() {
    // Store the coordinates in holder vars.
    int vert = location.first;
    int horz = location.second;
    
    std::pair<int, int> pairDir[4];
    pairDir[0] = std::pair<int, int>(vert, horz - 1);
    pairDir[1] = std::pair<int, int>(vert, horz + 1);
    pairDir[2] = std::pair<int, int>(vert - 1, horz);
    pairDir[3] = std::pair<int, int>(vert + 1, horz);
    
    //    std::pair<int, int> left = std::pair<int, int>(vert, horz - 1);
    //    std::pair<int, int> right = std::pair<int, int>(vert, horz + 1);
    //    std::pair<int, int> up = std::pair<int, int>(vert - 1, horz);
    //    std::pair<int, int> down = std::pair<int, int>(vert + 1, horz);
    
    for (int count = 0; count < 4; count++) {
        if (pairDir[count].first < 0 || 4 <= pairDir[count].first) {
            continue;
        } else if (pairDir[count].second < 0 || 4 <= pairDir[count].second) {
            continue;
        } else {
            // Next push.
            adjacency.push_back(std::pair<int, int>(pairDir[count]));
            //                adjacency.insert(std::pair<direction, std::pair<int, int>>(static_cast<direction>(count), pairDir[count]));
        }
    
    }
    
    //    std::cout << adjacency[up].first << ", " << adjacency[up].second << std::endl;
    //    std::cout << adjacency[right].first << ", " << adjacency[right].second << std::endl;
}

// Set the location of the state, then call set adajaceny to establish adjacent pieces.
void State::setBackground(int first, int last) {
    Symbol sym = Symbol(0, std::pair<int, int>(0,0));
    LogicSentence ls;
    location = std::pair<int, int>(first, last);
    this->setAdjacency();
    
    // Set the tautologies from the start.
    std::string breezeTautology = ls.returnPerceptTautology(0, location, adjacency);
    std::string stenchTautology = ls.returnPerceptTautology(3, location, adjacency);
    
    backgroundKnowledge.push_back(breezeTautology);
    backgroundKnowledge.push_back(stenchTautology);
    
    // Instantitate the wumpus and pit storage vectors.
//    for (int count = 0; count < adjacency.size(); count++) {
//        sym = Symbol(1, location);
//        holder = sym.returnStringValue();
//        possiblePits.push_back();
//    }
}

// Set the status based upon the percepts and instantiate the knowledge field based upon percepts.
void State::setStatus() {
    LogicSentence ls;
    this->setBreeze();
    this->setGlitter();
    this->setPit();
    this->setStench();
    this->setWumpus();
    Symbol sym = Symbol(0, std::pair<int, int>(0,0));
    std::string holder;
    
    if (this->isBreeze()) {
        sym = Symbol(0, location);
        holder = sym.returnStringValue();
        queryKnowledge.push_back(holder);
    }
    
    if (!this->isBreeze()) {
        sym = Symbol(0, location);
        holder = sym.returnStringValue();
        holder = ls.notFunc(holder);
        queryKnowledge.push_back(holder);
    }
    
    if (this->isGlitter()) {
        sym = Symbol(1, location);
        holder = sym.returnStringValue();
        queryKnowledge.push_back(holder);
    }
    
    if (!this->isGlitter()) {
        sym = Symbol(1, location);
        holder = sym.returnStringValue();
        holder = ls.notFunc(holder);
        queryKnowledge.push_back(holder);
    }
    
    if (this->isPit()) {
        sym = Symbol(2, location);
        holder = sym.returnStringValue();
        queryKnowledge.push_back(holder);
    }
    
    if (!this->isPit()) {
        sym = Symbol(2, location);
        holder = sym.returnStringValue();
        holder = ls.notFunc(holder);
        queryKnowledge.push_back(holder);
    }
    
    if (this->isStench()) {
        sym = Symbol(3, location);
        holder = sym.returnStringValue();
        queryKnowledge.push_back(holder);
    }
    
    if (!this->isStench()) {
        sym = Symbol(3, location);
        holder = sym.returnStringValue();
        holder = ls.notFunc(holder);
        queryKnowledge.push_back(holder);
    }
    
    if (this->isWumpus()) {
        sym = Symbol(4, location);
        holder = sym.returnStringValue();
        queryKnowledge.push_back(holder);
    }
    
    if (!this->isWumpus()) {
        sym = Symbol(4, location);
        holder = sym.returnStringValue();
        holder = ls.notFunc(sym.returnStringValue());
        queryKnowledge.push_back(holder);
    }
    
    this->setSafety();
}
