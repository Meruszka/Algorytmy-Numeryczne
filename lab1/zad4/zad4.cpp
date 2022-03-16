#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>

// cytat z StackOverflow (dużo szybsza funkcja potęgująca)
double fastpot(double x, long y){
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

double zad4(double x, long kroki){
    double sumlog = 0;
    double sumarc = 0;
    double templog = x;
    double temparc = x;
    double tablog[kroki]{0};
    double tabarc[kroki]{0};
    double wynik = 0;
    for(long i=2; i<kroki; i++){
        tablog[i] = templog;
        tabarc[i] = temparc;
        templog = (-1)*(templog)*(x)*(i-1)/i;
        temparc = (-1)*(temparc)*(fastpot(x, 2))*((2*(i-1))-1)/((2*i)-1);
    }
    for(long i=kroki-1; i>=2; i--){
        sumlog += tablog[i];
        sumarc += tabarc[i];
    }
    wynik = sumlog * sumarc;
    return wynik;
}


int main(int argc, char *argv[])
{   
    //ln(1 + x) · arctan(x)
    std::cout.precision(25);
    double number = 0.1;
    long kroki = 0;
    std::cin>>kroki;
    double w = zad4(number, kroki);
    std::cout<<"0.0094994371897874237131657982374337312586560454954487194634"<<std::endl;
    std::cout<<w<<std::endl;
    return 0;
}