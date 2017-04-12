//
//  LogicSentence.hpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/7/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef LogicSentence_hpp
#define LogicSentence_hpp

#include <stdio.h>
#include <string>
#include "Symbol.hpp"
#include <vector>

class LogicSentence {
public:
    // Stuff for the knowledge base.
    std::string notFunc(std::string);
    std::string andFunc(std::string, std::vector<std::string>);
    std::string orFunc(std::string, std::vector<std::string>);
    std::string implyFunc(std::string, std::string);
    std::string iffFunc(std::string, std::string);
    
    
    // Truth table algorithms.
    bool plTrue(std::vector<std::string>, std::map<std::string, bool>);
    bool ttEntails(std::vector<std::string>, std::string);
    bool ttCheckAll(std::vector<std::string>, std::string, std::vector<std::string>, std::map<std::string, bool>);
    
    // Helper functions. Such as string and map manipulators.
    std::vector<std::string> prepForParse(std::string);
    std::vector<std::string> postfix(std::vector<std::string>);
    std::vector<std::string> returnSplitVector(std::vector<std::string>);
    std::vector<std::string> returnSymbols(std::vector<std::string>, std::string);
    std::string removeSpaces(std::string);
    std::vector<std::string> extract_keys(std::map<std::string, bool> const&);
    std::string returnPerceptTautology(int, std::pair<int, int>, std::vector<std::pair<int, int>>);
    std::vector<std::string> returnAdjSymbols(int, std::vector<std::pair<int,int>>);
    std::pair<int, int> parseSymbol(std::string);
    int convertToInt(char);
    
    // Booleans for the logic sentences.
    bool isValidValue(char);
    bool isParenValue(char);
    bool isSpace(char);
    bool higherPrecedence(std::string, std::string);
    bool solveExpression(std::vector<std::string>, std::map<std::string, bool>);
    bool solveBoolean(bool, bool, char);
};
#endif /* LogicSentence_hpp */
