/* 
 * Exercise 1
 * 
 * Created on 14. Dezember 2012, 08:54
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

void print_array10( ostream& os, int* a ){
    for (int i=0; i<10;i++){
        os<<a[i]<<endl;
    }
}

int main(int argc, char** argv) {
    //Aufgabe 1a)
    double* pointer = new double (9.8765); //Freigabe
    cout << "Adresse:\t" << pointer << endl;
    cout << "Inhalt:\t\t" << *pointer << endl;
    delete pointer; //Löschen
    //Überprüfung
    cout << "Adresse:\t" << pointer << endl;
    cout << "Inhalt:\t\t" << *pointer << endl;

    //Aufgabe 1b)
    int* ipdr (new int [10]);
    for (int i=0; i<10; i++){
        ipdr[i]=i;//Benennung des Speichers
        cout << setw(4) << ipdr[i];//Ausgabe des Speichers
        if(i==9) cout << endl;
    }
    delete[] ipdr;
    for (int i=0; i<10; i++){//Überprüfung
        cout<<setw(4)<<ipdr[i];//Ausgabe des Speichers
        if (i==9)cout<<endl;
    }
    
    //Aufgabe 1c) //Offenes Labor!!
    int f[11];
    f[0]=0; f[1]=1; f[2]=2; f[3]=3; f[4]=4; f[5]=5; f[6]=6; f[7]=7; 
    f[8]=8; f[9]=9;  
    print_array10(cout, f);
    
    return 0;
}

