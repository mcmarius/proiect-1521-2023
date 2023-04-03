//
// Created by marius on 03.04.2023.
//

#include "Profesor.h"

Profesor::Profesor(const std::string &nume, int vechime) : nume(nume), vechime(vechime) {
    this->nume.operator=(nume);
}

Profesor::Profesor(const Profesor &other) : nume(other.nume), vechime(other.vechime) {
    std::cout << "cc prof\n";
}

Profesor::~Profesor() {
    std::cout << "destr prof\n";
}

Profesor &Profesor::operator=(const Profesor &other) {
    nume = other.nume;
    vechime = other.vechime;
    std::cout << "op= prof\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Profesor &profesor) {
    os << "nume: " << profesor.nume << " vechime: " << profesor.vechime;
    return os;
}
