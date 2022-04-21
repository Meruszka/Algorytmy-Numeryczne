#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <random>
#include <fstream>
#include <Eigen>
#include<chrono>

#include "mojamacierz.h"
#include "mojwektor.h"

#define SIZE 100
#define RANGE_MIN -65536
#define RANGE_MAX 65535

double PGD(int seed){
    double A[SIZE*SIZE];
    double B[SIZE];
    MojaMacierz<double, SIZE> macierz;
    MojWektor<double, SIZE> wektor;
    MojWektor<double, SIZE>wynik;
    Eigen::VectorXd Xwynik(SIZE);

    std::srand(seed);
    for(int i=0; i<SIZE*SIZE; i++){
        double r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        A[i] = r/65536;
    }
    for(int i=0; i<SIZE; i++){
        double r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        B[i] = r/65536;
    }

    Eigen::Map<Eigen::MatrixXd> matrix(A,SIZE,SIZE);
    Eigen::Map<Eigen::VectorXd> vec(B,SIZE);
    macierz.setValues(A);
    wektor.setValues(B);
    // Obliczenia
    // ==================
        std::chrono::steady_clock::time_point start1 = std::chrono::steady_clock::now();
            wynik = macierz.PGauss(wektor);
        std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

        std::chrono::steady_clock::time_point start2 = std::chrono::steady_clock::now();
            Xwynik = matrix.transpose().partialPivLu().solve(vec);
        std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

        std::ofstream czas;
        czas.open("Wyniki/Czasy/PGD.csv", std::ios_base::app);
        czas << std::fixed << std::setprecision(20);
        czas << SIZE << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end1 - start1).count() << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end2 - start2).count() <<"\n";
        czas.close();
    // ===============

    double sum = 0;
    for(int i=0; i<SIZE; i++){
        sum += abs(abs(wynik(i)) - abs(Xwynik[i]));
    }
    return sum;
}

double GTD(int seed){
    double A[SIZE*SIZE];
    double B[SIZE];
    MojaMacierz<double, SIZE> macierz;
    MojWektor<double, SIZE> wektor;
    MojWektor<double, SIZE> wynik;
    Eigen::VectorXd Xwynik(SIZE);

    std::srand(seed);
    for(int i=0; i<SIZE*SIZE; i++){
        double r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        A[i] = r/65536;
    }
    for(int i=0; i<SIZE; i++){
        double r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        B[i] = r/65536;
    }
    Eigen::Map<Eigen::MatrixXd> matrix(A,SIZE,SIZE);
    Eigen::Map<Eigen::VectorXd> vec(B,SIZE);
    macierz.setValues(A);
    wektor.setValues(B);
    // Obliczenia
    // ==================
        std::chrono::steady_clock::time_point start1 = std::chrono::steady_clock::now();
            wynik = macierz.Gauss(wektor);
        std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

        std::chrono::steady_clock::time_point start2 = std::chrono::steady_clock::now();
            Xwynik = matrix.transpose().colPivHouseholderQr().solve(vec);
        std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

        std::ofstream czas;
        czas.open("Wyniki/Czasy/GTD.csv", std::ios_base::app);
        czas << std::fixed << std::setprecision(20);
        czas << SIZE << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end1 - start1).count() << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end2 - start2).count() <<"\n";
        czas.close();
    // ===============

    double sum = 0;
    for(int i=0; i<SIZE; i++){
        sum += abs(abs(wynik(i)) - abs(Xwynik[i]));
    }
    return sum;
}

float PGF(int seed){
    float A[SIZE*SIZE];
    float B[SIZE];
    MojaMacierz<float, SIZE> macierz;
    MojWektor<float, SIZE> wektor;
    MojWektor<float, SIZE> wynik;
    Eigen::VectorXf Xwynik(SIZE);

    std::srand(seed);
    for(int i=0; i<SIZE*SIZE; i++){
        float r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        A[i] = r/65536;
    }
    for(int i=0; i<SIZE; i++){
        float r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        B[i] = r/65536;
    }

    Eigen::Map<Eigen::MatrixXf> matrix(A,SIZE,SIZE);
    Eigen::Map<Eigen::VectorXf> vec(B,SIZE);
    macierz.setValues(A);
    wektor.setValues(B);
    // Obliczenia
    // ==================
        std::chrono::steady_clock::time_point start1 = std::chrono::steady_clock::now();
            wynik = macierz.PGauss(wektor);
        std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

        std::chrono::steady_clock::time_point start2 = std::chrono::steady_clock::now();
            Xwynik = matrix.transpose().partialPivLu().solve(vec);
        std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

        std::ofstream czas;
        czas.open("Wyniki/Czasy/PGF.csv", std::ios_base::app);
        czas << std::fixed << std::setprecision(20);
        czas << SIZE << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end1 - start1).count() << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end2 - start2).count() <<"\n";
        czas.close();
    // ===============

    float sum = 0;
    for(int i=0; i<SIZE; i++){
        sum += abs(abs(wynik(i)) - abs(Xwynik[i]));
    }
    return sum;
}

float GTF(int seed){
    float A[SIZE*SIZE];
    float B[SIZE];
    MojaMacierz<float, SIZE> macierz;
    MojWektor<float, SIZE> wektor;
    Eigen::VectorXf Xwynik(SIZE);
    MojWektor<float, SIZE>wynik;

    std::srand(seed);
    for(int i=0; i<SIZE*SIZE; i++){
        float r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        A[i] = r/65536;
    }
    for(int i=0; i<SIZE; i++){
        float r = RANGE_MIN + std::rand() % (( RANGE_MAX + 1 ) - RANGE_MIN);
        B[i] = r/65536;
    }
    Eigen::Map<Eigen::MatrixXf> matrix(A,SIZE,SIZE);
    Eigen::Map<Eigen::VectorXf> vec(B,SIZE);
    macierz.setValues(A);
    wektor.setValues(B);
    // Obliczenia
    // ==================
        std::chrono::steady_clock::time_point start1 = std::chrono::steady_clock::now();
            wynik = macierz.Gauss(wektor);
        std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

        std::chrono::steady_clock::time_point start2 = std::chrono::steady_clock::now();
            Xwynik = matrix.transpose().colPivHouseholderQr().solve(vec);
        std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

        std::ofstream czas;
        czas.open("Wyniki/Czasy/GTF.csv", std::ios_base::app);
        czas << std::fixed << std::setprecision(20);
        czas << SIZE << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end1-start1).count() << "," << std::chrono::duration_cast<std::chrono::nanoseconds> (end2-start2).count() <<"\n";
        czas.close();
    // ===============
    float sum = 0;
    for(int i=0; i<SIZE; i++){
        sum += abs(abs(wynik(i)) - abs(Xwynik[i]));
    }
    return sum;
}
int main()
{
    int seed[10] = {74, 66, 33, 173, 14, 13, 190, 175, 45, 151};
    std::cout<<"START"<<std::endl;
    double sumGTD, sumPGD;
    float sumGTF, sumPGF;
    for(int i=0; i<10; i++){
        sumGTD += GTD(seed[i]);
        sumPGD += PGD(seed[i]);
        sumGTF += GTF(seed[i]);
        sumPGF += PGF(seed[i]);
    }
    std::ofstream wyniki;
    wyniki.open("Wyniki/Błędy.csv", std::ios_base::app);
    wyniki << std::fixed << std::setprecision(20);
    wyniki << SIZE << "," <<sumGTD/10 << "," << sumPGD/10 << "," << sumGTF/10 << "," << sumPGF/10 << "\n";
    wyniki.close();
    std::cout<<"END"<<std::endl;
    return 0;
}
