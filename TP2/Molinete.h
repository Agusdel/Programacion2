#ifndef MOLINETE_H_INCLUDED
#define MOLINETE_H_INCLUDED

class Molinete{

private:

    unsigned int cantIngr;
    unsigned int cantEgr;

public:

    Molinete();

    void dejarEntrar();

    void dejarSalir();

    unsigned int cantIngresos();

    unsigned int cantEgresos();

};

#endif // MOLINETE_H_INCLUDED
