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
    /* FUNCIÓN: Crea un nuevo servidor con colas vacías, tiempos en 0 y se establece la contraseña.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Crea un nuevo servidor con una contraseña, colas vacías y tiempos en 0.
     */

    bool CambiarContrasenia(std::string nuevaContrasenia, std::string contraseniaActual);
    /* FUNCIÓN: Se cambia la contraseña por una nueva.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Se cambia la contraseña por una nueva.
     */

    bool Vincularse(Cliente& c, std::string contrasenia);
    /* FUNCIÓN: Si la contraseña es correcta, se vincula un cliente con el servidor.
     * PRECONDICIÓN: El cliente no esta vinculado ya.
     * POSTCONDICION: Si la contraseña es correcta, se vincula un cliente con el servidor. Se agrega un puntero al cliente en la lista clientes.
     */

    void Desvincularse(Cliente& c);
    /* FUNCIÓN: Se desvincula un cliente del servidor.
     * PRECONDICIÓN: El cliente se encuentra vinculado.
     * POSTCONDICION: Se desvincula un cliente del servidor. Se quita el puntero al cliente de la lista clientes.
     */

    bool Vinculado(Cliente& c);
    /* FUNCIÓN: Determina si el cliente se encuentra vinculado actualmente al servidor.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Determina si el cliente se encuentra vinculado actualmente al servidor.
     */

    void EnviarPeticion(Cliente& c, const Peticion& pet);
    /* FUNCIÓN: Se recibe una nueva petición.
     * PRECONDICIÓN: El cliente está vinculado con el servidor.
     * POSTCONDICION: La petición se agrega última en la cola de peticiones no críticas. Se aumenta el tiempo de peticiones en la duración de esta.
     */

    void EnviarPeticion(Cliente& c, const PeticionCritica& pet);
    /* FUNCIÓN: Se recibe una nueva petición critica.
     * PRECONDICIÓN: El cliente está vinculado con el servidor.
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
