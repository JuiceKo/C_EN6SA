#pragma once

template<typename T>
MatrixBase<T>::MatrixBase()
    : nrows(0), ncols(0) {}

template<typename T>
MatrixBase<T>::MatrixBase(int rows, int cols, const T& init)
    : nrows(rows), ncols(cols), data(rows, std::vector<T>(cols, init)) {}

template<typename T>
int MatrixBase<T>::getRows() const {
    return nrows;
}

template<typename T>
int MatrixBase<T>::getCols() const {
    return ncols;
}

template<typename T>
void MatrixBase<T>::addElement(int r, int c, const T& value) {
    data[r][c] = value;
}

template<typename T>
const T& MatrixBase<T>::getElement(int r, int c) const {
    return data[r][c];
}

template<typename T>
T& MatrixBase<T>::getElement(int r, int c) {
    return data[r][c];
}

template<typename T>
void MatrixBase<T>::display(std::ostream& os) const {
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            os << data[i][j] << " ";
        }
        os << '\n';
    }
}
