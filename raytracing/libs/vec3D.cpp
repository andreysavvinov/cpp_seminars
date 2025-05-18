#include "vec3D.h"

template<typename T>
T& Vector3D<T>::operator[](size_t index) {
    if (index == 0) return x;
    if (index == 1) return y;
    if (index == 2) return z;
    throw std::out_of_range("Index out of range");
}

template <typename T>
Vector3D<T> Vector3D<T>::operator+(const Vector3D<T>& other) const {
    return Vector3D<T>(x + other.x, y + other.y, z + other.z);
}

template <typename T>
Vector3D<T> Vector3D<T>::operator-(const Vector3D<T>& other) const {
    return Vector3D<T>(x - other.x, y - other.y, z - other.z);
}

template <typename T>
Vector3D<T> Vector3D<T>::operator*(T scalar) const {
    return Vector3D<T>(x * scalar, y * scalar, z * scalar);
}

template <typename T>
Vector3D<T> Vector3D<T>::operator/(T scalar) const {
    return Vector3D<T>(x / scalar, y / scalar, z / scalar);
}

template <typename T>
T Vector3D<T>::dot(const Vector3D<T>& other) const {
    return x * other.x + y * other.y + z * other.z;
}

template <typename T>
Vector3D<T> Vector3D<T>::cross(const Vector3D<T>& other) const {
    return Vector3D<T>(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

template <typename T>
double Vector3D<T>::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

template <typename T>
Vector3D<T> Vector3D<T>::normalize() const {
    double mag = magnitude();
    return Vector3D<T>(x / mag, y / mag, z / mag);
}

