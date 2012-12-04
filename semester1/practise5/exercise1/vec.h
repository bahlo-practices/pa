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
        bool generate_int(int iCount);
        bool generate_str(int iCount);
        vector<int> get_int();
        vector<string> get_str();
        void set_int(vector<int> vIntNew);
        void set_str(vector<string> vStrNew);
        void print_int();
        void print_str();
        bool is_int_empty(bool message = false);
        bool is_str_empty(bool message = false);
        bool are_both_empty(bool messagef = false);
    private:
        vector<int> vInt;
        vector<string> vStr;
};

#endif	/* VEC_H */

