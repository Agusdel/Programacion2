#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "Servidor.h"
#include "Peticion.h"

class Servidor;

class Cliente{

private:

    static unsigned int ids;

    unsigned int id;

    Servidor* servidor;

public:

    Cliente();
    /* FUNCIÓN: Crea un nuevo cliente, y se le asigna un id univoco.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Crea un nuevo cliente, y se le asigna un id univoco.
     */

    Cliente(Servidor& servidor, std::string contrasenia);
    /* FUNCIÓN: Crea un nuevo cliente, se le asigna un id univoco, y si la contraseña es correcta, se vincula automáticamente con el servidor.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Crea un nuevo cliente, se le asigna un id univoco, y si la contraseña es correcta, se vincula automáticamente con el servidor.
     */

    unsigned int getID() const;
    /* FUNCIÓN: Devuelve el ID del cliente.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Devuelve el ID del cliente.
     */

    Servidor getServidor() const;
    /* FUNCIÓN: Devuelve el servidor del cliente.
     * PRECONDICIÓN: El cliente debe estar vinculado a un servidor.
     * POSTCONDICION: Devuelve el servidor del cliente.
     */

    bool ServidorVinculado();
    /* FUNCIÓN: Determina si el servidor se encuentra vinculado al servidor.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Determina si el servidor se encuentra vinculado al servidor.
     */

    bool VincularServidor(Servidor& servidor, std::string contrasenia);
    /* FUNCIÓN: Vincula al cliente con un servidor.
     * PRECONDICIÓN: El cliente no se encuentra vinculado a ningun servidor.
     * POSTCONDICION: Si la contraseña es la correcta, vincula al cliente con un servidor.
     */

    void DesvincularServidor();
    /* FUNCIÓN: Desvincula al cliente del servidor.
     * PRECONDICIÓN: El cliente debe estar vinculado a algun servidor.
     * POSTCONDICION: Desvincula al cliente del servidor.
     */

    void NotificarPeticionAtendida(Peticion peticion) const;
    /* FUNCIÓN: Informa al cliente que la petición ha sido atendida.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Imprime por pantalla un mensaje informando al cliente que una petición enviada por éste ha sido atendida.
     */

    void NotificarPeticionAtendida(PeticionCritica peticion) const;
    /* FUNCIÓN: Informa al cliente que la petición crítica ha sido atendida.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Imprime por pantalla un mensaje informando al cliente que una petición crítica enviada por éste ha sido atendida.
     */

    void EnviarPeticion(Peticion peticion);
    /* FUNCIÓN: Se envia una nueva petición al servidor con el que se está vinculado.
     * PRECONDICIÓN: El cliente está vinculado con un servidor.
     * POSTCONDICION: Se envia una nueva petición al servidor con el que se está vinculado.
     */

    void EnviarPeticion(PeticionCritica peticion);
    /* FUNCIÓN: Se envia una nueva petición crítica al servidor con el que se está vinculado.
     * PRECONDICIÓN: El cliente está vinculado con un servidor.
     * POSTCONDICION: Se envia una nueva petición crítica al servidor con el que se está vinculado.
     */

    bool operator== (Cliente otro);
    /* FUNCIÓN: Determina si dos clientes son el mismo.
     * PRECONDICIÓN: true.
     * POSTCONDICION: Determina si dos clientes son el mismo al comparar sus IDs.
     */
};

#endif // CLIENTE_H_INCLUDED
