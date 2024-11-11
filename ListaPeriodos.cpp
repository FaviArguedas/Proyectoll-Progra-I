#include "ListaPeriodos.h"

ListaPeriodos::ListaPeriodos() {
    primero = nullptr;
    actual = nullptr;
}

void ListaPeriodos::insertarAlFinal(Periodo* periodo) {
    NodoPeriodos* nuevo = new NodoPeriodos(periodo, nullptr);
    if (primero == nullptr) {
        primero = nuevo;
    }
    else {
        actual = primero;
        while (actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
    }
}

bool ListaPeriodos::eliminarEspecifico(int nombre_) {
    NodoPeriodos* anterior = nullptr;
    actual = primero;

    while (actual != nullptr && actual->getPeriodo()->getNumero() != nombre_) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if (actual == nullptr) {
        return false;
    }

    if (anterior == nullptr) {
        primero = actual->getSiguiente();
    }
    else {
        anterior->setSiguiente(actual->getSiguiente());
    }

    delete actual;
    return true;
}

Periodo * ListaPeriodos::buscarPeriodo(int nombre_) {
    actual = primero;
    while (actual != nullptr) {
        if (actual->getPeriodo()->getNumero() == nombre_) {
            return actual->getPeriodo();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

bool ListaPeriodos::listaVacia() {
    return primero == nullptr;
}

string ListaPeriodos::toString() {
    stringstream s;
    actual = primero;
    while (actual != nullptr) {
        s << actual->toStringNodo();
        actual = actual->getSiguiente();
    }
    return s.str();
}

Periodo* ListaPeriodos::informePeriodoEspecifico(int nombre_) {
    actual = primero;
    while (actual != nullptr) {
        if (actual->getPeriodo()->getNumero() == nombre_) {
            return actual->getPeriodo();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

ListaPeriodos::~ListaPeriodos() {
    while (primero != nullptr) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}
