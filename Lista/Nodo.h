#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template<class T> class Nodo {
private:

    T elem;
    Nodo<T>* siguiente;

public:

    Nodo(T elem){this->elem = elem; this->siguiente = NULL;}

    T obtenerElem() {return this->elem;}

    void cambiarElem(T nuevoElem) {this->elem = nuevoElem;}

    Nodo<T>* obtenerSiguiente() {return this->siguiente;}

    void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {this->siguiente = nuevoSiguiente;}


};


#endif // NODO_H_INCLUDED
