#pragma once

template<typename T>
MatrixNumerical<T>::MatrixNumerical()
    : MatrixBase<T>() {}

template<typename T>
MatrixNumerical<T>::MatrixNumerical(int rows, int cols, const T& init)
    : MatrixBase<T>(rows, cols, init) {}

template<typename T>
T MatrixNumerical<T>::getDeterminant() const {
    if (nrows != ncols) {
        throw std::runtime_error("Determinant only defined for square matrices");
    }

    int n = nrows;

    if (n == 0) {
        throw std::runtime_error("Empty matrix has no determinant");
    }

    if (n == 1) {
        return data[0][0];
    }

    if (n == 2) {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }

    T det = T{};
    int sign = 1;

    for (int col = 0; col < n; ++col) {
        MatrixNumerical<T> cof = getCofactor(0, col);
        det += static_cast<T>(sign) * data[0][col] * cof.getDeterminant();
        sign = -sign;
    }

    return det;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getCofactor(int p, int q) const {
    if (nrows != ncols) {
        throw std::runtime_error("Cofactor only defined for square matrices");
    }

    int n = nrows;
    MatrixNumerical<T> temp(n - 1, n - 1, T{});

    int i = 0, j = 0;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (row != p && col != q) {
                temp.data[i][j++] = data[row][col];

                if (j == n - 1) {
                    j = 0;
                    ++i;
                }
            }
        }
    }

    return temp;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    if (nrows != ncols) {
        throw std::runtime_error("Inverse only defined for square matrices");
    }

    int n = nrows;
    T det = getDeterminant();

    if (det == T{}) {
        throw std::runtime_error("Matrix is singular (determinant = 0)");
    }

    MatrixNumerical<T> adj(n, n, T{});

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            MatrixNumerical<T> cof = getCofactor(i, j);
            T sign = ((i + j) % 2 == 0) ? T(1) : T(-1);
            T c = sign * cof.getDeterminant();

            adj.data[j][i] = c;
        }
    }

    MatrixNumerical<T> inv(n, n, T{});
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inv.data[i][j] = adj.data[i][j] / det;
        }
    }

    return inv;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(
    const MatrixNumerical<T>& other) const {

    if (nrows != other.nrows || ncols != other.ncols) {
        throw std::runtime_error("Matrix sizes must match for addition");
    }

    MatrixNumerical<T> result(nrows, ncols, T{});
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(
    const MatrixNumerical<T>& other) const {

    if (nrows != other.nrows || ncols != other.ncols) {
        throw std::runtime_error("Matrix sizes must match for subtraction");
    }

    MatrixNumerical<T> result(nrows, ncols, T{});
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }

    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(
    const MatrixNumerical<T>& other) const {

    if (ncols != other.nrows) {
        throw std::runtime_error("Invalid sizes for matrix multiplication");
    }

    MatrixNumerical<T> result(nrows, other.ncols, T{});

    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < other.ncols; ++j) {
            T sum = T{};
            for (int k = 0; k < ncols; ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int n) {
    MatrixNumerical<T> I(n, n, T{});
    for (int i = 0; i < n; ++i) {
        I.data[i][i] = T(1);
    }
    return I;
}
