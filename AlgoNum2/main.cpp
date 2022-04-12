#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "mojamacierz.h"
#include "mojwektor.h"
int main()
{
    srand (time(NULL));
    MojaMacierz<double, 3>macierz;
    MojWektor<double, 3>vec;
    MojWektor<double, 3>wynik;
    double war[3]={1, 0 ,0};
    double arr[10]={1, 1, 1,
                    1, 2, 5,
                    -1, 1, -1};


    macierz.setValues(arr);
    vec.setValues(war);
    macierz.Print();
    vec.Print();
    wynik = macierz.PGauss(vec);
    wynik.Print();
    return 0;
}
