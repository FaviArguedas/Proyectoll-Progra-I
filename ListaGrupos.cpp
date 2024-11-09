#include "ListaGrupos.h"

ListaGrupos::ListaGrupos() {
    primero = nullptr;
    actual = nullptr;
}

void ListaGrupos::insertarAlFinal(Grupo* grupo) {
    NodoGrupos* nuevo = new NodoGrupos(grupo, nullptr);
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

bool ListaGrupos::eliminarEspecifico(int numeroGrupo) {
    NodoGrupos* anterior = nullptr;
    actual = primero;

    while (actual != nullptr && actual->getGrupo()->getNumeroGrupo() != numeroGrupo) {
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

bool ListaGrupos::listaVacia() {
    return primero == nullptr;
}

void ListaGrupos::asignarProfesor(Profesor *profesor, int numGrupo) {

    actual = primero;
    while (actual != nullptr) {
        if (actual->getGrupo()->getNumeroGrupo() == numGrupo) {
            actual->getGrupo()->setProfesor(profesor);
            break;
        }
        actual = actual->getSiguiente();
    }
}

string ListaGrupos::toString() {
    stringstream s;
    actual = primero;
    while (actual != nullptr) {
        s << actual->toStringNodo();
        actual = actual->getSiguiente();
    }
    return s.str();
}

Grupo* ListaGrupos::informeGrupoEspecifico(int numeroGrupo) {
    actual = primero;
    while (actual != nullptr) {
        if (actual->getGrupo()->getNumeroGrupo() == numeroGrupo) {
            return actual->getGrupo();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

ListaGrupos::~ListaGrupos() {
    while (primero != nullptr) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}
