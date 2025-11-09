#include "Complex2D.h"
#include <iostream>
#include <cmath>
using namespace std;

Complex2D::Complex2D() {
    real = 0;
    imag = 0;
}

Complex2D::Complex2D(double r, double i) {
    real = r;
    imag = i;
}

Complex2D::Complex2D(const Complex2D& other) {
    real = other.real;
    imag = other.imag;
}

Complex2D Complex2D::operator+(const Complex2D& other) const {
    return Complex2D(real + other.real, imag + other.imag);
}

Complex2D Complex2D::operator-(const Complex2D& other) const {
    return Complex2D(real - other.real, imag - other.imag);
}

Complex2D Complex2D::operator*(const Complex2D& other) const {
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    return Complex2D(r, i);
}

Complex2D Complex2D::operator/(const Complex2D& other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    double r = (real * other.real + imag * other.imag) / denom;
    double i = (imag * other.real - real * other.imag) / denom;
    return Complex2D(r, i);
}

bool Complex2D::operator<(const Complex2D& other) const {
    return module() < other.module();
}

bool Complex2D::operator>(const Complex2D& other) const {
    return module() > other.module();
}

void Complex2D::afficher() const {
    cout << real << " + " << imag << "i" << endl;
}

double Complex2D::module() const {
    return sqrt(real * real + imag * imag);
}
