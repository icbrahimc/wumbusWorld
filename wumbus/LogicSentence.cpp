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
        if (!this->isSpace(input[count])) {
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


std::vector<std::string> LogicSentence::prepForParse(std::string parse) {
    // Eliminate spaces.
    std::string parseString = this->removeSpaces(parse);
    std::cout << "Parse String: " << parseString << std::endl;
    std::string inputString = std::string();
    
    std::vector<std::string> good;
    for (int count = 0; count < parseString.size(); count++) {
        if (this->isValidValue(parseString[count])) {
            
            if (inputString.size() > 0) {
                good.push_back(inputString);
                inputString = std::string();
            }
            
            inputString += parseString[count];
            good.push_back(inputString);
            inputString = std::string();
        } else if (this->isParenValue(parseString[count])) {
            
            if (inputString.size() > 0) {
                good.push_back(inputString);
                inputString = std::string();
            }
            
            inputString += parseString[count];
            good.push_back(inputString);
            inputString = std::string();
        } else {
            inputString += parseString[count];
        }
        
    }
    
    return good;
}

std::vector<std::string> LogicSentence::postfix(std::vector<std::string> toPostFix) {
    char parenHolder;
    int index = 0;
    int parenthesesBinSize;
    int operationBinSize;
    bool parentheses = false;
    int lengthOfInfix = static_cast<int>(toPostFix.size());
    
    std::vector<std::string> postFixBin;
    std::vector<std::string> operationBin;
    std::vector<std::string> parenthesesBin;
    
    while (index < lengthOfInfix) {
        //        std::cout << toPostFix[index] << std::endl;
        parenHolder = toPostFix[index][0];
        // It is an operator.
        if (toPostFix[index].size() > 1) {
            postFixBin.push_back(toPostFix[index]);
            index++;
        }
        
        // If it is an open parentheses.
        else if ("(" == toPostFix[index]) {
            parentheses = true;
            // If the parentheses bin is not empty.
            if (parenthesesBin.size() > 0) {
                parenthesesBin.push_back("%");
            }
            
            index++;
        }
        
        // If it is an closed parentheses.
        else if (")" == toPostFix[index]) {
            parentheses = false;
            index++;
            while (parenthesesBin.size() > 0) {
                parenthesesBinSize = static_cast<int>(parenthesesBin.size());
                if (parenthesesBin[parenthesesBinSize - 1] == "%") {
                    parenthesesBin.pop_back();
                    break;
                }
                
                else {
                    postFixBin.push_back(parenthesesBin[parenthesesBinSize - 1]);
                    parenthesesBin.pop_back();
                }
            }
        }
        
        else if (this->isValidValue(parenHolder) && !parentheses) {
            if (operationBin.size() == 0) {
                operationBin.push_back(toPostFix[index]);
                index++;
            }
            
            else {
                operationBinSize = static_cast<int>(operationBin.size());
                if (this->higherPrecedence(toPostFix[index], operationBin[operationBinSize - 1])) {
                    operationBin.push_back(toPostFix[index]);
                    index++;
                }
                
                else {
                    while (operationBin.size() > 0) {
                        postFixBin.push_back(operationBin[operationBinSize - 1]);
                        operationBin.pop_back();
                    }
                    operationBin.push_back(toPostFix[index]);
                    index++;
                }
            }
        }
        
        else if (this->isValidValue(parenHolder) && parentheses) {
            if (parenthesesBin.size() == 0) {
                parenthesesBin.push_back(toPostFix[index]);
                index++;
            }
            
            else {
                parenthesesBinSize = static_cast<int>(parenthesesBin.size());
                if (this->higherPrecedence(toPostFix[index], parenthesesBin[parenthesesBinSize - 1])) {
                    parenthesesBin.push_back(toPostFix[index]);
                    index++;
                }
                
                else {
                    parenthesesBin.push_back(toPostFix[index]);
                    index++;
                }
            }
        }
        
    }
    
    while (operationBin.size() > 0) {
        operationBinSize = static_cast<int>(operationBin.size());
        postFixBin.push_back(operationBin[operationBinSize - 1]);
        operationBin.pop_back();
    }
    
    return postFixBin;
}

bool LogicSentence::higherPrecedence(std::string opOne, std::string opTwo) {
    if (opOne == "~") {
        if (opTwo == "&" || opTwo == "|" || opTwo == ">") {
            return true;
        }
    } else if (opOne == "&") {
        if (opTwo == "|" || opTwo == ">") {
            return true;
        }
    } else if (opOne == "|") {
        if (opTwo == ">") {
            return true;
        }
    } else {
        return true;
    }
    return false;
}

// Solve the boolean.
bool LogicSentence::solveBoolean(bool operOne, bool operTwo, char operation) {
    
    switch (operation) {
        case '~':
            return !operOne;
            break;
            
        case '&':
            return (operOne && operTwo);
            break;
            
        case '|':
            return (operOne || operTwo);
            break;
            
        case '>':
            if (operOne && !operTwo) {
                return false;
            } else {
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}

// Solve the postfix expression.
bool LogicSentence::solveExpression(std::vector<std::string> postFix, std::map<std::string, bool> expressions) {
    bool operandOne = false;
    bool operandTwo = false;
    bool result = false;
    std::string dequeueElement;
    std::vector<bool> solutionStack;
    
    int idx = 0;
    while (idx < postFix.size()) {
        dequeueElement = postFix[idx];
        
        // Nomenclature for the variables.
        if (dequeueElement.size() > 1) {
            operandOne = expressions[dequeueElement];
            solutionStack.push_back(operandOne);
        } else if(this->isValidValue(dequeueElement[0]) && dequeueElement != "~") {
            operandTwo = solutionStack[solutionStack.size() - 1];
            operandOne = solutionStack[solutionStack.size() - 2];
            solutionStack.pop_back();
            solutionStack.pop_back();
            
            result = this->solveBoolean(operandOne, operandTwo, dequeueElement[0]);
            solutionStack.push_back(result);
        } else if (this->isValidValue(dequeueElement[0]) && dequeueElement == "~") {
            operandOne = solutionStack[solutionStack.size() - 1];
            result = this->solveBoolean(operandOne, operandTwo, dequeueElement[0]);
            solutionStack.push_back(result);
        }
        
        idx++;
    }
    
    return solutionStack[0];
}

// Returns the tautology sentence given a particular percept, location, and adjacent locations.
std::string LogicSentence::returnPerceptTautology(int percept, std::pair<int, int> stateLocation, std::vector<std::pair<int, int>> adjLocations) {
    int breeze = 0;
    int glitter = 1;
    int pit = 2;
    int stench = 3;
    int wumpus = 4;
    
    std::string tautologyHolder;
    std::string combinationHolder;
    std::string firstLiteralHolder;
    
    Symbol stateSymbol = Symbol(percept, stateLocation);
    std::vector<Symbol> symbolArray;
    std::vector<std::string> stringArray;
    
    switch (percept) {
        case 0:
            for (int i = 0; i < adjLocations.size(); i++) {
                symbolArray.push_back(Symbol(pit, adjLocations[i]));
            }
            
            firstLiteralHolder = symbolArray[0].returnStringValue();
            for (int j = 1; j < symbolArray.size(); j++) {
                stringArray.push_back(symbolArray[j].returnStringValue());
            }
            
            combinationHolder = this->orFunc(firstLiteralHolder, stringArray);
            tautologyHolder = this->iffFunc(stateSymbol.returnStringValue(), combinationHolder);
            break;
            
        case 3:
            for (int i = 0; i < adjLocations.size(); i++) {
                symbolArray.push_back(Symbol(wumpus, adjLocations[i]));
            }
            
            firstLiteralHolder = symbolArray[0].returnStringValue();
            for (int j = 1; j < symbolArray.size(); j++) {
                stringArray.push_back(symbolArray[j].returnStringValue());
            }
            
            combinationHolder = this->orFunc(firstLiteralHolder, stringArray);
            tautologyHolder = this->iffFunc(stateSymbol.returnStringValue(), combinationHolder);
            break;
            
            
        default:
            break;
    }
    
    return tautologyHolder;
}
