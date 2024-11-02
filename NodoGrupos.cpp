#include "NodoGrupos.h"

NodoGrupos::NodoGrupos(Grupo* _grupo, NodoGrupos* _siguiente) {
    grupo = _grupo;
    siguiente = _siguiente;
}

NodoGrupos::~NodoGrupos() {
    delete grupo;
}

void NodoGrupos::setGrupo(Grupo* _grupo) {
    grupo = _grupo;
}

Grupo* NodoGrupos::getGrupo() {
    return grupo;
}

void NodoGrupos::setSiguiente(NodoGrupos* _siguiente) {
    siguiente = _siguiente;
}

NodoGrupos* NodoGrupos::getSiguiente() {
    return siguiente;
}

string NodoGrupos::toStringNodo() {
    return grupo->toString();
}