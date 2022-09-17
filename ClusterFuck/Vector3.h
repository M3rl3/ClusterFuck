#pragma once

#include <iostream>

class Vector3 {
public:
    Vector3();
    Vector3(float);
    Vector3(float, float, float);
    ~Vector3();
    Vector3(const Vector3&);
    Vector3 operator=(const Vector3);
    Vector3 operator+(const Vector3);
    Vector3 operator-(const Vector3&);
    Vector3 operator*(const float);
    Vector3 operator/(const float&);

    friend std::ostream& operator<<(std::ostream&, Vector3&);

    //void operator*=(float&);

    void normal();
    float magnitude();
    Vector3 invert(Vector3&);

    float x;
    float y;
    float z;

};
