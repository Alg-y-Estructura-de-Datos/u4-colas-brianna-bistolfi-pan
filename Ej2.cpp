#include <iostream>
#include "Cola/Cola.h"

using namespace std;

void mostrar(Cola<int> &cola) {
    Cola<int> aux;

    while (!cola.esVacia()) {
        int valor = cola.desencolar();
        cout << valor << " ";
        aux.encolar(valor);
    }

    cout << endl;

    while (!aux.esVacia()) {
        int valor = aux.desencolar();
        cola.encolar(valor);
    }
}

void mayor(Cola<int> &cola, const int &n) {
    Cola<int> aux;

    while (!cola.esVacia()) {
        int valor = cola.desencolar();
        if (valor <= n) {   aux.encolar(valor); }
    }

    while (!aux.esVacia()) {
        int valor = aux.desencolar();
        cola.encolar(valor);
    }
}


int main() {
    Cola<int> cola1;

    cola1.encolar(1);
    cola1.encolar(3);
    cola1.encolar(6);
    cola1.encolar(10);
    cola1.encolar(6);
    cola1.encolar(9);

    cout << "la cola antes de la operacion: " << endl;
    mostrar(cola1);

    cout << "la cola luego de la operacion: " << endl;
    mayor(cola1, 9);

    mostrar(cola1);


    return 0;
}
