/* 
 * Created on 14. Dezember 2012, 14:44
 */

#include "DoLL.h"
#include <iostream>

using namespace std;

DoLL::DoLL() : item(), next(0), last(0) {
}

DoLL::DoLL(string s, DoLL* p, DoLL* l)
: item(s), next(p), last(l) {
}

void DoLL::print_item(DoLL* l){
    if(l == 0) cerr << "ungültiger wert";
    else cout << l << ": "<< l->item <<" "<< l->next <<" "<< l->last<<endl;
}

DoLL* DoLL::ablegen(string s) {//push_back
    DoLL* letztes_Element;
    for (letztes_Element = this; letztes_Element->next != 0; letztes_Element = letztes_Element->next) {
    }

    DoLL* DoLL1 = new DoLL(s, NULL, letztes_Element);
    letztes_Element->next = DoLL1;
    return DoLL1;
}

DoLL* DoLL::pop_front() {
    DoLL* erstes_Element;   
    for (erstes_Element = this; erstes_Element->last != 0; erstes_Element = erstes_Element->last) {
    
    }
    erstes_Element->next->last = 0;
    DoLL* nachstes (this->next->next);
    DoLL* previous (NULL);
    
    DoLL* neues_erstes_Element = new DoLL((this->next->item), nachstes, previous);
    delete erstes_Element;
    return neues_erstes_Element;
}

DoLL* DoLL::erstes_Elem(){
    DoLL* erstes_Element;
    for (erstes_Element = this; erstes_Element->last != 0; erstes_Element = erstes_Element->last) {
    
    }
    return erstes_Element;
}
DoLL* DoLL::letztes_Elem(){
    DoLL* tmp=this;
    DoLL* letztes_Element (this);
    for (tmp; tmp->next != 0; tmp = tmp->next) {
        if (tmp->next ==0) letztes_Element=tmp;
            DoLL::print_item(letztes_Element);
    
    }
    delete tmp;
    return letztes_Element;
}

DoLL* DoLL::push_front(string s) {//vorne einfügen
    
    cout<<"Methoden Anfang"<<endl;
    printall(this);
    DoLL* erstes_Element;
    for (erstes_Element = this; erstes_Element->last != NULL; erstes_Element = erstes_Element->last) {
        //DoLL::print_item(erstes_Element);
    }
    
    if(erstes_Element->last == NULL){
        
        DoLL* DoLL2 = new DoLL(s, erstes_Element, NULL);
        erstes_Element->last = DoLL2;
        printall(this);
         cout<<"Methoden Ende"<<endl;
        return DoLL2;
    }
    
}

DoLL* DoLL::push_back_node(string s) {
    DoLL* DoLL3 = new DoLL(s, this->next, this);

    this->next = DoLL3;
    this->next->next->last = DoLL3;
    return DoLL3;
}

DoLL* DoLL::push_prev_node(string s) {
    DoLL* DoLL4 = new DoLL(s, this, this->last);
    this->last = DoLL4;
    this->last->last->next = DoLL4;
    return DoLL4;
}

DoLL* DoLL::get_next() {
    return next;
}

DoLL* DoLL::get_last() {
    return last;
}

void DoLL::printall(DoLL* l) {
    if (l == 0) {
        return;
    }
    
    DoLL* letztes_Element;
    
    for (letztes_Element = l; letztes_Element->next != 0; letztes_Element = letztes_Element->next) {
  
    }  
  
    for(DoLL* aktuell = letztes_Element; aktuell != NULL; aktuell=aktuell->last){
        print_item(aktuell);
    }
}

DoLL* DoLL::entnehmen() {//pop_back
  
    DoLL* letztes_Element;
    for (letztes_Element = this; letztes_Element->next != 0; letztes_Element = letztes_Element->next) {
    }
    if(letztes_Element->last == NULL){
        cerr<<"Letzter Wert in der Liste. Fehler.";
    } else {
      
            DoLL* temp = letztes_Element->last;
            if(letztes_Element->last->last != NULL) letztes_Element->last->last->next = letztes_Element;
            letztes_Element->next = 0;
            if(letztes_Element->last != NULL) {
                letztes_Element->item = letztes_Element->last->item;
                letztes_Element->last = letztes_Element->last->last;
            }
            
            //delete temp;
                    
            //DoLL* neues_letztes_Element = letztes_Element->last;
            //cerr << letztes_Element << endl;
        //return neues_letztes_Element;
        

    }
}

DoLL* DoLL::pop_back_node() {

    if ((this->next) == 0) {
        return this;
    } else if ((this->next->next) == 0) {
        delete this->next;
        this->next = 0;

    } else {
        DoLL* tmp = this->next;

        this->next = this->next->next;
        this->next->last = this;
        delete tmp;
    }
    return this;
}

DoLL* DoLL::pop_prev_node() {
    if ((this->last) == 0) {
        return this;
    } else if ((this->last->last) == 0) {
        this->last = 0;
    } else {
        DoLL* tmp = this->last;
        this->last = this->last->last;
        this->last->next = this;
        delete tmp;
    }
    return this;
}
