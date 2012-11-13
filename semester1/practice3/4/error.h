/* 
 * File:   error.h
 *
 * Created on 10. November 2012, 22:49
 */

#ifndef ERROR_H
#define	ERROR_H

#include <iostream>
#include <stdexcept>
using std::string;
using std::runtime_error;
void error(string s) {
    throw runtime_error( s );
}
void error(string s1, string s2) {
    error(s1 + s2);
}

#endif	/* ERROR_H */

