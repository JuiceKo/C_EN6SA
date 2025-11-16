#pragma once

#include <vector>
#include <iostream>

template<typename T>
class MatrixBase {
protected:
    int nrows;
    int ncols;
    std::vector<std::vector<T>> data;

public:
    MatrixBase();
    MatrixBase(int rows, int cols, const T& init = T{});

    int getRows() const;
    int getCols() const;

    void addElement(int r, int c, const T& value);
    const T& getElement(int r, int c) const;
    T&       getElement(int r, int c);

    void display(std::ostream& os = std::cout) const;
};

#include "MatrixBase.tpp"
