#include "NodoPeriodos.h"

NodoPeriodos::NodoPeriodos(Periodo* periodo_, NodoPeriodos* siguiente_) {
    periodo = periodo_;
    siguiente = siguiente_;
}

NodoPeriodos::~NodoPeriodos() {
    delete periodo;
}

void NodoPeriodos::setPeriodo(Periodo* periodo_) {
    periodo = periodo_;
}

Periodo* NodoPeriodos::getPeriodo() {
    return periodo;
}

void NodoPeriodos::setSiguiente(NodoPeriodos* _siguiente) {
    siguiente = _siguiente;
}

NodoPeriodos* NodoPeriodos::getSiguiente() {
    return siguiente;
}

string NodoPeriodos::toStringNodo() {
    return periodo->toString();
}
