/* 
 * File:   main.cpp
 *
 * Created on 15. Mai 2013, 16:13
 */

#include <iostream>

#include "myVector.h"
#include "myVec.h"

int main(int argc, char** argv) {
    try {
        //    myVector<double> h1( 5 );
        myVector<int> i1;
        i1.push_back(5);
        i1.set(0, 1);
        std::cout << i1.get(0) << std::endl;

        myVec<double> d1;
        d1.push_back(2.3);
        d1.push_back(-2.3);
        // d1.push_back("asdasd"); geht nicht, falscher typ
        
        myVec<char> c1;
        c1.push_back('a');
        // c1.push_back("asd");
        
        //myVec<char> asd1(2, -5);
        
        std::cout << "asdasd" << std::endl;
        myVec<int> i3(0,5);
        i3.set(0,23);
        i3.set(1,21);
        i3.set(2,22);
        myVec<int> i2;
        i2 = i3;
        i2.set(2,55);
        std::cout << "asd" << std::endl;
        std::cout << i2.get(2)<< std::endl;
        std::cout << i3.get(2)<< std::endl;
        
        
        std::cout << "main" << std::endl;
        return 0;
    } catch (std::runtime_error) {
        return -3;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return -2;
    } catch (...) {
        std::cout << "Unknown Error\n";
        return -1;
    }
}

