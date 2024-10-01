#include <iostream>
#include <limits>
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

void sumarelemento(Cola<int> &cola, const int &n, int &suma) {
    Cola<int> aux;
    bool encontrado = false;

    while (!cola.esVacia()) {
        int valor = cola.desencolar();
        aux.encolar(valor);
        if (valor == n) {
            encontrado = true;
            break;
        }
        suma += valor;
    }

    if (!encontrado) {
        cout << "No se encontro " << n << " en la cola" << endl;
    }

    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar()); //reponer
    }
}

int main() {
    Cola<int> cola;
    int n;
    int num;
    int suma = 0;

    cout << "CREAR COLA, ingrese 'q' para terminar: " << endl;
    while (true) {
        cout << "ingrese numero " << endl;
        if (cin >> n) {
            cola.encolar(n);
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }


    cout << "Cola Inicial: " << endl;
    mostrarcola(cola);

    cout << "\ningrese numero entero: " << endl;
    cin >> num;

    sumarelemento(cola, num, suma);

    cout << "\nLa suma es: " << suma << endl;
}
