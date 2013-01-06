/* 
 * Exercise 4
 * 
 * Created on 14. Dezember 2012, 14:29
 */

#include <cstdlib>
#include <iostream>
#include "DoLL.h"

using namespace std;



int main() {
    char menu (' ');
    string anfang (" ");
    cout<<"Bitte geben Sie einen Anfangswert(Zeichenkette) für Ihre doppelt-"
            "verlinkte-Liste ein > ";
    //cin>>anfang;
    anfang = "Eins";
    DoLL liste (anfang, NULL, NULL);
    DoLL::printall(&liste);
    cout<<endl;
    liste.ablegen("Zwei");
    liste.ablegen ("Drei");
    liste.ablegen ("Vier");
    liste.ablegen ("Fünf");
    liste.ablegen ("Sechs");
    liste.ablegen ("Sieben");
    liste.ablegen ("Acht");
    DoLL::printall(&liste);
    cout<<endl;
    DoLL::print_item(&liste);
    cout<<endl;
    liste.letztes_Elem();
    DoLL::print_item(&liste);
    cout<<endl;
    
    
//    cout<<"Bitte wählen Sie ein Menü:\n";
//    cout<<"Für das Navigationsmenü 1 drücken, für das Funktionsmenü die 2.\n"
//            "Bestätigen mit Enter";
//    cin>>menu;
//    switch (menu) {
//            case '1' :
//                liste.navi();
//            break;
//        case '2': 
//            liste.functions();
//            break;
//
//    }
    return 0;
}

//    DoLL hi;
//    DoLL liste1("Test0", NULL, NULL);
//    liste1.ablegen("Test1");
//    liste1.ablegen("Test2");
//    liste1.ablegen("Test3");
//    liste1.ablegen("Test4");
//    liste1.ablegen("Test5");
//    liste1.ablegen("Test6");
//    liste1.ablegen("Test7");
//    liste1.ablegen("Test8");
//    DoLL::printall(&liste1);
//    liste1.entnehmen();
//    liste1.entnehmen();
//    liste1.entnehmen();
//    DoLL::printall(&liste1);
//    