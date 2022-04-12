#include <iostream>
#include <iomanip>
#include <cstdlib>

double pot(double x, int y){
    // x^y
    double wynik = 1.0;
    for(int i=0; i<y; i++){
        wynik = wynik * x;
    }
    return wynik;
}
double logn(double liczba, double krok){
        // (-1)^(a-1)*(x^a)/a; a=2, a=>inf
    return pot(-1, krok-1)*(pot(liczba, krok)/(krok));
}
double arctan(double liczba, double krok){
        // (-1)^(a-1)*(x^(2a-1))/(2a-1); a=2, a=>inf
    return pot(-1, krok-1)*(pot(liczba, ((2*krok)-1))/((2*krok)-1));
}
int main(int argc, char *argv[])
{   
    //ln(1 + x) · arctan(x)
    std::cout.precision(15);
    double x = 0.1;
    int ilosc_krokow = 100000;
    double sumlog = x;
    double sumarc = x;
    double wynik = 0;
    for(int i=2; i<ilosc_krokow; i++){
        sumlog += logn(x, i);
        sumarc += arctan(x, i);
    }
    wynik = sumarc * sumlog;
    std::cout<<wynik;
    return 0;
}