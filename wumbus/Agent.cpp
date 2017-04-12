//
//  Agent.cpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/3/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include "Agent.hpp"



// Set the adjacency pairs for the particular agent in at a coordinate.
void Agent::setAdjacency() {
    // Store the coordinates in holder vars.
    int vert = location.first;
    int horz = location.second;
    
    std::pair<int, int> pairDir[4];
    pairDir[left] = std::pair<int, int>(vert, horz - 1);
    pairDir[right] = std::pair<int, int>(vert, horz + 1);
    pairDir[up] = std::pair<int, int>(vert - 1, horz);
    pairDir[down] = std::pair<int, int>(vert + 1, horz);
    
//    std::pair<int, int> left = std::pair<int, int>(vert, horz - 1);
//    std::pair<int, int> right = std::pair<int, int>(vert, horz + 1);
//    std::pair<int, int> up = std::pair<int, int>(vert - 1, horz);
//    std::pair<int, int> down = std::pair<int, int>(vert + 1, horz);
    
    for (int count = 0; count < 4; count++) {
        if (visited[pairDir[count]] == true) {
            continue;
        } else {
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
    }
    
//    std::cout << adjacency[up].first << ", " << adjacency[up].second << std::endl;
//    std::cout << adjacency[right].first << ", " << adjacency[right].second << std::endl;
}

// Don't necessarily need this.
// Turn the agent.
void Agent::turnAgent() {
    switch (look) {
        case left:
            std::cout << "The agent is turning and is now facing the UP direction.\n";
            look = up;
            break;
            
        case up:
            std::cout << "The agent is turning and is now facing the RIGHT direction.\n";
            look = right;
            break;
            
        case right:
            std::cout << "The agent is turning and is now facing the DOWN direction.\n";
            look = down;
            break;
            
        case down:
            std::cout << "The agent is turning and is now facing the LEFT direction.\n";
            look = left;
            break;
            
        default:
            break;
    }
}

// Make a move to the next tile.
void Agent::makeAMove(std::pair<int, int> newTile) {
    std::pair<int, int> move;
//    bool match = false;
//    do {
//        
//        if (adjacency[look].first == newTile.first && adjacency[look].second == newTile.second) {
//            std::cout << "The agent has now moved to " << newTile.first << ", " << newTile.second << std::endl;
//            match = true;
//        } else {
//            this->turnAgent();
//        }
//        
//    } while (!match);
}

// Set the location as visited in the database.
void Agent::setVisited() {
    visited.insert(std::pair<std::pair<int, int>, bool>(location, true));
}


