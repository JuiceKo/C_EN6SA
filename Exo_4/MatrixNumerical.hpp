#pragma once

#include "MatrixBase.hpp"
#include <type_traits>
#include <stdexcept>

template<typename T>
class MatrixNumerical : public MatrixBase<T> {
    static_assert(std::is_arithmetic<T>::value,
                  "MatrixNumerical requires a numeric type");

public:
    using MatrixBase<T>::nrows;
    using MatrixBase<T>::ncols;
    using MatrixBase<T>::data;
    using MatrixBase<T>::getRows;
    using MatrixBase<T>::getCols;

    MatrixNumerical();
    MatrixNumerical(int rows, int cols, const T& init = T{});

    // 7. Déterminant
    T getDeterminant() const;

    // 8. Cofacteur
    MatrixNumerical<T> getCofactor(int p, int q) const;

    // 11. Inverse utilisant la méthode des cofacteurs
    MatrixNumerical<T> getInverse() const;

    // 9–10. Opérateurs +, -, *
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const;

    // 12. Matrice identité statique
    static MatrixNumerical<T> getIdentity(int n);
};

#include "MatrixNumerical.tpp"
