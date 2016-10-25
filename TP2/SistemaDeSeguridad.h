#ifndef SISTEMADESEGURIDAD_H_INCLUDED
#define SISTEMADESEGURIDAD_H_INCLUDED

#include <iostream>
#include "Molinete.h"
#include "Lista.h"
#include "Huesped.h"

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

    bool hayMolineteRoto;
    unsigned short molineteRoto;

public:

    SistemaDeSeguridad();
    ~SistemaDeSeguridad();

    void ActivarHuesped(Huesped huesped);
    void DesactivarHuesped(Huesped huesped);

    void ActivarMolineteDeRepuesto(unsigned short num);
    void MolinetesReparados();

    bool IngresaHuesped(Huesped huesped, unsigned short numMolinete);
    bool SaleHuesped(Huesped huesped, unsigned short numMolinete);

    void ImprimirListaHuespedes();
    void ImprimirInformeActividad();

};

#endif // SISTEMADESEGURIDAD_H_INCLUDED
