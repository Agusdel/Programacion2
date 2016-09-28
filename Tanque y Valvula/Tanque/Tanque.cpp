#include "Tanque.h"

Tanque::Tanque(std::string passwordEntrada, std::string passwordSalida, float capacidad){
    this->contenido=0;
    Valvula valvEntrada(passwordEntrada);
    Valvula valvSalida(passwordSalida);
    this->valvulaEntrada = valvEntrada;
    this->valvulaSalida = valvSalida;
    this->capacidad = capacidad;
}

float Tanque::getContenido(){
    return this->contenido;
}

float Tanque::getCapacidad(){
    return capacidad;
}

void Tanque::agregar(float cantidad, std::string passwordEntrada){
    if (this->valvulaEntrada.AbrirValvula(passwordEntrada)){
        float aux = cantidad + this->contenido;
        if( aux <= getCapacidad()){
            this->contenido = aux;
        }
        else{
            std::cout<<"Si agrega "<<cantidad<<" supera la capacidad\n";
        }
    } else {
        std::cout << "Contraseña inválida." << std::endl;
    }
}

void Tanque::sacar(float cantidad, std::string passwordSalida){
    if (this->valvulaSalida.AbrirValvula(passwordSalida)){
        float aux = this->contenido - cantidad;
        if(aux >= 0)
            this-> contenido = aux;
        else
            std::cout<<"Si saca "<<cantidad<<" extrae mas del contenido y queda un nivel negativo\n";
    } else {
        std::cout << "Contraseña inválida." << std::endl;
    }
}
