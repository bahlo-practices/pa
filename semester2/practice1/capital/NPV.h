/* 
 * File:   NPV.h
 * Author: arne
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
    NPV(vector<long int> inv, double irate);
    
    // Randomize
    void randomize();
    
    // Calculation
    void calculate();
    
    // Getter
    vector<long int> const get_inv();
    double const get_irate();
    
    // Setter
    void set_inv(vector<long int> inv);
    void set_irate(double irate);
    
    // Print
    void const print();
private:
    vector<long int> inv;
    double irate;
    double capital;
};

#endif	/* NPV_H */

