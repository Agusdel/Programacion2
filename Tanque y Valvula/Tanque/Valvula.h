#ifndef VALVULA_H_INCLUDED
#define VALVULA_H_INCLUDED

#include <string>

class Valvula {

private:
    std::string password;

public:

    Valvula(std::string password = "123");
    bool AbrirValvula(std::string password);
};

#endif // VALVULA_H_INCLUDED
