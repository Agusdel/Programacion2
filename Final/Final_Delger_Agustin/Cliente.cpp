#include "Cliente.h"

unsigned int Cliente::ids = 1;

Cliente::Cliente(){
    id = ids++;
    servidorVinculado = false;
}

Cliente::Cliente(Servidor& servidor){
    servidorVinculado = true;
    this->servidor = &servidor;
}

unsigned int Cliente::getID() const{
    return id;
}

Servidor Cliente::getServidor() const{
    return *servidor;
}

bool Cliente::ServidorVinculado() const{
    return servidorVinculado;
}

void Cliente::VincularServidor(Servidor& servidor){
    servidorVinculado = true;
    this->servidor = &servidor;
}

void Cliente::DesvincularServidor(){
    servidorVinculado = false;
}

void Cliente::NotificarPeticionAtendida(Peticion peticion) const{
    std::cout << "\t + + La siguiente peticion ha sido procesada de forma exitosa: \n\n\t\t";
    std::cout << peticion << std::endl << std::endl;
}

void Cliente::NotificarPeticionAtendida(PeticionCritica peticion) const{
    std::cout << "\t + + La siguiente peticion ha sido procesada de forma exitosa: \n\n\t\t";
    std::cout << peticion << std::endl << std::endl;
}

void Cliente::EnviarPeticion(Peticion peticion) const{
    if (servidorVinculado)
        servidor->EnviarPeticion(*this, peticion);
    else{
        std::cout << "ERROR: Debe vincular un servidor para poder mandar una peticion." << std::endl << std::endl;
        throw 0;
    }
}

void Cliente::EnviarPeticion(PeticionCritica peticion) const{
    if (servidorVinculado)
        servidor->EnviarPeticion(*this, peticion);
    else{
        std::cout << "ERROR: Debe vincular un servidor para poder mandar una peticion." << std::endl << std::endl;
        throw 0;
    }
}

bool Cliente::operator== (Cliente otro){
    return this->id == otro.id;
}
