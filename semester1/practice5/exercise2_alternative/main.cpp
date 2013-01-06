/* 
 * File:   main.cpp
 * Author: Johannes Wahl
 *
 * Created on 8. Dezember 2012, 14:05
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <ctime>
#include <iomanip>

using namespace std;

bool checkIntVec(vector<int> vec) {
    bool check = true;
    if (vec.size() > 0) {
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec.at(i) > vec.at(i + 1)) {
                check = false;
            }
        }
    }
    return check;
}

int binSearch(const vector<int> &vV, int x, int ui, int oi) {
    int mid(0);
    while (ui < oi) {
        mid = (ui + oi) / 2;
        if (vV[mid] == x)
            return mid;
        else if (vV[mid] > x)
            oi = mid - 1;
        else
            ui = mid + 1;
    }
    return -1;
}

int stringBinSearch(const vector<string> &vV, string x, int ui, int oi) {
    int mid(0);
    while (ui < oi) {
        mid = ((ui + oi) / 2);
        if (vV[mid] == x)
            return mid;
        else if (vV[mid] > x)
            oi = mid - 1;
        else
            ui = mid + 1;
    }
    return -1;
}

int seqSearch(const vector<int> &vV, int x, int li, int re) {
    for (int i = li; i < re; ++i)
        if (x == vV.at(i)) return i;
    return -1;
}

int stringSeqSearch(const vector<string> &vV, string x, int li, int re) {
    for (int i = li; i < re; ++i)
        if (x == vV.at(i)) return i;
    return -1;
}

int intSearch(const vector<int> &vV, int x, int ui, int oi) {
    int mid(0);
    if (!(checkIntVec(vV))) {
        cerr<<"Die Werte im Vektor sind nicht sortiert!";

    }
    while (ui <= oi) {
        mid = ui + ((x - vV.at(ui)) / vV.at(oi) - vV.at(ui))*(oi - ui);
        if (x == vV[mid]) {
            return mid;
        }
        if (x < vV[mid]) {
            oi = mid - 1;
        } else ui = mid + 1;
    }
    return -1;
}

int generateRandomInt() {
    int num = (rand() % 100) + 1;
    return num;
}

void printVectorInt(const vector<int> &vV) {
    int length = vV.size();
    for (int i = 0; i < length; i++) {
        cout << "\nWert an Stelle: " << i << " ist: " << vV.at(i);

    }
}

void printVectorString(const vector<string> &vV) {
    int length = vV.size();
    for (int i = 0; i < length; i++) {
        cout << "\nWert an Stelle: " << i << " ist: " << vV.at(i);

    }
}

void generateRandomString(vector<string> &vV, int iCount) {

    vector<string> tmp;
    vV = tmp; // clear vector
    string sWord = "";
    string sCharset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";

    for (int i(0); i < iCount; i++) {
        sWord = "";
        for (int j(0); j < (rand() % 15) + 1; j++) {
            sWord = sWord + sCharset[rand() % (sCharset.size() - 1)];
        }
        vV.push_back(sWord);
    }
}

int main() {

    try {
        srand(time(0)); //Generate random number set
        int anzahl(0);
        int iSearch(0);
        int result(0);
        int length(0);
        string sSearch(" ");
        double time1 = 0.0, sint;
        double time2 = 0.0, bint;
        
        vector<int> iValues;
        vector<string> sValues;

        cout << "\nWieviele Elemente sollen im Vector erstellt werden?: ";
        cin >> anzahl;
        if(!cin){cerr<<"Fehler in der Eingabe.";return -1;}

        for (int i = 0; i < anzahl; i++) {
            iValues.push_back(generateRandomInt());
            cout << setw(4) << iValues.at(i) << " ";
            if ((i % 10) == 0) cout << endl;
        }


        cout << "\nNach welchem Wert moechten Sie mit der sequenziellen Suche suchen?";
        try {
            cin >> iSearch;
            length = iValues.size();
            sint = clock();
            result = seqSearch(iValues, iSearch, 0, length);
            time1 += clock() - sint;
            cout << "\nErgebnis: " << result;
        } catch (exception &e) {
            cout << "\nUngueltiger Wert.";
        }


        cout << "\nNach welchem Wert moechten Sie mit der binaeren Suche suchen?";
        sort(iValues.begin(), iValues.end());
        try {
            cin >> iSearch;
            bint = clock();
            length = iValues.size();
            time2 += clock() - bint;
            result = binSearch(iValues, iSearch, 0, length);
            cout << "\nErgebnis: " << result;
        } catch (exception &e) {
            cout << "\nWert nicht gefunden.";
        }


        cout << "\nWieviele Elemente moechten Sie im string Vector erstellen?";
        cin >> anzahl;
        if(!cin){ cerr<<"Fehler in der Eingabe"; return -1;}
        generateRandomString(sValues, anzahl);
        for (int i = 0; i < anzahl; i++) {
            cout << setw(10) << sValues.at(i) << " ";
            if ((i % 10) == 0) cout << endl;
        }

        cout << "\nNach welchem string moechten Sie mit der sequenziellen Suche suchen? :";
        try {
            cin >> sSearch;
            length = sValues.size();
            result = stringSeqSearch(sValues, sSearch, 0, length);
            cout << "\nErgebnis: " << result;
        } catch (exception &e) {
            cout << "\nWert nicht gefunden";
        }

        cout << "\nNach welchem string moechten Sie mit der binaeren Suche suchen? :";
        try {
            cin >> sSearch;
            length = sValues.size();
            result = stringBinSearch(sValues, sSearch, 0, length);
            cout << "\nErgebnis: " << result;
        } catch (exception &e) {
            cout << "\nWert nicht gefunden";
        }
        

        
        time1 = time1 / CLOCKS_PER_SEC;

        cout << "\nErgebnis der Laufzeitmessung:  " << time1 << "\n";

        return 0;
    } catch (exception &e) {
        cerr << e.what();
    } catch (...) {
        cerr << "Unbekannter Fehler!";
    }
}



