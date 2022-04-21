#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <random>
#include <fstream>
#include <Eigen>

#include "mojamacierz.h"
#include "mojwektor.h"

#define SIZE 400

time_t start1, end1, start2, end2;


double PGD(int seed){
    std::cout<<"SIEMA2"<<std::endl;
    double A[SIZE*SIZE];
    double B[SIZE];
    MojaMacierz<double, SIZE> macierz;
    MojWektor<double, SIZE> wektor;
    Eigen::VectorXd Xwynik(SIZE);

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distr(-65536, 65536 - 1);
    for(int i=0; i<SIZE*SIZE; i++){
        double r = distr(gen);
        A[i] = r/65536;
    }
    for(int i=0; i<SIZE; i++){
        double r = distr(gen);
        B[i] = r/65536;
    }

    Eigen::Map<Eigen::MatrixXd> matrix(A,SIZE,SIZE);
    Eigen::Map<Eigen::VectorXd> vec(B,SIZE);
    macierz.setValues(A);
    wektor.setValues(B);
    // Obliczenia
    time(&start1);
        std::ios_base::sync_with_stdio(false);
        MojWektor<double, SIZE>wynik;
        wynik = macierz.PGauss(wektor);
    time(&end1);

    time(&start2);
        std::ios_base::sync_with_stdio(false);
        Xwynik = matrix.transpose().partialPivLu().solve(vec);
    time(&end2);

    std::ofstream czas1;
    czas1.open("Wyniki/PGD1C.csv", std::ios_base::app);
    czas1 << std::fixed << std::setprecision(20);
    czas1 << SIZE << "," << double(end1-start1) << "\n";

    std::ofstream czas2;
    czas2.open("Wyniki/PGD2C.csv", std::ios_base::app);
    czas2 << std::fixed << std::setprecision(20);
    czas2 << SIZE << "," << double(end2-start2) << "\n";

    czas1.close();
    czas2.close();

    double sum = 0;
    for(int i=0; i<SIZE; i++){
        sum += abs(abs(wynik(i)) - abs(Xwynik[i]));
    }
    return sum;
}

double GTD(int seed){
    std::cout<<"SIEMA"<<std::endl;
    double A[SIZE*SIZE];
    double B[SIZE];
    MojaMacierz<double, SIZE> macierz;
    MojWektor<double, SIZE> wektor;
    Eigen::VectorXd Xwynik(SIZE);

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distr(-65536, 65536 - 1);
    for(int i=0; i<SIZE*SIZE; i++){
        double r = distr(gen);
        A[i] = r/65536;
    }
    for(int i=0; i<SIZE; i++){
        double r = distr(gen);
        B[i] = r/65536;
    }
    Eigen::Map<Eigen::MatrixXd> matrix(A,SIZE,SIZE);
    Eigen::Map<Eigen::VectorXd> vec(B,SIZE);
    macierz.setValues(A);
    wektor.setValues(B);
    // Obliczenia
    time(&start1);
        MojWektor<double, SIZE>wynik;
        wynik = macierz.Gauss(wektor);
    time(&end1);

    time(&start2);
        Xwynik = matrix.transpose().colPivHouseholderQr().solve(vec);
    time(&end2);

    std::ofstream czas1;
    czas1.open("Wyniki/GTD1C.csv", std::ios_base::app);
    czas1 << std::fixed << std::setprecision(20);
    czas1 << SIZE << "," << double(end1-start1) << "\n";

    std::ofstream czas2;
    czas2.open("Wyniki/GTD1C.csv", std::ios_base::app);
    czas2 << std::fixed << std::setprecision(20);
    czas2 << SIZE << "," << double(end2-start2) << "\n";

    czas1.close();
    czas2.close();


    double sum = 0;
    for(int i=0; i<SIZE; i++){
        sum += abs(abs(wynik(i)) - abs(Xwynik[i]));
    }
    return sum;
}

int main()
{
    int seed[10] = {74, 66, 33, 173, 14, 13, 190, 175, 45, 151};
    double sumGTD, sumPGD;
    for(int i=0; i<10; i++){
        sumGTD += GTD(seed[i]);
        sumPGD += PGD(seed[i]);
    }
    std::ofstream wyniki;
    wyniki.open("Wyniki/WynikiDouble.csv", std::ios_base::app);
    wyniki << std::fixed << std::setprecision(20);
    wyniki << SIZE << "," <<sumGTD/10 << "," <<sumPGD/10<<"\n";
    wyniki.close();
    return 0;
}
