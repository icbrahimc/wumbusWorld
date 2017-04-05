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
        if (pairDir[count].first < 0 || 4 <= pairDir[count].first) {
            continue;
        } else if (pairDir[count].second < 0 || 4 <= pairDir[count].second) {
            continue;
        } else {
            adjacency.insert(std::pair<direction, std::pair<int, int>>(static_cast<direction>(count), pairDir[count]));
        }
    }
    
//    std::cout << adjacency[up].first << ", " << adjacency[up].second << std::endl;
//    std::cout << adjacency[right].first << ", " << adjacency[right].second << std::endl;
}
