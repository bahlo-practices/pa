/* 
 * Created on 27. November 2012, 09:01
 */

#ifndef ERROR_H
#define	ERROR_H

#include <iostream>
#include <stdexcept>

using std::string;
using std::runtime_error;
using std::out_of_range;

void error(string s) { throw runtime_error( s ); }
void error(string s1, string s2) { error( s1 + s2 ); }


#endif	/* ERROR_H */
