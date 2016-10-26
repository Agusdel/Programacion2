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
    this->cantidadTotalEgresos = 0;

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
            std::cout << "Este molinete se encuentra desactivado actualmente. Sera activado en caso de mal funcionamiento por parte de otro molinete. \n";
        }
        else { ///CASO DE MOLINETE VALIDO Y EN FUNCIONAMIENTO.
            int pos = 0;
            int pos2 = 0;
            if (PerteneceHuespedALista(listaDeHuespedes, huella, pos) && !PerteneceHuespedALista(listaHuespedesAdentro, huella, pos2)){  // CASO EL HUESPED PERTENECE A LA LISTA
                listaHuespedesAdentro->agregar(listaDeHuespedes->obtener(pos));
                cantidadTotalIngresos++;
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
                std::cout << "Acceso denegado.\n";
            }
            ImprimirEnArchivo(huella,"ingreso",ingresoExitoso);
        }
    }
    else{
        std::cout << "Numero de molinete invalido. 1-6 para molinetes regulares. 7 para molinete de respuesto. \n";
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
            std::cout << "Este molinete se encuentra desactivado actualmente. Sera activado en caso de mal funcionamiento por parte de otro molinete. \n";
        }
        else { ///CASO DE MOLINETE VALIDO Y EN FUNCIONAMIENTO.
            int pos = 0;
            if (PerteneceHuespedALista(listaHuespedesAdentro, huella, pos)){  // CASO EL HUESPED PERTENECE A LA LISTA
                // tiene que estar en la lista de huespedes o la de huespedes adentro????? huespedes adentro
                listaHuespedesAdentro->eliminar(pos);
                cantidadTotalEgresos++;
                switch (numMolinete){
                    case 1:
                        molinete1.dejarSalir();
                        break;
                    case 2:
                        molinete2.dejarSalir();
                        break;
                    case 3:
                        molinete3.dejarSalir();
                        break;
                    case 4:
                        molinete4.dejarSalir();
                        break;
                    case 5:
                        molinete5.dejarSalir();
                        break;
                    case 6:
                        molinete6.dejarSalir();
                        break;
                    case 7:
                        molineteDeRespuesto.dejarSalir();
                        break;
                }
                egresoExitoso = true;
            }
            else {                                      // CASO NO PERTENECE
                std::cout << "Salida denegada.\n";
            }
            ImprimirEnArchivo(huella,"egreso",egresoExitoso);
        }
    }
    else{
        std::cout << "Numero de molinete invalido. 1-6 para molinetes regulares. 7 para molinete de respuesto. \n";
        //En un código más en serio, acá tiro excepción.
    }
    return egresoExitoso;
}

void SistemaDeSeguridad::ImprimirListaHuespedes(){
    std::cout << "\tCantidad de huespedes registrados en el hotel: " << listaDeHuespedes->tamanio() << "\n\n";
    std::cout << "\tListado de huespedes registrados en el hotel: \n\n";
    listaDeHuespedes->iniciarCursor();
    while(listaDeHuespedes->avanzarCursor()){
        std::cout << "\t\t - " << listaDeHuespedes->obtenerCursor() << std::endl;
    }
}

void SistemaDeSeguridad::ImprimirListaHuespedesAdentro(){
    std::cout << "\tCantidad de huespedes dentro del hotel: " << listaHuespedesAdentro->tamanio() << "\n\n";
    std::cout << "\tListado de huespedes dentro del hotel: \n\n";
    listaHuespedesAdentro->iniciarCursor();
    while(listaHuespedesAdentro->avanzarCursor()){
        std::cout << "\t\t - " << listaHuespedesAdentro->obtenerCursor() << std::endl;
    }
}

void SistemaDeSeguridad::ImprimirInformeActividad(){
    std::cout << "\t***********************************************************************************************\n\n";
    std::cout << "\tInforme de actividad: \n\n";
    std::cout << "\t\t - Cantidad de huespedes que ingresaron hasta la fecha: " << cantidadTotalIngresos << ".\n";
    std::cout << "\t\t - Cantidad de huespedes dentro del predio actualmente: " << listaHuespedesAdentro->tamanio() << ".\n\n";
    if (cantidadTotalIngresos != 0){
        std::cout << "\t\t - Porcentaje de ingresos por molinete: \n";
        std::cout << "\t\t\t * Molinete 1: " << 100*molinete1.cantIngresos()/cantidadTotalIngresos << "%\n";
        std::cout << "\t\t\t * Molinete 2: " << 100*molinete2.cantIngresos()/cantidadTotalIngresos << "%\n";
        std::cout << "\t\t\t * Molinete 3: " << 100*molinete3.cantIngresos()/cantidadTotalIngresos << "%\n";
        std::cout << "\t\t\t * Molinete 4: " << 100*molinete4.cantIngresos()/cantidadTotalIngresos << "%\n";
        std::cout << "\t\t\t * Molinete 5: " << 100*molinete5.cantIngresos()/cantidadTotalIngresos << "%\n";
        std::cout << "\t\t\t * Molinete 6: " << 100*molinete6.cantIngresos()/cantidadTotalIngresos << "%\n";
        std::cout << "\t\t\t * Molinete de Repuesto: " << 100*molineteDeRespuesto.cantIngresos()/cantidadTotalIngresos << "%\n\n";
    }
    if (cantidadTotalEgresos != 0){
        std::cout << "\t\t - Porcentaje de egresos por molinete: \n";
        std::cout << "\t\t\t * Molinete 1: " << 100*molinete1.cantEgresos()/cantidadTotalEgresos << "%\n";
        std::cout << "\t\t\t * Molinete 2: " << 100*molinete2.cantEgresos()/cantidadTotalEgresos << "%\n";
        std::cout << "\t\t\t * Molinete 3: " << 100*molinete3.cantEgresos()/cantidadTotalEgresos << "%\n";
        std::cout << "\t\t\t * Molinete 4: " << 100*molinete4.cantEgresos()/cantidadTotalEgresos << "%\n";
        std::cout << "\t\t\t * Molinete 5: " << 100*molinete5.cantEgresos()/cantidadTotalEgresos << "%\n";
        std::cout << "\t\t\t * Molinete 6: " << 100*molinete6.cantEgresos()/cantidadTotalEgresos << "%\n";
        std::cout << "\t\t\t * Molinete de Repuesto: " << 100*molineteDeRespuesto.cantEgresos()/cantidadTotalEgresos << "%\n\n";
    }
    if (hayMolineteRoto)
        std::cout << "\t\t - Actualmente el molinete " << molineteRoto << " se encuentra fuera de servicio por una falla mecánica. El molinete de respuesto se encuentra activo para compensar.\n";
    else
        std::cout << "\t\t - Actualmente todos los molinetes se encuentran en perfecto funcionamiento.\n";
    std::cout << "\n\n\t***********************************************************************************************\n\n";
}


void SistemaDeSeguridad::ImprimirEnArchivo(std::string huella, std::string ingresaOSale, bool exitoso){
    std::ofstream archivo(archivoActividad, std::ios::app);
    if (ingresaOSale == "ingreso")
        archivo << "Ingreso";
    else
        archivo << "Egreso";

    std::string hora;
    ObtenerHora(hora);

    if (exitoso){
        Huesped huesped;
        if (ingresaOSale == "ingreso")
            huesped = listaDeHuespedes->obtenerCursor();
        else
            huesped = listaHuespedesAdentro->obtenerCursor();
        archivo << " - Huesped: " << huesped.Apellido() << ", " << huesped.Nombre() << ", " << huesped.Dni() << ". Fecha y hora: " << hora << ".\n";
    }
    else{
        archivo << " denegado - Huella: " << huella<< ". Fecha y hora: " << hora << ".\n";
    }
    archivo.close();
}

bool SistemaDeSeguridad::PerteneceHuespedALista(Lista<Huesped>* lista, std::string huella, int &posicion){ //posiciona el cursor de la lista en el elemento.
    lista->iniciarCursor();
    posicion = -1;
    bool pertenece = false;;
    int pos = 0;
    while (lista->avanzarCursor() && !pertenece){
        pos++;
        Huesped huesped = lista->obtenerCursor();
        if (huesped.Huella() == huella){
            pertenece = true;
        }
    }
    if (pertenece)
        posicion = pos;
    return pertenece;
}

void SistemaDeSeguridad::ObtenerHora(std::string &hora){

  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
  hora = buffer;
}

