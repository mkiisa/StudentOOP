#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;



ostream& operator<< (ostream& os, const Complex& c) {

    os << setprecision(4) << c.real << showpos << c.imag << noshowpos << endl;
    return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex::operator bool() const {
    return (real == 0 || imag == 0);
}

Complex& Complex::operator++() {
    ++real;
    return *this;
}

Complex Complex::operator++(int dummy) {
    Complex temp(real,imag);
    ++real;
    return temp;
}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

Complex& Complex::operator--() {
    --real;
    return *this;
}

Complex Complex::operator--(int dummy) {
    Complex temp(*this);
    --real;
    return temp;
}

Complex Complex::operator*(const int i) {
    Complex temp(real * i,imag * i);
    return temp;
    
}

bool operator== (const Complex& c1, const Complex& c2) {
    return (c1.get_real() == c2.get_real()) && (c2.get_imag() == c1.get_imag());
}

bool operator!= (const Complex& c1, const Complex& c2) {
    return !(c1 == c2);
}
/*
 * `+` adds real to real, and complex to complex.
 * */
Complex operator+(const Complex& c1, const Complex& c2) {
    Complex temp(c1.get_real() + c2.get_real(),c1.get_imag() + c2.get_imag());
    return temp;
}

/*
 * `-` subtracts real from real, and complex from complex.
 * */
Complex operator-(const Complex& c1, const Complex& c2) {
    Complex temp(c1.get_real() - c2.get_real(),c1.get_imag() - c2.get_imag());
    return temp;
}
