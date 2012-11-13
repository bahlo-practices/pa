/* 
 * File:   error.h
 * Author: Yannik
 *
 * Created on 12. November 2012, 16:16
 */

#ifndef ERROR_H
#define	ERROR_H

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

