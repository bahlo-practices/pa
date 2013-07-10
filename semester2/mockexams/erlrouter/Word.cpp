//
//  Word.cpp
//  Erlrouter
//
//  Created by Arne Bahlo on 09.07.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include <sstream>
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

const std::string Word::getLineNumbersAsString() {
    lineNumbers.sort();
    std::stringstream stream;
    std::string list("");
    for(std::list<int>::iterator it = lineNumbers.begin(); it != lineNumbers.end(); ++it)
        stream << *it << " ";
    list = stream.str();
    return list;
}

const void Word::addLineNumber(int lineNumber) {
    lineNumbers.push_back(lineNumber);
}

const void Word::print() {
    std::cout << word << " " << getLineNumbersAsString() << std::endl;
}