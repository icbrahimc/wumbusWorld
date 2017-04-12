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
    std::vector<std::string> pWumpus;
    std::vector<std::string> pPits;
    
    std::vector<bool> tWumpus;
    std::vector<bool> tPits;
    
    bool pitAsk;
    bool wumpusAsk;
    
    std::vector<std::pair<int, int>> goodMove;
    std::vector<std::pair<int, int>> fairMove;
    std::vector<std::pair<int, int>> noMove;
    
    std::pair<int, int> move;
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
        
//        currentState.setSafety();
        
        pPits = currentState.returnPossiblePits();
        pWumpus = currentState.returnPossibleWumpus();
        
        
        for (int count = 0; count < pPits.size(); count++) {
            wumpusAsk = person.ask(pWumpus[count]);
            pitAsk = person.ask(pPits[count]);
            if (!wumpusAsk && !pitAsk) {
                goodMove.push_back(lsHelper.parseSymbol(pPits[count]));
            } else if (pitAsk && !wumpusAsk) {
                fairMove.push_back(lsHelper.parseSymbol(pPits[count]));
            } else if (!pitAsk && wumpusAsk) {
                fairMove.push_back(lsHelper.parseSymbol(pPits[count]));
            } else {
                noMove.push_back(lsHelper.parseSymbol(pPits[count]));
            }
        }
        
        for (int count = 0; count < goodMove.size(); count++) {
            std::cout << "Good Move: " << goodMove[count].first << ", " << goodMove[count].second << std::endl;
        }
        
        for (int count = 0; count < fairMove.size(); count++) {
            std::cout << "Fair Move: " << fairMove[count].first << ", " << fairMove[count].second << std::endl;
        }
        
        for (int count = 0; count < noMove.size(); count++) {
            std::cout << "Bad Move: " << noMove[count].first << ", " << noMove[count].second << std::endl;
        }
        
        if (goodMove.size() > 0) {
            move = goodMove.back();
            goodMove.pop_back();
        } else if (fairMove.size() > 0) {
            move = fairMove.back();
            fairMove.pop_back();
        } else {
            move = noMove.back();
            fairMove.pop_back();
        }
        
        // Make the move.
        person.makeAMove(move);
        
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
