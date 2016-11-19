#include <iostream>

#include "Peticion.h"
#include "Servidor.h"
#include "Cliente.h"

#include "Lista.h"

using namespace std;

int main()
{
    Servidor s("hola");

    Cliente c;

    /*PeticionCritica pc1 = PeticionCritica(20,2);
    cout << "Duracion pc1: " << pc1.getDuracion() << endl;
    cout << pc1 << endl;
    c.EnviarPeticion(pc1);
    //cout << "Se envió pc1." << endl;

    Peticion p1 = Peticion(15);
    cout << p1 << endl;
    PeticionCritica pc2(15,5);
    cout << pc2 << endl;
    s.EnviarPeticion(pc2);
    //cout << "Se envió pc2." << endl;
    PeticionCritica pc3(31,5);
    //cout << pc3 << endl;
    PeticionCritica pc4(30,5);
    //cout << pc4 << endl;
    PeticionCritica pc5(30,5);
    //cout << pc5 << endl;

    Peticion p2 = Peticion(7);
    cout << p2 << endl;
    s.EnviarPeticion(p2);
    //cout << "Se envió p2." << endl;
    Peticion p3 = Peticion(60);
    //cout << p3 << endl;
    Peticion p4 = Peticion(90);
    //cout << p4 << endl;
    s.EnviarPeticion(p1);
    //cout << "Se envió p1." << endl;

    s.EnviarPeticion(PeticionCritica(25,0));
    cout << "Se envió peticion critica 25 - 3." << endl;

    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();

    s.AtenderPeticiones(100);
    s.PeticionesCriticasPorAtender();
    s.PeticionesNoCriticasPorAtender();
    s.ProximaPeticion();

    ///     CLIENTE


    Peticion p(20);

    Cliente c(s);

    c.EnviarPeticion(p);
    PeticionCritica ph(30,5);
    cout << ph << endl;
    c.EnviarPeticion(ph);
    PeticionCritica ph2 =  PeticionCritica(20,4);
    cout << ph2 << endl;
    c.EnviarPeticion(ph2);

    s.ProximaPeticion();*/







    /*Lista<int> l;
    l.agregar(3);
    l.agregar(2);
    Lista<int> s = l;

    cout << " s = l " << endl << endl;

    l.iniciarCursor();
    cout << "   Elementos de l. " << endl << endl;
    while (l.avanzarCursor()){
        cout << "Elem l: " << l.obtenerCursor() << endl;
    }
    s.iniciarCursor();
    cout << "   Elementos de s. " << endl << endl;
    while (s.avanzarCursor()){
        cout << "Elem s: " << s.obtenerCursor() << endl;
    }

    cout << "Elementos de l: " << l.contarElementos() << endl;
    cout << "Elementos de s: " << s.contarElementos() << endl;


    cout << " l.remover(1) " << endl << endl;
    l.remover(1);
    cout << " s.agregar(5) " << endl << endl;
    s.agregar(5);
    cout << "Elementos de l: " << l.contarElementos() << endl;
    cout << "Elementos de s: " << s.contarElementos() << endl;
    l.iniciarCursor();
    cout << "   Elementos de l. " << endl << endl;
    while (l.avanzarCursor()){
        cout << "Elem l: " << l.obtenerCursor() << endl;
    }
    s.iniciarCursor();
    cout << "   Elementos de s. " << endl << endl;
    while (s.avanzarCursor()){
        cout << "Elem s: " << s.obtenerCursor() << endl;
    }

    s.asignar(4,3);
    cout << " s.asignar(4,3) " << endl << endl;

    l.iniciarCursor();
    cout << "   Elementos de l. " << endl << endl;
    while (l.avanzarCursor()){
        cout << "Elem l: " << l.obtenerCursor() << endl;
    }
    s.iniciarCursor();
    cout << "   Elementos de s. " << endl << endl;
    while (s.avanzarCursor()){
        cout << "Elem s: " << s.obtenerCursor() << endl;
    }*/

    return 0;
}
