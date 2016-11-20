#include <iostream>

#include "Peticion.h"
#include "Servidor.h"
#include "Cliente.h"

#include "Lista.h"

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
    cout << "Se envió peticion critica 25 - 3." << endl;

    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();

    cout << "Se atienden peticiones por lo siguientes 50 ciclos de reloj." << endl << endl;
    s.AtenderPeticiones(50);
    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();

    cout << "Se atienden peticiones por lo siguientes 8 ciclos de reloj." << endl << endl;
    s.AtenderPeticiones(8);
    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();

    cout << "Se atienden peticiones por lo siguientes 40 ciclos de reloj." << endl << endl;
    s.AtenderPeticiones(40);
    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();

    return 0;
}
