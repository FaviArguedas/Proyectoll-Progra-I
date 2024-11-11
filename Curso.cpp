#include "Curso.h"
#include <sstream>

Curso::Curso() {
    this->nombre = "";
    this->id = 0;
    this->horas = 0;
    this->precio = 0.0;
    this->estado = false;
    this->periodo = nullptr;
}

Curso::Curso(string _nombre, int _id, int _horas, float _precio, bool _estado, Periodo* _periodo) {
    this->nombre = _nombre;
    this->id = _id;
    this->horas = _horas;
    this->precio = _precio;
    this->estado = _estado;
    this->periodo = _periodo;
}

string Curso::getNombre() {
    return this->nombre;
}

void Curso::setNombre(string _nombre) {
    this->nombre = _nombre;
}

int Curso::getId() {
    return this->id;
}

void Curso::setId(int _id) {
    this->id = _id;
}

int Curso::getHoras() {
    return this->horas;
}

void Curso::setHoras(int _horas) {
    this->horas = _horas;
}

float Curso::getPrecio() {
    return this->precio;
}

void Curso::setPrecio(float _precio) {
    this->precio = _precio;
}

bool Curso::getEstado() {
    return this->estado;
}

void Curso::setEstado(bool _estado) {
    this->estado = _estado;
}

string Curso::toString() {
    stringstream s;
    s << "Nombre: " << this->nombre << "\n";
    s << "ID: " << this->id << "\n";
    s << "Horas: " << this->horas << "\n";
    s << "Precio: " << this->precio << "\n";
    s << "Estado: " << (this->estado ? "Activo" : "Inactivo") << "\n";
    return s.str();
}

string Curso::toStringPeriodo() {
    stringstream s;
    s << "Periodo: " << this->periodo->getNumero() << "\n";
    s << "Nombre de curso: " << this->nombre << "\n";

    return s.str();
}
