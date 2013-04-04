//
//  main.cpp
//  exercise1
//
//  Created by Arne Bahlo on 04.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include <iostream>

#include "Bas.h"
#include "Pro.h"
#include "Roo.h"

int main() {
    Bas base;
    
    // Add new Pro
    Pro *proPointer = new Pro;
    base.add_children(proPointer);
    
    // Add new Roo
    Roo *rooPointer = new Roo;
    base.add_children(rooPointer);
    
    // Print pointers for debugging
    base.print_children();
    
    return 0;
}

