#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "Dado.h"
#include "TablaDeResultados.h"

class Jugador{

private:
    Dado* dadoAzul;
    Dado* dadoVerde;
    Dado* dadoRojo;

public:
    Jugador(int cantCarasAzul = 6, int cantCarasVerde = 8, int cantCarasRojo = 12);
    ~Jugador();
    TablaDeResultados LanzarDados();
    int getCarasAzul();
    int getCarasVerde();
    int getCarasRojo();
};

#endif // JUGADOR_H_INCLUDED
