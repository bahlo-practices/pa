/*
 * 2 
 *
 * Created on 8. Dezember 2012, 14:05
 * 
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <ctime>

using namespace std;

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

int seqSearch(const vector<int> &vV, int x, int li, int re) {
    for (int i = li; i <= re; ++i)
        if (x == vV.at(i)) return i;
    return -1;
}

int stringSeqSearch(const vector<string> &vV, string x, int li, int re) {
    for (int i = li; i <= re; ++i)
        if (x == vV.at(i)) return i;
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

void generateRandomString(vector<string> &vV) {

    char target = 'a';
    string builder;

    for (int i = 0; i < 5; i++) {
        int num = (rand() % 100) + 1;
        target = num;
        builder = builder + target;
        //cout<<"debug builder: "<<builder;
    }
    vV.push_back(builder);
    builder.clear();
}

int main() {

    try {
        srand(time(NULL)); //Generate random number set  
        int anzahl(0);
        int iSearch(0);
        int result(0);
        int length(0);
        string sSearch(" ");
        double time1=0.0, tstart;
        tstart = clock();  

        vector<int> iValues;
        vector<string> sValues;

        cout << "\nWieviele Elemente sollen im Vector erstellt werden?: ";
        cin >> anzahl;

        for (int i = 0; i < anzahl; i++) {
            iValues.push_back(generateRandomInt());
        }


        cout << "\nNach welchem Wert moechten Sie mit der sequenziellen Suche suchen?";
        try {
            cin >> iSearch;
            length = iValues.size();
            result = seqSearch(iValues, iSearch, 0, length);
            cout << "\nErgebnis: " << result;
        } catch (exception &e) {
            cout << "\nWert nicht gefunden.";
        }


        cout << "\nNach welchem Wert moechten Sie mit der binaeren Suche suchen?";
        sort(iValues.begin(), iValues.end());
        try {
            cin >> iSearch;
            length = iValues.size();
            result = binSearch(iValues, iSearch, 0, length);
            cout << "\nErgebnis: " << result;
        } catch (exception &e) {
            cout << "\nWert nicht gefunden.";
        }


        cout << "\nWieviele Elemente moechten Sie im string Vector erstellen?";
        cin >> anzahl;
        for (int i = 0; i < anzahl; i++) {
            generateRandomString(sValues);
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

        time1 += clock() - tstart;  
        time1 = time1/CLOCKS_PER_SEC;
        
        cout<<"\nErgebnis der Laufzeitmessung: "<<time1;
        
        return 0;
    }    catch (exception &e) {
        cerr << e.what();
    }    catch (...) {
        cerr << "Unbekannter Fehler!";
    }
}


