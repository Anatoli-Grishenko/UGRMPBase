/**
 * @file main.cpp
 * @author MP
 */
#include <iostream>
#include <cstring>
#include "MPTools.h"
#include "Byte.h"
using namespace std;

int main() {
    Byte b;
    int posiciones[8];
    int size;
    bool inicial[] = {1, 0, 1, 0, 0, 0, 0, 0};

    offByte(b);
    cout << "\nbyte apagado bits: " << endl;
    CVAL << to_string(b) << endl;

    // enciendo dos bits
    cout << "\nInicializo el byte a partir de un vector de bool " << endl;
    encodeByte(b, inicial);
    CVAL << to_string(b) << endl;
    cout << "\nAhora enciendo los bits 0, 1 y 2 con la funcion on \n";
    onBit(b, 0);
    CVAL << to_string(b) << endl;
    onBit(b, 1);
    CVAL << to_string(b) << endl;
    onBit(b, 2);
    CVAL << to_string(b) << endl;

    cout << "\nLos bits encendidos estan en las posiciones: " << endl;
    decomposeByte(b, posiciones, size);
    for (int i = 0; i < size; i++)
        CVAL << posiciones[i] << ",";

    CVAL << endl;

    cout << "\nTodos encendidos: " << endl;
    onByte(b);
    CVAL << to_string(b) << endl;

    cout << "Todos apagados: " << endl;
    offByte(b);
    CVAL << to_string(b) << endl;

    cout << "\n\nEjemplo 1 \n";
    onByte(b);
    CVAL << to_string(b) << endl;
    offBit(b, 7);
    CVAL << to_string(b) << endl;
    for (int i = 6; i >= 0; i--) {
        onBit(b, i + 1);
        offBit(b, i);
        CVAL << to_string(b) << endl;
    }

    cout << "\nAhora la animacion\nEjemplo 2 \n";
    onByte(b);
    CVAL << to_string(b) << endl;
    for (int i = 0; i < 4; i++) {
        offBit(b, i);
        offBit(b, 7 - i);
        CVAL << to_string(b) << endl;
    }

    for (int i = 3; i >= 0; i--) {
        onBit(b, i);
        onBit(b, 7 - i);
        CVAL << to_string(b) << endl;
    }

    return 0;
}
