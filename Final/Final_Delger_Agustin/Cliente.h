#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "Servidor.h"
#include "Peticion.h"

class Servidor;

class Cliente{

private:

    static unsigned int ids;

    unsigned int id;

    Servidor* servidor;

public:

    Cliente();

    Cliente(Servidor& servidor, std::string contrasenia);

    unsigned int getID() const;

    Servidor getServidor() const;

    bool ServidorVinculado();

    bool VincularServidor(Servidor& servidor, std::string contrasenia);

    void DesvincularServidor();

    void NotificarPeticionAtendida(Peticion peticion) const;

    void NotificarPeticionAtendida(PeticionCritica peticion) const;

    void EnviarPeticion(Peticion peticion);

    void EnviarPeticion(PeticionCritica peticion);

    bool operator== (Cliente otro);
};

#endif // CLIENTE_H_INCLUDED
