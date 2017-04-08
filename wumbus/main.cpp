//
//  main.cpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/3/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include "Agent.hpp"
#include "LogicSentence.hpp"
#include "State.hpp"
#include "Symbol.hpp"
#include "World.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Symbol sym = Symbol(0, std::pair<int, int>(0, 0));
    Symbol sym1 = Symbol(2, std::pair<int, int>(1, 0));
    Symbol sym2 = Symbol(2, std::pair<int, int>(0, 1));
    LogicSentence log = LogicSentence(sym);
    log.setAnd(sym1);
    log.setImplies(sym2);
//    log.setNot();
    std::cout << log.returnSentence() << std::endl;
    Agent agent = Agent();
    //Sentence sen = Sentence();
    
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
