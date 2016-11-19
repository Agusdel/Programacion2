#include <iostream>
#include "Lista.h"

using namespace std;

int main() {

    Lista<float> listaDeCalificaciones;

    cout << "Ingrese las calificaciones, 0 para terminar" << endl;

    float calificacion;

    do {

        cin >> calificacion;
        listaDeCalificaciones.agregar(calificacion);

    } while (calificacion > 0);

    float promedio = 0;

    int mayores = 0;

    listaDeCalificaciones.iniciarCursor();

    while (listaDeCalificaciones.avanzarCursor()) {

        promedio += listaDeCalificaciones.obtenerCursor();

        if (listaDeCalificaciones.obtenerCursor() > 70.00) {

            mayores++;
        }
    }

    cout << "\n\nPromedio: " << promedio / listaDeCalificaciones.contarElementos() << endl;

    cout << "\n\nMayores a 70.00: " << mayores << endl;

    cout << "\n\nIngrese elemento a buscar: ";

    int busqueda;

    cin >> busqueda;

    cout << "\n\nPodicion del elemento: " << listaDeCalificaciones.esta(busqueda) << endl;

	return 0;
}
