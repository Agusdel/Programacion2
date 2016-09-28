#include <iostream>
#include "Jugador.h"


Jugador::Jugador(int cantCarasAzul, int cantCarasVerde, int cantCarasRojo){
    this->dadoAzul = new Dado(cantCarasAzul);
    this->dadoVerde = new Dado(cantCarasVerde);
    this->dadoRojo = new Dado(cantCarasRojo);
}

Jugador::~Jugador(){
    delete this->dadoAzul;
    delete this->dadoVerde;
    delete this->dadoRojo;
}

TablaDeResultados Jugador::LanzarDados(){
    TablaDeResultados tabla;
    tabla.setAzul(this->dadoAzul->lanzar());
    std::cout << "Se tira el dado azul y sale..." << tabla.Azul() << std::endl;
    tabla.setVerde(this->dadoVerde->lanzar());
    std::cout << "Se tira el dado verde y sale..." << tabla.Verde() << std::endl;
    tabla.setRojo(this->dadoRojo->lanzar());
    std::cout << "Se tira el dado rojo y sale..." << tabla.Rojo() << std::endl;
    return tabla;
}

int Jugador::getCarasAzul(){
    return this->dadoAzul->getCaras();
}

int Jugador::getCarasVerde(){
    return this->dadoVerde->getCaras();
}

int Jugador::getCarasRojo(){
    return this->dadoRojo->getCaras();
}
