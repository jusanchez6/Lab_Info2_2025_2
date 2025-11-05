#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

#include <Particle.hpp>
#include <Obstacle.hpp>
#include <Logger.hpp>


class Simulation
{
private:
    double xmin, xmax, ymin, ymax;
    double dt;
    double endTime;
    double obstacleRestitution;

    std::vector<Particle> particles;
    std::vector<Obstacle> obstacles;
    Logger logger;

    void handleWallCollisions(double t);
    void handleObstacleCollisions(double t);
    void handleParticleCollisions(double t);

public:
    Simulation();

    void addParticle(const Particle& p);
    void addObstacle(const Obstacle& o);

    void setBounds(double xMin, double xMax, double yMin, double yMax);
    void setTimeParams(double dt_, double endTime_);
    void setRestitution(double e);

    void run();
};




#endif