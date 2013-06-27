#include "Tree.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

template<class T> void printFound(BST<T>& e, int t){
    node<T>* tmp;
    tmp = e.find(t);
    if(tmp != 0){
        cout<<t<<" wurde gefunden."<<endl;
    }
}

template<class T> bool isOrdered(BST<T>& e){
    bool result = false;
    result = isOrderedLevelCheck(e.getRoot());

    return result;
}

template<class T> bool isOrderedLevelCheck(node<T>* tmp){
    if(tmp->left != 0){
       if(tmp->key < tmp->left->key){
           return false;
        }
       isOrderedLevelCheck(tmp->left);
    }
    if(tmp->right != 0){
        if(tmp->key > tmp->right->key){
                return false;
          }
        isOrderedLevelCheck (tmp->right);
    }
    return true;

}

template<class T> void printTestResult(BST<T>& e, string testType, string description) {
    bool successful = isOrdered(e);
    if (!successful) cout << "\nFAILED test ";
    else cout << "\n succeeded test ";
    cout << testType << '(' << description << ')' << endl;

}

void insertRandomChars(BST<char>& btmp) {
    int rnd = (rand() % 100) + 1;
    char ctmp(' ');
    for (int i(0); i < rnd; i++) {
        ctmp = int ((rand() % 27) + 65);
        btmp.insert(ctmp);
    }
}

int main(int argc, char** argv) {
    try {

        srand(time(NULL));
        BST<int> hallo;

        hallo.insert(10);
        hallo.insert(5);
        hallo.insert(2);
        hallo.insertAsRoot(1);
        hallo.in_order(hallo.getRoot());

        cout << endl;
        cout << "Anzahl der Knoten im linken Teilbaum:" << hallo.count_Nodes("links") << endl;
        cout << "Anzahl der Knoten im rechten Teilbaum:" << hallo.count_Nodes("rechts") << endl;
        cout << endl;
        cout << "Wurzel " << hallo.getRoot()->key << " - " << hallo.getRoot()->value << endl;
        cout << "Höhe des BST " << hallo.height() << endl;

//                BST<char> hi;
//                insertRandomChars(hi);
//                hi.in_order(hi.getRoot());
//                cout << "Anzahl der Knoten im Linken Teilbaum: " << hi.count_Nodes("links") << endl;
//                cout << "Anzahl der Knoten im Linken Teilbaum: " << hi.count_Nodes("rechts") << endl;
//                cout << "Höhe des BST " << hi.height() << endl;

        printTestResult(hallo, "checkTrue", "isOrdered");

        return 0;
    } catch (exception& e) {
        cout << e.what() << endl;
        return -2;
    } catch (...) {
        cout << "Unbekannter Fehler" << endl;
        return -1;
    }
}
