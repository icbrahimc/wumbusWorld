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

using namespace std;

string notFunc(string);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

string notFunc(string input) {
    return "~{" + input + "}";
}
