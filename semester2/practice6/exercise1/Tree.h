#ifndef TREE_H
#define	TREE_H

#include <cstdlib>
#include <queue>
#include <iostream>
#include <stdexcept>

using std::cout;

template<class T>
struct node {
    T key;
    int value;
    node<T>* left;
    node<T>* right;
    node<T>* pre;
    explicit node(const T&, int, node<T>*, node<T>*, node<T>*);
};

template<class T>
node<T>::node(const T& k = T(), int v = 0, node<T>* l = 0, node<T>* r = 0, node<T>* p = 0)
: key(k), value(v), left(l), right(r), pre(p) {
}

template <class T>
class BST {
public:
    explicit BST(); //läuft
    typedef node<T>* nodep;
    node<T>* getRoot(); // läuft

    int height(); //läuft
    node<T>* find(T); //läuft
    void insert(T); //läuft
    void insertAsRoot(T);
    void in_order(node<T>*); //läuft
    void level_order(node<T>*); //läuft
    void visit(node<T>*); //läuft
    int count_Nodes(const std::string&);


private:
    int countNodes(int&, node<T>*); //läuft
    node<T>* root;
    int nodes;
    int height(nodep, int&); //läuft
    void insert(T, node<T>*); //läuft
    void rotateR(nodep& w); //läuft
    void rotateL(nodep& w); //läuft
    void rotateToRoot(nodep& nn); //läuft
};

template<class T> BST<T>::BST()
: root(0), nodes(0) {
}

template<class T> node<T>* BST<T>::getRoot() {
    return root;
}

template<class T> node<T>* BST<T>::find(T object) {
    node<T>* tmp = root;
    while (tmp != 0 && object != tmp->key) {
        if (object < tmp->key) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    if (tmp == 0) {
        std::cout << "Element nicht gefunden.\n";
    }
    return tmp;
}

template<class T> void BST<T>::insert(T ob) {
    if (root != 0) {
        insert(ob, root);
    } else {
        node<T>* tmp = new node<T>;
        tmp->key = ob;
        tmp->value++;
        tmp->pre = 0;
        tmp->left = 0;
        tmp->right = 0;
        root = tmp;
        nodes++;
    }
}

template <class T> void BST<T>::insert(T ob, node<T>* act) {
    if (act->key == ob) {
        act->value++;
    } else {
        if (act->key < ob) {// nach rechts gehen, wenn aktuelles Element kleiner ist
            if (act->right != 0) {//weiter nach passender Stelle suchen
                insert(ob, act->right);
            } else {
                node<T>* tmp = new node<T>;
                tmp->key = ob;
                tmp->value++;
                act->right = tmp;
                tmp->pre = act;
                tmp->right = 0;
                tmp->left = 0;
                nodes++;
            }
        }
        if (act->key > ob) {// nach links gehen
            if (act->left != 0) {
                insert(ob, act->left);
            } else {
                node<T>* tmp = new node<T>;
                tmp->key = ob;
                tmp->value++;
                act->left = tmp;
                tmp->pre = act;
                tmp->right = 0;
                tmp->left = 0;
                nodes++;
            }
        }
    }
}

template<class T> void BST<T>::visit(node<T>* ptr) {
    cout << ptr->key << " - " << ptr->value << std::endl;
}

template<class T> void BST<T>::in_order(node<T>* n) {
    if (n == 0) return;
    if (n->left != 0)
        in_order(n->left);
    visit(n); // z.B. cout
    if (n->right != 0)
        in_order(n->right);
}

template<class T> int BST<T>::countNodes(int& counter, node<T>* tmp) {
    counter++;
    if (tmp->left != 0) {
        countNodes(counter, tmp->left);
    }
    if (tmp->right != 0) {
        countNodes(counter, tmp->right);
    }
    if (tmp->right && tmp->left == 0) {
        return 0;
    }
}

template<class T> void BST<T>::level_order(node<T>* n) {
    if (n == 0) return;
    std::queue<node<T>*> q;
    q.push(n);
    while (!q.empty()) {
        n = q.front();
        q.pop();
        visit(n); // z.B. cout
        if (n->left != 0)
            q.push(n->left);
        if (n->right != 0)
            q.push(n->right);
    }
}

template <class T> void BST<T>::rotateR(nodep& w) {
    node<T>* x = w->pre;
    w->pre = x->pre;
    x->pre = w;
    x->left = w->right;
    w->right = x;
    if (x->left) {
        x->left->pre = x;
    }
    rotateToRoot(w);
}

template <class T> void BST<T>::rotateL(nodep& w) {
    node<T>* x = w->pre;
    w->pre = x->pre;
    x->pre = w;
    x->right = w->left;
    w->left = x;
    if (x->right) {
        x->right->pre = x;
    }
    rotateToRoot(w);
}

template<class T> void BST<T>::rotateToRoot(nodep& nn) {
    if (nn->pre == 0) {
        root = nn;
        return;
    }
    if (nn->key < nn->pre->key) {
        rotateR(nn);
    } else {
        rotateL(nn);
    }

}

template <class T> void BST<T>::insertAsRoot(T ob) {
    insert(ob);
    node<T>* nn = find(ob);
    rotateToRoot(nn);
}

template <class T> int BST<T>::height() {
    int h = 0;
    if (root != 0) {
        if (root->right == 0 && root->left == 0) {
            return h++;
        }
        int heightLeft = height(root->left, h);
        int heightRight = height(root->right, h);
        if (heightLeft > heightRight) {
            h = heightLeft + 1;
        } else {
            h = heightRight + 1;
        }
    }
    return h;
}

template<class T> int BST<T>::height(nodep act, int& h) {
    if (act != 0) {
        if (act->right == 0 && act->left == 0) {
            return h++;
        }
        int heightLeft = height(act->left, h);
        int heightRight = height(act->right, h);
        if (heightLeft > heightRight) {
            h = heightLeft + 1;
        } else {
            h = heightRight + 1;
        }
    }
    return h;
}

template<class T> int BST<T>::count_Nodes(const std::string& teilbaum) {
    int counter = 0;

    if (root == 0) {
        std::cout << "Achtung Keine Wurzel vorhanden.";
        return 0;
    }
    if (teilbaum == "links") {
        if (root->left == 0) {
            //std::cout << "Achtung keine Knoten im linken Teilbaum." << std::endl;
            return 0;
        } else {
            countNodes(counter, root->left);
        }
    }
    if (teilbaum == "rechts") {
        if (root->right == 0) {
            //std::cout << "Achtung keine Knoten im rechten Teilbaum." << std::endl;
            return 0;
        } else {
            countNodes(counter, root->right);
        }
    }
    if (teilbaum != "links" && teilbaum != "rechts") {
        throw std::runtime_error("Ungueltige Auswahl eines Teilbaumes!");
    }

    return counter;
}

#endif	/* TREE_H */

