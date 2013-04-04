//
//  main.cpp
//  exercise1
//
//  Created by Arne Bahlo on 04.04.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include <iostream>
#include <vector>

#include "Bas.h"
#include "Pro.h"
#include "Roo.h"

int main() {
    try {
        Bas base;
        
        // Add 5 new Pro pointers to vectors
        std::vector<Pro*> pros;
        pros.push_back(new Pro());
        pros.push_back(new Pro("Mac OS X", 10));
        pros.push_back(new Pro("20", 20));
        //pros.push_back(new Pro(-12, "10")); // No matching constructor
        //pros.push_back(new Pro('c', -5)); // Same as above
        // Add to base
        for(int i(0); i < pros.size(); ++i) {
            base.add_children(pros.at(i));
        }
        
        // Add 5 new Roo pointers to vector
        std::vector<Roo*> roos;
        roos.push_back(new Roo("1234", "the secretly stored secret"));
        //roos.push_back(new Roo("root", -12)); // No matching constructor
        //roos.push_back(new Roo('c', "like a char"));
        roos.push_back(new Roo("the breaking?", "bad"));
        roos.push_back(new Roo("", "last but not least!"));
        // Add to base
        for(int i(0); i < roos.size(); ++i) {
            base.add_children(roos.at(i));
        }
        
        // Print pointers for debugging
        base.print_children();
        
        return 0;
    } catch(std::exception &e) {
        std::cerr << std::endl << "Exception: " << e.what() << std::endl;
    } catch(...) {
        std::cerr << std::endl << "Ein unbekannter Fehler ist aufgetreten!" << std::endl;
    }
}

