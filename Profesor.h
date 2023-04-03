//
// Created by marius on 03.04.2023.
//

#ifndef OOP_PROFESOR_H
#define OOP_PROFESOR_H


#include <string>
#include <iostream>

class Profesor {
    std::string nume;
    int vechime = 0;
public:
    Profesor(const std::string &nume, int vechime);

    Profesor(const Profesor &other);

    ~Profesor();

    Profesor &operator=(const Profesor &other);

    friend std::ostream &operator<<(std::ostream &os, const Profesor &profesor);
};


#endif //OOP_PROFESOR_H
