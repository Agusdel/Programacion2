#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED

#include <time.h>
#include <windows.h>

enum Lado {
    Cara,
    Ceca
};

class Moneda{

private:

public:

    Lado lanzar();

private:

    void prepararRandom();

};

#endif // MONEDA_H_INCLUDED
