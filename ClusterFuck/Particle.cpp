#include "Particle.h"

//Calculate particle position and velocity
void Particle::calculate(float dt) {
    std::cout << "velocity = " << velocity.y << " + " << acceleration.y << " * " << dt << "\n";
    velocity = velocity + acceleration * dt;
    std::cout << "position = " << position.y << " + " << velocity.y << " * " << dt << "\n";
    position = position + velocity * dt;
}