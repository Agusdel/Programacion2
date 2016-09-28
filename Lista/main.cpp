#include <iostream>
#include "Lista.h"
using namespace std;

int main()
{
    Lista<int>* lista = new Lista<int>;
    lista->agregar(7,1);
    lista->agregar(4);
    lista->agregar(2,1);
    lista->agregar(1);

    for (short i = 1; i <= lista->tamanio();i++){
        int num = lista->operator[](i);
        //int num = lista->obtener(i);
        cout << num << endl;
    }
    cout << endl << endl;

    lista->eliminar(2);
    for (short i = 1; i <= lista->tamanio();i++){
        //int num = lista[i];
        int num = lista->obtener(i);
        cout << num << endl;
    }
    cout << endl << endl;

    lista->asignar(15,2);
    for (short i = 1; i <= lista->tamanio();i++){
        //int num = lista[i];
        int num = lista->obtener(i);
        cout << num << endl;
    }
    cout << endl << endl;


    return 0;
}
