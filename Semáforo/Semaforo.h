#ifndef SEMAFORO_H_INCLUDED
#define SEMAFORO_H_INCLUDED

#include "Luz.h"

#include <iostream>

enum Estado { Detenerse, Prepararse, Avanzar, Advertencia};

class Semaforo {

private:

    Estado estado;
    Luz* rojo;
    Luz* amarillo;
    Luz* verde;

public:

    Semaforo(Estado estado);
    ~Semaforo();
    Estado getEstado() const;
    void AvanzarEstado();

    Semaforo operator=(Semaforo otroSemaforo);

    friend std::ostream& operator<< (std::ostream& os, const Semaforo& sem);
};

#endif // SEMAFORO_H_INCLUDED
