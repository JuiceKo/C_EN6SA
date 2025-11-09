#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D {
private:
    double real;
    double imag;
    
public:
    Complex2D();
    Complex2D(double real, double imag);
    Complex2D(const Complex2D& other);

    Complex2D operator+(const Complex2D& other) const;
    Complex2D operator-(const Complex2D& other) const;
    Complex2D operator*(const Complex2D& other) const;
    Complex2D operator/(const Complex2D& other) const;

    bool operator<(const Complex2D& other) const;
    bool operator>(const Complex2D& other) const;

    void afficher() const;
    double module() const;
};

#endif
