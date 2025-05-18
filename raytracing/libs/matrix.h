#pragma once

#include <vector>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <type_traits>

template <typename T>
class Matrix {
    static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

private:
    std::vector<std::vector<T>> mat;
    size_t rows, cols;

public:
    // Конструкторы
    Matrix(size_t n, size_t m, T initValue = 0);
    Matrix(const std::vector<std::vector<T>>& arr);
    Matrix(const Matrix& M);

    // Оператор присваивания
    Matrix& operator=(const Matrix& M);

    // Операции с матрицами
    Matrix operator+(const Matrix& M) const;
    Matrix operator-(const Matrix& M) const;
    Matrix operator*(const Matrix& M) const;
    Matrix operator/(const Matrix& M) const;

    // Обратная матрица и определитель
    std::optional<Matrix> inv() const;
    double det() const;

    // Вывод матрицы
    void print() const;

    // Получение размеров
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    std::vector<T>& operator[](size_t row);
    const std::vector<T>& operator[](size_t row) const;
};
