#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#pragma once

#include <algorithm>
#include <cmath>

#include "Vector2.hpp"
#include "Particle.hpp"

class Obstacle {
public:
    double x, y, w, h;
    Obstacle(double x_, double y_, double w_, double h_);
    bool circleCollision(const Particle& c,
                         Vector2& out_point,
                         Vector2& out_normal,
                         double& penetration) const;
};

#endif