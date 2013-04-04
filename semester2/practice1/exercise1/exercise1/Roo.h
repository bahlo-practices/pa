//
//  Roo.h
//  exercise1
//
//  Created by Arne Bahlo on 04.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#ifndef __exercise1__Roo__
#define __exercise1__Roo__

#include <iostream>

#include "Bas.h"

class Roo : public Bas {
public:
    Roo();
    Roo(std::string _password, std::string _secret);
    
    void print() const;
    
    // Getter
    std::string get_secret(std::string _password) const;
    
    // Setter
    void set_password(std::string _password);
    void set_secret(std::string _secret);
private:
    std::string password;
    std::string secret;
};

#endif /* defined(__exercise1__Roo__) */
