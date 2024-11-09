#include <iostream>
#include <sstream>
#include "Periodo.h"
using namespace  std;

class NodoPeriodos{
private:
    Periodo* periodo;
    NodoPeriodos* siguiente;

public:
    NodoPeriodos(Periodo*, NodoPeriodos*);
    ~NodoPeriodos();
    void setPeriodo(Periodo*);
    Periodo* getPeriodo();
    void setSiguiente(NodoPeriodos*);
    NodoPeriodos* getSiguiente();
    string toStringNodo();


};