//
//  LogicSentence.cpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/7/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include "LogicSentence.hpp"

// helper functions.
bool isNotAnd(char);
bool isNotOr(char);

// Set the sentence to a not.
// Ex:
//  - Take P and ~(P).
void LogicSentence::setNot() {
    std::string newSentence = "~(" + sentenceRep + ")";
    sentenceRep = newSentence;
}

// Add the and connective to the sentence.
// Ex:
//  - Take P and Q.
//  - Return P & Q.
void LogicSentence::setAnd(Symbol literal) {
    bool sameSymbol = true;
    std::string newSentence;
    // Check if the symbols are the same.
    for (int count = 0; count < sentenceRep.size(); count++) {
        if (isNotAnd(sentenceRep[count])) {
            newSentence = "(" + sentenceRep + ")" + " & " + literal.returnStringValue();
            sentenceRep = newSentence;
            sameSymbol = false;
            break;
        }
    }
    
    if (sameSymbol) {
        newSentence = sentenceRep + " & " + literal.returnStringValue();
        sentenceRep = newSentence;
    }
    
}

// Add the or connective to the sentence.
// Ex:
//  - Take P and Q.
//  - Return P | Q.
void LogicSentence::setOr(Symbol literal) {
    bool sameSymbol = true;
    std::string newSentence;
    // Check if the symbols are the same.
    for (int count = 0; count < sentenceRep.size(); count++) {
        if (isNotOr(sentenceRep[count])) {
            newSentence = "(" + sentenceRep + ")" + " | " + literal.returnStringValue();
            sentenceRep = newSentence;
            sameSymbol = false;
            break;
        }
    }
    
    if (sameSymbol) {
        newSentence = sentenceRep + " | " + literal.returnStringValue();
        sentenceRep = newSentence;
    }
}

bool isNotAnd(char input) {
    return (input == '|' || input == '~' || input == '>' || input == '=');
}

bool isNotOr(char input) {
    return (input == '&' || input == '~' || input == '>' || input == '=');
}

