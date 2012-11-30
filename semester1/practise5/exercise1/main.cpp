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
        sort sort;
        menu menu;
        
        // Show menu
        //menu.show(false);
        
        // Debug
        vec.generate(16, "int");
        vector<int> temp = vec.get_int();
        sort.ins_int(vec.get_int(), 0, temp.size());
        vec.print("int");
    } catch (exception &e) {
        cerr << "Ausname: " << e.what();
    } catch (...) {
        cerr << "Unbekannter Fehler";
    }
    return 0;
}

