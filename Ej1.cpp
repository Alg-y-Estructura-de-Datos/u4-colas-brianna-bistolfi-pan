#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void largo(Cola<char> &cola1, Cola<char> &cola2) {
    Cola<char> aux1;
    Cola<char> aux2;

    int contador1 = 0;
    int contador2 = 0;

    while (!cola1.esVacia()) {
        char valor = cola1.desencolar();
        aux1.encolar(valor);
        contador1++;
    }

    while (!cola2.esVacia()) {
        char valor = cola2.desencolar();
        aux2.encolar(valor);
        contador2++;
    }

    if (contador1 != contador2) {
        cout << "No coincide el largo, no son iguales" << endl;
    } else {
        int cont = 0;
        while (!aux1.esVacia() && !aux2.esVacia()) {
            char val1 = aux1.desencolar();
            char val2 = aux2.desencolar();
            cola1.encolar(val1);
            cola2.encolar(val2);
            if (val1 == val2) { cont++; }
        }

        if (contador1 == cont) {
            cout << "las colas son iguales" << endl;
        } else
            cout << "las colas No son iguales" << endl;
    }
}


int main() {
    Cola<char> cola1;
    Cola<char> cola2;

    cola1.encolar(1);
    cola1.encolar(2);
    cola1.encolar(3);
    cola2.encolar(1);
    cola2.encolar(2);
    cola2.encolar(3);
    cola2.encolar(4);

    largo(cola1, cola2);

    return 0;
}
