/**
 * @file main.cpp
 * @author DECSAI
 * @note To be debugged. Output should be 1.5. What is wrong? 1, 2, 3 or 4?
 */
#include <iostream>
using namespace std;
int main() {
    // 1 Declaraciones e inicializaciones
    const int n=3;
    double datos[n]={0.5,1.5,2.5};
    double media=0, suma=0;
    
    // 2 Calcular la suma
    suma=datos[0]+datos[1]+datos[2];
    // 3 Calcular la media
    media=1/n*suma;
    // 4 Mostrar resultados
    cout << "La media es "<<media<< endl; 
    
    return 0;
}

