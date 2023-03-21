#include <iostream>
#include <vector>
#include <cpp-terminal/input.hpp>
#include <cpp-terminal/terminal.hpp>
#include <cpp-terminal/tty.hpp>

class Profesor {
    std::string nume;
    int vechime=0;
public:
    Profesor(const std::string &nume, int vechime) : nume(nume), vechime(vechime) {
        this->nume.operator=(nume);
    }
    Profesor(const Profesor& other) : nume(other.nume), vechime(other.vechime) {
        std::cout << "cc prof\n";
    }
    ~Profesor() {
        std::cout << "destr prof\n";
    }
    Profesor& operator=(const Profesor& other) {
        nume = other.nume;
        vechime = other.vechime;
        std::cout << "op= prof\n";
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Profesor &profesor) {
        os << "nume: " << profesor.nume << " vechime: " << profesor.vechime;
        return os;
    }
};

class Facultate {
    std::vector<Profesor> profi;
//    Profesor prof{"a", 1};
public:
    explicit Facultate(const std::vector<Profesor> &profi) : profi(profi) {}

    friend std::ostream &operator<<(std::ostream &os, const Facultate &facultate) {
        os << "profi:\n";
        for(const auto& prof : facultate.profi)
            os << prof;
        return os;
    }
};

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
