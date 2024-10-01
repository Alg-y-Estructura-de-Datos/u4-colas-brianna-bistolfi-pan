#include <iostream>
#include "Cola/Cola.h"
#include "Pila/Pila.h"

using namespace std;


void mostrar(Pila<int>& pila) {

    if (pila.esVacia()) {
        cout << "La pila esta vacia" << endl;
    } else {
        Pila<int> auxx;
        while (!pila.esVacia()) {
            int valor = pila.pop();
            cout << valor << endl;
            auxx.push(valor);
        }

        while (!auxx.esVacia()) {
            pila.push(auxx.pop());
        }
    }
}


void mostrar(Cola<int> &cola) {
    if (cola.esVacia()) {
        cout << "La Cola esta vacia" << endl;
    } else {
        Cola<int> aux;
        while (!cola.esVacia()) {
            int valor = cola.desencolar();
            cout << valor << " ";
            aux.encolar(valor);
        }

        while (!aux.esVacia()) {
            cola.encolar(aux.desencolar());
        }
    }
}

void colapila(Cola<int> &cola, Pila<int> &pila) {
    Cola<int> aux;

    while (!cola.esVacia()) {
        int valor = cola.desencolar();
        if (valor % 2 != 0) {
            pila.push(valor);
        } else {
            aux.encolar(valor);
        }
    }
    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
}

int main() {
    Cola<int> cola;
    Pila<int> pila;

    cola.encolar(1);
    cola.encolar(3);
    cola.encolar(2);
    cola.encolar(4);
    cola.encolar(5);
    cola.encolar(8);

    cout << "Cola Incial: " << endl;
    mostrar(cola);

    colapila(cola, pila);

    cout << "\nCola despues de operacion: " << endl;
    mostrar(cola);
    cout << "\nPila despues de operacion: " << endl;
    mostrar(pila);

    return 0;
}
