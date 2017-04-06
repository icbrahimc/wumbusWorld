//
//  Symbol.cpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/6/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include "Symbol.hpp"
std::string intToString(int);

// Returns the string value of the literal for printing.
std::string Symbol::returnStringValue() {
    switch (literal) {
        case B:
            return "B(" + intToString(location.first) + ", " + intToString(location.second) + ")";
            break;
        case G:
            return "G(" + intToString(location.first) + ", " + intToString(location.second) + ")";
            break;
        case P:
            return "P(" + intToString(location.first) + ", " + intToString(location.second) + ")";
            break;
        case S:
            return "S(" + intToString(location.first) + ", " + intToString(location.second) + ")";
            break;
        case W:
            return "W(" + intToString(location.first) + ", " + intToString(location.second) + ")";
            break;
            
        default:
            return "!";
            break;
    }
}

// Converts an int to a string.
std::string intToString(int input) {
    switch (input) {
        case 0:
            return "0";
            break;
        case 1:
            return "1";
            break;
        case 2:
            return "2";
            break;
        case 3:
            return "3";
            break;
        default:
            return "!";
            break;
    }
}
