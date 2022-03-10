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
        // (-1)^(a-1)*(x^a)/a; a=2, a=>inf
    return fastpot(-1, krok-1)*(fastpot(liczba, krok)/(krok));
}
double arctan(double liczba, double krok){
        // (-1)^(a-1)*(x^(2a-1))/(2a-1); a=2, a=>inf
    if(krok ==2){
        return (-1)*(fastpot(liczba, ((2*krok)-1))/((2*krok)-1));
    }
    return (fastpot(liczba, ((2*krok)-1))/((2*krok)-1));
}
double zad1(double x, int kroki){
    double sumlog = x;
    double sumarc = x;
    double wynik = 0;
    for(int i=2; i<kroki; i++){
        sumlog += logn(x, i);
        sumarc += arctan(x, i);
        std::cout<<"log: "<<logn(x,i)<<std::endl<<"arctan: "<<arctan(x,i)<<std::endl;

    }
    wynik = sumarc * sumlog;
    return wynik;
}
double zad2(double x, int kroki){
    double sumlog = 0;
    double sumarc = 0;
    double wynik = 0;
    for(int i=kroki; i>2; i--){
        sumlog += logn(x, i);
        sumarc += arctan(x, i);
    }
    sumlog += x;
    sumarc += x;
    wynik = sumarc * sumlog;
    return wynik;
}
double zad3(double x, int kroki){
    double sumlog = 0;
    double sumarc = 0;
    double templog = x;
    double temparc = x;
    double wynik = 0;
    for(int i=2; i<kroki; i++){
        sumlog += templog;
        sumarc += temparc;
        templog = (-1)*(templog)*(x)*(i-1)/i;
        temparc = temparc*(fastpot(x, 2))*((2*(i-1))-1)/((2*i)-1);
    }
    wynik = sumlog * sumarc;
    return wynik;
}
double zad4(double x, int kroki){
    double sumlog = 0;
    double sumarc = 0;
    double templog = x;
    double temparc = x;
    double wynik = 0;
    for(int i=kroki; i<2; i++){
        sumlog += templog;
        sumarc += temparc;
        templog = (-1)*(templog)*(x)*(i-1)/i;
        temparc = temparc*(fastpot(x, 2))*((2*(i-1))-1)/((2*i)-1);
    }
    wynik = sumlog * sumarc;
    return wynik;
}
int main(int argc, char *argv[])
{   
    //ln(1 + x) · arctan(x)
    std::cout.precision(20);
    double number = 0.1;
    int steps = 10;
    double w1;
    double w2;
    double w3;
    double w4;
    std::cout<<"zad1:"<<std::endl;
    w1 = zad1(number, steps);
    std::cout<<w1<<std::endl;

    std::cout<<"zad2:"<<std::endl;
    w2 = zad2(number, steps);
    std::cout<<w2<<std::endl;

    std::cout<<"zad3:"<<std::endl;
    w3 = zad3(number, steps);
    std::cout<<w3<<std::endl;
    
    std::cout<<"zad4:"<<std::endl;
    w4 = zad4(number, steps);
    std::cout<<w4<<std::endl;

    return 0;
}