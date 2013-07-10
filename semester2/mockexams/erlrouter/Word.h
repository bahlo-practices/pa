//
//  Word.h
//  Erlrouter
//
//  Created by Arne Bahlo on 09.07.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#ifndef __Erlrouter__Word__
#define __Erlrouter__Word__

#include <iostream>
#include <list>

class Word {
public:
    Word() : word(""), lineNumbers() {};
    Word(std::string _word, int lineNumber);
    const void addLineNumber(int lineNumber);
    const std::string getWord();
    const std::list<int> getLineNumbers();
    const void print();
private:
    std::string word;
    std::list<int> lineNumbers;
};

#endif /* defined(__Erlrouter__Word__) */
