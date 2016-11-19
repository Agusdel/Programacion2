#include "Servidor.h"

bool Servidor::PunteroCliente::operator==(PunteroCliente otro){
    return cliente->getID() == otro.cliente->getID();
}

Servidor::Servidor(std::string contrasenia){
    this->contrasenia = contrasenia;
    tiempoPets = 0;
    tiempoPetsCrits = 0;
}

void Servidor::EnviarPeticion(const Cliente& c, const Peticion& pet){
    PetNC p;
    p.pet = &pet;
    p.cliente = &c;
    peticiones.push(p);
    tiempoPets += pet.getDuracion();
}

void Servidor::EnviarPeticion(const Cliente& c, const PeticionCritica& pet){
    PetC p;
    p.pet = &pet;
    p.cliente = &c;
    peticionesCriticas.push(p,pet.getPrioridad());
    tiempoPetsCrits += pet.getDuracion();
}

void Servidor::PeticionesNoCriticasPorAtender() const{
    if (!peticiones.estaVacia()){
        std::cout << std::endl << std::endl;
        std::cout << "\t* * * Cantidad de peticiones no criticas por atender: " << peticiones.contarElementos() << ". * * *" << std::endl << std::endl;
        std::cout << "\t* * * Se requeriran " << tiempoPets << " ciclos de reloj para procesarlas todas. * * *\n\n";
    }
    else
        std::cout << "\t* * * No hay peticiones no criticas por atender. * * *\n\n";
}

void Servidor::PeticionesCriticasPorAtender() const{
    if (!peticionesCriticas.estaVacia()){
        std::cout << std::endl << std::endl;
        std::cout << "\t* * * Cantidad de peticiones criticas por atender: " << peticionesCriticas.cantidadElementos() << ". * * *" << std::endl << std::endl;
        std::cout << "\t* * * Se requeriran " << tiempoPetsCrits << " ciclos de reloj para procesarlas todas. * * *\n\n";
    }
    else
        std::cout << "\t* * * No hay peticiones criticas por atender. * * *\n\n";
}

void Servidor::ProximaPeticion(){
    std::cout << "\tProxima peticion a ser atendida: \n\t\t";
    if (!peticionesCriticas.estaVacia()){
        std::cout << *peticionesCriticas.top().pet;
    }
    else if (!peticiones.estaVacia())
        std::cout << *peticiones.top().pet;
    else
        std::cout << "No hay peticiones.";
    std::cout << "\n\n";
}

void Servidor::AtenderPeticiones(unsigned int tiempo){
    if (tiempo == 0){  // Caso tiempo 0: reestablezco las colas.
        while (!colaAuxC.estaVacia()){             /// IMPORTANTE: AL REESTABLECER LA COLA DE PRIORIDAD, LAS PETICIONES VUELVEN A QUEDAR EN ORDEN RESPETANDO SU PRIORIDAD.
            PetC p = colaAuxC.pop();
            peticionesCriticas.push(p,p.pet->getPrioridad());
        }
        while (!peticiones.estaVacia()){           /// IMPORTANTE: SI SE REESTABLECIERA LA COLA ORIGINAL SIMPLEMENTE PUSHEANDO LOS ELEMENTOS DE LA AUXILIAR,
                                                  /// SE PERDERÍA EL ORDEN ORIGINAL, QUEDANDO LAS DE LA COLA QUE ORIGINALMENTE ESTABAN PRIMERAS, AL FINAL.
                                                  /// PARA MANTENER EL ORDEN, PRIMERO SE TERMINAN DE PASAR TODAS LAS PETICIONES A LA COLA AUXILIAR, Y DESPUÉS TODAS NUEVAMENTE A LA ORIGINAL,
                                                  /// Y ASÍ SE GARANTIZA MANTENER EL ORDEN ORIGINAL. SI SE TRABAJARA CON MILLONES DE PETICIONES, ESTO SERIA BASTANTE INEFICIENTE, PERO ACA NO SAPA NADA.
            colaAuxNC.push(peticiones.pop());
        }
        while (!colaAuxNC.estaVacia())
            peticiones.push(colaAuxNC.pop());
    }
    else if (!peticionesCriticas.estaVacia()){
        PetC p = peticionesCriticas.pop();
        if (p.pet->getDuracion() > tiempo){     // EN CASO DE QUE NO HAYA SUFICIENTE TIEMPO PARA ATENDER ESA PETICION, SE LA GUARDA EN UNA COLA AUXILIAR Y SE SIGUE CON LA SIGUIENTE.
            colaAuxC.push(p);
            AtenderPeticiones(tiempo);
        }
        else { //CASO DONDE ALCANZA EL TIEMPO: YA LA POPEE Y LLAMO RECURSIVAMENTE PERO RESTANDOLE EL TIEMPO.
            tiempoPetsCrits -= p.pet->getDuracion();
            p.cliente->NotificarPeticionAtendida(*p.pet);
            AtenderPeticiones(tiempo-p.pet->getDuracion());
        }
    }
    else if (!peticiones.estaVacia()){
        PetNC p = peticiones.pop();
        if (p.pet->getDuracion() > tiempo){     // EN CASO DE QUE NO HAYA SUFICIENTE TIEMPO PARA ATENDER ESA PETICION, SE LA GUARDA EN UNA COLA AUXILIAR Y SE SIGUE CON LA SIGUIENTE.
            colaAuxNC.push(p);
            AtenderPeticiones(tiempo);
        }
        else { //CASO DONDE ALCANZA EL TIEMPO: YA LA POPEE Y LLAMO RECURSIVAMENTE PERO RESTANDOLE EL TIEMPO.
            tiempoPets -= p.pet->getDuracion();
            p.cliente->NotificarPeticionAtendida(*p.pet);
            AtenderPeticiones(tiempo-p.pet->getDuracion());
        }
    }
    else {// CASO DONDE NO HAY PETICIONES POR ATENDER, O DONDE EL TIEMPO NO ALCANZA PARA ATENDER NINGUNA (llega a este caso porque todas las peticiones están en las colas auxiliares.)
        AtenderPeticiones(0); // Se llama al caso base para que se reestablezcan las colas y se termine la ejecución de la función.
    }
}
