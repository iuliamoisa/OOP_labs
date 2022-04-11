#include <iostream>
#include "DoubleLinkedList.h"

void printInt(const int& v) {
    std::cout << v << ", ";
}

void printDouble(const double& v) {
    std::cout << v << ", ";
}

int main() {
    DoubleLinkedList<double> d;
    d.PushOnFront(1.5);
    d.PrintAll(printDouble);
    d.PushOnFront(2.5);
    d.PushOnBack(3.5);
    d.PrintAll(printDouble);
    while (d.GetCount()) {
        std::cout << d.PopFromBack() << ",";
    }

    std::cout << std::endl;
    DoubleLinkedList<int> i;
    for (int index = 0; index < 10; index++) {
        if (index % 2 == 0)
            i.PushOnBack(index);
        else
            i.PushOnFront(index);
    }
    i.PrintAll(printInt);
    return 0;
}

/*
DoubleLinkedList ? este o lista dublu înl?n?uit? care folose?te intern un template “Node”
cu 3 campuri (next, precedent ?i value). Template-ul “Node” va fi definit într-un fi?ier
header (“Node.h”) separat.

La adaugarea unul element în lista (prin metodele PushOnBack sau PushOnFront) se
aloca un element de tipul Node care apoi este adaugat la lista prin campurile “next” ?i
“precedent”


Adaugati in fi?ierul main.cpp o func?ie “printInt” care sa afi?eze un int (similar cu func?ia
printDouble). Func?ia printInt este utilizata ca ?i parametru pentru metoda “PrintAll”
apelata pentru variabila “i” din func?ia main.
*/