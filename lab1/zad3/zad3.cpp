#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>

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
        temparc = (-1)*temparc*(fastpot(x, 2))*((2*(i-1))-1)/((2*i)-1);
    }
    wynik = sumlog * sumarc;
    return wynik;
}


int main(int argc, char *argv[])
{   
    //ln(1 + x) · arctan(x)
    std::cout.precision(20);
    double number = 0.1;
    int kroki = 1000;
    std::cin>>kroki;
    double w = zad3(number, kroki);
    std::cout<<"0.0094994371897874237131657982374337312586560454954487194634"<<std::endl;
    std::cout<<w<<std::endl;
    return 0;
}