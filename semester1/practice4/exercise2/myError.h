/* 
 * File:   myError.h
 * Author: Johannes Wahl
 *
 * Created on 26. November 2012, 14:05
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



