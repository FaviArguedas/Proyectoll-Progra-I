#include<iostream>
#pragma once

#include "estudiante.h"

using namespace std;

estudiante::estudiante(){
    nombre = "";
    ID = "";
    especialidad = "";
    email = "";
    numTelefono = 0;
    edad = 0;
}

estudiante::estudiante(string nom, string id, string esp, string em, int numT, int ed){
    nombre = nom;
    ID = id;
    especialidad = esp;
    email = em;
    numTelefono = numT;
    edad = ed;
    cantH = 0;

    horarios = new horario*[100];
    for (int i = 0; i < 100; i++){
        horarios[i] = nullptr;
    }
}

bool estudiante::ingresarHorario(horario* h){
    if(cantH < 100){
        horarios[cantH] = h;
        cantH++;
        return true;
    }
    return false;
}

void estudiante::setNombre (string nom){
    nombre = nom;
}

void estudiante::setID (string id){
    ID = id;
}

void estudiante::setEdad (int ed){
    edad = ed;
}

string estudiante::getNombre (){
    return nombre;
}

string estudiante::getID (){
    return ID;
}

string estudiante::getEspecialidad(){
    return especialidad;
}

string estudiante::getEmail(){
    return email;
}

int estudiante::getNumTelefono(){
    return numTelefono;
}

int estudiante::getEdad (){
    return edad;
}
int estudiante::getCantH(){
    return cantH;
}

string estudiante::toString (){
    stringstream s;
    s << "Nombre: " << nombre << endl;
    s << "ID: " << ID << endl;
    s << "Especialidad: " << especialidad << endl;
    s << "Email: " << email << endl;
    s << "Numero de telefono: " << numTelefono << endl;
    s << "Edad: " << edad << endl;
    s << "Estado: ";
    if(cantH>=1){
        s << "Matriculado. "<<endl;
    }
    else{
        s << "NO Matriculado. " << endl;
    }


    return s.str();
}

string estudiante::toStringInfoBasica(){
    stringstream s;
    s << "Nombre del estudiante: " << nombre << endl;
    s << "ID: " << ID << endl;
    return s.str();
}

string estudiante::toStringCursos(){
    stringstream s;

    s << "Cursos matriculados: " << endl;

    for (int i=0; i<cantH; i++){
        s << horarios[i]->toString();
        s << endl;
    }

    return s.str();
}

horario* estudiante::buscarHorario(horario* h){
    if (cantH == 0){
        return nullptr;
    }
    else{
        for(int i=0; i<cantH; i++){
            if(horarios[i] == h){
                return horarios[i];
            }
        }
    }

    return nullptr;
}

horario* estudiante::buscarHorario2(string dia, string hora, int annio, int per){
    string d, hI, hF;
    int a, p;

    if(cantH == 0){
        return nullptr;
    }
    else{
        for (int i=0; i < cantH; i++){
            d = horarios[i]->getDia();
            hI = horarios[i]->getHoraIn();
            hF = horarios[i]->getHoraFin();
            a = horarios[i]->getAnnio();
            p = horarios[i]->getPeriodo();

            if(d == dia && a == annio && p == per && (hI == hora || hF == hora)){
                return horarios[i];
            }

        }
    }
    return NULL;
}

void estudiante::corrimiento(int pos){
    for (int i=pos; i<cantH; i++){
        horarios[i] = horarios[i+1];
    }
    horarios[cantH-1] = nullptr;
}

bool estudiante::eliminarBloque(int cod, int p){
    int c, pr;
    for(int i=0; i<cantH; i++){
        c = horarios[i]->getCodCurso();
        pr = horarios[i]->getPeriodo();

        if(c == cod && pr == p){
            horarios[i] == NULL;
            corrimiento(i);
            cantH--;

            return true;
        }
    }
    return false;
}

string estudiante::crearBloque(string dia, string hora, int annio, int per){
    stringstream s;

    if(buscarHorario2(dia, hora, annio, per) != NULL){
        horario* h = buscarHorario2(dia, hora, annio, per);

        s << h->getNomCurso();
        s << endl;

    }
    else{
        s << "Espacio Libre..." << endl;
    }

    return s.str();
}

string estudiante::mostrarHorario(int annio, int per){
    stringstream s;

    int a = annio;
    int p = per;

    do{
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|---------------- Horario - Periodo " << per << ", " << annio <<"---------------|"<<endl;
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|----------------------- Dia Lunes ------------------------|"<<endl;
        s<<"|    9:00am                                                |"<<endl;
        s << crearBloque("Lunes", "9:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    10:00am                                               |"<<endl;
        s << crearBloque("Lunes", "10:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    11:00am                                               |"<<endl;
        s << crearBloque("Lunes", "11:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    1:00pm                                                |"<<endl;
        s << crearBloque("Lunes", "1:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    2:00pm                                                |"<<endl;
        s << crearBloque("Lunes", "2:00pm" , annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    3:00pm                                                |"<<endl;
        s << crearBloque("Lunes", "3:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    4:00pm                                                |"<<endl;
        s << crearBloque("Lunes", "4:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    5:00pm                                                |"<<endl;
        s << crearBloque("Lunes", "5:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    6:00pm                                                |"<<endl;
        s << crearBloque("Lunes", "6:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    7:00pm                                                |"<<endl;
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|----------------------- Dia Martes -----------------------|"<<endl;
        s<<"|    9:00am                                                |"<<endl;
        s << crearBloque("Martes", "9:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    10:00am                                               |"<<endl;
        s << crearBloque("Martes", "10:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    11:00am                                               |"<<endl;
        s << crearBloque("Martes", "11:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    1:00pm                                                |"<<endl;
        s << crearBloque("Martes", "1:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    2:00pm                                                |"<<endl;
        s << crearBloque("Martes", "2:00pm" , annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    3:00pm                                                |"<<endl;
        s << crearBloque("Martes", "3:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    4:00pm                                                |"<<endl;
        s << crearBloque("Martes", "4:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    5:00pm                                                |"<<endl;
        s << crearBloque("Martes", "5:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    6:00pm                                                |"<<endl;
        s << crearBloque("Martes", "6:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    7:00pm                                                |"<<endl;
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|---------------------- Dia Miercoles ---------------------|"<<endl;
        s<<"|    9:00am                                                |"<<endl;
        s << crearBloque("Miercoles", "9:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    10:00am                                               |"<<endl;
        s << crearBloque("Miercoles", "10:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    11:00am                                               |"<<endl;
        s << crearBloque("Miercoles", "11:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    1:00pm                                                |"<<endl;
        s << crearBloque("Miercoles", "1:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    2:00pm                                                |"<<endl;
        s << crearBloque("Miercoles", "2:00pm" , annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    3:00pm                                                |"<<endl;
        s << crearBloque("Miercoles", "3:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    4:00pm                                                |"<<endl;
        s << crearBloque("Miercoles", "4:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    5:00pm                                                |"<<endl;
        s << crearBloque("Miercoles", "5:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    6:00pm                                                |"<<endl;
        s << crearBloque("Miercoles", "6:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    7:00pm                                                |"<<endl;
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|----------------------- Dia Jueves -----------------------|"<<endl;
        s<<"|    9:00am                                                |"<<endl;
        s << crearBloque("Jueves", "9:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    10:00am                                               |"<<endl;
        s << crearBloque("Jueves", "10:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    11:00am                                               |"<<endl;
        s << crearBloque("Jueves", "11:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    1:00pm                                                |"<<endl;
        s << crearBloque("Jueves", "1:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    2:00pm                                                |"<<endl;
        s << crearBloque("Jueves", "2:00pm" , annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    3:00pm                                                |"<<endl;
        s << crearBloque("Jueves", "3:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    4:00pm                                                |"<<endl;
        s << crearBloque("Jueves", "4:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    5:00pm                                                |"<<endl;
        s << crearBloque("Jueves", "5:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    6:00pm                                                |"<<endl;
        s << crearBloque("Jueves", "6:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    7:00pm                                                |"<<endl;
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|----------------------- Dia Viernes ----------------------|"<<endl;
        s<<"|    9:00am                                                |"<<endl;
        s << crearBloque("Viernes", "9:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    10:00am                                               |"<<endl;
        s << crearBloque("Viernes", "10:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    11:00am                                               |"<<endl;
        s << crearBloque("Viernes", "11:00am", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    1:00pm                                                |"<<endl;
        s << crearBloque("Viernes", "1:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    2:00pm                                                |"<<endl;
        s << crearBloque("Viernes", "2:00pm" , annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    3:00pm                                                |"<<endl;
        s << crearBloque("Viernes", "3:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    4:00pm                                                |"<<endl;
        s << crearBloque("Viernes", "4:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    5:00pm                                                |"<<endl;
        s << crearBloque("Viernes", "5:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    6:00pm                                                |"<<endl;
        s << crearBloque("Viernes", "6:00pm", annio, per);
        s<<"|----------------------------------------------------------|"<<endl;
        s<<"|    7:00pm                                                |"<<endl;
        s<<"|----------------------------------------------------------|"<<endl;

        a++;
        p++;

    } while(a == annio && p == per);

    return s.str();
}


bool estudiante::estudianteMatriculado(bool matr){
    if (matr == true){
        return true;
    }
    return false;
}

float estudiante::cobroBase(){
    float precioBase = 0;
    float prc;

    for (int i = 0; i<cantH; i++){
        prc = horarios[i]->getPrecio();
        precioBase += prc;
    }

    return precioBase;
}

float estudiante::descuentoPeriodo(float precioBase){
    float descuento;
    int cantPer = 0;


    for (int j = 1; j<=4; j++){
        for (int i = 0; i<cantH; i++){
            if(horarios[i]->getPeriodo() == j){
                cantPer += 1;
            }
        }
    }

    if(cantPer >= 2){
        descuento = precioBase * 0.15;
    }
    else{
        descuento = 0;
    }

    return descuento;
}

float estudiante::descuentoAnnio(float precioBase){
    float descuento;
    int annio = 2024;
    int cantAn;

    for (int i = 0; i<cantH; i++){
        if(horarios[i]->getAnnio() == annio){
            cantAn += 1;
        }
    }

    if(cantAn>=4){
        descuento = precioBase*0.25;
    }
    else{
        descuento = 0;
    }

    return descuento;
}

float estudiante::IVA(float precioBase){
    float iva;

    iva = precioBase*0.13;

    return iva;
}

float estudiante::cobroTotal(float cobroBase, float descuentoPer, float descuentoAnn, float iva){
    float total;

    total = cobroBase + iva - descuentoPer - descuentoAnn;


    return total;
}

string estudiante::generarFactura(){
    stringstream s;

    float precioBase = cobroBase();
    float descPer = descuentoPeriodo(precioBase);
    float descAn = descuentoAnnio(precioBase);
    float iva = IVA(precioBase);
    float precioTotal = cobroTotal(precioBase, descPer, descAn, iva);

    s << "--------------------------  Factura  --------------------------" << endl;
    s << "Estudiante: " << nombre << ". ID:" << ID << endl;
    s << "---------------------------------------------------------------" << endl;
    s << "Cursos matriculados y Precios ---------------------------------" << endl;
    for (int i=0; i<cantH; i++){
        s << "- "<< horarios[i]->getNomCurso() <<". Precio: $" << horarios[i]->getPrecio();
        s << endl;
    }
    s << "---------------------------------------------------------------" << endl;
    s << "SubTotal : $" << precioBase << endl;
    s << "---------------------------------------------------------------" << endl;
    s << "Descuentos Aplicados: -----------------------------------------" << endl;
    s << "Descuento por cursos del mismo periodo: $" << descPer << endl;
    s << "Descuento por cursos del mismo annio: $"<<descAn << endl;
    s << "---------------------------------------------------------------" << endl;
    s << "Cobro por IVA: ------------------------------------------------" << endl;
    s << "IVA: $"<<iva << endl;
    s << "---------------------------------------------------------------" << endl;
    s << "Cobro Total: --------------------------------------------------" << endl;
    s << "TOTAL: $"<<precioTotal<<endl;
    s << "---------------------------------------------------------------" << endl;

    return s.str();
}