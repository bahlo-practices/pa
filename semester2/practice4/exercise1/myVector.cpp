/* 
 * File:   myVector.cpp
 * 
 * Created on 13. Mai 2013, 17:03
 */
#include "myVector.h"

#include <math.h>
#include <stdexcept>

myVector::myVector() : sz(0), elem(0), space(0) {
}

myVector::myVector(int s) : sz(s) {
    int tmp = 2 * s;
     elem = new double[tmp];
    space =tmp;
    for (int i = 0; i < s; ++i) elem[i] = 0.0;
  
    
}

myVector::myVector(const myVector& a)
: sz(a.size()), elem(new double [a.size()]) , space(a.capacity()){ // Copy-Konstruktor
    for (int i(0); i < a.size(); i++ ){
        elem[i] = a.get(i);
    }
}

myVector::~myVector() {
    delete[] elem;
    elem = 0;
}

void myVector::reserve(int newspace) {
    if (newspace <= space) return; // nie weniger Platz holen
    double* p = new double[newspace]; // mit new Speicher allokieren
    for (int i = 0; i < sz; ++i) p[i] = elem[i]; // Elemente kopieren
    delete[] elem; // alten Speicher freigeben
    elem = p; // Zeiger umhaengen
    space = newspace; // Platz korrekt setzen
}

void myVector::push_back(double d) {
    if (space == 0) // Erstes Element
        reserve(8); // Platz aus dem Heap holen
    else
        if (sz == space) // Kein Platz mehr?
        reserve(space * 2); // Aus dem Heap holen
    elem[sz]=d; // Jetzt d anhaengen…
    sz++; // …und den Elementezaehler erhoehen
}

void myVector::resize(int newsize) {
    reserve(newsize); // Speicher im Heap reservieren
    for (int i = sz; i < newsize; ++i) // Initialisierung der
        elem[i] = double(); // zusaetzlichen Elemente
    sz = newsize;
}

double& myVector::operator[](int index) {
    if (index < 0 || sz <= index) {
        //cout << "myVector::operator[](), bad index";
        throw std::out_of_range("myVector::operator[](), bad index");
    }
    return elem[index];
};

const double& myVector::operator [](int index) const{
     if (index < 0 || sz <= index) {
        //cout << "myVector::operator[](), bad index";
        throw std::out_of_range("myVector::operator[](), bad index");
    }
    return elem[index];   
}

int myVector::size() const {
    return sz;
}

int myVector::capacity() const {
    return space;
}

myVector& myVector::operator=(const myVector& a) {
    if (this == &a) return *this;
    if (a.sz <= space) { // genug Platz, d.h. keine weitere Allokation
        for (int i = 0; i < a.sz; ++i)
            elem[i] = a.elem[i]; // Elemente kopieren
        // Bem.: die beiden myVector Objekte sind
        // bzgl. space nicht mehr unbedingt identisch
        sz = a.sz;
        return *this;
    }
    double* p = new double[a.sz]; // copy & swap, Platz aus dem Heap holen
    for (int i = 0; i < a.sz; ++i)
        p[i] = a.elem[i]; // Elemente kopieren
    delete[] elem; // alten Speicherplatz feigeben
    elem = p; // Zeiger umhaengen
    space = sz = a.sz; // Groesse richtig setzen
    return *this; // die (eigene) Adresse zurueckgeben
}

double myVector::get(int a) const {
    if (a < 0 || sz <= a) {
        throw std::out_of_range("myVector::operator[](), bad index");
    }
    return elem[a];
}

void myVector::set(int a, double e) {
    if (a < 0 || sz <= a) {
        throw std::out_of_range("myVector::operator[](), bad index");
    }
    elem[a] = e;
}