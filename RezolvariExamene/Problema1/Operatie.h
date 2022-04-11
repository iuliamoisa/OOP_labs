#pragma once
class Operatie {
protected:
    char nume[1005];
public:
    virtual char* getName() = 0;
    virtual int comp(int a, int b) = 0;
};
