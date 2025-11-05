#include <Particle.hpp>

Particle::Particle(int id_, Vector2 p, Vector2 v, double m, double r)
: id(id_), pos(p), vel(v), mass(m), radius(r), alive(true) {}

void Particle::step (double dt) {
    pos = pos + vel * dt;

}


void Particle::applyImpulse(const Vector2& J) {
    vel = vel +J / mass;
}