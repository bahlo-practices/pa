/* 
 * File:   main.cpp
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
    // Funktioniert einwandfrei, Kapital: -234
    vector<long int> inv1;
    double irate1(0.0);
    
    inv1.push_back(-234);
    
    tests.push_back(NPV(inv1, irate1));
    
    // Testcase 2
    // Funktioniert einwandfrei, Kapital: -5.89662
    vector<long int> inv2;
    double irate2(0.1337);
    
    inv2.push_back(-50);
    inv2.push_back(50);
    inv2.push_back(0);
    
    tests.push_back(NPV(inv2, irate2));
    
    // Testcase 3
    // Funktioniert nicht wegen negativer irate
//    vector<long int> inv3;
//    double irate3(-0.008);
//    
//    inv3.push_back(100);
//    inv3.push_back(-1000);
//    
//    tests.push_back(NPV(inv3, irate3));
    
    // Testcase 4
    // Funktioniert, aber der Float wert wird nicht erkannt, Kapital: 0
    vector<long int> inv4;
    double irate4(0.01);
    
    inv4.push_back(-0.2);
    
    tests.push_back(NPV(inv4, irate4));
    
    // Testcase 5
    // Funktioniert einwandfrei, Kapital: -500.5
    vector<long int> inv5;
    double irate5(1.00);
    
    inv5.push_back(-1000);
    inv5.push_back(999);
    
    tests.push_back(NPV(inv5, irate5));
    
    // Testcase 6
    // Funktioniert einwandfrei, Kapital: 1e+16
    vector<long int> inv6;
    double irate6(0.000001);
    
    inv6.push_back(9999999999999999);
    
    tests.push_back(NPV(inv6, irate6));
    
    // Testcase 7
    // Funktioniert einwandfrei, Kapital: -99
    vector<long int> inv7;
    double irate7(0.99);
    
    inv7.push_back(-99);
    
    tests.push_back(NPV(inv7, irate7));
    
    // Testcase 8
    // Funktioniert einwandfrei, Kapital: 1.875
    vector<long int> inv8;
    double irate8(1);
    
    inv8.push_back(1);
    inv8.push_back(1);
    inv8.push_back(1);
    inv8.push_back(1);
    
    tests.push_back(NPV(inv8, irate8));
    
    // Testcase 9
    // Funktioniert nicht, weil irate über 100 %
//    vector<long int> inv9;
//    double irate9(1.99); // 199%
//    
//    tests.push_back(NPV(inv9, irate9));
    
    
    // Testcase 10
    // Funktioniert einwandfrei, Kapital: 105.95
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

void generateRandom() {
    // Ten random cases
    for(int i = 0; i < 10; i++) {
        NPV capital;
        capital.calculate();
        capital.print();
    }
}

int main() {
    try {
        //testcases();
        
        //* Menu
        bool menu(true); // Define variable to prevent showing the menu even from the deepest loops (where break wouldn't work)
        while(menu) {
            int choice(0);
            cout << "Sie haben folgende Optionen:" << endl;
            cout << "(1) Zufällig generieren" << endl;
            cout << "(2) Eingeben" << endl;
            cout << "(3) Beenden" << endl;
            cout << "Ihre Wahl: ";
            
            cin >> choice;
            
            if(cin) {
                switch(choice) {
                    case 1: {
                        generateRandom();
                        break;
                    }
                    case 2: {
                        vector<long int> inv;
                        double irate(0.0);
                        
                        bool prompt = true;
                        while(prompt) {
                            // Get rate
                            cout << "Geben Sie den Zinssatz als dezimalzahl ein (0.5 = 50%): ";
                            cin >> irate;
                            if(!cin) throw runtime_error("\nFehlerhafte Eingabe! Das Programm wurde beendet.");
                            if(irate < 0 || irate > 1) {
                                cerr << endl << "Der Zinssatz muss zwischen 0 und 1 liegen!" << endl << endl;
                                continue;
                            }
                            
                            // Get invs
                            cout << "Geben Sie ganze Zahlen ein und bestätigen Sie jeweils mit <Enter> (Beenden mit q):";
                            while(true) {
                                long int singleInv(0);
                                cin >> singleInv;
                                if(!cin) {
                                    prompt = false;
                                    break;
                                }
                                inv.push_back(singleInv);
                            }
                            
                            // Create object
                            NPV input(inv, irate);
                            input.calculate();
                            
                            // Print object
                            cout << endl;
                            input.print();
                        }
                        break;
                    }
                    case 3: {
                        menu = false;
                        break;
                    }
                    default: {
                        cerr << endl << "Bitte geben Sie eine Zahl zwischen 1 und 3 ein!" << endl << endl;
                        break;
                    }
                }
            } else {
                throw runtime_error("\nFehlerhafte Eingabe! Das Programm wurde beendet.");
            }
        }
        // */
        
        cout << endl << "Das Programm wurde beendet" << endl;
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

