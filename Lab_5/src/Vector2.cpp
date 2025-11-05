#include <Vector2.hpp>

Vector2::Vector2(double x_, double y_) : x(x_), y(y_) {}

Vector2 Vector2::normalized() const
{
    double n = norm();
    return n == 0 ? Vector2(0, 0) : (*this) / n;
}