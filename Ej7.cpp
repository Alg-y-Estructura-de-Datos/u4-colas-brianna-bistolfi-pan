#include <iostream>
#include "Cola/Cola.h"


using namespace std;

void mostrarcola(Cola<string> &cola) {
    Cola<string> aux;

    while (!cola.esVacia()) {
        string documento = cola.desencolar();
        cout << documento << "\n" ;
        aux.encolar(documento);
    }

    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
}

void imprimir(Cola<string> &cola) {
    if (cola.esVacia()) {
        cout << "No hay documentos en la cola de impresion." << endl;
    }
    else {
        cout << "imprimendo documento... " << cola.peek()<<endl;
        cola.desencolar();
    }
}


int main() {
    Cola<string> cola;

    int op;

    while (op < 4) {
        cout << "Que desea hacer:  " << endl;
        cout << "1. Agregar documento. " << endl;
        cout << "2. imprimir documentos en orden eviado" << endl;
        cout << "3. mostrar estado de cola de impresion." << endl;
        cout << "4. salir " << endl;
        cin >> op;

        string documento;

        switch (op) {
            case 1: cout << "ingrese documento: " << endl;
            cin.ignore();
                getline(cin, documento);
                cola.encolar(documento);
                cout << "Documento agregado a la cola de impresion." << endl;

                break;
            case 2: imprimir(cola);
                break;
            case 3: mostrarcola(cola);
                break;
            case 4: exit(-1);
                break;
            default: cout << " opcion incorrecta " << endl;
        }
    }
    return 0;
}
