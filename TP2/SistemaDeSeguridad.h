#ifndef SISTEMADESEGURIDAD_H_INCLUDED
#define SISTEMADESEGURIDAD_H_INCLUDED

#include <iostream>
#include <fstream>
#include <time.h>
#include "Molinete.h"
#include "Lista.h"
#include "Huesped.h"

static char* archivoActividad = "actividadHuespedes.txt";

class SistemaDeSeguridad{

private:

    Lista<Huesped>* listaDeHuespedes;
    Lista<Huesped>* listaHuespedesAdentro;

    Molinete molinete1;
    Molinete molinete2;
    Molinete molinete3;
    Molinete molinete4;
    Molinete molinete5;
    Molinete molinete6;
    Molinete molineteDeRespuesto;

    unsigned int cantidadTotalIngresos;
    unsigned int cantidadTotalEgresos;

    bool hayMolineteRoto;
    unsigned short molineteRoto;

public:

    SistemaDeSeguridad();
    ~SistemaDeSeguridad();

    void ActivarHuesped(Huesped huesped);
    void DesactivarHuesped(Huesped huesped); ///PRECONDICIÓN: El huesped no se encuentra dentro del predio.

    void ActivarMolineteDeRepuesto(unsigned short num);
    void MolinetesReparados();

    bool IngresaHuesped(std::string huella, unsigned short numMolinete);
    bool SaleHuesped(std::string huella, unsigned short numMolinete);

    void ImprimirListaHuespedes();
    void ImprimirListaHuespedesAdentro();
    void ImprimirInformeActividad();

private:

    void ImprimirEnArchivo(std::string huella, std::string ingresaOSale, bool exitoso);

    bool PerteneceHuespedALista(Lista<Huesped>* lista, std::string huella, int &pos); //posiciona el cursor de la lista en el elemento. YA NO

    void ObtenerHora(std::string &hora);
};

#endif // SISTEMADESEGURIDAD_H_INCLUDED
