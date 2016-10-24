#include "SistemaDeSeguridad.h"


SistemaDeSeguridad::SistemaDeSeguridad(){
    listaDeHuespedes = new Lista<Huesped>();

    molinete1 = Molinete();
    molinete2 = Molinete();
    molinete3 = Molinete();
    molinete4 = Molinete();
    molinete5 = Molinete();
    molinete6 = Molinete();
    molineteDeRespuesto = Molinete();

    this->cantidadTotalIngresos = 0;

    hayMolineteRoto = false;
}

SistemaDeSeguridad::~SistemaDeSeguridad(){
    delete listaDeHuespedes;
}

void SistemaDeSeguridad::ActivarHuesped(Huesped huesped){
    listaDeHuespedes->agregar(huesped);
}
void SistemaDeSeguridad::DesactivarHuesped(Huesped huesped){
    listaDeHuespedes->eliminar(listaDeHuespedes->pertenece(huesped));
}

void SistemaDeSeguridad::ActivarMolineteDeRepuesto(unsigned short numMolineteRoto){
    if (!hayMolineteRoto){
        hayMolineteRoto = true;
        molineteRoto = numMolineteRoto;
    }
    else {
        std::cout << "El molinete de respuesta ya se encuentra activado, dado que el molinete " << molineteRoto << " no está en funcionamiento. \n";
    }
}
void SistemaDeSeguridad::MolinetesReparados(){
    hayMolineteRoto = false;
}

bool SistemaDeSeguridad::IngresaHuesped(Huesped huesped, unsigned short numMolinete){
    bool ingresoExitoso = false;
    if (numMolinete >= 1 && numMolinete <= 7){
        if (hayMolineteRoto && numMolinete == molineteRoto){
            std::cout << "Este molinete se encuentra fuera de servicio actualmente. Disculpe las molestias ocasionadas. \n";
        }
        else if (numMolinete == 7 && !hayMolineteRoto){
            std::cout << "Este molinete se encuentra desactivado actualmente. Será activado en caso de mal funcionamiento por parte de otro molinete. \n";
        }
        else { ///CASO DE MOLINETE VALIDO Y EN FUNCIONAMIENTO.
            if (listaDeHuespedes->pertenece(huesped)){  // CASO EL HUESPED PERTENECE A LA LISTA

                ingresoExitoso = true;
            }
            else {                                      // CASO NO PERTENECE

            }
        }
    }
    else{
        std::cout << "Número de molinete inválido. 1-6 para molinetes regulares. 7 para molinete de respuesto. \n";
        //En un código más en serio, acá tiro excepción.
    }
    return ingresoExitoso;
}

bool SistemaDeSeguridad::SaleHuesped(Huesped huesped, unsigned short numMolinete){
    bool egresoExitoso = false;
    if (numMolinete >= 1 && numMolinete <= 7){
        if (hayMolineteRoto && numMolinete == molineteRoto){
            std::cout << "Este molinete se encuentra fuera de servicio actualmente. Disculpe las molestias ocasionadas. \n";
        }
        else if (numMolinete == 7 && !hayMolineteRoto){
            std::cout << "Este molinete se encuentra desactivado actualmente. Será activado en caso de mal funcionamiento por parte de otro molinete. \n";
        }
        else { ///CASO DE MOLINETE VALIDO Y EN FUNCIONAMIENTO.
            if (listaDeHuespedes->pertenece(huesped)){  // CASO EL HUESPED PERTENECE A LA LISTA

                egresoExitoso = true;
            }
            else {                                      // CASO NO PERTENECE

            }
        }
    }
    else{
        std::cout << "Número de molinete inválido. 1-6 para molinetes regulares. 7 para molinete de respuesto. \n";
        //En un código más en serio, acá tiro excepción.
    }
    return egresoExitoso;
}

void SistemaDeSeguridad::ImprimirListaHuespedes(){

}

void SistemaDeSeguridad::ImprimirInformeActividad(){

}
