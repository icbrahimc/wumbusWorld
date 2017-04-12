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
    std::vector<std::string> background;
    std::vector<std::string> query;
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
    do {
        // Get the state that the player is in.
        State currentState = game.returnState(person.returnLocation());
        person.setVisited();
        
        // Set the background knowledge.
        background = currentState.returnBackgroundKnowledge();
        person.tell(background);
        
        // Set status of the state and add the query to the knowledge base.
        currentState.setStatus();
        query = currentState.returnQueryKnowledge();
        person.tell(query);
        
        // If there is a wumpus, end the game.
        if (currentState.isWumpus()) {
            std::cout << "Game over!\n";
            std::cout << "Wumpus Eats!\n";
            break;
        }
        
        // If there is a pit, end the game.
        if (currentState.isPit()) {
            std::cout << "Game over!\n";
            std::cout << "You fall down the pit!\n";
            break;
        }
        
        if (currentState.isGlitter()) {
            std::cout << "Game over!\n";
            std::cout << "You won the game!\n";
            break;
        }
        
        if (currentState.isBreeze()) {
            
        }
        
    } while (!person.returnGlitter());
//    person.returnLocation()
    State currentState = game.returnState(person.returnLocation());
    person.setVisited();
    // Get the status of the state. Before you put it into the the KB.
   
    person.tell(background);
    currentState.setStatus();
    person.tell(query);
    std::cout << "Pit Exists?: " << person.ask("{W2,0}") << std::endl;
    game.printWorld();


    return 0;
}
