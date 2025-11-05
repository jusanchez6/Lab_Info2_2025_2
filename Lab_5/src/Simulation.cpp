#include <Simulation.hpp>

Simulation::Simulation() : xmin(0), xmax(200), ymin(0), ymax(200), dt(0.01), endTime(10.0), obstacleRestitution(0.7), logger("./bin/positions.csv", "./bin/collisions.log") {}

void Simulation::addParticle(const Particle &p) { particles.push_back(p); }

void Simulation::addObstacle(const Obstacle &o) { obstacles.push_back(o); }

void Simulation::setBounds(double xMin, double xMax, double yMin, double yMax)
{
    xmin = xMin;
    xmax = xMax;
    ymin = yMin;
    ymax = yMax;
}
void Simulation::setTimeParams(double dt_, double endTime_)
{
    dt = dt_;
    endTime = endTime_;
}
void Simulation::setRestitution(double e) { obstacleRestitution = e; }

void Simulation::run()
{
    double t = 0.0;
    while (t <= endTime + 1e-12)
    {
        for (auto &p : particles)
            if (p.alive)
                p.step(dt);

        handleWallCollisions(t);
        handleObstacleCollisions(t);
        handleParticleCollisions(t);

        logger.logPositions(t, particles);
        t += dt;
    }
}

void Simulation::handleWallCollisions(double t) {
    for (auto &p : particles) {
        if (!p.alive) continue;
        bool collided = false;

        if (p.pos.x - p.radius < xmin) { p.pos.x = xmin + p.radius; p.vel.x = -p.vel.x; collided = true; }
        if (p.pos.x + p.radius > xmax) { p.pos.x = xmax - p.radius; p.vel.x = -p.vel.x; collided = true; }
        if (p.pos.y - p.radius < ymin) { p.pos.y = ymin + p.radius; p.vel.y = -p.vel.y; collided = true; }
        if (p.pos.y + p.radius > ymax) { p.pos.y = ymax - p.radius; p.vel.y = -p.vel.y; collided = true; }

        if (collided)
            logger.logCollision(t, "Particle " + std::to_string(p.id) + " collided with wall.");
    }
}

void Simulation::handleObstacleCollisions(double t) {
    for (auto &p : particles) {
        if (!p.alive) continue;
        for (const auto& obs : obstacles) {
            Vector2 cp, normal;
            double penetration;
            if (obs.circleCollision(p, cp, normal, penetration)) {
                p.pos = p.pos + normal * penetration;
                Vector2 v = p.vel;
                double v_perp = v.dot(normal);
                Vector2 v_para = v - normal * v_perp;
                Vector2 v_perp_new = normal * (-obstacleRestitution * v_perp);
                p.vel = v_para + v_perp_new;
                logger.logCollision(t, "Particle " + std::to_string(p.id) + " hit obstacle.");
            }
        }
    }
}

void Simulation::handleParticleCollisions(double t) {
    size_t n = particles.size();
    for (size_t i = 0; i < n; ++i) {
        if (!particles[i].alive) continue;
        for (size_t j = i+1; j < n; ++j) {
            if (!particles[j].alive) continue;

            auto& a = particles[i];
            auto& b = particles[j];
            Vector2 diff = b.pos - a.pos;
            double dist2 = diff.norm2();
            double rsum = a.radius + b.radius;

            if (dist2 <= rsum*rsum) {
                double m1 = a.mass, m2 = b.mass, M = m1 + m2;
                Vector2 newVel = (a.vel * m1 + b.vel * m2) / M;
                Vector2 newPos = (a.pos * m1 + b.pos * m2) / M;
                double newRadius = std::sqrt(a.radius*a.radius + b.radius*b.radius);

                a.pos = newPos;
                a.vel = newVel;
                a.mass = M;
                a.radius = newRadius;
                b.alive = false;

                logger.logCollision(t, "Particles " + std::to_string(a.id) + " and " + std::to_string(b.id) + " fused.");
            }
        }
    }
}