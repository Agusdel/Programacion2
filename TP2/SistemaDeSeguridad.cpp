#include "SistemaDeSeguridad.h"


SistemaDeSeguridad::SistemaDeSeguridad(){
    listaDeHuespedes = new Lista<Huesped>();
    listaHuespedesAdentro = new Lista<Huesped>();

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
    delete listaHuespedesAdentro;
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

bool SistemaDeSeguridad::IngresaHuesped(std::string huella, unsigned short numMolinete){
    bool ingresoExitoso = false;
    if (numMolinete >= 1 && numMolinete <= 7){
        if (hayMolineteRoto && numMolinete == molineteRoto){
            std::cout << "Este molinete se encuentra fuera de servicio actualmente. Disculpe las molestias ocasionadas. \n";
        }
        else if (numMolinete == 7 && !hayMolineteRoto){
            std::cout << "Este molinete se encuentra desactivado actualmente. Será activado en caso de mal funcionamiento por parte de otro molinete. \n";
        }
        else { ///CASO DE MOLINETE VALIDO Y EN FUNCIONAMIENTO.
            if (PerteneceHuespedALista(listaDeHuespedes, huella)){  // CASO EL HUESPED PERTENECE A LA LISTA
                listaHuespedesAdentro->agregar(listaDeHuespedes->obtenerCursor());
                switch (numMolinete){
                    case 1:
                        molinete1.dejarEntrar();
                        break;
                    case 2:
                        molinete2.dejarEntrar();
                        break;
                    case 3:
                        molinete3.dejarEntrar();
                        break;
                    case 4:
                        molinete4.dejarEntrar();
                        break;
                    case 5:
                        molinete5.dejarEntrar();
                        break;
                    case 6:
                        molinete6.dejarEntrar();
                        break;
                    case 7:
                        molineteDeRespuesto.dejarEntrar();
                        break;
                }
                ingresoExitoso = true;
            }
            else {                                      // CASO NO PERTENECE
            }
            ImprimirEnArchivo(huella,"ingreso",ingresoExitoso);
        }
    }
    else{
        std::cout << "Número de molinete inválido. 1-6 para molinetes regulares. 7 para molinete de respuesto. \n";
        //En un código más en serio, acá tiro excepción.
    }
    return ingresoExitoso;
}

bool SistemaDeSeguridad::SaleHuesped(std::string huella, unsigned short numMolinete){
    bool egresoExitoso = false;
    if (numMolinete >= 1 && numMolinete <= 7){
        if (hayMolineteRoto && numMolinete == molineteRoto){
            std::cout << "Este molinete se encuentra fuera de servicio actualmente. Disculpe las molestias ocasionadas. \n";
        }
        else if (numMolinete == 7 && !hayMolineteRoto){
            std::cout << "Este molinete se encuentra desactivado actualmente. Será activado en caso de mal funcionamiento por parte de otro molinete. \n";
        }
        else { ///CASO DE MOLINETE VALIDO Y EN FUNCIONAMIENTO.
            if (PerteneceHuespedALista(listaHuespedesAdentro, huella)){  // CASO EL HUESPED PERTENECE A LA LISTA
                // tiene que estar en la lista de huespedes o la de huespedes adentro????? huespedes adentro
                egresoExitoso = true;
            }
            else {                                      // CASO NO PERTENECE

            }
            ImprimirEnArchivo(huella,"egreso",egresoExitoso);
        }
    }
    else{
        std::cout << "Número de molinete inválido. 1-6 para molinetes regulares. 7 para molinete de respuesto. \n";
        //En un código más en serio, acá tiro excepción.
    }
    return egresoExitoso;
}

void SistemaDeSeguridad::ImprimirListaHuespedes(){
    std::cout << "\tCantidad de huespedes dentro del hotel: " << listaHuespedesAdentro->tamanio() << "\n\n";
    std::cout << "\tListado de huespedes dentro del Hotel: \n\n";
    listaHuespedesAdentro->iniciarCursor();
    while(listaHuespedesAdentro->avanzarCursor()){
        std::cout << "\t\t - " << listaHuespedesAdentro->obtenerCursor() << std::endl;
    }
}

void SistemaDeSeguridad::ImprimirInformeActividad(){
    std::cout << "\tInforme de actividad: \n\n";
    std::cout << "\t\t - Huespedes que ingresaron hasta la fecha: " << cantidadTotalIngresos << ".\n";
    std::cout << "\t\t - Huespedes dentro del predio actualmente: " << listaHuespedesAdentro->tamanio() << ".\n";
    std::cout << "\t\t - Porcentaje de ingresos por molinete: \n";
    std::cout << "\t\t\t * Molinete 1: " << molinete1.cantIngresos()/cantidadTotalIngresos << "%\n";
    std::cout << "\t\t\t * Molinete 2: " << molinete2.cantIngresos()/cantidadTotalIngresos << "%\n";
    std::cout << "\t\t\t * Molinete 3: " << molinete3.cantIngresos()/cantidadTotalIngresos << "%\n";
    std::cout << "\t\t\t * Molinete 4: " << molinete4.cantIngresos()/cantidadTotalIngresos << "%\n";
    std::cout << "\t\t\t * Molinete 5: " << molinete5.cantIngresos()/cantidadTotalIngresos << "%\n";
    std::cout << "\t\t\t * Molinete 6: " << molinete6.cantIngresos()/cantidadTotalIngresos << "%\n";
    std::cout << "\t\t\t * Molinete de Repuesto: " << molineteDeRespuesto.cantIngresos()/cantidadTotalIngresos << "%\n\n";
    std::cout << "\t\t - Porcentaje de egresos por molinete: \n";
    std::cout << "\t\t\t * Molinete 1: " << molinete1.cantEgresos()/(cantidadTotalIngresos-listaHuespedesAdentro->tamanio()) << "%\n";
    std::cout << "\t\t\t * Molinete 2: " << molinete2.cantEgresos()/(cantidadTotalIngresos-listaHuespedesAdentro->tamanio()) << "%\n";
    std::cout << "\t\t\t * Molinete 3: " << molinete3.cantEgresos()/(cantidadTotalIngresos-listaHuespedesAdentro->tamanio()) << "%\n";
    std::cout << "\t\t\t * Molinete 4: " << molinete4.cantEgresos()/(cantidadTotalIngresos-listaHuespedesAdentro->tamanio()) << "%\n";
    std::cout << "\t\t\t * Molinete 5: " << molinete5.cantEgresos()/(cantidadTotalIngresos-listaHuespedesAdentro->tamanio()) << "%\n";
    std::cout << "\t\t\t * Molinete 6: " << molinete6.cantEgresos()/(cantidadTotalIngresos-listaHuespedesAdentro->tamanio()) << "%\n";
    std::cout << "\t\t\t * Molinete de Repuesto: " << molineteDeRespuesto.cantEgresos()/(cantidadTotalIngresos-listaHuespedesAdentro->tamanio()) << "%\n\n";
    if (hayMolineteRoto)
        std::cout << "\t\t - Actualmente el molinete " << molineteRoto << " se encuentra fuera de servicio por una falla mecánica. El molinete de respuesto se encuentra activo para compensar.\n";
    else
        std::cout << "\t\t - Actualmente todos los molinetes se encuentran en perfecto funcionamiento.\n";
}


void SistemaDeSeguridad::ImprimirEnArchivo(std::string huella, std::string ingresaOSale, bool exitoso){

}

bool SistemaDeSeguridad::PerteneceHuespedALista(Lista<Huesped>* lista, std::string huella){ //posiciona el cursor de la lista en el elemento.

    return true;
}

