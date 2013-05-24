/* 
 * File:   myVector.h
 *
 * Created on 15. Mai 2013, 16:20
 */

#ifndef MYVECTOR_H
#define	MYVECTOR_H

#include <iostream>
#include <math.h>
#include <stdexcept>

template <class T>
class myVector {
private:
    int sz; // size
    T* elem; // Zeiger auf die Elemente
    int space; // size + weiterer Platz
public:
    myVector(); // Standardkonstruktor
    explicit myVector(int, T); // ein Konstruktor
    myVector(const myVector<T>&); // Copy-Konstruktor
    myVector& operator=(const myVector<T>&); // Zuweisungsoperator
    virtual ~myVector(); // Destruktor
    
    T& operator[](int); // Indexoperator
    const T& operator[](int) const; // Indexoperator
    int size() const; // Anzahl Elemente
    virtual T get(int) const; // read
    virtual void set(int, T); // write
    void reserve(int);
    void push_back(T);
    void resize(int, T);

    int capacity() const;
};


template <class T> myVector<T>::myVector() : sz(0), elem(0), space(0) {
    
}
template <class T> myVector<T>::myVector(int s, T def=T()) : sz(s) {
    int tmp = 2 * s;
    elem = new T[tmp];
    space = tmp;
    for (int i = 0; i < s; ++i) elem[i] = def;
    
     std::cout << "TEST2" << std::endl;


}

template <class T> myVector<T>::myVector(const myVector<T>& a)
: sz(a.size()), elem(new T [a.size()]), space(a.size()) { // Copy-Konstruktor
    for (int i(0); i < a.size(); i++) {
        elem[i] = a.get(i);
    }
     std::cout << "TEST-KOPIE" << std::endl;
}

template <class T> myVector<T>::~myVector() {
    delete[] elem;
    elem = 0;
}

template <class T>
void myVector<T>::reserve(int newspace) {
    
    if (newspace <= space) return; // nie weniger Platz holen
    T* p = new T[newspace]; // mit new Speicher allokieren
    for (int i = 0; i < sz; ++i) p[i] = elem[i]; // Elemente kopieren
    delete[] elem; // alten Speicher freigeben
    elem = p; // Zeiger umhaengen
    space = newspace; // Platz korrekt setzen
}

template <class T>
void myVector<T>::push_back(T d) {
    if (space == 0) // Erstes Element
        reserve(8); // Platz aus dem Heap holen
    else
        if (sz == space) // Kein Platz mehr?
        reserve(space * 2); // Aus dem Heap holen
    elem[sz] = d; // Jetzt d anhaengen…
    sz++; // …und den Elementezaehler erhoehen
}

template <class T>
void myVector<T>::resize(int newsize, T def=T()) {
    reserve(newsize); // Speicher im Heap reservieren
    for (int i = sz; i < newsize; ++i) // Initialisierung der
        elem[i] = def; // zusaetzlichen Elemente
    sz = newsize;
}

template <class T>
T& myVector<T>::operator[](int index) {
    if (index < 0 || sz <= index) {
        //cout << "myVector::operator[](), bad index";
        throw std::out_of_range("myVector::operator[](), bad index");
    }
    return elem[index];
};

template <class T>
const T& myVector<T>::operator [](int index) const {
    if (index < 0 || sz <= index) {
        //cout << "myVector::operator[](), bad index";
        throw std::out_of_range("myVector::operator[](), bad index");
    }
    return elem[index];
}

template <class T>
int myVector<T>::size() const {
    return sz;
}

template <class T>
int myVector<T>::capacity() const {
    return space;
}

template <class T>
myVector<T>& myVector<T>::operator=(const myVector& a) {
    if (this == &a) return *this;
    if (a.sz <= space) { // genug Platz, d.h. keine weitere Allokation
        for (int i = 0; i < a.sz; ++i)
            elem[i] = a.elem[i]; // Elemente kopieren
        // Bem.: die beiden myVector Objekte sind
        // bzgl. space nicht mehr unbedingt identisch
        sz = a.sz;
        return *this;
    }
    T* p = new T[a.sz]; // copy & swap, Platz aus dem Heap holen
    for (int i = 0; i < a.sz; ++i)
        p[i] = a.elem[i]; // Elemente kopieren
    delete[] elem; // alten Speicherplatz feigeben
    elem = p; // Zeiger umhaengen
    space = sz = a.sz; // Groesse richtig setzen
    return *this; // die (eigene) Adresse zurueckgeben
}

template<class T>
T myVector<T>::get(int a) const {
    if (a < 0 || sz <= a) {
        throw std::out_of_range("myVector::operator[](), bad index");
    }
    return elem[a];
}

template <class T>
void myVector<T>::set(int a, T e) {
    if (a < 0 || sz <= a) {
        throw std::out_of_range("myVector::operator[](), bad index");
    }
    elem[a] = e;
}
#endif	/* MYVECTOR_H */

