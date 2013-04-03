/* 
 * Created on 16. Januar 2013, 10:19
 */

#ifndef WS12_H
#define	WS12_H

#include <iostream>
#include <vector>

using namespace std;

class Liwanze {
public:
    enum Region {ndef, amer, apac, emea};
    Liwanze();
    Liwanze(string _name, Region _loc);
    string get_name() const;
    int get_loc() const;
    void print() const;
    // Aufgabe 2
    bool connects(Liwanze*) const;
    bool connected(Liwanze*) const;
    void print_tierone() const;
    void add_connTo(Liwanze*);
    void add_connFrom(Liwanze*);
private:
    string name;
    Region loc;
    // Aufgabe 2
    vector<string> connectsTo;
    vector<string> connectedFrom;
};

#endif	/* WS12_H */

