//
//  Bas.h
//  exercise1
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
