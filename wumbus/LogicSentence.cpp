//
//  LogicSentence.cpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/7/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include "LogicSentence.hpp"

// Set the sentence to a not.
// Ex:
//  - Take P and ~(P).
void LogicSentence::setNot() {
    std::string newSentence = "~(" + sentenceRep + ")";
    sentenceRep = newSentence;
}
