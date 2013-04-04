/* 
 * File:   main.cpp
 * Author: arne
 *
 * Created on 3. April 2013, 19:58
 */

#include <iostream>
#include <vector>
#include <stdexcept>

#include "NPV.h"

using namespace std;

// Helper functions
void testcases() {
    vector<NPV> tests;
    
    // Testcase 1
    vector<long int> inv1;
    double irate1(0.0);
    
    inv1.push_back(-234);
    
    tests.push_back(NPV(inv1, irate1));
    
    // Testcase 2
    vector<long int> inv2;
    double irate2(0.1337);
    
    inv2.push_back(-50);
    inv2.push_back(50);
    inv2.push_back(0);
    
    tests.push_back(NPV(inv2, irate2));
    
    // Testcase 3
    /* Funktioniert nicht wegen negativer irate
    vector<long int> inv3;
    double irate3(-0.008);
    
    inv3.push_back(100);
    inv3.push_back(-1000);
    
    tests.push_back(NPV(inv3, irate3));
    */
    
    // Testcase 4 
    vector<long int> inv4;
    double irate4(0.01);
    
    inv4.push_back(-0.2);
    
    tests.push_back(NPV(inv4, irate4));
    
    // Testcase 5
    vector<long int> inv5;
    double irate5(1.00);
    
    inv5.push_back(-1000);
    inv5.push_back(999);
    
    tests.push_back(NPV(inv5, irate5));
    
    // Testcase 6
    vector<long int> inv6;
    double irate6(0.000001);
    
    inv6.push_back(9999999999999999);
    
    tests.push_back(NPV(inv6, irate6));
    
    // Testcase 7
    vector<long int> inv7;
    double irate7(0.99);
    
    inv7.push_back(-99);
    
    tests.push_back(NPV(inv7, irate7));
    
    // Testcase 8
    vector<long int> inv8;
    double irate8(1);
    
    inv8.push_back(1);
    inv8.push_back(1);
    inv8.push_back(1);
    inv8.push_back(1);
    
    tests.push_back(NPV(inv8, irate8));
    
    // Testcase 9
    /* Funktioniert nicht, weil irate über 100 %
    vector<long int> inv9;
    double irate9(1.99); // 199%
    
    tests.push_back(NPV(inv9, irate9));
    */
    
    // Testcase 10
    vector<long int> inv10;
    double irate10(0.1);
    
    inv10.push_back(20);
    inv10.push_back(40);
    inv10.push_back(60);
        
    tests.push_back(NPV(inv10, irate10));
    
    
    // Calculate and print all testcases    
    for(int i = 0; i < tests.size(); i++) {
        tests.at(i).calculate();
        tests.at(i).print();
    }
}

int main() {
    try {
        // Ten random cases
        for(int i = 0; i < 10; i++) {
            NPV capital;
            capital.calculate();
            capital.print();
        }
        
        // testcases();
        
        // Custom test cases
        /*
        vector<long int> testerInv;
        
        double testerRate(0.1337);
        testerInv.push_back(1337);
        
        NPV tester(testerInv, testerRate);
        tester.calculate();
        tester.print();
        */
        
        return 0;  
    } catch (NPV::Invalid) {
        cerr << "Fehlerhafte Daten";
        return 1;
    } catch (exception &e) {
        cerr << e.what();
        return 2;
    } catch (...) {
        cerr << "Unbekannter Fehler!";
        return 3;
    }
}

