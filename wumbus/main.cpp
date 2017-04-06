//
//  main.cpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/3/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include "Agent.hpp"
#include "State.hpp"
#include "Symbol.hpp"
#include "World.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Agent agent = Agent();
    Symbol sym = Symbol(B, std::pair<int, int>(0, 0));
    std::cout << sym.returnStringValue() << std::endl;
//    agent.setLocation(1, 1);
//    agent.setAdjacency();
//    agent.turnAgent();
//    agent.turnAgent();
//    agent.turnAgent();
    World wumpus = World();
    wumpus.printWorld();
    return 0;
}
