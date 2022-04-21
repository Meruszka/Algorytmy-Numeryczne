#ifndef MOJAMACIERZ_H
#define MOJAMACIERZ_H

#include "mojwektor.h"

template<typename T, int N>
class MojaMacierz {
private:
    T macierz[N][N];
public:
    int getSize();
    void setValues(T val[]);
    T& operator()(int& row, int& col);
    void Print();

    MojaMacierz<T, N> operator+=(MojaMacierz<T, N>& rhs);
    MojaMacierz<T, N> operator*=(MojaMacierz<T, N>& rhs);
    MojWektor<T, N> operator*=(MojWektor<T, N>& rhs);
    MojWektor<T, N>& Gauss(MojWektor<T, N>& rhs);
    MojWektor<T, N>& PGauss(MojWektor<T, N>& rhs);
};

#include "mojamacierz.cpp"


#endif
