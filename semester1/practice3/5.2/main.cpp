/* 
 * File:   main.cpp
 *
 * Created on 12. November 2012, 12:59
 */

#include <iostream>
#include <vector>
#include "Name_values.h"
#include "error.h"

using namespace std;



int main( ) {
    try {
        vector<int> v;
        vector<Name_values> weeks;
        weeks.push_back(Name_values("Montag", v));
        weeks.push_back(Name_values("Dienstag", v));
        weeks.push_back(Name_values("Mittwoch", v));
        weeks.push_back(Name_values("Donnerstag", v));
        weeks.push_back(Name_values("Freitag", v));
        weeks.push_back(Name_values("Samstag", v));
        weeks.push_back(Name_values("Sonntag", v));
        string day = "";
        int value = 0;

        while(true) {
                if( cin >> day ) {
                    if( day == "q") {
                        break;
                    }
                    if( cin >> value ) {
                        if( day == "Mo" || day == "Mon" || day == "mo" || day == "mon" || day == "Montag" || day == "montag" ) {
                            weeks.at(0).add_value(value);
                        }
                        if( day == "Di" || day == "Die" || day == "di" || day == "die" || day == "Dienstag" || day == "Dienstag" ) {
                            weeks.at(1).add_value(value);
                        }
                        if( day == "Mi" || day == "Mit" || day == "Mitt" || day == "mi" || day == "mit" || day == "mitt" || day == "Mittwoch" || day == "mittwoch" ) {
                            weeks.at(2).add_value(value);
                        }
                        if( day == "Do" || day == "Don" || day == "do" || day == "don" || day == "Donnerstag" || day == "Donnerstag" ) {
                            weeks.at(3).add_value(value);
                        }
                        if( day == "Fr" || day == "Fre" || day == "fr" || day == "fre" || day == "Freitag" || day == "Freitag" ) {
                            weeks.at(4).add_value(value);
                        }
                        if( day == "Sa" || day == "Sam" || day == "sa" || day == "sam" || day == "Samstag" || day == "samstag" ) {
                            weeks.at(5).add_value(value);
                        }
                        if( day == "So" || day == "Son" || day == "so" || day == "son" || day == "Sonntag" || day == "Sonntag" ) {
                            weeks.at(6).add_value(value);
                        }
                    }
                    else {
                        error( "Es wurde keine gueltige Tag, Wert Kombination eingegeben!\nAuf einen Tag muss immer eine Zahl folgen.\n");
                    }
                }
                else {
                    //error( "Kein gueltiger Wert eingegeben.");
                }
            }

                weeks.at(0).print_all();
                weeks.at(1).print_all();
                weeks.at(2).print_all();
                weeks.at(3).print_all();
                weeks.at(4).print_all();
                weeks.at(5).print_all();
                weeks.at(6).print_all();

        return 0;
    }
    catch( exception &e ) {
        cerr << "Ausnahme: " << e.what(); 
        return -2;
    }
    catch( ... ) { // Ausnahmen beliebigen Typs
        cerr << "Unbekannte Ausnahme";
        return -1;
    }
}

