//
//  KnowledgeBase.hpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/6/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef KnowledgeBase_hpp
#define KnowledgeBase_hpp

#include "Sentence.hpp"
#include <stdio.h>
#include <map>
#include <string>
#include <vector>

class KnowledgeBase {
private:
    std::vector<Symbol> kb;
    std::map<std::string, Symbol> found;
public:
    // Constructor.
    KnowledgeBase();
};

#endif /* KnowledgeBase_hpp */
