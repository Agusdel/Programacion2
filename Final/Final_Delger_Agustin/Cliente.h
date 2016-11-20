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
    /* FUNCI�N: Crea un nuevo cliente, y se le asigna un id univoco.
     * PRECONDICI�N: true.
     * POSTCONDICION: Crea un nuevo cliente, y se le asigna un id univoco.
     */

    Cliente(Servidor& servidor, std::string contrasenia);
    /* FUNCI�N: Crea un nuevo cliente, se le asigna un id univoco, y si la contrase�a es correcta, se vincula autom�ticamente con el servidor.
     * PRECONDICI�N: true.
     * POSTCONDICION: Crea un nuevo cliente, se le asigna un id univoco, y si la contrase�a es correcta, se vincula autom�ticamente con el servidor.
     */

    unsigned int getID() const;
    /* FUNCI�N: Devuelve el ID del cliente.
     * PRECONDICI�N: true.
     * POSTCONDICION: Devuelve el ID del cliente.
     */

    Servidor getServidor() const;
    /* FUNCI�N: Devuelve el servidor del cliente.
     * PRECONDICI�N: El cliente debe estar vinculado a un servidor.
     * POSTCONDICION: Devuelve el servidor del cliente.
     */

    bool ServidorVinculado();
    /* FUNCI�N: Determina si el servidor se encuentra vinculado al servidor.
     * PRECONDICI�N: true.
     * POSTCONDICION: Determina si el servidor se encuentra vinculado al servidor.
     */

    bool VincularServidor(Servidor& servidor, std::string contrasenia);
    /* FUNCI�N: Vincula al cliente con un servidor.
     * PRECONDICI�N: El cliente no se encuentra vinculado a ningun servidor.
     * POSTCONDICION: Si la contrase�a es la correcta, vincula al cliente con un servidor.
     */

    void DesvincularServidor();
    /* FUNCI�N: Desvincula al cliente del servidor.
     * PRECONDICI�N: El cliente debe estar vinculado a algun servidor.
     * POSTCONDICION: Desvincula al cliente del servidor.
     */

    void NotificarPeticionAtendida(Peticion peticion) const;
    /* FUNCI�N: Informa al cliente que la petici�n ha sido atendida.
     * PRECONDICI�N: true.
     * POSTCONDICION: Imprime por pantalla un mensaje informando al cliente que una petici�n enviada por �ste ha sido atendida.
     */

    void NotificarPeticionAtendida(PeticionCritica peticion) const;
    /* FUNCI�N: Informa al cliente que la petici�n cr�tica ha sido atendida.
     * PRECONDICI�N: true.
     * POSTCONDICION: Imprime por pantalla un mensaje informando al cliente que una petici�n cr�tica enviada por �ste ha sido atendida.
     */

    void EnviarPeticion(Peticion peticion);
    /* FUNCI�N: Se envia una nueva petici�n al servidor con el que se est� vinculado.
     * PRECONDICI�N: El cliente est� vinculado con un servidor.
     * POSTCONDICION: Se envia una nueva petici�n al servidor con el que se est� vinculado.
     */

    void EnviarPeticion(PeticionCritica peticion);
    /* FUNCI�N: Se envia una nueva petici�n cr�tica al servidor con el que se est� vinculado.
     * PRECONDICI�N: El cliente est� vinculado con un servidor.
     * POSTCONDICION: Se envia una nueva petici�n cr�tica al servidor con el que se est� vinculado.
     */

    bool operator== (Cliente otro);
    /* FUNCI�N: Determina si dos clientes son el mismo.
     * PRECONDICI�N: true.
     * POSTCONDICION: Determina si dos clientes son el mismo al comparar sus IDs.
     */
};

#endif // CLIENTE_H_INCLUDED
