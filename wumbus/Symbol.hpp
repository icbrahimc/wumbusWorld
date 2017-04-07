//
//  Symbol.hpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/6/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef Symbol_hpp
#define Symbol_hpp

#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

//// enum to represent the connectives.
//enum connectives { NOT = 0, AND = 1, OR = 2, IMPLY = 3, IFF = 4 };

// Symbol class.
//  - The symbol class represents the symbolic literal of a specific spot.
//  - B(1,2): The symbol that there is a breeze in the coordinate (1,2).
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
    void setTruthValue(bool input) { truthValue = input; };
    
    // Return the truth value of the literal.
    bool returnTruthValue() { return truthValue; };
    std::pair<int, int> returnLocation() { return location; };
    std::string returnStringValue();
};
#endif /* Symbol_hpp */
