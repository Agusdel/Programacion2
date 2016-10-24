#include <string>
#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "Molinete.h"
#include "Huesped.h"

#define UP 72
#define LEFT 75
#define RIGHT 77
#define ENTER '\r'

using namespace std;

int main()
{
    /*Molinete unMolinete;
    bool continuar = true;
    cout << "Bienvenido, soy un molinete." << endl << endl;
    cout << "Dejar pasar ->, Dejar salir <-, Conocer cantidad ^, Salir ENTER" << endl << endl;
    do
    {
        switch(getch())
        {
            case UP:
                cout << "Cantidad de personas adentro: " << unMolinete.contarPersonas() << endl;
                break;

            case LEFT:
                if(unMolinete.contarPersonas()>=1){
                    cout << "Sale persona" << endl;
                }
                unMolinete.dejarSalir();
                break;

            case RIGHT:
                unMolinete.dejarEntrar();
                cout << "Entra persona" << endl;
                break;

            case ENTER:
                cout << endl << "Fin de mi trabajo. \n\nAtte.- Molinete" << endl;
                continuar = false;
                break;
        }

    }while(continuar);*/

    return 0;

}
