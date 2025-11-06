#ifndef COMPLEX2D_H
#define COMPLEX2D_H
#include <iostream>
using namespace std;

class Complex2D {
private:
    double re;
    double im;

public:
    Complex2D();                            
    Complex2D(double r, double i);
    Complex2D(const Complex2D& other);

    double getRe() const;
    double getIm() const;
    void afficher() const;

    Complex2D operator+(const Complex2D& other) const;
    Complex2D operator-(const Complex2D& other) const;
    Complex2D operator*(const Complex2D& other) const;
    Complex2D operator/(const Complex2D& other) const;

    bool operator==(const Complex2D& other) const;
    bool operator!=(const Complex2D& other) const;
    bool operator<(const Complex2D& other) const;
    bool operator>(const Complex2D& other) const;
};

#endif
