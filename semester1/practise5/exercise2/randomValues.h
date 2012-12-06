/* 
 * File:   randomValues.h
 * Author: Johannes Wahl
 *
 * Created on 6. Dezember 2012, 16:35
 */

#ifndef RANDOMVALUES_H
#define	RANDOMVALUES_H

#include <vector>
#include <iostream>

using std::string;
using std::vector;

class randomValues {
public:

    randomValues();
    void fillint(int totalitems);
    void fillstring(int totalitems);
    const void printallint();
    void printallstring();
    int intSeqSearch(int lookingfor);
    int intBinSearch(int lookingfor);
    int stringSeqSearch(string slookingfor);
    int stringBinSearch(string slookingfor);
    
private:
    vector<string> svalues;
    vector<int> ivalues;
    string builder;
    char target;
    int convert;
    
};

#endif	/* RANDOMVALUES_H */

