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

/*void MostrarMaletines(DealOrNoDeal deal);
bool HayMaletinesDisponibles(DealOrNoDeal deal);
int PosicionUltimoMaletin(DealOrNoDeal deal);
void SacarEspacios(string &name);
bool ConvertirANumero(string numString, int& numero);*/

bool ConvertirANumero(string numString, int& numero){
    bool esNumero = true;
    if (numString.length() > 0){
        for (short i = 0; i < numString.length(); i++){
            if (numString[i] < '0' || numString[i] > '9')
                esNumero = false;
        }
    }else{
        esNumero = false;
    }
    if (esNumero)
        numero = atoi(numString.c_str());
    return esNumero;
}

void SacarEspacios(string &name){
    while (name.find(' ') != -1){
        int pos = name.find(' ');
        name = name.erase(pos,1);
    }
}

void ToUpper(string &ingreso){
    for (short i=0; i<ingreso.length(); ++i){
        if (ingreso[i] >= 'a' && ingreso[i] <= 'z'){
            ingreso[i] = (char)(ingreso[i] - 32);
        }
    }
}

void MensajeInicial(string mejorJugador, int mejorPuntaje){ //Mostrar nombre del jugador con mejor puntaje.
    cout << "\n\n\n\n\tBienvenido al Deal or no Deal.\n" << endl;
    cout << "\n\tJugador que más dinero ganó:  " << mejorJugador << "    Monto:  " << mejorPuntaje << "\n\n\n\n\n\n\t";

    system("pause");
    system("cls");
}

void SolicitarNombre(DealOrNoDeal &deal){
    string name;
    cout << "\n\n\tIngrese su nombre: ";
    getline(cin,name);
    SacarEspacios(name);
    deal.nombre = name;
    system("cls");
}


void GuardarDatos(DealOrNoDeal deal, const char* archivoJugadores){

    ofstream archivo (archivoJugadores, ios::app);

    archivo << endl << deal.nombre << " "  << deal.premio;

    archivo.close();
}

void CargarMejorPuntaje(const char* archivoJugadores, string &mejorJugador, int &mejorPuntaje){
        ifstream archivo(archivoJugadores);

        if (archivo.is_open()){
            //LEO LA PRIMERA LINEA PARA TOMAR EL PRIMER PRUNTAJE COMO MAXIMO, Y DE AHÍ EN ADELANTE BUSCO EL MAXIMO.
            if (!archivo.eof()){
                archivo >> mejorJugador;
                archivo >> mejorPuntaje;
            }
            while (!archivo.eof())
            {
                string jugador;
                int puntaje;
                archivo >> jugador;
                archivo >> puntaje;
                if (puntaje > mejorPuntaje){
                    mejorPuntaje = puntaje;
                    mejorJugador = jugador;
                }
            }
            archivo.close();
        }
        //else cout << "\t ERROR AL CARGAR DATOS HISTORICOS.";
}

void CargarMaletines(DealOrNoDeal &deal, const char* archivoMaletines){

   ifstream archivo(archivoMaletines);

   if (archivo.is_open()){
        while (!archivo.eof())
        {
            string numeroMaletinStr;
            int valor;
            archivo >> numeroMaletinStr;
            int numeroMaletin = atoi(numeroMaletinStr.substr(0,numeroMaletinStr.length()-1).c_str()) - 1; //Saco la coma, y convierto a int. Resto 1 al final para que sean las posiciones del arreglo.
            archivo >> valor;
            deal.maletines[numeroMaletin] = valor;
        }
        archivo.close();
    }
        else cout << "\t ERROR AL CARGAR LOS MALETINES.";
}

bool FueraDeRango(int num){
    bool invalido = true;
    if (num >= 1 && num <= CANTIDAD_MALETINES)
        invalido = false;
    if (invalido)
        cout << "Número inválido." << endl;
    return invalido;
}

bool NumeroDisponible(int num, DealOrNoDeal deal){
    bool numDisponible = true;
    if (deal.mascara[num-1] == 1 || deal.mascara[num-1] == 2)
        numDisponible = false;
    if (!numDisponible)
        cout << "Ya has elegido ese maletín." << endl;
    return numDisponible;
}

void MostrarMaletines(DealOrNoDeal deal){
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
    char yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
    cout << "\n\n\t\t " << yellow << "DEAL OR NO DEAL";

    cout << "\n\t\t";
    for (short i=0; i < CANTIDAD_MALETINES; i++){
        if ((i)%3 == 0)
            cout << "\n\n\t\t";
        if (deal.mascara[i] == 0){
            cout << green;
        }else if (deal.mascara[i] == 1){
            cout << red;
        } else
            cout << yellow;
        cout << i+1 << "\t";
    }
    cout << "\n\n\n\t ";
    for (short i=0; i < CANTIDAD_MALETINES; i++){

        if (deal.mascara[deal.posicionesOrdenado[i]] == 1){
            cout << red;
        } else
            cout << green;
        cout << "$" << setw(6) << deal.maletinesOrdenados[i] << "    ";
        if ((i+1)%3 == 0)
            cout << "\n\n\t ";
    }

    cout << normal << "\n\n";
}

int ElegirMaletin(DealOrNoDeal &deal, int cantRestantes){
    system("cls");
    int num;
    string numStr;
    if (deal.esPrimeraVez)
        cout << "\n\nSelecciona un maletín para tí. Ten en cuenta que no podrás cambiarlo hasta el final.\n";
    else
        cout << "\n\nSelecciona un maletín para mostrar. " << cantRestantes << " restantes.\n";
    MostrarMaletines(deal);
    bool numeroOK;
    do{
        numeroOK = false;
        cout << "Ingrese el número del maletín deseado:  ";
        cin >> numStr;
        if (ConvertirANumero(numStr,num)){
            if (!FueraDeRango(num) && NumeroDisponible(num, deal)){
                numeroOK = true;
            }
        }else{
            cout << "Valor inválido.\n";
        }
    } while(!numeroOK);
    if (deal.esPrimeraVez)
        deal.mascara[num-1] = 2; //marca que ese maletin es el principal.
    else
        deal.mascara[num-1] = 1; //marca que ese maletín ya salió.

    return num-1;
}

void Reiniciar(bool &reiniciar){
    string ingreso;
    do{
    cout << "\n\n\tDesea volver a jugar? (Si/No)\n\n\t";
    cin >> ingreso;
    ToUpper(ingreso);

    } while (!(ingreso == "SI" || ingreso == "NO"));

    if (ingreso == "NO"){
        reiniciar = false;
    }
}

int CantMaletinesDisponibles(DealOrNoDeal deal){
    int cantMaletinesDisponibles = 0;
    for (short i = 0; i < CANTIDAD_MALETINES; i++){
        cantMaletinesDisponibles += 1 - deal.mascara[i]; //Suma la cantidad de maletines disponibles. Si hay un 1 (maletin no disponible), suma 0. Si hay un 0 (maletin disponible), suma 1. Si hay 2, resta uno en vez de sumar 0. Como siempre hay un unico 2, al final sumo dos para compensar.
    }
    cantMaletinesDisponibles++; //por comentario anterior, acá sumo 1 para compensar el -1 que generó el 2 del la mascara.
    return cantMaletinesDisponibles;
}

int Oferta(DealOrNoDeal deal){ /// Promedia los valores disponibles (incluyendo el maletin elegido) y multiplica por constante<1 para reducirlo.
    int sumaPremiosDisponibles = 0;
    int cantMaletinesDisponibles = 0;
    for (short i = 0; i < CANTIDAD_MALETINES; i++){
        if (deal.mascara[i] == 0 || deal.mascara[i] == 2){
            sumaPremiosDisponibles += deal.maletines[i];
            cantMaletinesDisponibles++;
        }
    }
    int oferta = sumaPremiosDisponibles/cantMaletinesDisponibles;
    oferta = oferta*(8-cantMaletinesDisponibles)/(9-cantMaletinesDisponibles); // Cuantos menos maletines quedan, es más alta la proporción del promedio que se ofrece.
    return oferta;
}

int PosicionUltimoMaletin(DealOrNoDeal deal){
    int posicion = 0;
    bool listo = false;
    while (!listo && posicion < CANTIDAD_MALETINES){
        if (deal.mascara[posicion] == 0)
            listo = true;
        else
            posicion++;
    }
    return posicion;
}

bool HacerOferta(DealOrNoDeal &deal){ ///OFERTA: Promedia los valores disponibles (incluyendo el maletin elegido) y multiplica por alguna constante en base a la cantidad de maletines restantes para reducirlo.
    bool aceptoOferta = false;
    if (deal.maletinesDisponibles >= 2){
        string respuestaStr;
        int respuesta;
        system("cls");
        cout << "\n\n\n";
        MostrarMaletines(deal);
        int numeroOK;
        do{
            numeroOK = false;
            cout << "\tOferta de la banca: $" << Oferta(deal) << ".\n\n\n\tDesea aceptar la oferta o continuar jugando?\n\n\t\t1) Aceptar oferta.\n\n\t\t2) Seguir jugando.\n\n\t";
            cin >> respuestaStr;
            if (ConvertirANumero(respuestaStr,respuesta)){
                if (respuesta == 1 || respuesta == 2){
                    numeroOK = true;
                }
            }else{
                cout << "Valor inválido.\n";
            }
        } while(!numeroOK);

        if (respuesta == 1){
            aceptoOferta = true;
            deal.premio = Oferta(deal);
        }
    }else{
        deal.premio = deal.maletines[deal.maletinPrincipal];
        string respuesta;
        system("cls");
        cout << "\n\n\n";
        MostrarMaletines(deal);
        do{
            cout << "\n\n\tHmm... No has aceptado ninguna de mis ofertas anteriores y ahora queda tan solo un maletín restante.\n\n\t¿Deseas cambiar tu maletín por éste?  (Si/No)\n\n\t";
            cin >> respuesta;
            ToUpper(respuesta);
        } while (respuesta != "SI" && respuesta != "NO");
        if (respuesta == "SI"){
            deal.premio = deal.maletines[PosicionUltimoMaletin(deal)];
            aceptoOferta = true;
        }else{
            deal.mascara[PosicionUltimoMaletin(deal)] = 1;
        }
    }
    return aceptoOferta;
}

void Juego(DealOrNoDeal &deal, bool& aceptoOferta){
    int cantidadAElegir = 3; // comienza en 3, después baja a dos, y para las proximas iteraciones queda siempre en 1.
    while(!aceptoOferta && CantMaletinesDisponibles(deal) > 0){ //HayMaletinesDisponibles devuelve true si hay al menos 2 maletines libres. (si hay solo 1, pasa a la oferta final)
        for (short i = 0; i < cantidadAElegir; i++){
            ElegirMaletin(deal, cantidadAElegir - i);
        }
        deal.maletinesDisponibles = CantMaletinesDisponibles(deal);
        aceptoOferta = HacerOferta(deal);
        if (cantidadAElegir > 1)
            cantidadAElegir--;
    }
}

void OrdenarMaletines(DealOrNoDeal &deal){
    int minimo;
    short posicion;
    int mascaraYaSalio[CANTIDAD_MALETINES] = {0,0,0,0,0,0,0,0};
    for (short i = 0; i < CANTIDAD_MALETINES; i++){
        minimo = -1;
        short j = 0;
        while (minimo == -1) { ///Pone como minimo el primer elemento que no agarré todavía, para compararlos después con los demás que no salieron.
            if (mascaraYaSalio[j] == 0){
                minimo = deal.maletines[j];
                posicion = j;
            }
            else
                j++;
        }
        if (i != CANTIDAD_MALETINES - 1){ ///En el caso CANT_MALETINES -1, no hay nada que hacer, ese es el único valor que falta salir.
            for (short k = j+1; k < CANTIDAD_MALETINES; k++){ ///Arrancando a la derecha del elemento que tomé inicialmente como mínimo, los comparo con éste, y si alguno es menor, lo tomo como nuevo mínimo.
                if (mascaraYaSalio[k] == 0){
                    if (deal.maletines[k] < minimo){
                        minimo = deal.maletines[k];
                        posicion = k;
                    }
                }
            }
        }
        mascaraYaSalio[posicion] = 1;
        deal.maletinesOrdenados[i] = minimo;
        deal.posicionesOrdenado[i] = posicion; /// ASÍ ARMO POSICIONES DE FORMA TAL QUE MALETINESORDENADOS[i] == MALETINES[POSICIONES[I]]
    }
}

void ImprimirDeal(DealOrNoDeal deal){

    cout << "\n\n\tMaletines:       ";
    for (short i = 0; i < CANTIDAD_MALETINES; i++){
        cout << setw(6) << deal.maletines[i] << "  ";
    }
    cout << "\n\n\tPosiciones:      ";
    for (short i = 0; i < CANTIDAD_MALETINES; i++){
        cout << setw(6) << deal.posicionesOrdenado[i] << "  ";
    }
    cout << "\n\n\tMalet ordenad:   ";
    for (short i = 0; i < CANTIDAD_MALETINES; i++){
        cout << setw(6) << deal.maletinesOrdenados[i] << "  ";
    }
    cout << "\n\n\tMascara:         ";
    for (short i = 0; i < CANTIDAD_MALETINES; i++){
        cout << setw(6) << deal.mascara[i] << "  ";
    }
    cout << "\n\n\n";
}

int main(){
    bool reiniciar;
    do{
        system("cls");
        reiniciar = true;

        string mejorJugador = "";
        int mejorPuntaje = 0;
        CargarMejorPuntaje(ARCHIVO_JUGADORES, mejorJugador, mejorPuntaje);

        MensajeInicial(mejorJugador, mejorPuntaje); //Mostrar nombre del jugador con mejor puntaje.

        DealOrNoDeal deal;

        SolicitarNombre(deal);

        CargarMaletines(deal, ARCHIVO_MALETINES);

        OrdenarMaletines(deal);
        ///***************** PEDAZO DE CODIGO PARA COMPRENDER EL STRUCT Y PARA SABER EL ESTADO DE TODOS LOS ARREGLOS EN ALGÚN MOMETO. SOLO PARA USO INTERNO.
        /*ImprimirDeal(deal);
        system("pause");*/
        ///**********************

        deal.maletinPrincipal = ElegirMaletin(deal, 1);

        deal.esPrimeraVez = false;
        bool aceptoOferta = false;

        Juego(deal, aceptoOferta);

        system("cls");
        if (aceptoOferta){
            cout << "\n\n\tHas aceptado la oferta." << endl;
        }
        cout << "\n\n\tFELICITACIONES " << deal.nombre << ": Te llevas $" << deal.premio << " a casa!" << endl;
        if (aceptoOferta){
            cout << "\n\n\tEl monto del maletín que habías elegido originalmente es $" << deal.maletines[deal.maletinPrincipal] << "!!" << endl;
            if (deal.maletines[deal.maletinPrincipal] > deal.premio)
                cout << "\n\tNo debiste haber aceptado mi oferta! JAJAJA!!" << endl;
            else
                cout << "\n\tHas tenido suerte chico!!" << endl;
        }

        GuardarDatos(deal, ARCHIVO_JUGADORES);

        Reiniciar(reiniciar); //pregunta si se desea reiniciar.
    } while(reiniciar);
    system("cls");
    cout << "\n\n\t¡Gracias por jugar al Deal or No Deal!\n\n\n\n\n";
}
