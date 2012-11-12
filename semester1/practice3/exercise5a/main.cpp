/* 
 * File:   main.cpp
 * Author: Arne Leiblein & Johannes Wahl
 *
 * Created on 11. November 2012, 10:29
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "myError.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::istringstream;
using std::endl;
using std::getline;
using std::stringstream;
using std::cerr;

int main() {
    try {

        vector<int>Montag;vector<int>Dienstag;vector<int>Mittwoch;
        vector<int>Donnerstag;vector<int>Freitag;vector<int>Samstag;
        vector<int>Sonntag;vector<string>allValues;
        
        stringstream convertstod;
        string sTemp = "";       
        bool run = true;
        string buf = "";
        int iTemp = 0;
        int counter = 0;
        int invalidinput = 0;
        int iMcommon = 0;
        int iDcommon = 0;
        int iMicommon = 0;
        int iDocommon = 0;
        int iFcommon = 0;
        int iSacommon = 0;
        int iSocommon = 0;

        cout << "Geben Sie Tag/Wertpaar Kombinationen ein: ";

        //input
        while (run) {
            getline(cin, sTemp);
            if (sTemp == "q") {
                run = false;
            }
            istringstream iss(sTemp);
            while (iss >> buf) {
                allValues.push_back(buf);
                invalidinput++;
            }
        }

        //put data from allValues to specific vector
        run = true;
        while (run) {
            for (int i = 0; i < allValues.size(); i++) {
                if (allValues.at(i) == "Montag" || allValues.at(i) == "Mo") {
                    i++;
                    sTemp = allValues.at(i);
                    convertstod << sTemp;
                    convertstod >> iTemp;
                    Montag.push_back(iTemp);
                    convertstod.clear();
                    counter++;
                }
                if (allValues.at(i) == "Dienstag" || allValues.at(i) == "Di") {
                    i++;
                    sTemp = allValues.at(i);
                    convertstod << sTemp;
                    convertstod >> iTemp;
                    Dienstag.push_back(iTemp);
                    convertstod.clear();
                    counter++;
                }
                if (allValues.at(i) == "Mittwoch" || allValues.at(i) == "Mi") {
                    i++;
                    sTemp = allValues.at(i);
                    convertstod << sTemp;
                    convertstod >> iTemp;
                    Mittwoch.push_back(iTemp);
                    convertstod.clear();
                    counter++;
                }
                if (allValues.at(i) == "Donnerstag" || allValues.at(i) == "Don") {
                    i++;
                    sTemp = allValues.at(i);
                    convertstod << sTemp;
                    convertstod >> iTemp;
                    Donnerstag.push_back(iTemp);
                    convertstod.clear();
                    counter++;
                }
                if (allValues.at(i) == "Freitag" || allValues.at(i) == "Fr") {
                    i++;
                    sTemp = allValues.at(i);
                    convertstod << sTemp;
                    convertstod >> iTemp;
                    Freitag.push_back(iTemp);
                    convertstod.clear();
                    counter++;
                }
                if (allValues.at(i) == "Samstag" || allValues.at(i) == "Sa") {
                    i++;
                    sTemp = allValues.at(i);
                    convertstod << sTemp;
                    convertstod >> iTemp;
                    Samstag.push_back(iTemp);
                    convertstod.clear();
                    counter++;
                }
                if (allValues.at(i) == "Sonntag" || allValues.at(i) == "So") {
                    i++;
                    sTemp = allValues.at(i);
                    convertstod << sTemp;
                    convertstod >> iTemp;
                    Sonntag.push_back(iTemp);
                    convertstod.clear();
                    counter++;
                }
                if (allValues.at(i) == "q") {
                    run = false;
                }
            }
        }

        //output 
        for (int i = 0; i < Montag.size(); i++) {
            cout << "Montag(" << i << "), Wert:" << Montag.at(i) << endl;
            iMcommon = iMcommon + Montag.at(i);
        }
        if (iMcommon > 0) cout << "Durchschnitt der Werte in Montag: " << (double) iMcommon / Montag.size() << endl;

        for (int i = 0; i < Dienstag.size(); i++) {
            cout << "Dienstag(" << i << "), Wert:" << Dienstag.at(i) << endl;
            iDcommon = iDcommon + Dienstag.at(i);
        }
        if (iDcommon > 0) cout << "Durchschnitt der Werte in Dienstag: " << (double) iDcommon / Dienstag.size() << endl;

        for (int i = 0; i < Mittwoch.size(); i++) {
            cout << "Mittwoch(" << i << "), Wert:" << Mittwoch.at(i) << endl;
            iMicommon = iMicommon + Mittwoch.at(i);
        }
        if (iMicommon > 0)cout << "Durchschnitt der Werte in Mittwoch: " << (double) iMicommon / Mittwoch.size() << endl;

        for (int i = 0; i < Donnerstag.size(); i++) {
            cout << "Donnerstag(" << i << "), Wert:" << Donnerstag.at(i) << endl;
            iDocommon = iDocommon + Donnerstag.at(i);
        }
        if (iDocommon > 0) cout << "Durchschnitt der Werte in Donnerstag: " << (double) iDocommon / Donnerstag.size() << endl;

        for (int i = 0; i < Freitag.size(); i++) {
            cout << "Freitag(" << i << "), Wert:" << Freitag.at(i) << endl;
            iFcommon = iFcommon + Freitag.at(i);
        }
        if (iFcommon > 0) cout << "Durchschnitt der Werte in Freitag: " << (double) iFcommon / Freitag.size() << endl;

        for (int i = 0; i < Samstag.size(); i++) {
            cout << "Samstag(" << i << "), Wert:" << Samstag.at(i) << endl;
            iSacommon = iSacommon + Samstag.at(i);
        }
        if (iSacommon > 0)cout << "Durchschnitt der Werte in Samstag: " << (double) iSacommon / Samstag.size() << endl;

        for (int i = 0; i < Sonntag.size(); i++) {
            cout << "Sonntag(" << i << "), Wert:" << Sonntag.at(i) << endl;
            iSocommon = iSocommon + Sonntag.at(i);
        }
        if (iSocommon > 0)cout << "Durchschnitt der Werte in Sonntag: " << (double) iSocommon / Sonntag.size() << endl;

        invalidinput--;
        invalidinput = invalidinput / 2;
        invalidinput = invalidinput - counter;
        if (invalidinput > 0) {
            cout << "Anzahl ignorierter Wertpaare aufgrund von Falscheingabe: " << invalidinput << endl;
        } else {
            cout << "Es liegen keine ungueligen Eingaben von Wertpaaren vor!" << endl;
        }

        return 0;

    } catch (runtime_error& e) {
        cerr << e.what();
        return -3;
    } catch (out_of_range& e) {
        cerr << endl << "Fehler: Ungueltiger Bereich im Vector!!." << endl;
        return -2;
    } catch (...) {
        cerr << endl << "Unbekannter Fehler!" << endl;
        return -1;
    }
}



