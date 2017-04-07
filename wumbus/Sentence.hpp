//
//  Sentence.hpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/6/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef Sentence_hpp
#define Sentence_hpp

#include "Agent.hpp"
#include <stdio.h>
#include <string>
#include "Symbol.hpp"


// Sentence class.
//  Logic sentence is the symbols with the connectives.
//  Truth Value is the value of the atomic sentence.

class Sentence {
private:
    std::string logicSentence;
    bool truthValue;
public:
    // Constructor
    Sentence();
    
    // Getters.
    std::string returnSentence() { return logicSentence; };
    bool returnTruthValue() { return truthValue; };
    
    // Setters.
    void determineTruthValue(Agent);
};

#endif /* Sentence_hpp */
