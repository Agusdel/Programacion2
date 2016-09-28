#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <locale>
#include <windows.h>
#include <iomanip>

using namespace std;

const int CANTIDAD_MALETINES = 9;
const char* ARCHIVO_MALETINES = "maletines_oficiales.txt";
const char* ARCHIVO_JUGADORES = "jugadores.txt";


struct DealOrNoDeal {
    string nombre;
    int maletines[CANTIDAD_MALETINES];
    int maletinesOrdenados[CANTIDAD_MALETINES];
    int posicionesOrdenado[CANTIDAD_MALETINES]; ///En la posición i posicionesOrdenado, nos dice en qué posición de maletines está maletinesOrdenados[i]; DE FORMA TAL QUE MALETINESORDENADOS[I] == MALETINES[POSICIONES[I]]
    int mascara[CANTIDAD_MALETINES] = {0,0,0,0,0,0,0,0};
    int maletinPrincipal;
    bool esPrimeraVez = true; ///Primera vez que se elige un maletin.
    int maletinesDisponibles; //cantidad de maletines restantes.
    int premio;
    /// PARA COMPRENDER MEJOR ESTA ESTRUCTURA, DESCOMENTAR PEDAZO DE CÓDIGO EN EL MAIN Y EJECUTAR.
} ;

bool ConvertirANumero(string numString, int& numero);
void SacarEspacios(string &name);
void ToUpper(string &ingreso);
void MensajeInicial(string mejorJugador, int mejorPuntaje);
void SolicitarNombre(DealOrNoDeal &deal);
void GuardarDatos(DealOrNoDeal deal, const char* archivoJugadores);
void CargarMejorPuntaje(const char* archivoJugadores, string &mejorJugador, int &mejorPuntaje);
void CargarMaletines(DealOrNoDeal &deal, const char* archivoMaletines);
bool FueraDeRango(int num);
bool NumeroDisponible(int num, DealOrNoDeal deal);
void MostrarMaletines(DealOrNoDeal deal);
int ElegirMaletin(DealOrNoDeal &deal, int cantRestantes);
void Reiniciar(bool &reiniciar);
int CantMaletinesDisponibles(DealOrNoDeal deal);
int Oferta(DealOrNoDeal deal);
bool HacerOferta(DealOrNoDeal &deal);
int PosicionUltimoMaletin(DealOrNoDeal deal);
void Juego(DealOrNoDeal &deal, bool& aceptoOferta);
void OrdenarMaletines(DealOrNoDeal &deal);
void ImprimirDeal(DealOrNoDeal deal);

#endif // FUNCIONES_H_INCLUDED
