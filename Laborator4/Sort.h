#pragma once
class Sort

{

    // add data members
    int* v;
    int nr_elements_v;

public:

    // add constuctors

    Sort(int* v, int nr_elements);

    Sort(int count, ...);

    Sort(char* c);

    //Sort(); 
 //----------------------------------------
    void InsertSort(bool ascendent = false); // by default, acendent=false 

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print(); //afiseaza vectorul

    int  GetElementsCount(); // returneaza nr total de elemente

    int  GetElementFromIndex(int index); //afiseaza de la un anumit index

};