//
//  Word.cpp
//  Erlrouter
//
//  Created by Arne Bahlo on 09.07.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include "Word.h"

Word::Word(std::string _word, int lineNumber) : word(_word) {
    lineNumbers.push_back(lineNumber);
}

const std::string Word::getWord() {
    return word;
}

const std::list<int> Word::getLineNumbers() {
    return lineNumbers;
}

const void Word::addLineNumber(int lineNumber) {
    lineNumbers.push_back(lineNumber);
}

const void Word::print() {
    lineNumbers.sort();
    
    std::cout << word << " :: ";
    for(std::list<int>::iterator it = lineNumbers.begin(); it != lineNumbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}