/**
 * @file main.cpp
 * @author DECSAI
 * @note To be debugged. The execution shows several errors in calculations
 * marked as nan (Not A Number). 
 */
#include <iostream>
#include <cmath>
using namespace std;

// 1 Declaración de la función
double f(int x)  {
    // 2 Declaración de variables
    double res=0;
    // 3 Caĺculos primarios
    res = -x;
    res += 1;
    //  4 Caĺculo principal
    res = sqrt(res);
    // 5 Devolución del resultado
    return res;
}

int main() {
    int i;
    // Bucle for
    for (i=-1; i<5; i++) {
        cout << f(i) <<endl; // Siempre debe imprimir un número válido
    }

    return 0;
}

