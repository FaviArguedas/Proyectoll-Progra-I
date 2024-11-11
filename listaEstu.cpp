#include<iostream>
#pragma once

#include "listaEstu.h"

using namespace std;

listaEstu::listaEstu(){
    inicio = nullptr;
    aux = nullptr;
}

bool listaEstu::insertarEst(estudiante* e){
    nodoEstu* nNuevo = new nodoEstu(e, nullptr);

    if(inicio == nullptr){
        inicio = nNuevo;
    }
    else{
        aux = inicio;
        while(aux->getSig() != nullptr){
            aux = aux->getSig();
        }
        aux->setSig(nNuevo);
    }
    cant++;

    return true;
}

bool listaEstu::isEmpty(){
    if (inicio == nullptr){
        return true;
    }
    return false;
}

string listaEstu::toString(){
    stringstream s;

    if (!isEmpty()){
        aux = inicio;
        s << "Estudiantes Registrados: " << endl << endl;
        while (aux != nullptr){
            s << aux->getEst()->toStringInfoBasica();
            s << endl;
            aux = aux->getSig();
        }
    }
    else{
        s << "No hay estudiantes registrados. " << endl;
    }

    return s.str();
}

estudiante* listaEstu::retornarEst(string id){
    aux = inicio;

    while (aux != nullptr){
        if(aux->getEst()->getID() == id){
            return aux->getEst();
        }
        aux = aux->getSig();
    }

    return nullptr;
}

bool listaEstu::buscarEst(string id){
    aux = inicio;

    if(aux = nullptr){
        return false;
    }
    else{
        while (aux != nullptr){
            if(aux->getEst()->getID() == id){
                return true;
            }
            aux = aux->getSig();
        }
    }
    return false;
}

bool listaEstu::eliminarEstudiante(string id){
    nodoEstu* anterior = nullptr;
    aux = inicio;

    if(inicio == nullptr){
        return false;
    }
    if (inicio->getEst()->getID() == id){
        aux = aux->getSig();
        delete inicio;
        inicio = aux;
        return true;
    }
    else{
        while (aux != nullptr && aux->getEst()->getID() != id){
            anterior = aux;
            aux = aux->getSig();
        }
        if(aux == nullptr){
            return false;
        }
        else{
            anterior->setSig(aux->getSig());
            delete aux;
            return true;
        }
    }

}

listaEstu::~listaEstu(){
    while (inicio != nullptr){
        aux = inicio;
        inicio = inicio->getSig();
        delete aux;
    }
}
