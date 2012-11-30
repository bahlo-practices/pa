/* 
 * File:   vec.h
 * Author: Arne
 *
 * Created on 30. November 2012, 15:19
 */

#ifndef VEC_H
#define	VEC_H

#include <vector>
using std::vector;
using std::string;

class vec {
    public:
        vec();
        bool generate(int iCount, string sWhat);
        vector<int> get_int();
        vector<string> get_str();
        void print(string sWhat);
    private:
        vector<int> vInt;
        vector<string> vStr;
};

#endif	/* VEC_H */

