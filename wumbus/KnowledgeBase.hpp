//
//  KnowledgeBase.hpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/6/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef KnowledgeBase_hpp
#define KnowledgeBase_hpp

//#include "Sentence.hpp"
#include "LogicSentence.hpp"
#include "Symbol.hpp"
#include <stdio.h>
#include <map>
#include <string>
#include <vector>

class KnowledgeBase {
private:
    std::vector<std::string> kBase;
public:
    // Constructor.
    KnowledgeBase() {};
    
    void tell(std::string sentence) {
        kBase.push_back(sentence);
    };
    
    // Ask the knowledge base if the knowledge base entails the sentence.
    bool ask(std::string sentence) {
        LogicSentence ls;
        return ls.ttEntails(kBase, sentence);
        
    };
    
};

#endif /* KnowledgeBase_hpp */
