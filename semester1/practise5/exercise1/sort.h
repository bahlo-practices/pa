/* 
 * File:   sort.h
 * Author: Arne
 *
 * Created on 30. November 2012, 17:38
 */

#ifndef SORT_H
#define	SORT_H

using std::string;
using std::vector;

class sort {
public:
    sort();
    vector<int> sel_int(vector<int>& vV, int ui, int oi);
    vector<string> sel_str(vector<string>& vV, int ui, int oi);
    vector<int> ins_int(vector<int>& vV, int ui, int oi);
    vector<string> ins_str(vector<string>& vV, int ui, int oi);
private:

};

#endif	/* SORT_H */

