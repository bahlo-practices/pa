/*
/*
 * File:   main.cpp
 *
 * Created on 13. Mai 2013, 16:31
 */

#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include "myVector.h"
#include "myVec.h"
using namespace std;


void tf(const myVec& rcmv, myVec& rmv) {
   //rcmv[1] = 4.2; // Fehler, wie es auch sein soll
     double d1 = rcmv[1]; // die const-Version []
    rmv[1] = 0.7; // die nicht-const-Version []
    double d2 = rmv[1]; // die nicht-const-Version []
}

int main() {
    try {
        // Tests
        myVec test(-2, 4);
        test.push_back(-1);
        test.push_back(-3.4);
        test.push_back(4.3);
        test.push_back(test.lo());
        // test.push_back("asd"); not valid

        myVec fu(-5, 5);
        fu.push_back(0);
        fu.push_back(1);
        fu.push_back(2);
        fu.push_back(3);
        fu.push_back(4);
        fu.push_back(5);
        fu.push_back(6);
        fu.push_back(7);
        fu.push_back(8);
        fu.push_back(9);

        // fu.push_back(5.5);

        for (int i(fu.lo()); i <= fu.hi(); ++i) {
            fu.set(i, i);
            cout << fu.get(i) << endl;
        }


        const myVec eins (-5, 5);
        myVec zwei (-5,5);
        tf(eins, zwei);


        cout.flush();
        cout.clear();
        return 0;
    } catch (runtime_error) {
        return -3;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
        return -2;
    } catch (...) {
        cout << "Unknown Error\n";
        return -1;
    }
}
