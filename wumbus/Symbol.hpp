//
//  Symbol.hpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/6/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef Symbol_hpp
#define Symbol_hpp

#include "Constants.cpp"
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

//// enum to represent the connectives.
//enum connectives { NOT = 0, AND = 1, OR = 2, IMPLY = 3, IFF = 4 };

// Symbol class.

class Symbol {
private:
    int literal;
    bool truthValue;
    std::pair<int, int> location;
    
public:
    // Constructor.
    Symbol(int input, std::pair<int, int> coord) {
        literal = input;
        location = coord;
        truthValue = false;
    };
    
    // Setters.
    void setTruthValue(bool input) { truthValue = true; };
    
    // Return the truth value of the literal.
    bool returnTruthValue() { return truthValue; };
    std::string returnStringValue();
};
#endif /* Symbol_hpp */
