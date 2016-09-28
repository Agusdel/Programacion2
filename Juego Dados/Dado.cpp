#include "Dado.h"

Dado::Dado(int caras){
    if(caras >= 2){
        this->caras = caras;
    }
}

int Dado::lanzar(){
    this->prepararRandom();
    return (1 + (rand() % this->caras));
}

int Dado::getCaras(){
    return this->caras;
}

void Dado::prepararRandom(){
    Sleep(1000);
    srand (time (NULL)); //Asegura números aleatorios
}
