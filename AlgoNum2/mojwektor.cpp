#ifndef MOJWEKTOR_CPP
#define MOJWEKTOR_CPP

#include <iostream>
#include <string.h>

#include "mojwektor.h"

template<typename T, int N>
int MojWektor<T, N>::getSize() { return N;}

template<typename T, int N>
void MojWektor<T, N>::setValues(T val[]){
    for(int i=0; i<this->getSize(); i++){
            wektor[i] = val[i];
    }
}

template<typename T, int N>
T& MojWektor<T, N>::operator()(int& x){
    return wektor[x];
}

template<typename T, int N>
void MojWektor<T, N>::Print(){
        for(long i=0; i<this->getSize(); i++){
            std::cout <<"| "<< wektor[i] <<" |"<< std::endl;
        }
        std::cout<<std::endl;
}


#endif


