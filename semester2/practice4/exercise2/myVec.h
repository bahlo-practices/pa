/* 
 * File:   myVec.h
 *
 * Created on 23. Mai 2013, 14:17
 */

#include "myVector.h"

#ifndef MYVEC_H
#define	MYVEC_H

template<class T> 
class myVec : public myVector<T>{
    
    public:
    myVec();
    myVec(int low, int high);
    T& operator[](int i);
    const T& operator[](int) const; // Indexoperator
    int lo() const;
    int hi() const;
    void set(int, T);
    T get(int) const;
    


private:
    int lb;
    
    
};

template <class T> myVec<T>::myVec(): myVector <T>(), lb(0) {
}

template <class T> myVec<T>::myVec(int low, int high) : myVector<T>( high - low + 1), lb(low) {
}

template <class T> 
 int myVec <T>::lo() const {
    return lb;
}

template <class T>
 int myVec <T>::hi() const {
    return lb + myVector <T>::size() - 1;
}

template <class T>
 T& myVec <T>::operator[](int i) {
    return myVector <T>::operator[](i - lb);
}

template <class T>
 const T& myVec <T>::operator [](int index) const {
    if (index < 0 || myVector <T>::size() <= index) {
        //cout << "myVector::operator[](), bad index";
        throw std::out_of_range("myVector::operator[](), bad index");
    }
    return myVector <T>::operator[](index - lb);
}

 template <class T>
 T myVec <T>::get(int index)const {
    T fu = myVector<T>::get(index - lb);
    return fu;
}

template <class T>
 void myVec <T>::set(int index, T d) {
    myVector<T>::set(index - lb, d);
}

#endif	/* MYVEC_H */

