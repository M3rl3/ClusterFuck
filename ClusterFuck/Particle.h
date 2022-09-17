#pragma once

#include <iostream>
#include "Vector3.h"

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