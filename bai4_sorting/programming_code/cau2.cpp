#include <iostream>
#include <cmath>

// Giả sử lớp Complex đã được định nghĩa như sau:
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

    // Print function for debugging
    void print() const {
        std::cout << real << (imag >= 0 ? " + " : " - ") << std::abs(imag) << " * i: " << getModulus() << std::endl;
    }
};

class StraightSelectionSort {
public:
    static void sort(Complex *list, int length) {
        sort(list, length, 0, length - 1);
    }

    static void sort(Complex *list, int length, int left, int right) {
        for (int i = left; i <= right - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j <= right; ++j) {
                if (list[j] < list[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                std::swap(list[i], list[minIndex]);
            }
        }
    }
};

// Main function for testing
int main() {
    int length = 5;
    Complex *list = new Complex[length];
    list[0] = Complex(3, -1);
    list[1] = Complex(5, 2);
    list[2] = Complex(1, -7);
    list[3] = Complex(6, 8);
    list[4] = Complex(-2, 4);

    StraightSelectionSort::sort(list, length);

    for (int i = 0; i < length; ++i) {
        list[i].print();
    }

    delete[] list;

    return 0;
}
