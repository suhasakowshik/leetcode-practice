#include <iostream>

class Complex {
private:
 double real, imag;
public:
 Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

 Complex operator+(const Complex& other) const {
 return Complex(real + other.real, imag + other.imag);
 }

 Complex operator*(const Complex& other) const {
 return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
 }

 friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
 os << c.real << " + " << c.imag << "i";
 return os;
 }
};

int main() {
 Complex c1(1.0, 2.0);
 Complex c2(2.0, 3.0);
 Complex c3 = c1 * c2 + c1;
 std::cout << c3 << std::endl;
 return 0;
}