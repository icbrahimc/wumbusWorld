//
//  main.cpp
//  kbWumpus
//
//  Created by Ibrahim Conteh on 4/8/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

std::string notFunc(std::string);
std::string andFunc(std::string, std::vector<std::string>);
std::string orFunc(std::string, std::vector<std::string>);
std::string implyFunc(std::string, std::string);
std::string iffFunc(std::string, std::string);

std::string makeNotExpression(std::string);

int main(int argc, const char * argv[]) {
    
    std::vector<int> ib;
//    std::cout << ib[0] << std::endl;
    // insert code here...
    std::string notStorage = notFunc("p");
    std::vector<std::string> lit;
    lit.push_back("B");
    lit.push_back("C");
    std::string andLit = andFunc("A", lit);
    std::string orLit = orFunc("A", lit);
    
    std::cout << implyFunc("Q", andLit);
    
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
    return "(" + first + " & " + second + ")";
}
