#include "Valvula.h"

Valvula::Valvula(std::string password) {
    this->password = password;
}

bool Valvula::AbrirValvula(std::string password) {
    return this->password == password;
}
