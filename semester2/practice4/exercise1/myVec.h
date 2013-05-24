/* 
 * File:   myVec.h
 *
 * Created on 13. Mai 2013, 17:26
 */

#ifndef MYVEC_H
#define	MYVEC_H
#include "myVector.h"

class myVec : public myVector {
public:
    myVec();
    myVec(int low, int high);
    double& operator[](int i);
    const double& operator[](int) const; // Indexoperator
    int lo() const;
    int hi() const;
    void set(int, double);
    double get(int) const;


private:
    int lb;
};

#endif	/* MYVEC_H */

