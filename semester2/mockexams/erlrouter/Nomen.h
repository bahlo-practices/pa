//
//  Nomen.h
//  Erlrouter
//
//  Created by Arne Bahlo on 09.07.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#ifndef __Erlrouter__Nomen__
#define __Erlrouter__Nomen__

#include <iostream>
#include "Word.h"

class Nomen : public Word {
public:
    Nomen() : Word() {};
    Nomen(std::string _word, int lineNumber) : Word(_word, lineNumber) {};
};

#endif /* defined(__Erlrouter__Nomen__) */
