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

// Split the vector.
std::vector<std::string> LogicSentence::returnSplitVector(std::vector<std::string> oldVector) {
    std::vector<std::string> newVector;
    for (int count = 1; count < oldVector.size(); count++) {
        newVector.push_back(oldVector[count]);
    }
    
    return newVector;
}

bool LogicSentence::isValidValue(char input) {
    return (input == '>' || input == '&' || input == '=' || input == '|' || input == '~');
}

bool LogicSentence::isParenValue(char input) {
    return (input == '(' || input == ')');
}

bool LogicSentence::isSpace(char input) {
    return input == 32;
}

std::vector<std::string> LogicSentence::returnSymbols(std::vector<std::string> listOfExp, std::string exp) {
    std::string symbolHolder;
    std::string holder;
    std::map<std::string, bool> symbolMap;
    
    // Collect the symbols from the list of exp.
    for (int i = 0; i < listOfExp.size(); i++) {
        
        // Hold the index of the string from the array.
        holder = this->removeSpaces(listOfExp[i]);
        for (int j = 0; j < holder.size(); j++) {
            
            if (this->isValidValue(holder[j])) {
                if (symbolHolder.size() > 0) {
                    symbolMap.insert(std::pair<std::string, bool>(symbolHolder, false));
                    symbolHolder = std::string();
                }
            } else if (this->isParenValue(holder[j])) {
                if (symbolHolder.size() > 0) {
                    symbolMap.insert(std::pair<std::string, bool>(symbolHolder, false));
                    symbolHolder = std::string();
                }
            } else {
                symbolHolder += holder[j];
            }
        }
    }
    
    // Collect the symbols from the singular expression.
    for (int j = 0; j < exp.size(); j++) {
        if (this->isValidValue(exp[j])) {
            if (symbolHolder.size() > 0) {
                symbolMap.insert(std::pair<std::string, bool>(symbolHolder, false));
                symbolHolder = std::string();
            }
        } else if (this->isParenValue(exp[j])) {
            if (symbolHolder.size() > 0) {
                symbolMap.insert(std::pair<std::string, bool>(symbolHolder, false));
                symbolHolder = std::string();
            }
        } else {
            symbolHolder += exp[j];
        }
    }
    
    return this->extract_keys(symbolMap);
}

std::string LogicSentence::removeSpaces(std::string input) {
    std::string newString = std::string();
    for (int count = 0; count < input.size(); count++) {
        if (this->isSpace(input[count])) {
            newString += input[count];
        }
    }
    return newString;
}

std::vector<std::string> LogicSentence::extract_keys(std::map<std::string, bool> const& input_map) {
    std::vector<std::string> retval;
    for (auto const& element : input_map) {
        retval.push_back(element.first);
    }
    return retval;
}

