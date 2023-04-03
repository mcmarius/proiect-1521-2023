//
// Created by marius on 03.04.2023.
//

#include "Facultate.h"

Facultate::Facultate(const std::vector<Profesor> &profi) : profi(profi) {}

std::ostream &operator<<(std::ostream &os, const Facultate &facultate) {
    os << "profi:\n";
    for (const auto &prof: facultate.profi)
        os << prof;
    return os;
}
