#ifndef LUZ_H_INCLUDED
#define LUZ_H_INCLUDED

using namespace std;

enum Color { Rojo, Amarillo, Verde, Azul , Naranja, Violeta};

class Luz{

private:

    Color color;
    bool encendida;

public:

    Luz(Color color = Rojo, bool encendida = false);
    Color getColor();
    void Encender();
    void Apagar();

    Luz operator=(Luz otraLuz);
} ;

#endif // LUZ_H_INCLUDED
