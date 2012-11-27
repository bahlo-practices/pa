/* 
 * File:   Triple.h
 * Author: jw
 *
 * Created on 27. November 2012, 09:17
 */

#ifndef TRIPLE_H
#define	TRIPLE_H

#include <string>
using namespace std;

class Triple {
    
public:
    Triple();
    Triple(string inhalt);
    
    void backwards(string in);
    void sortieren(string in);
private:
    string inhalt;

};

#endif	/* TRIPLE_H */

