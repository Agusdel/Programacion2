#ifndef PETICION_H_INCLUDED
#define PETICION_H_INCLUDED

#include<iostream>

class Peticion{

private:

    static unsigned int ids;

    unsigned int id;

    unsigned int duracion;

public:

    Peticion(unsigned int duracion = 0);

    Peticion(const Peticion& otra);

    unsigned int getID() const;

    unsigned int getDuracion() const;

    Peticion operator= (const Peticion& otraPet);
};

std::ostream& operator<<(std::ostream& os, Peticion p);

class PeticionCritica{

private:

    static unsigned int ids;

    unsigned int id;

    unsigned int duracion;

    unsigned int prioridad;

public:

    PeticionCritica(unsigned int duracion = 0, unsigned int prioridad = 10);

    PeticionCritica(const PeticionCritica& otra);

    unsigned int getID() const;

    unsigned int getDuracion() const;

    unsigned int getPrioridad() const;

    PeticionCritica operator= (const PeticionCritica& otraPet);
};

std::ostream& operator<<(std::ostream& os, PeticionCritica p);

#endif // PETICION_H_INCLUDED
