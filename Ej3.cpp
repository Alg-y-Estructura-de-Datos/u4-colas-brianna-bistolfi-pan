#include <iostream>
#include "Cola/Cola.h"

using namespace std;

void mostrarcola(Cola<int> &cola) {
    Cola<int> aux;

    while (!cola.esVacia()) {
        int valor = cola.desencolar();
        cout << valor << " ";
        aux.encolar(valor);
    }

    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar()); //reponer
    }
}


void eliminarocurrencia(Cola<int> &cola, const int &n) {
    Cola<int> aux;
    bool encontrado = false;

    while (!cola.esVacia()) {
        int valor = cola.desencolar();
        if (valor == n) {
            if (!encontrado) {
                encontrado = true;
                aux.encolar(valor);
            } else
            {}
        } else {

            aux.encolar(valor);
        }
    }

    if (!encontrado) {
        cout << "no se encontro numero en la cola" << endl;
    }


    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
}

int main() {
    Cola<int> cola;
    int n;
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);
    cola.encolar(4);
    cola.encolar(2);

    cout << "Cola Inicial: " << endl;
    mostrarcola(cola);

    cout << "\ningrese numero para eliminar: " << endl;
    cin >> n;

    eliminarocurrencia(cola, n);

    cout << "\nCola despues de buscar Ocurrencia: " << endl;
    mostrarcola(cola);

    return 0;
}
