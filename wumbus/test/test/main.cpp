//
//  main.cpp
//  test
//
//  Created by Ibrahim Conteh on 4/8/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

std::string notFunc(std::string);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Brooklyn!\n";
    std::cout << "Brooklyn";
    std::cout << "Ouch";
    std::cout << notFunc("A") << std::endl;
    return 0;
}

std::string notFunc(std::string input) {
    return "~{" + input + "}";
}
