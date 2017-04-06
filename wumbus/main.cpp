//
//  main.cpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/3/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include "Agent.hpp"
#include "State.hpp"
#include "World.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Agent agent = Agent();
//    agent.setLocation(1, 1);
//    agent.setAdjacency();
//    agent.turnAgent();
//    agent.turnAgent();
//    agent.turnAgent();
    World wumpus = World();
    wumpus.printWorld();
    return 0;
}
