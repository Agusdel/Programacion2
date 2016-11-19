#include "Peticion.h"

unsigned int Peticion::ids = 1;

Peticion::Peticion(unsigned int duracion){
    this->id = ids++;
    this->duracion = duracion;
}

Peticion::Peticion(const Peticion& otra){
    id = otra.id;
    duracion = otra.duracion;
}

unsigned int Peticion::getID() const {
    return id;
}

unsigned int Peticion::getDuracion() const{
    return duracion;
}

std::ostream& operator<<(std::ostream& os, Peticion p){
    std::cout << "[ Peticion no critica: ID: " << p.getID() << "; Duracion: " << p.getDuracion() << " ]";
    return os;
}

Peticion Peticion::operator= (const Peticion& otraPet){
    id = otraPet.id;
    duracion = otraPet.duracion;
    return *this;
}

///              PETICION CRITICA

unsigned int PeticionCritica::ids = 1;

PeticionCritica::PeticionCritica(unsigned int duracion, unsigned int prioridad){
    this->id = ids++;
    this->duracion = duracion;
    if (prioridad > 10)
        this->prioridad = 10;
    else if (prioridad == 0)
        this->prioridad = 1;
    else
        this->prioridad = prioridad;
}

PeticionCritica::PeticionCritica(const PeticionCritica& otra){
    id = otra.id;
    duracion = otra.duracion;
    prioridad = otra.prioridad;
}

unsigned int PeticionCritica::getID() const{
    return id;
}

unsigned int PeticionCritica::getDuracion() const{
    return duracion;
}

unsigned int PeticionCritica::getPrioridad() const{
    return prioridad;
}

std::ostream& operator<<(std::ostream& os, PeticionCritica p){
    std::cout << "[ Peticion critica: ID: " << p.getID() << "; Duracion: " << p.getDuracion() << "; Prioridad: " << p.getPrioridad() << " ]";
    return os;
}

PeticionCritica PeticionCritica::operator= (const PeticionCritica& otraPet){
    id = otraPet.id;
    duracion = otraPet.duracion;
    prioridad = otraPet.prioridad;
    return *this;
}
