#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template<class T>
class DoubleLinkedList {
    Nod<T>* p, * q;
    int n;
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void PushOnFront(const T& x);
    void PushOnBack(const T& x);
    T PopFromBack();
    void PrintAll(void (*prt)(const T& x));
    int GetCount();
};


template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    n = 0;
    p = q = nullptr;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    while (n--) {
        Nod<T>* vic = p;
        p = p->next;
        delete vic;
    }
    p = q = nullptr;
    n = 0;
}

template<class T>
void DoubleLinkedList<T>::PushOnFront(const T& x) {
    Nod<T>* t = new Nod<T>;
    t->info = x;
    t->next = nullptr;
    t->prev = nullptr;
    if (n == 0)
        p = q = t;
    else {
        t->next = p;
        p->prev = t;
        p = t;
    }
    n++;
}

template<class T>
void DoubleLinkedList<T>::PushOnBack(const T& x) {
    Nod<T>* t = new Nod<T>;
    t->info = x;
    t->next = nullptr;
    t->prev = nullptr;
    if (n == 0)
        p = q = t;
    else {
        q->next = t;
        t->prev = q;
        q = t;
    }
    n++;
}

template<class T>
T DoubleLinkedList<T>::PopFromBack() {
    Nod<T>* t = q;
    q = q->prev;
    T x = t->info;
    if (q != nullptr)
        q->next = nullptr;
    delete t;
    n--;
    return x;
}

template<class T>
void DoubleLinkedList<T>::PrintAll(void(*prt)(const T& x)) {
    cout << "Elements: " << this->GetCount() << " => ";
    Nod<T>* t = p;
    while (t != nullptr) {
        prt(t->info);
        t = t->next;
    }
    cout << '\n';
}

template<class T>
int DoubleLinkedList<T>::GetCount() {
    return n;
}
