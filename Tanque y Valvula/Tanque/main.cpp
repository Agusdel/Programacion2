#include "Tanque.h"

using namespace std;

int main(void)
{
    Tanque miTanque("entrada","salida",6000);

    cout << "Capacidad: " << miTanque.getCapacidad() << endl;

    miTanque.agregar(100.0,"entrada");
    cout << "Se agregan 100 litros." << endl << endl;

    cout << "Contenido: " << miTanque.getContenido() << endl;

    miTanque.agregar(3000.0,"salida");
    miTanque.agregar(3000.0,"entrada");

    cout << "Ahora tiene: " << miTanque.getContenido() << endl;

    miTanque.agregar(3000.0,"entrada");
    cout << "Se agregan 3000 litros." << endl << endl;

    miTanque.sacar(2000.0,"salida");
    cout << "Se sacan 2000 litros." << endl << endl;

    cout << "Ahora tiene: " << miTanque.getContenido() << endl;

    miTanque.sacar(2000.0,"salida");

    return 0;
}
