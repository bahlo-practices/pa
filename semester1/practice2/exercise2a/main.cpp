/*    _                         _                         
 *   (_)                       | |                        
 *    _  ___    _   _ _ __   __| |   __ _ _ __ _ __   ___ 
 *   | |/ _ \  | | | | '_ \ / _` |  / _` | '__| '_ \ / _ \
 *   | | (_) | | |_| | | | | (_| | | (_| | |  | | | |  __/
 *   | |\___/   \__,_|_| |_|\__,_|  \__,_|_|  |_| |_|\___|
 *  _/ |                                                  
 * |__/                                                   
 * 
 * Created on 17. Oktober 2012, 09:22
 * 
 * Beschreibung: berechnet den ggT und die anzahl der benötigten schritte;
 * am ende der berechnung wird der benutzer gefragt, ob er das programm erneut
 * ausführen möchte
 * 
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

    int i1 = 0, i2 = 0, tmp = 0, n = 1;
    bool decision=false;
    char erneut='a';

    do{
        cout << "Zwei positive ganze Zahlen eingeben: ";
        cin >> i1 >> i2;

        while( i1 != i2 ){
        cout << "\t(" << i1 << "," << i2 << ")" << endl;

        if( i1 < i2 ) i2 = i2-i1;
        else { tmp = i1; i1 = i2; i2 = tmp-i1; }

        ++n;
       }

         cout << "\t(" << i1 << "," << i2 << ")" << endl;
         cout << n << " Schritte zum ggT\n" << endl;
         cout <<"\t M\x94 \bchten Sie das Programm erneut ausf\x81hren (y)es/(q)uit?";
         cin >> erneut;
         cout << endl;
         if( erneut == 'y' ){
             decision = true;
             n=1;
         }else { decision = false; }

    }
    while(decision!=false);
    return 0;
}