#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>

double pot(double x, int y){
    // x^y
    double wynik = 1;
    for(int i=0; i<y; i++){
        wynik = wynik * x;
    }
    return wynik;
}
// cytat z StackOverflow (dużo szybsza funkcja potęgująca)
double fastpot(double x, int y){
    double temp;
    if(y==0){
        return 1;
    }
    temp = fastpot(x, y / 2);
    if((y%2) ==0){
        return temp * temp;
    }else{
        if(y > 0){
            return x * temp * temp;
        }else{
            return (temp * temp)/x;
        }
    }
}
// koniec cytatu


double logn(double liczba, double krok){
    if(krok == 0){
        return liczba;
    }
    krok++;
    return fastpot(-1, krok)*(fastpot(liczba, krok)/(krok));
}
double arctan(double liczba, double krok){
    if(krok == 0){
        return liczba;
    }
    if(krok == 1){
        krok++;
        return (-1)*(fastpot(liczba, ((2*krok)-1))/((2*krok)-1));
    }
    krok++;
    return (fastpot(liczba, ((2*krok)-1))/((2*krok)-1));
}

double zad1(double x, int kroki){
    double sumlog = 0;
    double sumarc = 0;
    for(int i=0; i<kroki; i++){
        sumlog += logn(x, i);
        sumarc += arctan(x, i);
        std::cout<<"log: "<<logn(x,i)<<std::endl<<"arctan: "<<arctan(x,i)<<std::endl;
    }
    return sumarc * sumlog;
}
int main(int argc, char *argv[])
{   
    //ln(1 + x) · arctan(x)
    std::cout.precision(20);
    double number = 0.1;
    int kroki = 0;
    std::cin>>kroki;
    double w1;
    std::cout<<"0.0094994371897874237131657982374337312586560454954487194634"<<std::endl;
    std::cout<<"zad1:"<<std::endl;
    w1 = zad1(number, kroki);
    std::cout<<w1<<std::endl;
    return 0;
}