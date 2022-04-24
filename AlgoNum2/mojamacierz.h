#ifndef MOJAMACIERZ_H
#define MOJAMACIERZ_H

#include "mojwektor.h"

template<typename T, int N>
class MojaMacierz {
public:
    T macierz[N][N];
    int getSize();
    void setValues(T val[]);
    T& operator()(int& row, int& col);
    void Print();
    MojWektor<T, N>& Gauss(MojWektor<T, N>& rhs);
    MojWektor<T, N>& PGauss(MojWektor<T, N>& rhs);
};

#include "mojamacierz.cpp"


#endif
