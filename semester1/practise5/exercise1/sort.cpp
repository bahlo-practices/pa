/* 
 * Created on 30. November 2012, 17:38
 */

#include <vector>
#include "sort.h"

using std::vector;
using std::swap;

sort::sort() {
}

void swap_if( int& a, int& b ) { 
    if(a>b) swap(a,b); 
}

vector<int> sort::sel_int(vector<int>& vV, int ui, int oi) {
    int min(0);
    for(int i=ui; i<oi; ++i){
        min = i;
        for(int j=i+1; j<=oi; ++j) {
            if(vV.at(j) < vV.at(min)) {
                min=j; 
                swap(vV.at(i), vV.at(min));
            }
        }
    }
}

vector<int> sort::ins_int(vector<int>& vV, int ui, int oi) {
    int i(0), j(0), tmp(0);
    for (i = oi; i > ui; --i) {
        swap_if(vV.at(i - 1), vV.at(i));
    }
    for (i = ui + 2; i <= oi; ++i) {
        j = i;
        tmp = vV.at(i);
        while (tmp < vV.at(j - 1)) {
            vV.at(j) = vV.at(j - 1);
            --j;
        }
        vV.at(j) = tmp;
    }
}

