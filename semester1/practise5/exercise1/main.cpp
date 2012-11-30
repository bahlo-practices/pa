/* 
 * 1a
 *
 * Created on 30. November 2012, 13:16
 */

#include <iostream>
#include <vector>
#include "error.h"
#include "vec.h"
#include "sort.h"
#include "menu.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

using std::string;
using std::vector;

using std::exception;

int main() {
    try {
        // Create objects
        vec vec;
        menu menu;
        
        // Show menu
        menu.show(false);
    } catch (exception &e) {
        cerr << "Ausname: " << e.what();
    } catch (...) {
        cerr << "Unbekannter Fehler";
    }
    return 0;
}

