//
// Created by marius on 03.04.2023.
//

#ifndef OOP_FACULTATE_H
#define OOP_FACULTATE_H


#include "Profesor.h"
#include <vector>

class Facultate {
    std::vector<Profesor> profi;
//    Profesor prof{"a", 1};
public:
    explicit Facultate(const std::vector<Profesor> &profi);

    friend std::ostream &operator<<(std::ostream &os, const Facultate &facultate);
};


#endif //OOP_FACULTATE_H
