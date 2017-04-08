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
private:
    std::string sentenceRep;
    bool truthValue;
public:
    // Constructor
    LogicSentence(Symbol literal) {
        sentenceRep = literal.returnStringValue();
    };
    
    // Getters.
    std::string returnSentence() { return sentenceRep; };
    bool returnTruthValue() { return truthValue; };
    
    // Setters.
    void setNot();
    void setAnd();
    void setOr();
    void setImplies();
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
