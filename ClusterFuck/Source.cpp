#include <iostream>
#include <cmath>

class Vector3 {
public:
    Vector3();
    Vector3(float);
    Vector3(float, float, float);
    Vector3(const Vector3&);
    Vector3 operator=(Vector3&);
    Vector3 operator+(Vector3&);
    Vector3 operator-(Vector3&);
    Vector3 operator*(float&);
    Vector3 operator/(float&);

    void normal();
    float magnitude();
    Vector3 invert();
    
    float x;
    float y;
    float z;
    

};

class Particle {
public:
    Vector3 position, velocity, acceleration;

    void calculate();
};

Vector3::Vector3() {

}

//Vector3::Vector3(float yes)  {
//
//}

Vector3::Vector3(float x, float y, float z) /*: x(x), y(y), z(z)*/ {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::Vector3(const Vector3& ass) {
    this->x = ass.x;
    this->y = ass.y;
    this->z = ass.z;
}

Vector3 Vector3::operator=(Vector3& ass) {
    this->x = ass.x;
    this->y = ass.y;
    this->z = ass.z;
    return ass;
}

Vector3 Vector3::operator+(Vector3& ass) {
    this->x + ass.x;
    this->y + ass.y;
    this->z + ass.z;
    return(ass);
}

Vector3 Vector3::operator-(Vector3& ass) {
    this->x - ass.x;
    this->y - ass.y;
    this->z - ass.z;
    return(ass);
}

Vector3 Vector3::operator*(float& ass) {
    return(x * ass, y * ass, z * ass);
   
}

Vector3 Vector3::operator/(float& ass) {
    return(x / ass, y / ass, z / ass);
}

float Vector3::magnitude() {
    float result = 0.0f;
    result = sqrt(x * x + y * y + z * z);
    return result;
}
 
Vector3 Vector3::invert() {
    return (Vector3(x, y, z) * -1.0f);
}

void Vector3::normal() {
    float result = magnitude();
}



void main() {


}