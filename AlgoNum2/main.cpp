#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <fstream>
#include <Eigen>


#include "mojamacierz.h"
#include "mojwektor.h"

#define SIZE 200

double PGD(int seed){
    const int sB = SIZE;
    double A[sB*sB];
    double B[sB];
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distr(-65536, 65536 - 1);
    for(int i=0; i<sB*sB; i++){
        double r = distr(gen);
        A[i] = r/65536;
    }
    for(int i=0; i<sB; i++){
        double r = distr(gen);
        B[i] = r/65536;
    }


    Eigen::Map<Eigen::MatrixXd> Amat(A,sB,sB);
    Eigen::Map<Eigen::VectorXd> Bvec(B,sB);
    Eigen::VectorXd Xwynik(sB);

    MojaMacierz<double, sB>macierz;
    MojWektor<double, sB>wektor;


    macierz.setValues(A);
    wektor.setValues(B);

    MojWektor<double, sB>wynik = macierz.PGauss(wektor);
    Xwynik = Amat.transpose().partialPivLu().solve(Bvec);
    double sum = 0;
    for(int i=0; i<sB; i++){
        sum += abs(abs(wynik(i)) - abs(Xwynik[i]));
    }
    return sum;
}
float PGF(int seed){
    const int sB = SIZE;
    float A[sB*sB];
    float B[sB];
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distr(-65536, 65536 - 1);
    for(int i=0; i<sB*sB; i++){
        float r = distr(gen);
        A[i] = r/65536;
    }
    for(int i=0; i<sB; i++){
        float r = distr(gen);
        B[i] = r/65536;
    }


    Eigen::Map<Eigen::MatrixXf> Amat(A,sB,sB);
    Eigen::Map<Eigen::VectorXf> Bvec(B,sB);
    Eigen::VectorXf Xwynik(sB);

    MojaMacierz<float, sB>macierz;
    MojWektor<float, sB>wektor;


    macierz.setValues(A);
    wektor.setValues(B);

    MojWektor<float, sB>wynik = macierz.PGauss(wektor);
    Xwynik = Amat.transpose().partialPivLu().solve(Bvec);

    float sum = 0;
    for(int i=0; i<sB; i++){
        sum += abs(abs(wynik(i)) - abs(Xwynik[i]));
    }
    return sum;
}
double GTD(int seed){

    const int sB = SIZE;
    double A[sB*sB];
    double B[sB];
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distr(-65536, 65536 - 1);
    for(int i=0; i<sB*sB; i++){
        double r = distr(gen);
        A[i] = r/65536;
    }
    for(int i=0; i<sB; i++){
        double r = distr(gen);
        B[i] = r/65536;
    }


    Eigen::Map<Eigen::MatrixXd> Amat(A,sB,sB);
    Eigen::Map<Eigen::VectorXd> Bvec(B,sB);
    Eigen::VectorXd Xwynik(sB);

    MojaMacierz<double, sB>macierz;
    MojWektor<double, sB>wektor;


    macierz.setValues(A);
    wektor.setValues(B);

    MojWektor<double, sB>wynik = macierz.PGauss(wektor);
    Xwynik = Amat.transpose().colPivHouseholderQr().solve(Bvec);
    double sum = 0;
    for(int i=0; i<sB; i++){
        sum += abs(abs(wynik(i)) - abs(Xwynik[i]));
    }
    return sum;
}
float GTF(int seed){
    const int sB = SIZE;
    float A[sB*sB];
    float B[sB];
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distr(-65536, 65536 - 1);
    for(int i=0; i<sB*sB; i++){
        float r = distr(gen);
        A[i] = r/65536;
    }
    for(int i=0; i<sB; i++){
        float r = distr(gen);
        B[i] = r/65536;
    }


    Eigen::Map<Eigen::MatrixXf> Amat(A,sB,sB);
    Eigen::Map<Eigen::VectorXf> Bvec(B,sB);
    Eigen::VectorXf Xwynik(sB);

    MojaMacierz<float, sB>macierz;
    MojWektor<float, sB>wektor;


    macierz.setValues(A);
    wektor.setValues(B);

    MojWektor<float, sB>wynik = macierz.PGauss(wektor);
    Xwynik = Amat.transpose().colPivHouseholderQr().solve(Bvec);

    float sum = 0;
    for(int i=0; i<sB; i++){
        sum += abs(abs(wynik(i)) - abs(Xwynik[i]));
    }
    return sum;
}
int main()
{
    int seed[10] = {74, 66, 33, 173, 14, 13, 190, 175, 45, 151};
    double sumGTD = 0;
    float sumGTF= 0;
    double sumPGD = 0;
    float sumPGF= 0;
    for(int i=0; i<10; i++){
        std::cout<<i<<std::endl;
        sumGTD += GTD(seed[i]);
        sumGTF += GTF(seed[i]);

        sumPGD += PGD(seed[i]);
        sumPGF += PGF(seed[i]);
    }
    std::ofstream wyniki;
    wyniki.open("wyniki.csv", std::ios_base::app);
    wyniki << std::fixed << std::setprecision(20);
    wyniki << SIZE << "," <<sumGTD/10 << "," <<sumGTF/10<< "," <<sumPGD/10<< "," << sumPGF/10 << "\n";

    return 0;
}
