#include "Semaforo.h"

Semaforo::Semaforo(Estado estado){
    this->estado = estado;
    this->rojo = new Luz(Rojo);
    this->amarillo = new Luz(Amarillo);
    this->verde = new Luz(Verde);
    switch (estado){
        case Detenerse:
            this->rojo->Encender();
            break;
        case 1:
            this->rojo->Encender();
            this->amarillo->Encender();
            break;
        case 2:
            this->verde->Encender();
            break;
        case 3:
            this->amarillo->Encender();
            break;
    }
}

Semaforo::~Semaforo(){
    delete rojo;
    delete amarillo;
    delete verde;
}

Estado Semaforo::getEstado() const{
    return this->estado;
}

void Semaforo::AvanzarEstado(){
    switch (this->estado){
    case 0:
        estado = Prepararse;
        amarillo->Encender();
        break;
    case 1:
        estado = Avanzar;
        rojo->Apagar();
        amarillo->Apagar();
        verde->Encender();
        break;
    case 2:
        estado = Advertencia;
        amarillo->Encender();
        verde->Apagar();
        break;
    case 3:
        estado = Detenerse;
        rojo->Encender();
        amarillo->Apagar();
        break;
    }
}

Semaforo Semaforo::operator=(Semaforo otro){
    this->estado = otro.estado;
    this->rojo = new Luz();
    this->amarillo = new Luz();
    this->verde = new Luz();
    rojo = otro.rojo;
    amarillo = otro.amarillo;
    verde = otro.verde;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Semaforo& sem){
    /*char red[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char yellow[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };*/
    switch (sem.getEstado()){
    case 0:
        os << "Semaforo: |||  -   -   Detenerse  \n";
        break;
    case 1:
        os << "Semaforo: ||| |||  -   Prepararse \n";
        break;
    case 2:
        os << "Semaforo:  -   -  |||  Avanzar    \n";
        break;
    case 3:
        os << "Semaforo:  -  |||  -   Advertencia\n";
        break;
    }

    return os;
}
