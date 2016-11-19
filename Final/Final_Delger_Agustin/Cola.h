#ifndef COLA_H_
#define COLA_H_

#include "Nodo.h"

template<class T> class Cola {

private:

    Nodo<T>* frente;
    Nodo<T>* ultimo;
    Nodo<T>* cursor;
    unsigned int tamanio;

public:

    Cola(){

        this->frente = NULL;
        this->ultimo = NULL;
        this->tamanio = 0;
    }

    ~Cola(){

        while (!estaVacia()) {
        pop();
        }
    }

    /**
     * Agrega el elemento a la cola
     */

    void push(T dato){

        Nodo<T>* aux = new Nodo<T>(dato);

        if (this->frente == NULL) {
            this->frente = aux;
            this->ultimo = aux;
        }

        else {
            this->ultimo->cambiarSiguiente(aux);
            this->ultimo = aux;
        }

        this->tamanio++;
        this->iniciarCursor();
    }

    /**
     * Retorna el primer dato ingresado, y lo elimina de la cola
     */

    T pop(){

        T elemento;

        if (frente != NULL) {

            elemento = frente->obtenerDato();
            Nodo<T>* aElminiar = this->frente;
            this->frente = this->frente->obtenerSiguiente();
            delete aElminiar;
            this->iniciarCursor();
            this->tamanio--;
        }

        return elemento;
    }

    /**
     * Retorna el primer dato ingresado
     */

    T top() const{

        T elemento;

        if (frente != NULL) {

            elemento = this->frente->obtenerDato();
        }

        return  elemento;
    }

    bool estaVacia() const{

        return (this->frente == NULL);
    }

    unsigned int contarElementos() const {

        return this->tamanio;
    }


   void iniciarCursor() {

    this->cursor = NULL;

    }

    bool avanzarCursor() {

    if (this->cursor == NULL) {

        this->cursor = this->frente;

    } else {

        this->cursor = this->cursor->obtenerSiguiente();
    }

    /* pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);

    }

    T obtenerCursor() {

    T elemento;

    if (this->cursor != NULL) {

        elemento = this->cursor->obtenerDato();
    }

    return elemento;
    }

};

#endif
