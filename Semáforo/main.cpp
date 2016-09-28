#include <iostream>

#include "Semaforo.h"


int main()
{
    Semaforo sem1(Detenerse);
    Semaforo sem2(Prepararse);
    Semaforo sem3(Avanzar);
    Semaforo sem4(Advertencia);

    cout << sem1 << endl << endl << sem2 << endl << endl << sem3 << endl << endl << sem4 << endl;

    sem1.AvanzarEstado();
    sem4.AvanzarEstado();

    cout << endl << sem1 << endl << endl << sem2 << endl << endl << sem3 << endl << endl << sem4 << endl;



    return 0;
}
