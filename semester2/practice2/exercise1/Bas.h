//
//  Bas.h
//  exercise1
//
//  Created by Arne Bahlo on 04.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#ifndef __exercise1__Bas__
#define __exercise1__Bas__

#include <iostream>
#include <vector>

class Bas {
public:
    Bas();
    virtual void print() const {};
    void print_all() const;
    Bas* next;
    static Bas* list;
private:
};

#endif /* defined(__exercise1__Bas__) */
