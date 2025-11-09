#include <iostream>
#include "Complex2D.h"
using namespace std;

int main() {
    Complex2D a;
    Complex2D b(3, 4);
    Complex2D c(b);
    a.afficher();
    b.afficher();
    c.afficher();
    (b + c).afficher();
    (b - c).afficher();
    (b * c).afficher();
    (b / c).afficher();
    return 0;
}
