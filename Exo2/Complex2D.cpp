#include "Complex2D.h"
#include <cmath>


Complex2D::Complex2D() { re = 0; im = 0; }
Complex2D::Complex2D(double r, double i) { re = r; im = i; }
Complex2D::Complex2D(const Complex2D& other) { re = other.re; im = other.im; }

double Complex2D::getRe() const { return re; }
double Complex2D::getIm() const { return im; }
void Complex2D::afficher() { cout << re << " + " << im << "i" << endl; }

double Complex2D::module() const { return sqrt(re * re + im * im); }

Complex2D Complex2D::operator+(const Complex2D& other) const {
    return Complex2D(re + other.re, im + other.im);
}

Complex2D Complex2D::operator-(const Complex2D& other) const {
    return Complex2D(re - other.re, im - other.im);
}

Complex2D Complex2D::operator*(const Complex2D& other) const {
    double r = re * other.re - im * other.im;
    double i = re * other.im + im * other.re;
    return Complex2D(r, i);
}

Complex2D Complex2D::operator/(const Complex2D& other) const {
    double denom = other.re * other.re + other.im * other.im;
    double r = (re * other.re + im * other.im) / denom;
    double i = (im * other.re - re * other.im) / denom;
    return Complex2D(r, i);
}

bool Complex2D::operator==(const Complex2D& other) const {
    return re == other.re && im == other.im;
}

bool Complex2D::operator!=(const Complex2D& other) const {
    return !(*this == other);
}

bool Complex2D::operator<(const Complex2D& other) const {
    return this->module() < other.module();
}

bool Complex2D::operator>(const Complex2D& other) const {
    return this->module() > other.module();
}
