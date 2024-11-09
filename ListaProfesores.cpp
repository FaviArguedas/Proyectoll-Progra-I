#include "ListaProfesores.h"
#include <sstream>

ListaProfesores::ListaProfesores() {
    primero = nullptr;
    actual = nullptr;
}

void ListaProfesores::insertarAlFinal(Profesor* profesor) {
    if (primero == nullptr) {
        primero = new NodoProfesores(profesor, nullptr);
    }
    else {
        actual = primero;
        while (actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(new NodoProfesores(profesor, nullptr));
    }
}

bool ListaProfesores::eliminarEspecifico(int id) {
    NodoProfesores* anterior = nullptr;
    actual = primero;

    if (primero == nullptr) {
        return false;
    }

    if (primero->getProfesor()->getId() == id) {
        actual = actual->getSiguiente();
        delete primero;
        primero = actual;
        return true;
    }

    while (actual != nullptr && actual->getProfesor()->getId() != id) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if (actual == nullptr) {
        return false;
    }
    else {
        anterior->setSiguiente(actual->getSiguiente());
        delete actual;
        return true;
    }
}

bool ListaProfesores::listaVacia() {

        if (primero == NULL){
            return true;
        }
        return false;

}


/*bool ListaProfesores::listaVacia() {
    return primero == nullptr;
}*/

Profesor* ListaProfesores::buscarEspecifico(int id_){
    actual = primero;
    while (actual != nullptr) {
        if (actual->getProfesor()->getId() == id_) {
            return actual->getProfesor();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

string ListaProfesores::toString() {
    stringstream s;
    actual = primero;
    while (actual != nullptr) {
        s << actual->toStringNodo();
        actual = actual->getSiguiente();
    }
    return s.str();
}

ListaProfesores::~ListaProfesores() {
    while (primero != nullptr) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}
