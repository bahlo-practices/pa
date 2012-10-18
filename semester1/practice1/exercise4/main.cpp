/* 
 *  .d8b.  d8888b. d8b   db d88888b 
 * d8' `8b 88  `8D 888o  88 88'     
 * 88ooo88 88oobY' 88V8o 88 88ooooo 
 * 88~~~88 88`8b   88 V8o88 88~~~~~ 
 * 88   88 88 `88. 88  V888 88.     
 * YP   YP 88   YD VP   V8P Y88888P 
 *
 * Created on 12. Oktober 2012, 21:17
 * 
 * Asks user for name and birthyear and -month and then calculates and displays 
 * the age of the user at semester start
 */

#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main( ) {
    string name  = "";
    int yob = 0; // year of birth
    int mob = 0; // month of birth
    
    int yos = 2012; // year of semesterstart
    int mos = 10; // month of semesterstart
    
    // get input from user
    cout << "Bitte geben Sie Ihren Namen ein: ";
    cin >> name;
    cout << "\nUnd nun ihr Geburtsjahr: ";
    cin >> yob;
    cout << "\nAls letztes wird noch Ihr Geburtsmonat ben\x94tigt: ";
    cin >> mob;
    
    // calculate age
    int years = yos - yob;
    int tmpmonth = mos - mob;
    
    if(tmpmonth < 0) {
        years -= 1;
        tmpmonth += 12;
    }
    int month = tmpmonth;
    
    /* alternate version of typcast
    double dyears = years;
    double dmonth = month;
    */
    double age = (double)years + (double)month/12;
    
    cout << "\n\nIhr Alter betrugt zum Semesterbeginn " << years << " Jahre und " << month << " Monate.";
    cout << "\nDas entspricht " << age << " Jahren" << "\n";

    return 0; 
}