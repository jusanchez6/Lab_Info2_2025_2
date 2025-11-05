#include <Obstacle.hpp>

Obstacle::Obstacle(double x_, double y_, double w_, double h_)
    : x(x_), y(y_), w(w_), h(h_) {}

bool Obstacle::circleCollision(const Particle& c,
                               Vector2& out_point,
                               Vector2& out_normal,
                               double& penetration) const {
    double cx = std::min(std::max(c.pos.x, x), x + w);
    double cy = std::min(std::max(c.pos.y, y), y + h);
    out_point = {cx, cy};

    Vector2 diff = c.pos - out_point;
    double dist2 = diff.norm2();
    double r = c.radius;

    if (dist2 <= r*r + 1e-12) {
        double dist = std::sqrt(std::max(dist2, 1e-12));
        out_normal = (dist == 0.0) ? Vector2(0,1) : diff / dist;
        penetration = r - dist;
        return true;
    }
    return false;
}