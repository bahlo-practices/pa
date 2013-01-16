/* 
 * Created on 16. Januar 2013, 10:19
 */

#ifndef WS12_H
#define	WS12_H

#include <iostream>

using namespace std;

class Liwanze {
public:
    enum Region {ndef, amer, apac, emea};
    Liwanze();
    Liwanze(string _name, Region _loc);
    string get_name() const;
    int get_loc() const;
    void print() const;
private:
    string name;
    Region loc;
};

#endif	/* WS12_H */

