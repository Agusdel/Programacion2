#include <iostream>

#include "Peticion.h"
#include "Servidor.h"
#include "Cliente.h"

using namespace std;

int main()
{
    Servidor s("hola");

    Cliente c = Cliente();

    c.VincularServidor(s,"hola");

    if (c.ServidorVinculado() && s.Vinculado(c))
        cout << "Se ha vinculado exitosamente!" << endl << endl;
    else
        cout << "No ha podido vincularse al servidor." << endl << endl;

    PeticionCritica pc1 = PeticionCritica(20,2);
    cout << pc1 << endl;
    c.EnviarPeticion(pc1);
    //cout << "Se envio pc1." << endl;

    Peticion p1 = Peticion(15);
    cout << p1 << endl;
    PeticionCritica pc2(15,5);
    cout << pc2 << endl;
    c.EnviarPeticion(pc2);
    //cout << "Se envió pc2." << endl;
    PeticionCritica pc3(31,5);
    //cout << pc3 << endl;
    PeticionCritica pc4(30,5);
    //cout << pc4 << endl;
    PeticionCritica pc5(30,5);
    //cout << pc5 << endl;

    Peticion p2 = Peticion(7);
    cout << p2 << endl;
    c.EnviarPeticion(p2);
    //cout << "Se envió p2." << endl;
    Peticion p3 = Peticion(60);
    //cout << p3 << endl;
    Peticion p4 = Peticion(90);
    //cout << p4 << endl;
    c.EnviarPeticion(p1);
    //cout << "Se envió p1." << endl;

    c.EnviarPeticion(PeticionCritica(25,3));
    cout << "Se envio peticion critica 25 - 3." << endl;

    cout << "\n********************************** 1 ****************************************" << endl << endl;
    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();

    cout << "\n********************************** 2 ****************************************" << endl << endl;
    cout << "Se atienden peticiones por lo siguientes 50 ciclos de reloj." << endl << endl;
    s.AtenderPeticiones(50);
    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();

    cout << "\n********************************** 3 ****************************************" << endl << endl;
    cout << "Se atienden peticiones por lo siguientes 8 ciclos de reloj." << endl << endl;
    s.AtenderPeticiones(8);
    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();

    cout << "\n********************************** 4 ****************************************" << endl << endl;
    cout << "Se atienden peticiones por lo siguientes 40 ciclos de reloj." << endl << endl;
    s.AtenderPeticiones(40);
    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();

    cout << "\n********************************** 5 ****************************************" << endl << endl;

    Cliente c2 = Cliente(s, "hol");
    c2.VincularServidor(s,"hola");

    if (c2.ServidorVinculado() && s.Vinculado(c2))
        cout << "Se ha vinculado exitosamente!" << endl << endl;
    else
        cout << "No ha podido vincularse al servidor." << endl << endl;

    cout << "\n********************************** 6 ****************************************" << endl << endl;

    c2.DesvincularServidor();
    cout << "Se desvinculo del servidor." << endl << endl;

    if (c2.ServidorVinculado() && s.Vinculado(c2))
        cout << "Se encuentra vinculado." << endl << endl;
    else
        cout << "No se encuentra vinculado." << endl << endl;

    cout << "\n********************************** 7 ****************************************" << endl << endl;

    c2.VincularServidor(s,"hola");

    if (c2.ServidorVinculado() && s.Vinculado(c2))
        cout << "Se ha vinculado exitosamente!" << endl << endl;
    else
        cout << "No ha podido vincularse al servidor." << endl << endl;

    Peticion petC(10);
    Peticion petC2(5);

    c.EnviarPeticion(petC);
    cout << "Cliente c enviando peticion " << petC << endl << endl;
    c2.EnviarPeticion(petC2);
    cout << "Cliente c2 enviando peticion " << petC2 << endl << endl;

    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();

    cout << "\n********************************** 8 ****************************************" << endl << endl;

    cout << "Se atienden peticiones por lo siguientes 7 ciclos de reloj." << endl << endl;
    s.AtenderPeticiones(7);
    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();





    cout << "\n********************************** 9 ****************************************" << endl << endl;

    Peticion pe(7);
    Cliente c3 = Cliente(s,"hola");

    c3.DesvincularServidor();
    cout << "Se desvinculo del servidor." << endl << endl;

    cout << "Intentando enviar peticion...." << endl;
    c3.EnviarPeticion(pe);

    return 0;
}
