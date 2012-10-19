/*
 *                                         | |   (_)      
 *   __ _ _ __ _ __   ___   _   _ _ __   __| |    _  ___  
 *  / _` | '__| '_ \ / _ \ | | | | '_ \ / _` |   | |/ _ \ 
 * | (_| | |  | | | |  __/ | |_| | | | | (_| |   | | (_) |
 *  \__,_|_|  |_| |_|\___|  \__,_|_| |_|\__,_|   | |\___/ 
 *                                              _/ |       
 *                                             |__/    
 *
 * Created on 12. Oktober 2012, 21:17
 * 
 * Gibt die vorgegebenen Sätze auf der Konsole aus
 */

#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main() {
    
    cout << "Umlaut: \x84 \x94 \x81 \x8E \x99 \x9A";
    cout << "\nsz-Ligatur: \xE1";
    cout << "\nTrema: \x89 \x8B";
    cout << "\nRoy sagt \"Sch\x94n ist es, auf der Welt zu sein,\nwenn die Sonne scheint f\x81r Gro\xE1 und Klein\".";
    cout << "\nOberfl\x84 \bchlich\n";
    
    return 0;
}
