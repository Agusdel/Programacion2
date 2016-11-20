#ifndef SERVIDOR_H_INCLUDED
#define SERVIDOR_H_INCLUDED

#include <string>

#include "Cola.h"
#include "ColaPrioridad.h"
#include "Peticion.h"
#include "Cliente.h"
#include "Lista.h"

class Cliente;

class Servidor{

private:

    struct PetNC{
        const Peticion* pet;
        const Cliente* cliente;
    };

    struct PetC{
        const PeticionCritica* pet;
        const Cliente* cliente;
    };
/*
    struct PunteroCliente{   /// IGUALAR LOS PUNTEROS POSTA POSTA
        Cliente* cliente;
        bool operator== (PunteroCliente otro);
    };*/

    std::string contrasenia;

    Lista<Cliente*> clientes;

    Cola<PetNC> peticiones;

    unsigned int tiempoPets;

    ColaPrioridad<PetC> peticionesCriticas;

    unsigned int tiempoPetsCrits;

    Cola<PetNC> colaAuxNC; //Cola auxiliar para peticiones no cr�ticas.

    Cola<PetC> colaAuxC;  //Cola auxiliar para peticiones cr�ticas.

public:

    Servidor(std::string contrasenia = "");
    /* FUNCI�N: Crea un nuevo servidor con colas vac�as y tiempos en 0.
     * PRECONDICI�N: true.
     * POSTCONDICION: Crea un nuevo servidor con una contrase�a, colas vac�as y tiempos en 0.
     */

    bool CambiarContrasenia(std::string nuevaContrasenia, std::string contraseniaActual);

    bool Vincularse(Cliente& c, std::string contrasenia);

    void Desvincularse(Cliente& c);

    bool Vinculado(Cliente& c);

    void EnviarPeticion(Cliente& c, const Peticion& pet);
    /* FUNCI�N: Se recibe una nueva petici�n.
     * PRECONDICI�N: true.
     * POSTCONDICION: La petici�n se agrega �ltima en la cola de peticiones no cr�ticas. Se aumenta el tiempo de peticiones en la duraci�n de esta.
     */

    void EnviarPeticion(Cliente& c, const PeticionCritica& pet);
    /* FUNCI�N: Se recibe una nueva petici�n critica.
     * PRECONDICI�N: true.
     * POSTCONDICION: Se ajusta la prioridad a un numero entre 1 y 10. La petici�n se agrega en la cola de peticiones no cr�ticas de acuerdo con su prioridad.
     *                Ser� ubicada �ltima entre las de su misma prioridad. Se aumenta el tiempo de peticiones criticas en la duraci�n de esta.
     */

    void PeticionesNoCriticasPorAtender() const;
    /* FUNCI�N: Se imprime por pantalla la cantidad de peticiones no cr�ticas por atender y el tiempo que consumir�a atenderlas todas.
     * PRECONDICI�N: true.
     * POSTCONDICION: Se imprime por pantalla la cantidad de peticiones no cr�ticas por atender y el tiempo que consumir�a atenderlas todas.
     */

    void PeticionesCriticasPorAtender() const;
    /* FUNCI�N: Se imprime por pantalla la cantidad de peticiones cr�ticas por atender y el tiempo que consumir�a atenderlas todas.
     * PRECONDICI�N: true.
     * POSTCONDICION: Se imprime por pantalla la cantidad de peticiones cr�ticas por atender y el tiempo que consumir�a atenderlas todas.
     */

    void ProximaPeticion();
    /* FUNCI�N: Se imprime por pantalla la proxima petici�n a ser atendida, si es que hay al menos una.
     * PRECONDICI�N: true.
     * POSTCONDICION: Se imprime por pantalla la proxima petici�n a ser atendida, si es que hay al menos una..
     */

    void AtenderPeticiones(unsigned int tiempo);
    /* FUNCI�N: Se atienden peticiones por los proximos "tiempo" ciclos de reloj.
     * PRECONDICI�N: true.
     * POSTCONDICION: Se atienden peticiones por los proximos "tiempo" ciclos de reloj. De no haber tiempo suficiente para atender una petici�n,
     *                se lo intentar� con la siguiente en la cola. El orden de las colas se mantiene.
     */

};

#endif // SERVIDOR_H_INCLUDED
