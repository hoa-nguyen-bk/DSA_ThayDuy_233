#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Method to get the modulus
    double getModulus() const {
        return std::sqrt(real * real + imag * imag);
    }

    // Overloading the comparison operators
    bool operator>(const Complex& other) const {
        return this->getModulus() > other.getModulus();
    }

    bool operator>=(const Complex& other) const {
        return this->getModulus() >= other.getModulus();
    }

    bool operator<(const Complex& other) const {
        return this->getModulus() < other.getModulus();
    }

    bool operator<=(const Complex& other) const {
        return this->getModulus() <= other.getModulus();
    }

    bool operator==(const Complex& other) const {
        return this->getModulus() == other.getModulus();
    }

    bool operator!=(const Complex& other) const {
        return this->getModulus() != other.getModulus();
    }
};

int main() {
    Complex a(1, 5);
    std::cout << a.getModulus() << std::endl;  // Output should be 5.09902

    Complex b(3, 4);
    std::cout << (a > b) << std::endl;  // Output depends on comparison

    return 0;
}
