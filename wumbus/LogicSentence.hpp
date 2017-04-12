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



//// Return the string with the not indicator.
//std::string otFunc(std::string input) {
//    return "~" + input;
//}

//// Return the and logic sentence.
//std::string andFunc(std::string firstLiteral, std::vector<std::string> multiple) {
//    if (multiple.size() == 1) {
//        return firstLiteral + " & " + multiple[0];
//    } else {
//        std::string newSentence = "(" + firstLiteral;
//        for(int count = 0; count < multiple.size(); count++) {
//            newSentence += " & " + multiple[count];
//        }
//        newSentence += ")";
//        return newSentence;
//    }
//}
//
//// Return thhe or logic sentence.
//std::string orFunc(std::string firstLiteral, std::vector<std::string> multiple) {
//    if (multiple.size() == 1) {
//        return firstLiteral + " | " + multiple[0];
//    } else {
//        std::string newSentence = "(" + firstLiteral;
//        for(int count = 0; count < multiple.size(); count++) {
//            newSentence += " | " + multiple[count];
//        }
//        newSentence += ")";
//        return newSentence;
//    }
//}
//
//// Return the imply logic sentence.
//std::string implyFunc(std::string firstLiteral, std::string secondLiteral) {
//    return "(" + firstLiteral + " > " + secondLiteral + ")";
//}
//
//// Return the iff logic sentence.
//std::string iffFunc(std::string firstLiteral, std::string secondLiteral) {
//    std::string first = implyFunc(firstLiteral, secondLiteral);
//    std::string second = implyFunc(secondLiteral, firstLiteral);
//    return first + " & " + second;
//}


class LogicSentence {
public:
    // Stuff for the knowledge base.
    std::string notFunc(std::string);
    std::string andFunc(std::string, std::vector<std::string>);
    std::string orFunc(std::string, std::vector<std::string>);
    std::string implyFunc(std::string, std::string);
    std::string iffFunc(std::string, std::string);
//    void set

};
#endif /* LogicSentence_hpp */



////
////  Sentence.hpp
////  wumbus
////
////  Created by Ibrahim Conteh on 4/6/17.
////  Copyright © 2017 Ibrahim Conteh. All rights reserved.
////
//
//#ifndef Sentence_hpp
//#define Sentence_hpp
//
//#include <stdio.h>
//#include <string>
//#include <map>
//#include "Symbol.hpp"
//
//
//// Sentence class.
////  Logic sentence is the symbols with the connectives.
////  Truth Value is the value of the atomic sentence.
//
//class Sentence {
//private:
//    std::string logicSentence;
//    bool truthValue;
//public:
//    // Constructor
//    Sentence();
//
//    // Getters.
//    std::string returnSentence() { return logicSentence; };
//    bool returnTruthValue() { return truthValue; };
//
//    // Setters.
//    void determineTruthValue(std::map<std::string, Symbol>);
//    void writeIFFSentence(Symbol, std::vector<Symbol>);
//};
//
//#endif /* Sentence_hpp */
