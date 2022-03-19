#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <cmath>

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
    if(krok == 1){
        return liczba;
    }
    return fastpot(-1, krok-1)*(fastpot(liczba, krok)/(krok));
}
double arctan(double liczba, double krok){
    if(krok == 1){
        return liczba;
    }
    return fastpot(-1, krok-1)*(fastpot(liczba, ((2*krok)-1))/((2*krok)-1));
}
double zad1(double x, int kroki){
    double sumlog=0;
    double sumarc=0;
    double wynik;
    for(int i=1; i<kroki+1; i++){
        sumlog += logn(x, i);
        sumarc += arctan(x, i);
    }
    wynik = sumarc * sumlog;
    return wynik;
}
double zad2(double x, int kroki){
    double sumlog = 0;
    double sumarc = 0;
    double wynik = 0;
    for(int i=kroki; i>=1; i--){
        sumlog += logn(x, i);
        sumarc += arctan(x, i);
    }
    wynik = sumarc * sumlog;
    return wynik;
}
double zad3(double x, int kroki){
    double sumlog=0;
    double sumarc=0;
    double templog = x;
    double temparc = x;
    double wynik = 0;
    for(int i=2; i<kroki+2; i++){
        sumlog += templog;
        sumarc += temparc;
        templog = (-1)*(templog)*(x)*(i-1)/i;
        temparc = (-1)*temparc*(fastpot(x, 2))*((2*(i-1))-1)/((2*i)-1);
    }
    wynik = sumlog * sumarc;
    return wynik;
}
double zad4(double x, int kroki){
    double sumlog=0;
    double sumarc=0;
    double templog = x;
    double temparc = x;
    double tablog[kroki]{0};
    double tabarc[kroki]{0};
    double wynik = 0;
    for(int i=2; i<kroki+2; i++){
        tablog[i] = templog;
        tabarc[i] = temparc;
        templog = (-1)*(templog)*(x)*(i-1)/i;
        temparc = (-1)*temparc*(fastpot(x, 2))*((2*(i-1))-1)/((2*i)-1);
    }
    for(int i=kroki; i>=2; i--){
        sumlog += tablog[i];
        sumarc += tabarc[i];
    }
    wynik = sumlog * sumarc;
    return wynik;
}
int main(int argc, char *argv[])
{   
    //ln(1 + x) · arctan(x)
    int steps=75;
    double w1;
    double w2;
    double w3;
    double w4;
    std::ofstream wyniki;
    wyniki.open("wyniki.csv");
    wyniki << std::fixed << std::setprecision(20);
    wyniki << "arg,zad1,zad2,zad3,zad4,dobre\n";
    
    for(double number=0.1; number<0.9; number+=0.000001){
        w1 = zad1(number, steps);
        w2 = zad2(number, steps);
        w3 = zad3(number, steps);        
        w4 = zad4(number, steps);
        wyniki << number << ',' << w1 << ',' << w2 << ',' << w3 << ',' << w4 << ',' << atan(number)*log(1+number) << '\n';
    }
    wyniki.close();
    return 0;
}