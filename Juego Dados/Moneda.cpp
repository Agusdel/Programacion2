#include "Moneda.h"

Lado Moneda::lanzar(){
    this->prepararRandom();
    int rdm = ((rand() % 2));
    if (rdm == 0){
        return Cara;
    }else{
        return Ceca;
    }
}

void Moneda::prepararRandom(){
    Sleep(1000);
    srand (time (NULL)); //Asegura números aleatorios
}
