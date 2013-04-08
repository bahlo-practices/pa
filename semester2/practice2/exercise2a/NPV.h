/*
 * File:   NPV.h
 *
 * Created on 3. April 2013, 20:00
 */

#ifndef NPV_H
#define	NPV_H

#include <vector>

using namespace std;

class NPV {
public:
    NPV();
    NPV(vector<long int> _inv, double _irate);

    class Invalid {}; // Invalid class for exceptions

    // Calculation
    void calculate();

    // Getter
    vector<long int> get_inv() const;
    double get_irate() const;

    // Setter
    void set_inv(vector<long int> _inv);
    void set_irate(double _irate);

    // Print
    void print() const;
private:
    vector<long int> inv;
    double irate;
    long double capital;
};

#endif	/* NPV_H */

