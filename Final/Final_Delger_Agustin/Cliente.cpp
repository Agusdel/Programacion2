#include "Cliente.h"

unsigned int Cliente::ids = 1;

Cliente::Cliente(){
    id = ids++;
}

Cliente::Cliente(Servidor& servidor, std::string contrasenia){
    this->servidor = &servidor;
    servidor.Vincularse(*this, contrasenia);
}

unsigned int Cliente::getID() const{
    return id;
}

Servidor Cliente::getServidor() const{
    return *servidor;
}

bool Cliente::ServidorVinculado(){
    return servidor->Vinculado(*this);
}

bool Cliente::VincularServidor(Servidor& servidor, std::string contrasenia){
    this->servidor = &servidor;
    return servidor.Vincularse(*this, contrasenia);
}

void Cliente::DesvincularServidor(){
    servidor->Desvincularse(*this);
}

void Cliente::NotificarPeticionAtendida(Peticion peticion) const{
    std::cout << "\t + + La siguiente peticion ha sido procesada de forma exitosa: \n\n\t\t";
    std::cout << peticion << std::endl << std::endl;
}

void Cliente::NotificarPeticionAtendida(PeticionCritica peticion) const{
    std::cout << "\t + + La siguiente peticion ha sido procesada de forma exitosa: \n\n\t\t";
    std::cout << peticion << std::endl << std::endl;
}

void Cliente::EnviarPeticion(Peticion peticion){
    servidor->EnviarPeticion(*this, peticion);
}

void Cliente::EnviarPeticion(PeticionCritica peticion){
    servidor->EnviarPeticion(*this, peticion);
}

bool Cliente::operator== (Cliente otro){
    return this->id == otro.id;
}
