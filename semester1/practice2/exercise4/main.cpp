/*  _  _   
 * | || |  
 * | || |_ 
 * |__   _|
 *    | |  
 *    |_|  
 * 
 * Created on 22. Oktober 2012, 19:19
 * 
 * Calculates the median
 * 
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;

using std::vector;
using std::sort;
using std::endl;

int main() {
    // Initialize variables
    vector<double> vTemps;
    double temp = 0.0;
    
    // Prompt for values
    cout << "Geben Sie nacheinander Zahlen ein und best\x84tigen Sie mit \(Enter\)." << endl;
    cout << "Wenn Sie fertig sind, geben Sie \"quit\" ein." << endl;
    
    // Read values and save them to vector
    while( cin >> temp)
    vTemps.push_back( temp );
    
    // Arithm. middle
    double sum = 0.0;
    for( int i=0; i<vTemps.size(); ++i )
    sum += vTemps[i];
    cout << "Temperaturmittel: " << sum/vTemps.size() << endl;
    
    // Sort vector
    sort(vTemps.begin(), vTemps.end());
    
    // Give out median
    double dMedian = 0.0;
    if(vTemps.size() % 2 == 0) {
        // Even quantity
        dMedian = (vTemps[(vTemps.size() / 2) - 1] + vTemps[vTemps.size() / 2]) / 2;
    } else {
        // Odd quantity
        dMedian = vTemps[vTemps.size() / 2];
    }
    
    // Cout the median
    cout << "Median: " << dMedian << endl;
    
    return 0;
}