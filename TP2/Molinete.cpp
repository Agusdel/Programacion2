#include "Molinete.h"

Molinete::Molinete(){
    this->cantIngr = 0;
    this->cantEgr = 0;
}

unsigned int Molinete::cantIngresos(){
    return this->cantIngr;
}

unsigned int Molinete::cantEgresos(){
    return this->cantEgr;
}

void Molinete::dejarEntrar(){
    this->cantIngr++;
}

void Molinete::dejarSalir(){
    this->cantEgr++;
}

