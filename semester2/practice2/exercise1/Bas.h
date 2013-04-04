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
    void add_children(Bas* pointer);
    void print_children() const;
private:
    std::vector<Bas*> deduced;
};

#endif /* defined(__exercise1__Bas__) */
