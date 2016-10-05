#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"
#include <stdexcept>

template<class T> class Lista {

private:

    unsigned int tam;
    Nodo<T>* prim;
    Nodo<T>* actual;

public:

    Lista();
    ~Lista();

    bool estaVacia() {return tam==0;}
    unsigned int tamanio() {return tam;}
    void agregar(T elem);
    void agregar(T elem, unsigned int pos);
    T operator[] (unsigned int pos);
    T obtener(unsigned int pos);
    void asignar(T elem, unsigned int pos);
    void eliminar(unsigned int pos);

private:

    Nodo<T>* obtenerNodo(unsigned int pos);

};

template<class T> Lista<T>::Lista(){
    this->prim = NULL;
    this->actual = NULL;
    this->tam = 0;
}

template<class T> Lista<T>::~Lista(){
    if (this->prim != NULL){
        Nodo<T>* aux;
        this->actual = this->prim;
        for (short i = 0; i < this->tam; i++){
            aux = this->actual;
            this->actual = this->actual->obtenerSiguiente();
            delete aux;
        }
    }
}

template<class T> void Lista<T>::agregar(T elem, unsigned int pos){
    if ( pos > 0 && pos <= this->tam+1){
        Nodo<T>* nodo = new Nodo<T>(elem);
        if (pos == 1){
            nodo->cambiarSiguiente(this->prim);
            this->prim = nodo;
        } else {
            this->actual = obtenerNodo(pos-1);
            nodo->cambiarSiguiente(this->actual->obtenerSiguiente());
            this->actual->cambiarSiguiente(nodo);
            this->actual = NULL;
        }
        this->tam++;
    } else {
        throw std::invalid_argument("Out of range exception.");
    }
}

template<class T> void Lista<T>::agregar(T elem){
    this->agregar(elem, this->tam+1);
}

template<class T> Nodo<T>* Lista<T>::obtenerNodo(unsigned int pos){
    this->actual = this->prim;
    for (unsigned short i = 0; i < pos - 1; i ++){
        this->actual = this->actual->obtenerSiguiente();
    }
    return this->actual;
}

template<class T> T Lista<T>::operator[] (unsigned int pos){
    return this->obtenerNodo(pos)->obtenerElem();
}


template<class T> T Lista<T>::obtener(unsigned int pos){
    if (pos > 0 && pos <= this->tam){
        return this->obtenerNodo(pos)->obtenerElem();
    } else {
        throw std::invalid_argument("Out of range exception.");
    }
}

template<class T> void Lista<T>::asignar(T elem, unsigned int pos){
    if (pos > 0 && pos <= this->tam){
        Nodo<T>* aux = this->obtenerNodo(pos);
        aux->cambiarElem(elem);
    } else {
        throw std::invalid_argument("Out of range exception.");
    }
}

template<class T> void Lista<T>::eliminar(unsigned int pos){
    if (pos > 0 && pos <= this->tam){
        Nodo<T>* aux;
        if (pos == 1){
            aux = this->prim;
            this->prim = this->prim->obtenerSiguiente();
            delete aux;
        } else {
            this->actual = this->obtenerNodo(pos-1);
            aux = this->actual->obtenerSiguiente();
            this->actual->cambiarSiguiente(aux->obtenerSiguiente());
            delete aux;
            this->actual = NULL;
        }
        this->tam--;
    } else {
        throw std::invalid_argument("Out of range exception.");
    }
}
#endif // LISTA_H_INCLUDED
