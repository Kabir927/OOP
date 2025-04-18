
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imag * other.imag,
                      real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                      (imag * other.real - real * other.imag) / denominator);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) os << " + ";
        os << c.imag << "i";
        return os;
    }

    friend double magnitude(const Complex& c) {
        return sqrt(c.real * c.real + c.imag * c.imag);
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    cout << "c1 * c2 = " << c1 * c2 << endl;
    cout << "c1 / c2 = " << c1 / c2 << endl;
    cout << "Magnitude of c1 = " << magnitude(c1) << endl;

    return 0;
}
