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
    LogicSentence lsHelper;
//    std::vector<std::pair<int, int>> yuh;
//    yuh.push_back(std::pair<int, int>(1,1));
//    yuh.push_back(std::pair<int, int>(0,1));
//    std::cout << lsHelper.returnPerceptTautology(0, std::pair<int, int>(0, 0), yuh) << std::endl;
//    std::cout << lsHelper.removeSpaces("A11 + B11") << std::endl;
//    std::cout << lsHelper.isSpace(32) << std::endl;
//    std::vector<std::string> hey = lsHelper.prepForParse("(A11 & B11)");
//    for (int count = 0; count < hey.size(); count++) {
//        std::cout << hey[count] << std::endl;
//    }
    Agent person = Agent();
    World game = World();
    State currentState = game.returnState(person.returnLocation());
    person.setVisited();
    // Get the status of the state. Before you put it into the the KB.
    currentState.setBreeze();
    currentState.setGlitter();
    currentState.setPit();
    currentState.setStench();
    currentState.setWumpus();
    
    // Pass the percepts to the agent to create the logic sentences.
//    person.setPercepts(currentState.returnPercepts());
//    person.setAdjacency();
//    Symbol sym = Symbol(0, std::pair<int, int>(0, 0));
//    Symbol sym1 = Symbol(2, std::pair<int, int>(1, 0));
//    Symbol sym2 = Symbol(2, std::pair<int, int>(0, 1));
//    Symbol symLit[3] = {
//        sym, sym1, sym2
//    };
//    
//    for (int count = 0; count < 3; count++) {
//        <#statements#>
//    }
//    LogicSentence log = LogicSentence(sym);
//    log.setImplies(sym1);
//    log.setOr(sym2);
////    log.setAnd(sym1);
////    log.setImplies(sym2);
////    log.setNot();
//    std::cout << log.returnSentence() << std::endl;
    Agent agent = Agent();
    std::cout << agent.returnLocation().first << ", " << agent.returnLocation().second << std::endl;
    
    agent.setAdjacency();
    //Sentence sen = Sentence();
    
//    std::cout << sym.returnStringValue() << std::endl;
//    agent.setLocation(1, 1);
//    agent.setAdjacency();
//    agent.turnAgent();
//    agent.turnAgent();
//    agent.turnAgent();
    World wumpus = World();
    wumpus.printWorld();
    return 0;
}
