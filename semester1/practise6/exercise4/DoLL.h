/* 
 * File:   DoLL.h
 * Author: Tobias Hereth
 *
 * Created on 14. Dezember 2012, 14:44
 */

#ifndef DOLL_H
#define	DOLL_H

#include <iostream>

using namespace std;

class DoLL {
public:

    DoLL();

    DoLL(string s, DoLL* p, DoLL* l);

    DoLL* ablegen(string s); //push back
    DoLL* entnehmen(); //pop back
    DoLL* push_front(string s);
    DoLL* push_back_node(string s);
    DoLL* push_prev_node(string s);
    DoLL* pop_front();
    DoLL* pop_back_node();
    DoLL* pop_prev_node();
    DoLL* erstes_Elem();
    DoLL* letztes_Elem();
    DoLL* links();
    DoLL* rechts();
    static void print_item(DoLL* l);
    
    static void printall(DoLL* l);
    
    DoLL* get_next();
    DoLL* get_last();
    DoLL* navi();
    
    void functions();
    

private:
    string item;
    DoLL* last;
    DoLL* next;

};

#endif	/* DOLL_H */

