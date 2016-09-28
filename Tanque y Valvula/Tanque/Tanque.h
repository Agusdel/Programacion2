#ifndef TANQUE_H_INCLUDED
#define TANQUE_H_INCLUDED
#include <iostream>
#include <string>
#include "Valvula.h"

class Tanque{

    private:

        float contenido;
        float capacidad;
        Valvula valvulaEntrada;
        Valvula valvulaSalida;

    public:

        Tanque(std::string passwordEntrada, std::string passwordSalida, float capacidad = 2000);
        float getCapacidad();
        float getContenido();
        void agregar(float cantidad, std::string passwordEntrada);
        void sacar(float cantidad, std::string passwordSalida);
};

#endif // TANQUE_H_INCLUDED
