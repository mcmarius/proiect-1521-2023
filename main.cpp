#include <iostream>
#include <vector>
#include <cpp-terminal/input.hpp>
#include <cpp-terminal/terminal.hpp>
#include <cpp-terminal/tty.hpp>
#include "Profesor.h"



int main() {
    {
        Term::Terminal term(true, false, false);
        if (!Term::is_stdout_a_tty()) {
            std::cout << "sad\n";
            return 0;
        }
        while (true) {
            Term::Key key{static_cast<Term::Key>(Term::read_key())};
            if (key == Term::Key::q)
                break;
            switch (key) {
                case Term::Key::ARROW_UP:
                    std::cout << "pressed up\n";
                    break;
                case Term::Key::ARROW_DOWN:
                    std::cout << "pressed down\n";
                    break;
                default:
                    std::cout << "other key\n";
                    break;
            }
        }
    }
    std::vector<Facultate> facultati;
    facultati.push_back(Facultate{{}});
    std::cout << "Hello, world!\n";
    int *x = new int[100];
    std::cout << sizeof(x) << "\n";
    std::string nume;
    std::cin >> nume;
    std::cout << "am citit " << nume << "\n";
    return 0;
}
