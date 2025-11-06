#include <iostream>
#include "Complex2D.h"
using namespace std;

int main() {
    Complex2D a;
    Complex2D b(3, 4);
    Complex2D c(b);
    cout << "a = "; a.afficher(); << endl
    cout << "b = "; b.afficher(); << endl
    cout << "c = "; c.afficher(); << endl

    cout << "\nAddition : "; (b + c).afficher(); << endl
    cout << "Soustraction : "; (b - c).afficher(); << endl
    cout << "Multiplication : "; (b * c).afficher(); << endl
    cout << "Division : "; (b / c).afficher(); << endl

    cout << "\nModule de b = " << b.module() << endl;
    cout << "Module de c = " << c.module() << endl;

    if (b > c)
        cout << "b est plus grand que c (en module)" << endl;
    else if (b < c)
        cout << "b est plus petit que c (en module)" << endl;
    else
        cout << "b et c ont le même module" << endl;

    if (b == c)
        cout << "b et c sont égaux" << endl;
    else
        cout << "b et c sont différents" << endl;

    return 0;
}
