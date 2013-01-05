/* 
 * Exercise 3
 * 
 * Created on 14. Dezember 2012, 11:22
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Praktikum 6_ Aufgabe 3
 * Heap und Stack speicher!
 */
int main(int argc, char** argv) {
    //Heap mit new
    //Sonst Stack


    //Heap
    cout << "Heap:\n";
    double* hallo = new double();
    double* hallo2(new double);
    double* hallo3(new double);
    double* hallo4(new double);
    double* hallo5(new double);

    cout << "Adresse 1: " << hallo << endl;
    cout << "Adresse 2: " << hallo2 << endl;
    cout << "Adresse 3: " << hallo3 << endl;
    cout << "Adresse 4: " << hallo4 << endl;
    cout << "Adresse 5: " << hallo5 << endl;
    cout << "Heap-Speicher wächst nach oben!\n";
    /*Heap-Adressen Aufsteigend=>wächst
     *Stack und Heap wachsen aufeinander zu
     * =>Stack wächst nach unten 
     */

    //Stack
    cout << "\nStack:\n";
    int a[3] = {2, 3, 4};
    int b[3] = {2, 3, 4};
    int c[3] = {2, 3, 4};
    int d[3] = {2, 3, 4};
    int e[3] = {2, 3, 4};
    cout << "Adresse a: " << &a << endl;
    cout << "Adresse b: " << &b << endl;
    cout << "Adresse c: " << &c << endl;
    cout << "Adresse d: " << &d << endl;
    cout << "Adresse e: " << &e << endl;
    cout << "Stack-Speicher wächst nach unten!\n\n";
    return 0;
}

