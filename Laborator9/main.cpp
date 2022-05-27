#include <iostream>
#include "Map.h"
using namespace std;


int main()

{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}

/*
Index:0, Key=10, Value=C++

Index:1, Key=20, Value=test

Index:2, Key=30, Value=Poo

Index:0, Key=10, Value=C++

Index:1, Key=20, Value=result

Index:2, Key=30, Value=Poo
*/






