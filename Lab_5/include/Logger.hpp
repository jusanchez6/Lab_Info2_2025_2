#ifndef LOGGER_HPP
#define LOGGER_HPP

#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "Particle.hpp"

class Logger {
private:
    std::ofstream posOut;
    std::ofstream collOut;

public:
    Logger(const std::string& posFile = "positions.csv",
           const std::string& collFile = "collisions.log");

    ~Logger();

    void logPositions(double t, const std::vector<Particle>& parts);
    void logCollision(double t, const std::string& msg);
};

#endif