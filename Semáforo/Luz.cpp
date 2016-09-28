#include "Luz.h"

Luz::Luz(Color color, bool encendida){
    this->color = color;
    this->encendida = encendida;
}

void Luz::Encender(){
    this->encendida = true;
}

void Luz::Apagar(){
    this->encendida = false;
}

Color Luz::getColor(){
    return this->color;
}

Luz Luz::operator=(Luz otra){
    this->color = otra.color;
    this->encendida = otra.encendida;
    return *this;
}
