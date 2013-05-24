/* 
 * File:   myVector.h
 *
 * Created on 13. Mai 2013, 17:03
 */

#ifndef MYVECTOR_H
#define	MYVECTOR_H

using namespace std;
#include <iostream>

class myVector {
private:
    int sz; // size
    double* elem; // Zeiger auf die Elemente
    int space; // size + weiterer Platz
public:
    myVector(); // Standardkonstruktor
    explicit myVector(int); // ein Konstruktor
    myVector(const myVector&); // Copy-Konstruktor
    myVector& operator=(const myVector&); // Zuweisungsoperator
    ~myVector(); // Destruktor
    double& operator[](int); // Indexoperator
    const double& operator[](int) const; // Indexoperator
    int size() const; // Anzahl Elemente
    virtual double get(int) const; // read
    virtual void set(int, double); // write
    void reserve(int);
    void push_back(double);
    void resize(int);

    int capacity() const;
};
#endif	/* MYVECTOR_H */

