/* 
 *                                         | |   (_)      
 *   __ _ _ __ _ __   ___   _   _ _ __   __| |    _  ___  
 *  / _` | '__| '_ \ / _ \ | | | | '_ \ / _` |   | |/ _ \ 
 * | (_| | |  | | | |  __/ | |_| | | | | (_| |   | | (_) |
 *  \__,_|_|  |_| |_|\___|  \__,_|_| |_|\__,_|   | |\___/ 
 *                                              _/ |       
 *                                             |__/    
 *
 * Created on 12. Oktober 2012, 21:17
 * 
 * This application asks you for three numbers and displays them in ascending order
 * then it displays the sum, the product, the difference and the quotient between them
 */

#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main( ) {
    // initialize arrays
    int input[] = {0, 0, 0};
    int output[] = {0, 0, 0};
    
    // set variables based on user input
    cout << "Dieses Programm nimmt Ihre Zahlen entgegen und gibt sie in aufsteigender Reihenfolge zurueck.\n\n\tGeben Sie die erste Zahl an: ";
    cin >> input[0];
    cout << "\n\tSehr gut! Nun die zweite: ";
    cin >> input[1];
    cout << "\n\tPrima, eine letze noch: ";
    cin >> input[2];
    
    // calculate     
    if(input[0] <= input[1] && input[0] <= input[2]) {
        // the first is the smallest
        output[0] = input[0];
        if(input[1] <= input[2]) {
            output[1] = input[1];
            output[2] = input[2];
        } else {
            output[1] = input[2];
            output[2] = input[1];
        }
    } else if(input[1] <= input[0] && input[1] <= input[2]) {
        //the second is the smallest
        output[0] = input[1];
        if(input[0] < input[2]) {
            output[1] = input[0];
            output[2] = input[2];
        } else {
            output[1] = input[2];
            output[2] = input[0];
        }
    } else if(input[2] <= input[0] && input[2] <= input[0]) {
        // the third is the smallest
        output[0] = input[2];
        if(input[0] <= input[1]) {
            output[1] = input[0];
            output[2] = input[1];
        } else {
            output[1] = input[1];
            output[2] = input[0];
        }
    }
    
    // cout the order
    cout << "\n\nDie Zahlen in aufsteigender Reihenfolge sind: " << output[0] << ", " << output[1] << ", " << output[2];
    
    
    // calculate the sum and the product of the numbers
    int sum = output[0] + output[1] + output[2];
    int product = output[0] * output[1] * output[2];
    
    // cout the sum and the product
    cout << "\nDie Summe der drei Zahlen ist: " << sum << "\nUnd das Produkt ist: " << product;
    
    
    // calculate the differences 
    int diff[] = {output[1] - output[0], output[2] - output[1]};
    
    // cout the differences
    // cout << "\nDie Differenzen sind " << diff[0] << " und " << diff[1];
    cout << "\nDie Differenzen: \n" << output[1] << " - " << output[0] << " = " << diff[0];
    cout << "\n" << output[2] << " - " << output[1] << " = " << diff[1];
    
    
    // calculate the quotient
    double quot[] = {(double)output[0] / (double)output[1], (double)output[1] / (double)output[2]};
    
    // cout the quotient
    // cout << "\nDie Quotenten sind " << quot[0] << " und " << quot[1];
    cout << "\nDie Quotienten: \n" << output[0] << " / " << output[1] << " = " << quot[0];
    cout << "\n" << output[1] << " / " << output[2] << " = " << quot[1] << "\n";
            
    return 0;
}

