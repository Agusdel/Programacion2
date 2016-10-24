#ifndef HUESPED_H_INCLUDED
#define HUESPED_H_INCLUDED

#include<string>

class Huesped {

private:
    std::string nombre;
    std::string apellido;
    unsigned int dni;
    std::string huellaDactilar;

public:
    Huesped(const Huesped& otro) :
        nombre(otro.nombre), apellido(otro.apellido), dni(otro.dni), huellaDactilar(otro.huellaDactilar){};

    Huesped(std::string nombre, std::string apellido, unsigned int dni, std::string huella) :
        nombre(nombre), apellido(apellido), dni(dni), huellaDactilar(huella){};

    bool operator== (Huesped otro){return nombre == otro.nombre && apellido == otro.apellido && dni == otro.dni && huellaDactilar == otro.huellaDactilar;}

    friend std::ostream& operator<< (std::ostream &os, const Huesped &huesped);
};

    std::ostream& operator<< (std::ostream &os, const Huesped &huesped){
        os << "< Huesped: " << huesped.apellido << ", " << huesped.nombre << ", DNI: " << huesped.dni << " >";
        return os;
    }
#endif // HUESPED_H_INCLUDED
