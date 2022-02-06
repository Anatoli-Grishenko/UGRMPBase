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

	 /// ...
    cout << "\nbyte apagado bits: " << endl;
    CVAL << to_string(b) << endl;


    cout << "\nInicializo el byte a partir de un vector de bool " << endl;
	 /// ...
    CVAL << to_string(b) << endl;
    cout << "\nAhora enciendo los bits 0, 1 y 2 con la funcion on \n";
	 /// ...
    CVAL << to_string(b) << endl;
	 /// ...
    CVAL << to_string(b) << endl;
	 /// ...
    CVAL << to_string(b) << endl;

    cout << "\nLos bits encendidos estan en las posiciones: " << endl;
	 /// ...
    for (int i = 0; i < size; i++)
        CVAL << posiciones[i] << ",";
	 /// ...
    CVAL << endl;

    cout << "\nTodos encendidos: " << endl;
	 /// ...
    CVAL << to_string(b) << endl;

    cout << "Todos apagados: " << endl;
	 /// ...
    CVAL << to_string(b) << endl;

    cout << "\n\nEjemplo 1 \n";
	 /// ...
    CVAL << to_string(b) << endl;

    CVAL << to_string(b) << endl;
    for (int i = 6; i >= 0; i--) {
	 /// ...
	 /// ...
        CVAL << to_string(b) << endl;
    }

    cout << "\nAhora la animacion\nEjemplo 2 \n";
	 /// ...
    CVAL << to_string(b) << endl;
    for (int i = 0; i < 4; i++) {
	 /// ...
	 /// ...
        CVAL << to_string(b) << endl;
    }

    for (int i = 3; i >= 0; i--) {
	 /// ...
	 /// ...
        CVAL << to_string(b) << endl;
    }

    return 0;
}
