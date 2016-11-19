#ifndef COLAPRIORIDAD_H_INCLUDED
#define COLAPRIORIDAD_H_INCLUDED

#include "Lista.h"

template <class T>
class ColaPrioridad{

private:

    struct Par{
        T* elem;
        unsigned int prioridad;
    };

    Lista<Par> lista;

public:

    ~ColaPrioridad(){
        while (!estaVacia())
            pop();
    }

    void push(T elem, unsigned int prioridad){
        lista.iniciarCursor();
        bool listo = false;
        unsigned int pos = 1;
        while (lista.avanzarCursor() && !listo){
            Par par = lista.obtenerCursor();
            if (prioridad < par.prioridad){
                listo = true;
                Par nuevoElem;
                nuevoElem.elem = new T(elem);
                nuevoElem.prioridad = prioridad;
                lista.agregar(nuevoElem,pos);
            }
            pos++;
        }
        if (!listo){
            Par nuevoElem;
            nuevoElem.elem = new T(elem);
            nuevoElem.prioridad = prioridad;
            lista.agregar(nuevoElem);
        }
    }

    T pop(){
        T tope;
        if (!lista.estaVacia()){
            Par p = lista.obtener(1);
            tope = T(*p.elem);
            delete p.elem;
            lista.remover(1);
        }
        return tope;
    }

    T top() {
        T tope = T(*lista.obtener(1).elem);
        return tope;
    }

    bool estaVacia() const {return lista.estaVacia();}

    unsigned int cantidadElementos() const {return lista.contarElementos();}

    void iniciarCursor(){lista.iniciarCursor();}

    bool avanzarCursor(){return lista.avanzarCursor();}

    T obtenerCursor(){
        T tope = T(*lista.obtenerCursor().elem);
        return tope;
    }

};

#endif // COLAPRIORIDAD_H_INCLUDED
