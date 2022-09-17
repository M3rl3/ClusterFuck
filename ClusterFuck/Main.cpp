#include <iostream>
#include <cmath>

#include "Vector3.h"
#include "Particle.h"

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