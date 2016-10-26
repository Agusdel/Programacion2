#include <string>
#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "SistemaDeSeguridad.h"
#include "Huesped.h"

using namespace std;

int main()
{
    SistemaDeSeguridad sistema;

    Huesped huesped1("Juan","pachucho",156435,"huella");
    Huesped huesped2("Pepe","pachucho",156435,"huella2");
    Huesped huesped3("Pipo","pachucho",156435,"huella3");
    Huesped huesped4("Papo","pachucho",156435,"huella4");

    sistema.ActivarHuesped(huesped1);
    sistema.ActivarHuesped(huesped2);
    sistema.ActivarHuesped(huesped3);
    sistema.ActivarHuesped(huesped4);
    cout << endl;

    cout << "*****************************" << endl;
    sistema.ImprimirListaHuespedes();
    cout << endl;
    sistema.ImprimirListaHuespedesAdentro();
    cout << "*****************************" << endl;

    cout << endl;
    cout << "\nIngresa nadie" << endl;
    sistema.IngresaHuesped("hasduella",5);
    cout << "\nIngresa 1" << endl;
    sistema.IngresaHuesped("huella",5);
    cout << "\nIngresa 2" << endl;
    sistema.IngresaHuesped("huella2",2);
    cout << "\nIngresa nadie" << endl;
    sistema.IngresaHuesped("huellasdasda2",2);
    cout << "\nIngresa 2" << endl;
    sistema.IngresaHuesped("huella2",5);

    cout << "*****************************" << endl;
    sistema.ImprimirListaHuespedes();
    cout << endl;
    sistema.ImprimirListaHuespedesAdentro();
    cout << "*****************************" << endl;

    cout << "\nSale 1" << endl;
    sistema.SaleHuesped("huella",2);
    cout << "\nSale nadie" << endl;
    sistema.SaleHuesped("huel651a",2);
    cout << "\nSale 1" << endl;
    sistema.SaleHuesped("huella",2);
    cout << "\nIngresa 1" << endl;
    sistema.IngresaHuesped("huella",5);

    cout << "*****************************" << endl;
    sistema.ImprimirListaHuespedes();
    cout << endl;
    sistema.ImprimirListaHuespedesAdentro();
    cout << "*****************************" << endl;

    //sistema.ActivarMolineteDeRepuesto(5);


    cout << "\nIngresa 2 mol 7" << endl;
    sistema.IngresaHuesped("huella2",7);

    cout << "\n";
    sistema.ImprimirInformeActividad();

    return 0;

}
