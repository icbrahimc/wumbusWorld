//
//  State.cpp
//  wumbus
//
//  Created by Ibrahim Conteh on 4/3/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include "State.hpp"

// Set the safety of the state.
void State::setSafety() {
    int count = 0;
    for ( ; count < 5; count++) {
        if (percepts[count] == true) {
            break;
        }
    }
    
    if (count == 5) {
        safe = true;
    }
}
