#include "ListaCursos.h"
#include <sstream>

ListaCursos::ListaCursos() {
    primero = NULL;
    actual = NULL;
}

string ListaCursos::toString() {
    stringstream s;
    actual = primero;
    while (actual != NULL) {
        s << actual->toStringNodo();
        actual = actual->getSiguiente();
    }
    return s.str();
}

void ListaCursos::insertarAlFinal(Curso* curso) {
    NodoCursos* nuevo = new NodoCursos(curso, nullptr);

    if (primero == nullptr) {
        primero = nuevo;
    } else {
        actual = primero;
        while (actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
    }
}

bool ListaCursos::eliminarEspecifico(string nombre) {
    NodoCursos* anterior = NULL;
    actual = primero;

    if (primero == NULL) {
        return false;
    }

    if (primero->getCurso()->getNombre() == nombre) {
        actual = primero->getSiguiente();
        delete primero;
        primero = actual;
        return true;
    }

    while (actual != NULL && actual->getCurso()->getNombre() != nombre) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if (actual == NULL) {
        return false;
    }
    else {
        anterior->setSiguiente(actual->getSiguiente());
        delete actual;
        return true;
    }
}

Curso * ListaCursos::buscarCurso(int  id) {
    actual = primero;
    while (actual != nullptr) {
        if (actual->getCurso()->getId() == id) {
            return actual->getCurso();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

ListaCursos::~ListaCursos() {
    while (primero != NULL) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}

bool ListaCursos::listaVacia() {
    return primero == NULL;
}
