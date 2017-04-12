//
//  Symbol.cpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/6/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
// B: 0, G: 1, P: 2, S: 3, P: 4

#include "Symbol.hpp"
std::string intToString(int);

// Returns the string value of the literal for printing.
std::string Symbol::returnStringValue() {
    switch (literal) {
        case 0:
            return "{B" + intToString(location.first) + ", " + intToString(location.second) + "}";
            break;
        case 1:
            return "{G" + intToString(location.first) + ", " + intToString(location.second) + "}";
            break;
        case 2:
            return "{P" + intToString(location.first) + ", " + intToString(location.second) + "}";
            break;
        case 3:
            return "{S" + intToString(location.first) + ", " + intToString(location.second) + "}";
            break;
        case 4:
            return "{W" + intToString(location.first) + ", " + intToString(location.second) + "}";
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
