//
//  Akronym.h
//  Erlrouter
//
//  Created by Arne Bahlo on 10.07.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#ifndef __Erlrouter__Akronym__
#define __Erlrouter__Akronym__

#include <iostream>
#include "Word.h"

class Akronym : public Word {
public:
    Akronym() : Word() {};
    Akronym(std::string _word, int lineNumber) : Word(_word, lineNumber) {};
};

#endif /* defined(__Erlrouter__Akronym__) */
