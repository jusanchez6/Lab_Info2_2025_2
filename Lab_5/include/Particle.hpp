#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <Vector2.hpp>

class Particle
{
public:

    int id;
    Vector2 pos;
    Vector2 vel;

    double mass;
    double radius;
    bool alive;

    Particle(int id_, Vector2 p, Vector2 v, double m, double r);

    void step (double dt);
    void applyImpulse(const Vector2& J);
};



#endif