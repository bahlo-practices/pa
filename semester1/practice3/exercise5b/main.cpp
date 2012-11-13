/*  _____ _     
 * | ____| |    
 * | |__ | |__  
 * |___ \| '_ \ 
 *  ___) | |_) |
 * |____/|_.__/ 
 *
 * Created on 11. November 2012, 11:43
 * 
 * Liest Wochentag mit zugehörigen Werten ein und speichert sie in einem Vector
 * 
 */

#include <iostream>
#include <vector>
#include "Name_values.h"
#include "myError.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;


int main( ) {
    try {
        vector<int> v; // Leerer vector, um die einzelnen Wochentage zu füllen
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
                        if( day == "Mo" || day == "Mon" || day == "Montag") {
                            weeks.at(0).add_value(value);
                        }
                        if( day == "Di" || day == "Die" || day == "Dienstag") {
                            weeks.at(1).add_value(value);
                        }
                        if( day == "Mi" || day == "Mit" || day == "Mittwoch") {
                            weeks.at(2).add_value(value);
                        }
                        if( day == "Do" || day == "Don" || day == "Donnerstag") {
                            weeks.at(3).add_value(value);
                        }
                        if( day == "Fr" || day == "Fre" || day == "Freitag") {
                            weeks.at(4).add_value(value);
                        }
                        if( day == "Sa" || day == "Sam" || day == "Samstag") {
                            weeks.at(5).add_value(value);
                        }
                        if( day == "So" || day == "Son" || day == "Sonntag") {
                            weeks.at(6).add_value(value);
                        }
                    }
                    else {
                        error( "Sie haben entweder keinen g\x81ltigen Tag oder keinen g\x81ltigen Wert eingegeben!\nGebene Sie einen Tag und einen zugeh\x94rigen Wert getrennt durch ein Leerzeichen ein.\n");
                    }
                }
                else {
                    //error( "Kein g\x81ltiger Wert eingegeben.");
                }
            }

        
            // Alles ausgeben
            for(int i = 0;i < weeks.size();i++) {
                weeks.at(i).print_all();
            }
            cout << endl << endl;
            
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

