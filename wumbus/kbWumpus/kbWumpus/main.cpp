//
//  main.cpp
//  kbWumpus
//
//  Created by Ibrahim Conteh on 4/8/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

// Stuff for the knowledge base.
std::string notFunc(std::string);
std::string andFunc(std::string, std::vector<std::string>);
std::string orFunc(std::string, std::vector<std::string>);
std::string implyFunc(std::string, std::string);
std::string iffFunc(std::string, std::string);


// Stuff for the knowledge base.
std::vector<std::string> prepForParse(std::string);
std::vector<std::string> postfix(std::vector<std::string>);
bool plTrue(std::vector<std::string>, std::map<std::string, bool>);
bool higherPrecedence(std::string, std::string);
bool solveExpression(std::vector<std::string>, std::map<std::string, bool>);
bool solveBoolean(bool, bool, char);
bool ttEntails(std::vector<std::string>, std::string);
bool ttCheckAll(std::vector<std::string>, std::string, std::vector<std::string>, std::map<std::string, bool>);
std::vector<std::string> returnSplitVector(std::vector<std::string>);
std::vector<std::string> returnSymbols(std::vector<std::string>, std::string);
// tt_check_all(kb, alpha, prop_symbols(kb & alpha), {})

bool isValidValue(char);
bool isParenValue(char);
bool isSpace(char);

std::string makeNotExpression(std::string);

int main(int argc, const char * argv[]) {
    
    std::vector<int> ib;
//    std::cout << ib[0] << std::endl;
    // insert code here...
    std::string notStorage = notFunc("p");
    std::vector<std::string> lit;
    lit.push_back("B12");
    lit.push_back("C21");
    std::string andLit = andFunc("A11", lit);
    std::string orLit = orFunc("A11", lit);
    std::string imply = implyFunc("Q", andLit);
    std::string iff = iffFunc("Q12", orLit);
    
    std::cout << implyFunc("Q", orLit) << std::endl;
    std::cout << iffFunc("Q12", orLit) << std::endl;
    
    std::vector<std::string> alk = prepForParse(iff);
    std::vector<std::string> walk = postfix(alk);
    std::map<std::string, bool> symbols = {
        {"Q12", true},
        {"A11", false},
        {"B12", false},
        {"C21", false},
    };
    
    std::cout << solveExpression(walk, symbols);
    for (int count = 0; count < walk.size(); count++) {
        std::cout << walk[count] << std::endl;
    }
    
    return 0;
}

std::string notFunc(std::string input) {
    return "~" + input;
}

std::string andFunc(std::string firstLiteral, std::vector<std::string> multiple) {
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

std::string orFunc(std::string firstLiteral, std::vector<std::string> multiple) {
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

std::string implyFunc(std::string firstLiteral, std::string secondLiteral) {
    return "(" + firstLiteral + " > " + secondLiteral + ")";
}

std::string iffFunc(std::string firstLiteral, std::string secondLiteral) {
    std::string first = implyFunc(firstLiteral, secondLiteral);
    std::string second = implyFunc(secondLiteral, firstLiteral);
    return first + " & " + second;
}

std::vector<std::string> prepForParse(std::string parse) {
    // Eliminate spaces.
    std::string parseString = std::string();
    for (int count = 0; count < parse.size(); count++) {
        if (!isSpace(parse[count])) {
            parseString += parse[count];
        }
    }
    std::string inputString = std::string();
    
    std::vector<std::string> good;
    for (int count = 0; count < parseString.size(); count++) {
        if (isValidValue(parseString[count])) {
            
            if (inputString.size() > 0) {
                good.push_back(inputString);
                inputString = std::string();
            }
            
            inputString += parseString[count];
            good.push_back(inputString);
            inputString = std::string();
        } else if (isParenValue(parseString[count])) {
            
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

std::vector<std::string> postfix(std::vector<std::string> toPostFix) {
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
        
        else if (isValidValue(parenHolder) && !parentheses) {
            if (operationBin.size() == 0) {
                operationBin.push_back(toPostFix[index]);
                index++;
            }
            
            else {
                operationBinSize = static_cast<int>(operationBin.size());
                if (higherPrecedence(toPostFix[index], operationBin[operationBinSize - 1])) {
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
        
        else if (isValidValue(parenHolder) && parentheses) {
            if (parenthesesBin.size() == 0) {
                parenthesesBin.push_back(toPostFix[index]);
                index++;
            }
            
            else {
                parenthesesBinSize = static_cast<int>(parenthesesBin.size());
                if (higherPrecedence(toPostFix[index], parenthesesBin[parenthesesBinSize - 1])) {
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

bool higherPrecedence(std::string opOne, std::string opTwo) {
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

// Solve the kb.
bool plTrue(std::vector<std::string> kb, std::map<std::string, bool> sub) {
    // Get the sentences from the knowledge base.
    bool holder;
    std::vector<bool> andBool;
    std::string kbRelation;
    std::vector<std::string> parsable;
    std::vector<std::string> postFix;
    for (int count = 0; count < kb.size(); count++) {
        kbRelation = kb[count];
        parsable = prepForParse(kbRelation);
        postFix = postfix(parsable);
        holder = solveExpression(postFix, sub);
        andBool.push_back(holder);
    }
    
    holder = true;
    for (int count = 0; count < andBool.size(); count++) {
        holder = (holder && andBool[count]);
    }
    
    return holder;
}

bool isValidValue(char input) {
    return (input == '>' || input == '&' || input == '=' || input == '|' || input == '~');
}

bool isParenValue(char input) {
    return (input == '(' || input == ')');
}

bool isSpace(char input) {
    return input == 32;
}

// Solve the boolean.
bool solveBoolean(bool operOne, bool operTwo, char operation) {
    
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
bool solveExpression(std::vector<std::string> postFix, std::map<std::string, bool> expressions) {
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
        } else if(isValidValue(dequeueElement[0]) && dequeueElement != "~") {
            operandTwo = solutionStack[solutionStack.size() - 1];
            operandOne = solutionStack[solutionStack.size() - 2];
            solutionStack.pop_back();
            solutionStack.pop_back();
            
            result = solveBoolean(operandOne, operandTwo, dequeueElement[0]);
            solutionStack.push_back(result);
        } else if (isValidValue(dequeueElement[0]) && dequeueElement == "~") {
            operandOne = solutionStack[solutionStack.size() - 1];
            result = solveBoolean(operandOne, operandTwo, dequeueElement[0]);
            solutionStack.push_back(result);
        }
        
        idx++;
    }
    
    return solutionStack[0];
}

bool ttEntails(std::vector<std::string> kb, std::string alpha) {
    std::vector<std::string> symbols;
    std::map<std::string, bool> substitution;
    return ttCheckAll(kb, alpha, symbols, substitution);
}

// tt_check_all(kb, alpha, prop_symbols(kb & alpha), {})
bool ttCheckAll(std::vector<std::string> kb, std::string alpha, std::vector<std::string> symbols, std::map<std::string, bool> substitution) {
    bool result;
    if (symbols.size() == 0) {
        if (plTrue(kb, substitution)) {
            std::vector<std::string> alphaHolder;
            alphaHolder.push_back(alpha);
            result = plTrue(alphaHolder, substitution);
            return result;
        } else {
            return true;
        }
    } else {
        std::string insertor = symbols[0];
        symbols = returnSplitVector(symbols);
        std::map<std::string, bool> trueMap = substitution;
        std::map<std::string, bool> falseMap = substitution;
        trueMap.insert(std::pair<std::string, bool>(insertor, true));
        falseMap.insert(std::pair<std::string, bool>(insertor, false));
        return (ttCheckAll(kb, alpha, symbols, trueMap) && ttCheckAll(kb, alpha, symbols, falseMap));
    }
}

// Split the vector.
std::vector<std::string> returnSplitVector(std::vector<std::string> oldVector) {
    std::vector<std::string> newVector;
    for (int count = 1; count < oldVector.size(); count++) {
        newVector.push_back(oldVector[count]);
    }
    
    return newVector;
}
