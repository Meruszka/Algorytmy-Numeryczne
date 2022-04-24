#ifndef MOJAMACIERZ_CPP
#define MOJAMACIERZ_CPP

#include <iostream>
#include <string.h>
#include "mojamacierz.h"

template<typename T, int N>
int MojaMacierz<T, N>::getSize() { return N;}

template<typename T, int N>
void MojaMacierz<T, N>::setValues(T val[]){
    int n=0;
    for(int i=0; i<this->getSize(); i++){
        for(int j=0; j<this->getSize(); j++){
            this->macierz[i][j] = val[n];
            n++;
        }
    }
}

template<typename T, int N>
T& MojaMacierz<T, N>::operator()(int& row, int& col){
    return this->macierz[row][col];
}
template<typename T, int N>
void MojaMacierz<T, N>::Print(){

    for(long i=0; i<N; i++){
            std::cout<<"| ";
        for(long j=0; j<N; j++){
            std::cout << macierz[i][j] << " | ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

template<typename T, int N>
MojWektor<T, N>& MojaMacierz<T, N>::Gauss(MojWektor<T, N>& rhs){
    for(int k=0; k<N; k++){
        T pivot = macierz[k][k];
        for(int j=k+1; j<N; j++){
            this->macierz[k][j] = macierz[k][j]/pivot;
        }
        rhs(k) = rhs(k)/pivot;
        for(int i=0; i<N; i++){
            if(i == k || this->macierz[i][k]==0){
                    continue;
            }
            T f = this->macierz[i][k];
            for(int j=k; j<N; j++){
                this->macierz[i][j] -= f*this->macierz[k][j];
            }
            rhs(i) -= f*rhs(k);
        }
    }
    return rhs;
}
template<typename T, int N>
MojWektor<T, N>& MojaMacierz<T, N>::PGauss(MojWektor<T, N>& rhs){
    for(int k=0; k<N; k++){
        for(int j=k+1; j<N; j++){
            if(macierz[j][k]>macierz[k][k]){
                T temp[N];
                std::copy(macierz[j], macierz[j]+N, temp);
                std::copy(macierz[k], macierz[k]+N, macierz[j]);
                std::copy(temp, temp+N, macierz[k]);

                T tempV;
                tempV = rhs(j);
                rhs(j) = rhs(k);
                rhs(k) = tempV;
            }
        }
        T pivot = macierz[k][k];
        for(int j=k+1; j<N; j++){
            this->macierz[k][j] = macierz[k][j]/pivot;
        }
        rhs(k) = rhs(k)/pivot;
        for(int i=0; i<N; i++){
            if(i == k || this->macierz[i][k]==0){
                    continue;
            }
            T f = this->macierz[i][k];
            for(int j=k; j<N; j++){
                this->macierz[i][j] -= f*this->macierz[k][j];
            }
            rhs(i) -= f*rhs(k);
        }
    }
    return rhs;
}

#endif


