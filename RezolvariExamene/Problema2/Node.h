#pragma once


template<class T>
struct Nod {
    T info;
    Nod<T>* next;
    Nod<T>* prev;
};

