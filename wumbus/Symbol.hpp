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
#include <stdio.h>

//enum
enum connectives { b = 0, g = 1, p = 2, s = 3, w = 4};

class Symbol {
private:
    
    bool truthValue;
    std::pair<int, int> location;
};
#endif /* Symbol_hpp */
