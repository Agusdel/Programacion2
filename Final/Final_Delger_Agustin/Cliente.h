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

    bool servidorVinculado;

public:

    Cliente();

    Cliente(Servidor& servidor);

    void Vincularse(const Cliente& c, std::string contrasenia);

    void Desvincularse(const Cliente& c);

    bool Vinculado(const Cliente& c) const;

    unsigned int getID() const;

    Servidor getServidor() const;

    bool ServidorVinculado() const;

    void VincularServidor(Servidor& servidor);

    void DesvincularServidor();

    void NotificarPeticionAtendida(Peticion peticion) const;

    void NotificarPeticionAtendida(PeticionCritica peticion) const;

    void EnviarPeticion(Peticion peticion) const;

    void EnviarPeticion(PeticionCritica peticion) const;

    bool operator== (Cliente otro);
};

#endif // CLIENTE_H_INCLUDED
