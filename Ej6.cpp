#include <iostream>
#include  <ostream>
#include <string>
#include "Cola/Cola.h"

using namespace std;

class paciente {
public:
    string nombre;
    string telefono;

    paciente(): nombre(""), telefono("") {
    };

    paciente(const string &n, const string &t): nombre(n), telefono(t) {
    }

    friend ostream &operator<<(ostream &os, const paciente &pac) {
        os << " Nombre: " << pac.nombre << ". Telefono: " << pac.telefono;
        return os;
    }
};

void nuevopaciente(Cola<paciente> &colaconturno, Cola<paciente> &colasinturno) {
    string nombre, telefono;

    cin.ignore();
    cout << "Ingrese nombre del paciente: " << endl;
    getline(cin, nombre);
    cout << "ingrese telefono del paciente: " << endl;
    getline(cin, telefono);

    paciente pac;
    pac.nombre = nombre;
    pac.telefono = telefono;

    int op;
    cout << "1. con turno" << endl;
    cout << "2. sin turno" << endl;
    cin >> op;

    switch (op) {
        case 1: colaconturno.encolar(pac);
            break;
        case 2: colasinturno.encolar(pac);
            break;
        default: cout << "error en la opcion" << endl;
            exit(-1);
    }
}

void mostrarpacientesconturno(Cola<paciente> &colaconturno) {
    //COLA CON TURNO
    if (colaconturno.esVacia()) {
        cout << "No hay ningun paciente con turno" << endl;
    } else {
        Cola<paciente> aux;
        while (!colaconturno.esVacia()) {
            paciente valor = colaconturno.desencolar();
            cout << valor << endl;
            aux.encolar(valor);
        }

        while (!aux.esVacia()) {
            colaconturno.encolar(aux.desencolar());
        }
    }
}

void mostrarpacientessinturno(Cola<paciente> &colasinturno) {
    //COLA SIN TURNO
    if (colasinturno.esVacia()) {
        cout << "No hay ningun paciente Sin turno" << endl;
    } else {
        Cola<paciente> aux;
        while (!colasinturno.esVacia()) {
            paciente valor = colasinturno.desencolar();
            cout << valor << endl;
            aux.encolar(valor);
        }

        while (!aux.esVacia()) {
            colasinturno.encolar(aux.desencolar());
        }
    }
}

void atenderapacientes(Cola<paciente> &colaconturno, Cola<paciente> &colasinturno) {
    if (colaconturno.esVacia()) {
        cout << "\nNo hay ningun paciente con turno para atender" << endl;
    } else {
        cout << "\nse atiende paciente Con turno" << endl;
        while (!colaconturno.esVacia()) {
            paciente valor = colaconturno.desencolar();
            cout << "\nse atiende a paciente: " << valor;
        }
    }

    if (colasinturno.esVacia()) {
        cout << "\nNo hay ningun paciente Sin turno para atender" << endl;
    } else {
        cout << "\nse atiende paciente Sin turno" << endl;
        while (!colasinturno.esVacia()) {
            paciente valor = colasinturno.desencolar();
            cout << "\nse atiende a paciente: " << valor;
        }
    }
}

int main() {
    Cola<paciente> colaconturno;
    Cola<paciente> colasinturno;

   /* colaconturno.encolar(paciente("lorena", "29354345"));
    colaconturno.encolar(paciente("paulo", "2456342"));
    colaconturno.encolar(paciente("juan", "895367"));*/
    colasinturno.encolar(paciente("julieta", "351751475"));
    colasinturno.encolar(paciente("pedro", "532474675"));
    colasinturno.encolar(paciente("agostina", "23423429"));


    int op;

    while (op < 4) {
        cout << "\ningrese que desea hacer: " << endl;
        cout << "1. Mostrar pacientes" << endl;
        cout << "2. Agregar pacientes" << endl;
        cout << "3. Atender pacientes en espera" << endl;
        cout << "4. salir del menu" << endl;
        cin >> op;

        switch (op) {
            case 1:
                cout << "\npacientes con turno: " << endl;
                mostrarpacientesconturno(colaconturno);
                cout << "\npacientes sin turno: " << endl;
                mostrarpacientessinturno(colasinturno);
                break;
            case 2:
                nuevopaciente(colaconturno, colasinturno);
                break;
            case 3:
                atenderapacientes(colaconturno, colasinturno);
                break;
            case 4: exit(-1);
            default: cout << " opcion incorrecta " << endl;
        }
    }


    return 0;
}
