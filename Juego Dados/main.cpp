#include <iostream>

#include "Jugador.h"
#include "Moneda.h"

using namespace std;

void pedirValores(TablaDeResultados &tabla, int num){
    int mascara[] = {0,0,0};
    bool repetir;
    for (short i = 0; i < 3; i++){
        do{
            repetir = false;
            cout << "Jugador " << num << ": Ingrese la cantidad de caras para el dado ";
            switch (i){
                case 0:
                    cout << "azul." << endl;
                    break;
                case 1:
                    cout << "verde." << endl;
                    break;
                case 2:
                    cout << "rojo." << endl;
                    break;
            }
            int num;
            cin >> num;
            int pos;
            switch (num){
                case 6:
                    pos = 0;
                    break;
                case 8:
                    pos = 1;
                    break;
                case 12:
                    pos = 2;
                    break;
                default:
                    repetir = true;
                    cout << "   Valor invalido." << endl;
            }
            if (!repetir){
                if (mascara[pos] == 0){
                    mascara[pos] = 1;
                    if (i == 0)
                        tabla.setAzul(num);
                    else if (i == 1)
                        tabla.setVerde(num);
                    else if (i == 2)
                        tabla.setRojo(num);
                } else {
                    repetir = true;
                    cout << "   Ya has elegido ese valor." << endl;
                }
            }
        } while (repetir);
    }
}

void lanzarDados(Jugador jug1, Jugador jug2, bool &ganoElUno, bool &empate){
    cout << endl << "El jugador 1 se prepara para lanzar..." << endl << endl;
    TablaDeResultados tabla1 = jug1.LanzarDados();
    cout << endl << "El jugador 2 se prepara para lanzar..." << endl << endl;
    TablaDeResultados tabla2 = jug2.LanzarDados();
    int difPuntos = 0; // puntos jugador 1 - puntos jugador 2;
    // azul
    if (tabla1.Azul() > tabla2.Azul())
        difPuntos++;
    else if (tabla1.Azul() < tabla2.Azul())
        difPuntos--;
    // verde
    if (tabla1.Verde() > tabla2.Verde())
        difPuntos++;
    else if (tabla1.Verde() < tabla2.Verde())
        difPuntos--;
    // rojo
    if (tabla1.Rojo() > tabla2.Rojo())
        difPuntos++;
    else if (tabla1.Rojo() < tabla2.Rojo())
        difPuntos--;

    if (difPuntos < 0)
        ganoElUno = false;
    else if (difPuntos == 0){
        empate = true;
        cout << "Han empatado!! Para decidir quién gana, se lanzará una moneda!" << endl;
    }
}

void lanzarMoneda(Jugador jug1, Jugador jug2, bool ganoElUno){
    Moneda coin;
    Lado lado = coin.lanzar();
    cout << "Se lanza la moneda y sale..." << endl;
    Sleep(1000);
    if (lado == Cara)
        cout << "CARA!!" << endl;
    else if (lado == Ceca){
        cout << "CECA!!" << endl;
        ganoElUno = false;
    }
}

void mensajeGanador(bool ganoElUno){
    if (ganoElUno)
        cout << endl << "GANADOR EL JUGADOR 1! FELICITACIONES! " << endl;
    else
        cout << endl << "GANADOR EL JUGADOR 2! FELICITACIONES! " << endl;
}

int main()
{
    TablaDeResultados tabla;
    pedirValores(tabla,1);
    system("cls");

    Jugador jugador1(tabla.Azul(),tabla.Verde(),tabla.Rojo());
    pedirValores(tabla,2);
    system("cls");
    Jugador jugador2(tabla.Azul(),tabla.Verde(),tabla.Rojo());

    bool empate = false;
    bool ganoElUno = true;

    lanzarDados(jugador1, jugador2, ganoElUno, empate);
    if (empate)
        lanzarMoneda(jugador1, jugador2, ganoElUno);

    mensajeGanador(ganoElUno);
    return 0;
}
