/**
 * @file main.cpp
 * @author DECSAI
 * @note To be debugged. The execution produces a segmentation fault error,
 * most likely due to an access to a vector out of its boundaries
 */
#include <iostream>
using namespace std;

int main() {
    // 1 La constante
    const int n=10;
    // 2 El vector skip
    int skip[n]={1,2,3,4,5,6,7,8,9,10},
            // 3 El vector data
            data[n]={10,9,8,7,6,5,4,3,2,1},
            i=0;
    // 3 El tipo de bucle y su condición
    do {
        // 4 Primer acceso
        i = i+skip[i];
        // 5 Segundo y tercer acceso
        data[i] = skip[i];
        // 6 Cuarto acceso
        cout << data[i] << endl;
    } while (i<n);
    return 0;
}

