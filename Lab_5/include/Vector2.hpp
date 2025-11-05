#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>

class Vector2
{
public:
    double x, y;

    Vector2(double x_ = 0.0, double y_ = 0.0);

    Vector2 operator+(const Vector2 &o) const { return {x + o.x, y + o.y}; }
    Vector2 operator-(const Vector2 &o) const { return {x - o.x, y - o.y}; }
    Vector2 operator*(double s) const { return {x*s, y*s}; }
    Vector2 operator/(double s) const { return {x/s, y/s}; } 


    double dot(const Vector2& o) const { return x*o.x + y*o.y; }
    double norm2() const { return x*x + y*y; }
    double norm() const { return std::sqrt(norm2()); }

    Vector2 normalized() const;
};

#endif