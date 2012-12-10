/* 
 * 1a
 *
 * Created on 30. November 2012, 13:16
 */

#include <iostream>
#include <vector>
#include "error.h"
#include "vec.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

using std::string;
using std::vector;
using std::swap;
using std::exception;

// MENU
int show_menu(bool error = false) {
    int i(1);
    int iAction(-1);
    
    if(error)
        cout << endl << "Bitte geben Sie eine g\x81ltige Option an!" << endl << endl;
    
    cout << "Sie haben folgende Optionen: " << endl;
    
    vector<string> vOptions;
    vOptions.push_back("Einen Vector mit zuf\x84lligen Werten generieren");
    vOptions.push_back("Einen Vector ausgeben");
    vOptions.push_back("Einen Vector sortieren");
    vOptions.push_back("Einen Vector \x81 \bberpr\x81 \bfen");
    vOptions.push_back("Das Programm beenden");
    
    for(int i(0); i < vOptions.size(); i++) {
        cout << i+1 << ". " << vOptions.at(i) << endl;   
    }
    
    cout << endl << "Ihre Auswahl: ";
    cin >> iAction;
    cout << endl;
    
    iAction--; // yes.
    return iAction;
}

// SORTING
void swap_if( int& a, int& b ) { 
    if(a>b) swap(a,b); 
}

vector<int> sel_int(vector<int> vV, int ui, int oi) {
    int min(0);
    for(int i=ui; i<oi; ++i){
        min = i;
        for(int j=i+1; j<=oi; ++j) {
            if(vV.at(j) < vV.at(min)) {
                min=j; 
                swap(vV.at(i), vV.at(min));
            }
        }
    }
    return vV;
}

vector<int> ins_int(vector<int> vV, int ui, int oi) {
    int i(0), j(0), tmp(0);
    for (i = oi; i > ui; --i) {
        swap_if(vV.at(i - 1), vV.at(i));
    }
    for (i = ui + 2; i <= oi; ++i) {
        j = i;
        tmp = vV.at(i);
        while (tmp < vV.at(j - 1)) {
            vV.at(j) = vV.at(j - 1);
            --j;
        }
        vV.at(j) = tmp;
    }
    return vV;
}

// MAIN
int main() {
    try {
        // Create object
        vec vectors;
        
        while(true) {
            switch(show_menu()) {
                case 0: {
                    // GENERIEREN
                    int iCount(0);
                    int iWhat(0);

                    cout << "Was f\x81r einen Typ sollen die Werte in dem Vector haben?" << endl;
                    cout << "1. Int" << endl;
                    cout << "2. String" << endl;
                    cout << "Ihre Auswahl: ";
                    cin >> iWhat;
                    cout << endl;

                    cout << "Geben Sie die Anzahl der zu generierenden Werte ein: ";
                    cin >> iCount;

                    switch(iWhat) {
                        case 1:
                            vectors.generate_int(iCount);
                            break;
                        case 2:
                            vectors.generate_str(iCount);
                            break;
                        default:
                            error("Ein Fehler ist aufgetreten.");
                    }

                    cout << endl;
                    break;
                }
                case 1: {
                    if(vectors.are_both_empty(true)) break;
                    // AUSGEBEN
                    int iWhat(0);

                    cout << "Welcher Vector soll ausgegeben werden?" << endl;
                    cout << "1. Int" << endl;
                    cout << "2. String" << endl;
                    cout << "Ihre Auswahl: ";
                    cin >> iWhat;
                    cout << endl << endl;
                    
                    switch(iWhat) {
                        case 1:
                            if(!vectors.is_int_empty()) vectors.print_int();
                            else break;
                        case 2:
                            if(!vectors.is_str_empty()) vectors.print_str();
                            else break;
                        default:
                            error("Ein Fehler ist aufgetreten.");
                    }

                    cout << endl;
                    break;
                }
                case 2: {
                    if(vectors.are_both_empty(true)) break;
                    
                    // SORTIEREN
                    int iWhat(0);
                    int iSort(0);
                    
                    cout << "Welcher Vector soll sortiert werden?" << endl;
                    cout << "1. Int" << endl;
                    cout << "2. String" << endl;
                    cout << "Ihre Auswahl: ";
                    cin >> iWhat;
                    cout << endl;
                    
                    if(iWhat == 1 && vectors.is_int_empty()) break;
                    if(iWhat == 2 && vectors.is_str_empty()) break;
                    
                    cout << "Welche Sortiermethode soll angewendet werden?" << endl;
                    cout << "1. Sortieren durch Ausw\x84hlen" << endl;
                    cout << "2. Sortieren durch Einf\x81gen" << endl;
                    cout << "Ihre Auswahl: ";
                    cin >> iSort;
                    cout << endl;
                    
                    //if(iSort < 1 || iSort > 2) error("Ung\x81ltige Option.");
                    if(iSort == 1) {
                        vector<int> temp;
                        if(iWhat == 1) temp = sel_int(vectors.get_int(), 0, vectors.get_int().size() - 1);
                        if(iWhat == 2) temp = ins_int(vectors.get_int(), 0, vectors.get_int().size() - 1);
                        vectors.set_int(temp);
                    } 
                    if(iSort == 2) {
                        vector<string> temp;
                        if(iWhat == 1); // do sth
                        if(iWhat == 2); // do sth else
                        vectors.set_str(temp);
                    }
                    
                    cout << endl;
                    break;
                }
                case 3: {
                    if(vectors.are_both_empty(true)) break;
                    
                    // ÜBERPRÜFEN
                    int iWhat(0);
                    
                    cout << "Welcher Vector soll sortiert werden?" << endl;
                    cout << "1. Int" << endl;
                    cout << "2. String" << endl;
                    cout << "Ihre Auswahl: ";
                    cin >> iWhat;
                    cout << endl;
                    
                    if(iWhat == 1 && vectors.is_int_empty()) break;
                    if(iWhat == 2 && vectors.is_str_empty()) break;
                    
                    switch(iWhat) {
                        case 1:
                            if(vectors.check_int()) {
                                cout << "Vektor ist korrekt sortiert." << endl;
                            } else {
                                cout << "Vektor ist nicht korrekt sortiert." << endl;
                            }
                            break;
                        default:
                            cout << "Ung\x81ltige Option" << endl;
                    }
                    
                    cout << endl;
                    break;
                }
                case 4: {
                    return 0;
                }
                default:
                    cout << "Bitte geben Sie eine g\x81ltige Option an!" << endl << endl;
                    break;
            }
        }
        
    } catch (exception &e) {
        error("Ausname: ", e.what());
        return -2;
    } catch (...) {
        error("Unbekannter Fehler");
        return -1;
    }
}

