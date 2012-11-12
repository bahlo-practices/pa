/* 
 * File:   myError.h
 * Author: Arne Leiblein, Johannes Wahl
 * Description: basic error handling for c++ applications
 * Created on 4. November 2012, 10:29
 */

#ifndef MY_ERROR_H
#define	MY_ERROR_H

#include <iostream>
#include <stdexcept>

using std::string;
using std::runtime_error;

void error( string s ) { throw runtime_error( s ); }
void error( string s1, string s2 ) { error( s1 + s2 ); }

#endif	/* MY_ERROR_H */


