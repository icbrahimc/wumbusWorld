//
//  LogicSentence.cpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/7/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include "LogicSentence.hpp"

// Return the string with the not indicator.
std::string LogicSentence::notFunc(std::string input) {
    return "~" + input;
}

// Return the and logic sentence.
std::string LogicSentence::andFunc(std::string firstLiteral, std::vector<std::string> multiple) {
    if (multiple.size() == 1) {
        return firstLiteral + " & " + multiple[0];
    } else {
        std::string newSentence = "(" + firstLiteral;
        for(int count = 0; count < multiple.size(); count++) {
            newSentence += " & " + multiple[count];
        }
        newSentence += ")";
        return newSentence;
    }
}

// Return the or logic sentence.
std::string LogicSentence::orFunc(std::string firstLiteral, std::vector<std::string> multiple) {
    if (multiple.size() == 1) {
        return firstLiteral + " | " + multiple[0];
    } else {
        std::string newSentence = "(" + firstLiteral;
        for(int count = 0; count < multiple.size(); count++) {
            newSentence += " | " + multiple[count];
        }
        newSentence += ")";
        return newSentence;
    }
}

// Return the imply logic sentence.
std::string LogicSentence::implyFunc(std::string firstLiteral, std::string secondLiteral) {
    return "(" + firstLiteral + " > " + secondLiteral + ")";
}

// Return the iff logic sentence.
std::string LogicSentence::iffFunc(std::string firstLiteral, std::string secondLiteral) {
    std::string first = this->implyFunc(firstLiteral, secondLiteral);
    std::string second = this->implyFunc(secondLiteral, firstLiteral);
    return first + " & " + second;
}
