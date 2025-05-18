#include "matrix.h"

// Конструктор с заполнением значением
template <typename T>
Matrix<T>::Matrix(size_t n, size_t m, T initValue) 
    : rows(n), cols(m), mat(n, std::vector<T>(m, initValue)) {}

// Конструктор от вектора векторов
template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& arr) 
    : mat(arr), rows(arr.size()), cols(arr.empty() ? 0 : arr[0].size()) {}

// Конструктор копирования
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& M) 
    : rows(M.rows), cols(M.cols), mat(M.mat) {}

// Оператор присваивания
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& M) {
    if (this == &M) return *this;  // Проверка на самоприсваивание
    rows = M.rows;
    cols = M.cols;
    mat = M.mat;
    return *this;
}

// Сложение матриц
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& M) const {
    if (rows != M.rows || cols != M.cols)
        throw std::invalid_argument("Размеры матриц должны совпадать для сложения!");
    
    Matrix<T> result(rows, cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            result.mat[i][j] = mat[i][j] + M.mat[i][j];

    return result;
}

// Вывод матрицы
template <typename T>
void Matrix<T>::print() const {
    for (const auto& row : mat) {
        for (const auto& elem : row)
            std::cout << elem << " ";
        std::cout << std::endl;
    }
}

// Определитель матрицы (только для квадратных)
template <typename T>
double Matrix<T>::det() const {
    if (rows != cols) throw std::invalid_argument("Определитель можно вычислить только для квадратных матриц!");

    // Базовый случай для 2×2 матрицы
    if (rows == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    double determinant = 0;
    for (size_t i = 0; i < cols; ++i) {
        Matrix<T> subMatrix(rows - 1, cols - 1);
        for (size_t j = 1; j < rows; ++j) {
            size_t colIndex = 0;
            for (size_t k = 0; k < cols; ++k) {
                if (k == i) continue;
                subMatrix.mat[j - 1][colIndex++] = mat[j][k];
            }
        }
        determinant += ((i % 2 == 0) ? 1 : -1) * mat[0][i] * subMatrix.det();
    }
    return determinant;
}

template <typename T>
std::vector<T>& Matrix<T>::operator[](size_t row) {
    if (row >= rows)
        throw std::out_of_range("Индекс выходит за границы матрицы!");
    return mat[row];
}

template <typename T>
const std::vector<T>& Matrix<T>::operator[](size_t row) const {
    if (row >= rows)
        throw std::out_of_range("Индекс выходит за границы матрицы!");
    return mat[row];
}

// Обратная матрица (метод Гаусса-Жордана)
template <typename T>
std::optional<Matrix<T>> Matrix<T>::inv() const {
    if (rows != cols)
        throw std::invalid_argument("Обратная матрица существует только для квадратных матриц!");

    size_t n = rows;
    Matrix<T> augmented(n, 2 * n);

    // Формируем расширенную матрицу [A | I]
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            augmented[i][j] = mat[i][j];
        augmented[i][n + i] = 1;  // Единичная матрица в правой части
    }

    // Прямой ход метода Гаусса
    for (size_t i = 0; i < n; ++i) {
        // Находим ведущий элемент
        size_t pivotRow = i;
        for (size_t k = i + 1; k < n; ++k)
            if (std::fabs(augmented[k][i]) > std::fabs(augmented[pivotRow][i]))
                pivotRow = k;

        // Если ведущий элемент ≈ 0, матрица необратима
        if (std::fabs(augmented[pivotRow][i]) < 1e-9)
            return std::nullopt;

        // Меняем строки местами (если нужно)
        if (pivotRow != i)
            std::swap(augmented[i], augmented[pivotRow]);

        // Нормализуем ведущий элемент
        T pivot = augmented[i][i];
        for (size_t j = 0; j < 2 * n; ++j)
            augmented[i][j] /= pivot;

        // Обнуляем элементы в текущем столбце (в других строках)
        for (size_t k = 0; k < n; ++k) {
            if (k == i) continue;
            T factor = augmented[k][i];
            for (size_t j = 0; j < 2 * n; ++j)
                augmented[k][j] -= factor * augmented[i][j];
        }
    }

    // Выделяем правую часть матрицы (обратную)
    Matrix<T> inverse(n, n);
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            inverse[i][j] = augmented[i][n + j];

    return inverse;
}
