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

    Cola<PetNC> colaAuxNC; //Cola auxiliar para peticiones no críticas.

    Cola<PetC> colaAuxC;  //Cola auxiliar para peticiones críticas.

public:

    Servidor(std::string contrasenia = "");
    /* FUNCIÓN: Crea un nuevo servidor con colas vacías y tiempos en 0.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Crea un nuevo servidor con una contraseña, colas vacías y tiempos en 0.
     */

    bool CambiarContrasenia(std::string nuevaContrasenia, std::string contraseniaActual);

    bool Vincularse(Cliente& c, std::string contrasenia);

    void Desvincularse(Cliente& c);

    bool Vinculado(Cliente& c);

    void EnviarPeticion(Cliente& c, const Peticion& pet);
    /* FUNCIÓN: Se recibe una nueva petición.
     * PRECONDICIÓN: true.
     * POSTCONDICION: La petición se agrega última en la cola de peticiones no críticas. Se aumenta el tiempo de peticiones en la duración de esta.
     */

    void EnviarPeticion(Cliente& c, const PeticionCritica& pet);
    /* FUNCIÓN: Se recibe una nueva petición critica.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Se ajusta la prioridad a un numero entre 1 y 10. La petición se agrega en la cola de peticiones no críticas de acuerdo con su prioridad.
     *                Será ubicada última entre las de su misma prioridad. Se aumenta el tiempo de peticiones criticas en la duración de esta.
     */

    void PeticionesNoCriticasPorAtender() const;
    /* FUNCIÓN: Se imprime por pantalla la cantidad de peticiones no críticas por atender y el tiempo que consumiría atenderlas todas.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Se imprime por pantalla la cantidad de peticiones no críticas por atender y el tiempo que consumiría atenderlas todas.
     */

    void PeticionesCriticasPorAtender() const;
    /* FUNCIÓN: Se imprime por pantalla la cantidad de peticiones críticas por atender y el tiempo que consumiría atenderlas todas.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Se imprime por pantalla la cantidad de peticiones críticas por atender y el tiempo que consumiría atenderlas todas.
     */

    void ProximaPeticion();
    /* FUNCIÓN: Se imprime por pantalla la proxima petición a ser atendida, si es que hay al menos una.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Se imprime por pantalla la proxima petición a ser atendida, si es que hay al menos una..
     */

    void AtenderPeticiones(unsigned int tiempo);
    /* FUNCIÓN: Se atienden peticiones por los proximos "tiempo" ciclos de reloj.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Se atienden peticiones por los proximos "tiempo" ciclos de reloj. De no haber tiempo suficiente para atender una petición,
     *                se lo intentará con la siguiente en la cola. El orden de las colas se mantiene.
     */

};

#endif // SERVIDOR_H_INCLUDED
