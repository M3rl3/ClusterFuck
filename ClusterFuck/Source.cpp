#include <iostream>
#include <cmath>

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

class Particle {
public:
    Vector3 position;
    Vector3 acceleration;
    Vector3 velocity;

    void calculate(float);

    friend std::ostream& operator<<(std::ostream& out, Particle& p1) {
        out << p1.position << p1.velocity;
        return out;
    }
};

//Def Constructor
Vector3::Vector3() {
    
}

//Parameterized constructor
Vector3::Vector3(float yes) /*: Vector3(yes, yes, yes)*/ {
    this->x = yes;
    this->y = yes;
    this->z = yes;

}

//Overloaded constructor
Vector3::Vector3(float x, float y, float z) /*: x(x), y(y), z(z)*/ {
    this->x = x;
    this->y = y;
    this->z = z;
}

//Copy Constructor
Vector3::Vector3(const Vector3& ass) {
    x = ass.x;
    y = ass.y;
    z = ass.z;
}

//Destructor
Vector3::~Vector3() {

}

//Assignment Overload
Vector3 Vector3::operator=(const Vector3 ass) {
    x = ass.x;
    y = ass.y;
    z = ass.z;
    return ass;
}

//Addition Overload
Vector3 Vector3::operator+(const Vector3 ass) {
    return Vector3(x + ass.x, y + ass.y, z + ass.z);
}

//Subtraction Overload
Vector3 Vector3::operator-(const Vector3& ass) {
    
    return Vector3(x - ass.x, y - ass.y, z - ass.z);
}

//Multiplication Overload
Vector3 Vector3::operator*(const float ass) {
    return Vector3(x * ass, y * ass, z * ass);  
}

//Division Overload
Vector3 Vector3::operator/(const float& ass) {
    return Vector3(x / ass, y / ass, z / ass);
}

//Insertion Overload
std::ostream& operator<<(std::ostream& out, Vector3& v1) {
    out << v1.x << v1.y << v1.z;
    return out;
}

//void Vector3::operator*=(float& ass) {
//    x *= ass;
//    y *= ass;
//    z *= ass;
//}

//Vector Magnitude
float Vector3::magnitude() {
    float result;
    result = sqrt(x * x + y * y + z * z);
    return result;
}
 
//Invert the vector
Vector3 Vector3::invert(Vector3& temp) {
    
    //return Vector3(x, y, z) * -1.0f;
    temp.x = temp.x * -1.0f;
    temp.y = temp.y * -1.0f;
    temp.z = temp.z * -1.0f;
    return (temp);
}

//Normalize the vector
void Vector3::normal() {
    float result = magnitude();

    x = x / result;
    y = y / result;
    z = z / result;

}

//Calculate particle position and velocity
void Particle::calculate(float dt) {
    std::cout << "velocity = " << velocity.y << " + " << acceleration.y << " * " << dt << "\n";
    velocity = velocity + acceleration * dt;
    std::cout << "position = " << position.y << " + " << velocity.y << " * " << dt << "\n";
    position = position + velocity * dt;
}

//print new y coordinate
void printparticle(Particle p) {
    std::cout << "\nPosition && Velocity: " << p.position.y << " " << p.velocity.y << std::endl;
}

//Main entry point
void main() {
    Vector3 vector(5, 6, 7);
    
    float f = vector.magnitude();
    std::cout << "\nMagnitude: " << f << std::endl;

    Vector3 v = vector.invert(vector);
    std::cout << "\nInvert: " << v << std::endl;

    vector.normal();
    std::cout << "\nNormal: " << vector.x << " " << vector.y << " " << vector.z << "\n" << std::endl;

    Particle p;
    p.position = Vector3(0.f);
    p.velocity = Vector3(0.f, 10.f, 0.f);
    p.acceleration = Vector3(0.f, -2.f, 0.f);

    //printing particle positions
    while (p.position.y >= 0) {
        p.calculate(.1f);
        printparticle(p);
        //if (p.velocity.y <= 0) break;
    }
}