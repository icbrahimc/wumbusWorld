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
    
    void tell(std::vector<std::string> sentences) {
        for (int count = 0; count  < sentences.size(); count++) {
            kBase.push_back(sentences[count]);
        }
    }
    
    // Ask the knowledge base if the knowledge base entails the sentence.
    bool ask(std::string sentence) {
        LogicSentence ls;
        return ls.ttEntails(kBase, sentence);
        
    };
    
    std::vector<std::string> returnKB() { return kBase; };
    
};

#endif /* KnowledgeBase_hpp */
