#include <iostream>
#include "MatrixNumerical.hpp"

int main() {
    // Exemple simple : matrice 3x3
    MatrixNumerical<double> M(3, 3, 0.0);

    double val = 1.0;
    for (int i = 0; i < M.getRows(); ++i) {
        for (int j = 0; j < M.getCols(); ++j) {
            M.addElement(i, j, val++);
        }
    }

    std::cout << "Matrice M :" << std::endl;
    M.display();

    try {
        double det = M.getDeterminant();
        std::cout << "\nDet(M) = " << det << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur determinant: " << e.what() << std::endl;
    }

    // Exemple avec une matrice inversible
    MatrixNumerical<double> A(2, 2, 0.0);
    A.addElement(0, 0, 4);
    A.addElement(0, 1, 7);
    A.addElement(1, 0, 2);
    A.addElement(1, 1, 6);

    std::cout << "\nMatrice A :" << std::endl;
    A.display();

    std::cout << "\nDet(A) = " << A.getDeterminant() << std::endl;

    std::cout << "\nInverse de A :" << std::endl;
    MatrixNumerical<double> Ainv = A.getInverse();
    Ainv.display();

    std::cout << "\nIdentite 3x3 :" << std::endl;
    auto I3 = MatrixNumerical<double>::getIdentity(3);
    I3.display();

    return 0;
}
