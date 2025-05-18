#pragma once
#include <iostream>
#include <cmath>
#include <type_traits>

template<typename T>
class Vector3D {

    static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

public:
    T x, y, z;

    Vector3D(T x, T y, T z) : x(x), y(y), z(z) {}
    
    explicit operator bool() const {
        return x != 0 || y != 0 || z != 0; 
    };

    T& operator[](size_t index);

    Vector3D operator+(const Vector3D& other) const;

    Vector3D operator-(const Vector3D& other) const;

    Vector3D operator*(T scalar) const;

    Vector3D operator/(T scalar) const;

    T dot(const Vector3D& other) const;

    Vector3D cross(const Vector3D& other) const;

    double magnitude() const;

    Vector3D normalize() const;

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
        os << "Vector3D(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
};