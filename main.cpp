#include <iostream>
#include <vector>

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
    std::vector<Facultate> facultati;
    facultati.push_back(Facultate{{}});
    std::cout << "Hello, world!\n";
    std::string nume;
    std::cin >> nume;
    std::cout << "am citit " << nume << "\n";
    return 0;
}
