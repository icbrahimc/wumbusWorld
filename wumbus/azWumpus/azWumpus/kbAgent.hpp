//
//  kbAgent.hpp
//  azWumpus
//
//  Created by Ibrahim Conteh on 4/9/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef kbAgent_hpp
#define kbAgent_hpp

#define X 4
#define Y 4

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

class kbAgent{
    
private:
    std::vector<std::string> clauses;
    std::pair<int, int> coordinates;
    std::vector<std::pair<int, int>> adjMoves;
    
public:
    // Constructor
    // Instantiate the knowledge based agent and
    kbAgent() {
        
    };
};
#endif /* kbAgent_hpp */
