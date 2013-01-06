/* 
 * 1
 * 
 * Erstellt, sortiert und gibt Vektoren aus
 * 
 * Created on 4. Dezember 2012, 15:55
 * 
 */


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
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

using namespace std;

// MENU
int show_menu(bool bError = false) {
    int i(1);
    int iAction(-1);

    if (bError)
        cout << endl << "Bitte geben Sie eine g\x81ltige Option an!" << endl << endl;

    cout << "Sie haben folgende Optionen: " << endl;

    vector<string> vOptions;
    vOptions.push_back("Einen Vektor erstellen");
    vOptions.push_back("Einen Vektor ausgeben");
    vOptions.push_back("Einen Vektor sortieren");
    vOptions.push_back("Einen Vektor \x81 \bberpr\x81 \bfen");
    vOptions.push_back("Das Programm beenden");

    for (int i(0); i < vOptions.size(); i++) {
        cout << i + 1 << ". " << vOptions.at(i) << endl;
    }

    cout << endl << "Ihre Auswahl: ";
    cin >> iAction;
    if(!cin) error("Ung\x81ltige Eingabe.");
    cout << endl;

    iAction--; // yes.
    return iAction;
}

// SORTIEREN
void swap_if(int& a, int& b) {
    if (a > b) swap(a, b);
}

void swap_str(string& a, string& b) {
    if (a > b) swap(a, b);
}

void swapString(string& a, string& b) {
    string stemp = a;
    a = b;
    b = stemp;
}

void sel_int(vector<int>& vV, int ui, int oi) {
    int min(0);
    for (int i = ui; i < oi; ++i) {
        min = i;
        for (int j = i + 1; j <= oi; ++j) {
            if (vV.at(j) < vV.at(min)) {
                min = j;
            }
        }
        swap(vV.at(i), vV.at(min));
    }
}

void sel_str(vector<string>& vV, int ui, int oi) {
    int min(0);
    for (int i = ui; i < oi; ++i) {
        min = i;
        for (int j = i + 1; j <= oi; ++j) {
            if (vV.at(j) < vV.at(min)) {
                min = j;
            }
        }
        swapString(vV.at(i), vV.at(min));
    }
}

void ins_int(vector<int>& vV, int ui, int oi) {
    int i(0), j(0), tmp(0);
    for (i = oi; i > ui; --i) swap_if(vV.at(i - 1), vV.at(i));
    for (i = ui + 2; i <= oi; ++i) {
        j = i;
        tmp = vV.at(i);
        while (tmp < vV.at(j - 1)) {
            vV.at(j) = vV.at(j - 1);
            --j;
        }
        vV.at(j) = tmp;

    }
}

void ins_str(vector<string>& vV, int ui, int oi) {
    int i(0), j(0);
    string tmp = "";
    for (i = oi; i > ui; --i) swap_str(vV.at(i - 1), vV.at(i));
    for (i = ui + 2; i <= oi; ++i) {
        j = i;
        tmp = vV.at(i);
        while (tmp < vV.at(j - 1)) {
            vV.at(j) = vV.at(j - 1);
            --j;
        }
        vV.at(j) = tmp;
    }
}

void ins_int_v1( vector<int>& vV, int ui, int oi ) {
    if(ui >= oi) {
        cerr << "Fehler"; 
        return;
    }
    for( int i=ui+1; i<=oi; ++i ) {
        for( int j=i; j>ui; --j ) {
            if( vV.at(j-1) < vV.at(j) ) break;
            swap( vV.at(j-1), vV.at(j) );
        }
    }
}

void ins_str_v1( vector<string>& vV, int ui, int oi ) {
    if(ui >= oi) {
        cerr << "Fehler"; 
        return;
    }
    for( int i=ui+1; i<=oi; ++i ) {
        for( int j=i; j>ui; --j ) {
            if( vV.at(j-1) < vV.at(j)) break;
            swap_str( vV.at(j-1), vV.at(j) );
        }
    }
}


void rev_ins_int(vector<int>& vV, int ui, int oi) {
    int i(0), j(0), tmp(0);
    for (i = oi; i > ui; --i) swap_if(vV.at(i), vV.at(i - 1));
    for (i = ui + 2; i <= oi; ++i) {
        j = i;
        tmp = vV.at(i);
        while (tmp > vV.at(j - 1)) {
            vV.at(j) = vV.at(j - 1);
            --j;
        }
        vV.at(j) = tmp;

    }
}

void rev_ins_str(vector<string>& vV, int ui, int oi) {
    int i(0), j(0);
    string tmp = "";
    for (i = oi; i > ui; --i) swap_str(vV.at(i), vV.at(i - 1));
    for (i = ui + 2; i <= oi; ++i) {
        j = i;
        tmp = vV.at(i);
        while (tmp > vV.at(j - 1)) {
            vV.at(j) = vV.at(j - 1);
            --j;
        }
        vV.at(j) = tmp;
    }
}


bool check_int(const vector<int> vInt) {
    for(int i(0); i < vInt.size(); i++) {
        if(vInt.at(i) > vInt.at(i+1)) return false;
    }
    return true;
}

bool check_str(const vector<string> vStr) {
    for(int i(0); i < vStr.size() - 1; i++) {
        if(vStr.at(i) > vStr.at(i+1)) return false;
    }
    return true;
}

// MAIN
int main() {
    try {
        // OBJEKTERSTELLUNG
        vec vectors;
        vector<int> vTmpInt;
        vector<string> vTmpStr;
        
        clock_t start = clock_t(-1);
        clock_t end = clock_t(-1);
        
        int iCount(0);
        
        cout << "Geben Sie die Anzahl der zu generierenden Elemente ein: ";
        cin >> iCount;
        
        if(!cin) error("Ungültige Option");
        
        // GENERATE
        vectors.generate_int(iCount);
        vectors.generate_str(iCount);
        cout << "Vektoren generiert." << endl;
        
        // SORTIEREN DURCH AUSWÄHLEN
        vTmpInt = vectors.get_int();
        vTmpStr = vectors.get_str();
        
        sel_int(vTmpInt, 0, vTmpInt.size() - 1);
        sel_str(vTmpStr, 0, vTmpStr.size() - 1);
        cout << "Vektoren sortiert durch Auswaehlen." << endl;
        if(check_int(vTmpInt)) {
            cout << "Int-Vektor korrekt sortiert." << endl;
        } else {
            cout << "Nicht korrekt sortiert." << endl;
        }
        if(check_str(vTmpStr)) {
            cout << "Str-Vektor korrekt sortiert." << endl;
        } else {
            cout << "Str-Vektor nicht korrekt sortiert" << endl;
        }
        
        // SORTIEREN DURCH EINFÜGEN 1
        vTmpInt = vectors.get_int();
        vTmpStr = vectors.get_str();
        
        ins_int_v1(vTmpInt, 0, vTmpInt.size() - 1);
        ins_str_v1(vTmpStr, 0, vTmpStr.size() - 1);
        cout << "Vektoren sortiert durch Einfuegen (V1)." << endl;
        
        if(check_int(vTmpInt)) {
            cout << "Int-Vektor korrekt sortiert." << endl;
        } else {
            cout << "Nicht korrekt sortiert." << endl;
        }
        if(check_str(vTmpStr)) {
            cout << "Str-Vektor korrekt sortiert." << endl;
        } else {
            cout << "Str-Vektor nicht korrekt sortiert" << endl;
        }
        
        // SORTIEREN DURCH EINFÜGEN 
        vTmpInt = vectors.get_int();
        vTmpStr = vectors.get_str();
        
        ins_int(vTmpInt, 0, vTmpInt.size() - 1);
        ins_str(vTmpStr, 0, vTmpStr.size() - 1);
        cout << "Vektoren sortiert durch Einfuegen." << endl;
        
        if(check_int(vTmpInt)) {
            cout << "Int-Vektor korrekt sortiert." << endl;
        } else {
            cout << "Nicht korrekt sortiert." << endl;
        }
        if(check_str(vTmpStr)) {
            cout << "Str-Vektor korrekt sortiert." << endl;
        } else {
            cout << "Str-Vektor nicht korrekt sortiert" << endl;
        }
        
        
        
        /*
        while (true) {
            switch (show_menu()) {
                case 0:
                {
                    // VEKTORGENERATOR
                    int iCount(0);
                    int iWhat(0);

                    cout << "Welcher Vektortyp?" << endl;
                    cout << "1. Int" << endl;
                    cout << "2. String" << endl;
                    cout << "Ihre Auswahl: ";
                    cin >> iWhat;
                    cout << endl;

                    cout << "Anzahl der zu generierenden Werte: ";
                    cin >> iCount;

                    switch (iWhat) {
                        case 1:
                            vectors.generate_int(iCount);
                            break;
                        case 2:
                            vectors.generate_str(iCount);
                            break;
                        default:
                            cout << "Ung\x81 \bltige Option" << endl;
                    }

                    cout << endl;
                    break;
                }
                case 1:
                {
                    if (vectors.are_both_empty(true)) break;
                    // AUSGABE
                    int iWhat(0);

                    cout << "Ausgabe welchen Vektors?" << endl;
                    cout << "1. Int" << endl;
                    cout << "2. String" << endl;
                    cout << "Ihre Auswahl: ";
                    cin >> iWhat;
                    cout << endl << endl;

                    switch (iWhat) {
                        case 1:
                            if (!vectors.is_int_empty()) {
                                vectors.print_int();
                                break;
                            } else break;
                        case 2:
                            if (!vectors.is_str_empty()) {
                                vectors.print_str();
                                break;
                            } else break;
                        default:
                            cout << "Ung\x81 \bltige Option" << endl;
                    }

                    cout << endl;
                    break;
                }
                case 2:
                {
                    if (vectors.are_both_empty(true)) break;

                    // SORTIEREN
                    int iWhat(0);
                    int iSort(0);

                    cout << "Sortierung welchen Vektors?" << endl;
                    cout << "1. Int" << endl;
                    cout << "2. String" << endl;
                    cout << "Ihre Auswahl: ";
                    cin >> iWhat;
                    cout << endl;

                    if (iWhat == 1 && vectors.is_int_empty()) break;
                    if (iWhat == 2 && vectors.is_str_empty()) break;

                    cout << "Welche Sortiermethode ?" << endl;
                    cout << "1. Sortieren durch Auswaehlen" << endl;
                    cout << "2. Sortieren durch Einfuegen" << endl;
                    cout << "3. Sortieren durch Einfuegen (v1)" << endl;
                    cout << "Ihre Auswahl: ";
                    cin >> iSort;
                    cout << endl;

                    start = clock();
                    if (start == clock_t(-1)) error("Fehler: keine Startzeit!\n");

                    //if(iSort < 1 || iSort > 2) error("Ung\x81ltige Option.");
                    if (iWhat == 1) {
                        // INT
                        temp = vectors.get_int();
                        if (iSort == 1) sel_int(temp, 0, temp.size() - 1);
                        if (iSort == 2) ins_int(temp, 0, temp.size() - 1);
                        if (iSort == 3) ins_int_v1(temp, 0, temp.size() - 1);
                        if (iSort == 4) rev_ins_int(temp, 0, temp.size() - 1);
                        vectors.set_int(temp);
                    }
                    if (iWhat == 2) {
                        // STRING
                        stemp = vectors.get_str();
                        if (iSort == 1) sel_str(stemp, 0, stemp.size() - 1);
                        if (iSort == 2) ins_str(stemp, 0, stemp.size() - 1);
                        if (iSort == 3) ins_str_v1(stemp, 0, stemp.size() - 1);
                        if (iSort == 4) rev_ins_str(stemp, 0, stemp.size() - 1);
                        vectors.set_str(stemp);
                    }

                    end = clock();
                    if (end == clock_t(-1)) error("Fehler: keine Endzeit!\n");

                    cout << "Sortierungdauer ";
                    cout << double( end - start) / CLOCKS_PER_SEC << " Sekunden";
                    cout << " (auf ca. 1/" << CLOCKS_PER_SEC << " Sekunde) genau";
                    
                    cout << endl;
                    break;
                }
                case 3: {
                    if (vectors.are_both_empty(true)) break;

                    // SORTIEREN
                    int iWhat(0);

                    cout << "Welcher Vektor soll \x81 \bberpr\x81 \bft werden?" << endl;
                    cout << "1. Int" << endl;
                    cout << "2. String" << endl;
                    cout << "Ihre Auswahl: ";
                    cin >> iWhat;
                    cout << endl;

                    if (iWhat == 1 && vectors.is_int_empty()) break;
                    if (iWhat == 2 && vectors.is_str_empty()) break;
                    
                    switch(iWhat) {
                        case 1: {
                            if(vectors.check_int()) {
                                cout << "Vektor ist korrekt sortiert." << endl;
                            } else {
                                cout << "Vektor ist nicht korrekt sortiert." << endl; 
                            }
                            break;
                        }
                        case 2: {
                            if(vectors.check_str()) {
                                cout << "Vektor ist korrekt sortiert." << endl;
                            } else {
                                cout << "Vektor ist nicht korrekt sortiert." << endl; 
                            }
                            break;
                        }
                        default: {
                            cout << "Ung\x81ltige Option." << endl;
                            break;
                        }
                    }
                    cout << endl << endl;
                    break;
                }
                case 4:
                {
                    return 0;
                }
                default:
                {
                    cout << "Bitte geben Sie eine g\x81ltige Option an!" << endl << endl;
                    break;
                }
            }
        }*/
    } catch (exception &e) {
        //error("Ausname: ", e.what());
        return -2;
    } catch (...) {
        error("Unbekannter Fehler");
        return -1;
    }
}