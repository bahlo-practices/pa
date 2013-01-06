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
    cout << l->item << endl;
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
    DoLL erstes_Element (*this);
    
    
    for (erstes_Element = *this; erstes_Element->last != 0; erstes_Element = erstes_Element->last) {
    }
    erstes_Element->next->last = 0;
    DoLL* nachstes (this->next->next);
    DoLL* previous (NULL);
    
    DoLL* neues_erstes_Element ((this->next->item), nachstes, previous);
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

DoLL* DoLL::links(){
    int counter (0);
    DoLL* linkes_Element;
    for (linkes_Element=this; counter<1; counter++){
        linkes_Element = linkes_Element->last;
    }
    return linkes_Element;
}

DoLL* DoLL::rechts(){
    int counter (0);
    DoLL* rechtes_Element;
    for (rechtes_Element=this; counter<2; counter++){
        rechtes_Element = rechtes_Element->last;
    }
    return rechtes_Element;
}

DoLL* DoLL::push_front(string s) {//vorne einfügen
    DoLL* erstes_Element;
    for (erstes_Element = this; erstes_Element->last != 0; erstes_Element = erstes_Element->last) {
        DoLL::print_item(erstes_Element);
    }
    DoLL* DoLL2 = new DoLL(s, erstes_Element, NULL);
    erstes_Element->last = DoLL2;
    return DoLL2;
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

//DoLL* DoLL::navi() {
//    char menu (' ');
//    cout<<"Wollen Sie sich in der Liste nach links (l) oder rechts (r) bewegen? > ";
//    cin>>menu;
//    switch (menu) {
//        case 'l':
//            if (this->last == 0) {
//                return this;
//            } else {
//                this = this->last;
//            }
//            break;
//        case 'r':
//            if (this->next==0){
//                return this;
//            }else{
//            this = this->next;
//            }
//            break;
//        default:
//            return this;
//            break;
//    }
//}

void DoLL::functions() {
    char auswahl_Funktion (' ');
    char auswahl_unterfunktion (' ');
    string neues_Element (" ");
    cout<<"Wleche Funktion wollen Sie ausführen?\n"
            "1 > Ein Element hinzufügen\n"
            "2 > Ein Element löschen\n"
            "3 > Alle Elemente ausgeben\n";
    
    switch (auswahl_Funktion) {
            case '1' :
                cout<<"\nBitte geben SIe Ihr Element ein >";
                cin>>neues_Element;
                cout<<"\nWo wollen Sie Ihr Element einfügen?\n"
                        "\n1 > Element ganz hinten an die Liste hinzufügen"
                        "\n2 > Element ganz vorne an der Liste hinzufügen"
                        "\n3 > Element hinter Ihrem derzeitigen Element einfügen"
                        "\n4 > Element vor Ihrem derzeitigen Element einfügen\n";
                cin>>auswahl_unterfunktion;
                switch (auswahl_unterfunktion){
                    case '1':
                        this->ablegen(neues_Element);
                        break;
                    case '2':
                        this->push_front(neues_Element);
                        break;
                    case '3':
                        this->push_prev_node(neues_Element);
                        break;
                    case '4':
                        this->push_back_node(neues_Element);
                        break;
                    default:
                        break;
                }
            break;
        case '2':
            cout<<"\nWo wollen Sie Ihr Element löschen?\n"
                        "\n1 > Element ganz hinten aus der Liste entfernen"
                        "\n2 > Element ganz vorne aus der Liste entfernen"
                        "\n3 > Element hinter Ihrem derzeitigen Element entfernen"
                        "\n4 > Element vor Ihrem derzeitigen Element entfernen\n";
            cin>>auswahl_unterfunktion;
            switch (auswahl_unterfunktion){
                case '1':
                    this->entnehmen();
                    break;
                case '2':
                    this->pop_front();
                    break;
                case '3':
                    this->pop_back_node();
                    break;
                case '4':
                    this->pop_prev_node();
                    break;
            }
            break;
        case '3':
            DoLL::printall(this);
            break;
    }
}

void DoLL::printall(DoLL* l) {
    if (l == 0) {
        return;
    }
    cout << l->item << endl;
    printall(l->next);
}

DoLL* DoLL::entnehmen() {//pop_back
    DoLL* letztes_Element;
    for (letztes_Element = this; letztes_Element->next != 0; letztes_Element = letztes_Element->next) {
    }
    letztes_Element->last->next = 0;
    DoLL* neues_letztes_Element = letztes_Element->last;
    delete letztes_Element;
    return neues_letztes_Element;
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
