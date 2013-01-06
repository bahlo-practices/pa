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
    void fillint(int totalitems, vector<int> &vV);
    void fillstring(int totalitems);
    void printallint(vector<int> &vV);
    void printallstring();
    int intSeqSearch(int lookingfor);
    int binSearch(vector<int> vV, int x, int ui, int oi);
    int seqSearch(vector<int> vV, int x, int li, int re);
    
private:
    vector<string> svalues;
    vector<int> ivalues;
    string builder;
    char target;
    int convert;
    
};

#endif	/* RANDOMVALUES_H */

