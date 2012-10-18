/* 
 *  .d8b.  d8888b. d8b   db d88888b 
 * d8' `8b 88  `8D 888o  88 88'     
 * 88ooo88 88oobY' 88V8o 88 88ooooo 
 * 88~~~88 88`8b   88 V8o88 88~~~~~ 
 * 88   88 88 `88. 88  V888 88.     
 * YP   YP 88   YD VP   V8P Y88888P 
 *
 * Created on 12. Oktober 2012, 21:17
 * 
 *  Gibt die vorgegebenen Sätze auf der Konsole aus
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