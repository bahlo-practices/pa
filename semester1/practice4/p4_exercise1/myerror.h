/* 
 * File:   myerror.h
 * Author: Tobias
 *
 * Created on 31. Oktober 2012, 10:42
 */

#ifndef MYERROR_H
#define	MYERROR_H
#include<iostream>
#include <stdexcept>
using std::string;
using std::runtime_error;
using namespace std;
void error (string s) {throw runtime_error(s);}
void error (string s1, string s2) {error (s1+s2);}
#endif	/* MYERROR_H */

