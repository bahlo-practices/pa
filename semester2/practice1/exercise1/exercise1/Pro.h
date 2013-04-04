//
//  Pro.h
//  exercise1
//
//  Created by Arne Bahlo on 04.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#ifndef __exercise1__Pro__
#define __exercise1__Pro__

#include <iostream>

#include "Bas.h"

class Pro : public Bas {
public:
    Pro();
    Pro(std::string _name, int _number);
    void increase();
    void print();
    // Getter
    std::string get_name() const;
    int get_number() const;
    // Setter
    void set_name(std::string _name);
    void set_number(int _number);
private:
    std::string name;
    int number;
};


#endif /* defined(__exercise1__Pro__) */
