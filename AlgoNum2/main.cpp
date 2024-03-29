#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <random>
#include <fstream>
#define EIGEN_STACK_ALLOCATION_LIMIT 0
#include <Eigen>
#include<chrono>

#include "mojamacierz.h"
#include "mojwektor.h"

#define SIZE 1000
#define RANGE_MIN -65536
#define RANGE_MAX 65535


template<typename T>
T PG(int seed, int n){
    T A[SIZE*SIZE];
    T B[SIZE];
    MojaMacierz<T, SIZE> macierz;
    MojWektor<T, SIZE> wektor;
    MojWektor<T, SIZE>wynik;
    Eigen::Vector<T, SIZE> Xwynik;

    std::srand(seed);
    for(int i=0; i<SIZE*SIZE; i++){
        T r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        A[i] = r/65536;
    }
    for(int i=0; i<SIZE; i++){
        T r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        B[i] = r/65536;
    }

    Eigen::Map<Eigen::Matrix<T, SIZE, SIZE>> matrix(A);
    Eigen::Map<Eigen::Vector<T, SIZE>> vec(B);
    macierz.setValues(A);
    wektor.setValues(B);
    // Obliczenia
    // ==================
        std::chrono::steady_clock::time_point start1 = std::chrono::steady_clock::now();
            wynik = macierz.PGauss(wektor);
        std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

        std::chrono::steady_clock::time_point start2 = std::chrono::steady_clock::now();
            Xwynik = matrix.transpose().colPivHouseholderQr().solve(vec);
        std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

        std::ofstream czas;
        czas.open("Wyniki/Czasy/PGD.csv", std::ios_base::app);
        czas << std::fixed << std::setprecision(20);
        czas << SIZE << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end1 - start1).count() << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end2 - start2).count() <<"\n";
        czas.close();
    // ===============

    T sum = 0;
    for(int i=0; i<SIZE; i++){
        sum += abs(Xwynik(i)- wynik(i));
    }
    return sum;
}
template<typename T>
T G(int seed, int n){
    T A[SIZE*SIZE];
    T B[SIZE];
    MojaMacierz<T, SIZE> macierz;
    MojWektor<T, SIZE> wektor;
    MojWektor<T, SIZE> wynik;
    Eigen::Vector<T, SIZE> Xwynik;

    std::srand(seed);
    for(int i=0; i<SIZE*SIZE; i++){
        T r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        A[i] = r/65536;
    }
    for(int i=0; i<SIZE; i++){
        T r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        B[i] = r/65536;
    }
    Eigen::Map<Eigen::Matrix<T, SIZE, SIZE>> matrix(A);
    Eigen::Map<Eigen::Vector<T, SIZE>> vec(B);
    macierz.setValues(A);
    wektor.setValues(B);
    // Obliczenia
    // ==================
        std::chrono::steady_clock::time_point start1 = std::chrono::steady_clock::now();
            wynik = macierz.Gauss(wektor);
        std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

        std::chrono::steady_clock::time_point start2 = std::chrono::steady_clock::now();
            Xwynik = matrix.transpose().householderQr().solve(vec);
        std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
        std::ofstream czas;
        czas.open("Wyniki/Czasy/GTD.csv", std::ios_base::app);
        czas << std::fixed << std::setprecision(20);
        czas << SIZE << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end1 - start1).count() << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end2 - start2).count() <<"\n";
        czas.close();
    // ===============

    T sum = 0;
    for(int i=0; i<SIZE; i++){
        sum += abs(Xwynik(i)- wynik(i));
    }
    return sum;
}

int main()
{
    int seed[10] = {74, 66, 33, 173, 14, 13, 190, 175, 45, 151};
    std::cout<<"START"<<std::endl;
    double sumGTD = 0, sumPGD = 0;
    float sumGTF = 0, sumPGF=0;
    for(int i=0; i<1; i++){
        sumGTD += G<double>(seed[i]);
        sumPGD += PG<double>(seed[i]);
        sumGTF += G<float>(seed[i]);
        sumPGF += PG<float>(seed[i]);
    }
    std::ofstream wyniki;
    wyniki.open("Wyniki/errors.csv", std::ios_base::app);
    wyniki << std::fixed << std::setprecision(20);
    wyniki << SIZE << "," <<sumGTD/10 << "," << sumPGD/10 << "," << sumGTF/10 << "," << sumPGF/10 << "\n";
    wyniki.close();
    std::cout<<"END"<<std::endl;
    return 0;
}
