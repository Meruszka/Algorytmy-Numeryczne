#ifndef MOJWEKTOR_H
#define MOJWEKTOR_H

template<typename T, int N>
class MojWektor {
public:
    T wektor[N];
    int getSize();
    void setValues(T val[]);
    T& operator()(int& x);
    void Print();
};

#include "mojwektor.cpp"

#endif
