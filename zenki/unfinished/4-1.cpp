// 双方向リスト
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class List {
private:
    Node d_first, d_last;
public:
    List() {
        d_first.prev = 0;
        d_first.next = &d_last;
        d_last.prev = &d_first;
        d_last.next = 0;
    }
    void insert(int x);
    void del(int x);
    void del_first();
    void del_last();
    void print();
};

void List::insert(int x) {
    Node* f = &d_first;
    
    Node* n = new Node();
    n->data = x;
    n->next = f->next;
    n->prev = f;
    n->next->prev = n;

    f->next = n;
}

void List::del(int x) {
    for (Node* n = d_first.next; n!=0 && n!=&d_last; n=n->next){
        if(n->data == x) {
            n->prev->next = n->next;
            n->next->prev = n->prev;

            delete n;
            break;
        }
    }
    
}

void List::del_first() {
    Node* f = &d_first;

    Node* target = f->next;
    f->next = target->next;
    target->next->prev = f;

    delete target;
}

void List::del_last() {
    Node* l = &d_last;

    Node* target = l->prev;
    target->prev->next = l;
    l->prev = target->prev;

    delete target;
}

void List::print() {
    for (Node* n = d_first.next; n!=0 && n!=&d_last; n=n->next){
        cout << n->data << ' ';
    }
    cout << endl;
}

int main() {
    List* L = new List();
    L->insert(5);
    L->insert(6);
    L->insert(6);
    L->insert(7);
    L->insert(8);
    L->del_first();
    L->del_last();
    L->print();
}