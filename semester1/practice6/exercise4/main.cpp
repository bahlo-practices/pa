/* 
 * Exercise 4
 * 
 * Created on 14. Dezember 2012, 14:29
 */

#include <cstdlib>
#include <iostream>
#include "DoLL.h"
#include <stdexcept>

using namespace std;

void menuetext() {
    cout << "Bitte waehlen Sie eine Option:" << endl;
    cout << "(1) Alles ausgeben" << endl;
    cout << "(2) vorne auf Stapel ablegen" << endl;
    cout << "(3) hinten auf Stapel ablegen" << endl;
    cout << "(4) Element vorne vom Stapel nehmen" << endl;
    cout << "(5) Element hinten vom Stapel nehmen" << endl;
    cout << "Druecken Sie q zum beenden oder ? fuer Hilfe." << endl;
}

int main() {

    try {
        //initialise first object
        bool loop = true;
        string initialise = "0";
        cout << "Bitte erstellen Sie ein initialies Objekt fuer die DoLL:" << endl;
        cin >> initialise;
        DoLL liste(initialise, NULL, NULL);


        char cMenue = 'c';
        menuetext();
        while (loop != false) {

            cin >> cMenue;

            switch (cMenue) {
                case '1': DoLL::printall(&liste);
                    break;
                case '2': cin >> initialise;
                    liste.push_front(initialise);
                    break;
                case '3': cin >> initialise;
                    liste.ablegen(initialise);
                    break;
                case '4': liste.pop_front();
                    break;
                case '5': liste.entnehmen();
                    break;
                case 'q': loop = false;
                    break;
                case '?': menuetext();
                    break;
                default: cout << "Keine gueltige Eingabe";
                    break;
            }
        }
    } catch (exception& e) {
        cerr << e.what();
        return -2;
    }    catch (...) {
        cerr << "Unbekannter Fehler";
        return -1;
    }
    return 0;
}

