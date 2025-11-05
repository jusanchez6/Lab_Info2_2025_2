#include <Logger.hpp>

Logger::Logger(const std::string& posFile, const std::string& collFile) {
    posOut.open(posFile);
    collOut.open(collFile);
    posOut << "time,id,x,y,vx,vy,mass,radius,alive\n";
}

Logger::~Logger() {
    posOut.close();
    collOut.close();
}

void Logger::logPositions(double t, const std::vector<Particle>& parts) {
    for (const auto& p : parts) {
        if (!p.alive) continue;
        posOut << t << "," << p.id << "," << p.pos.x << "," << p.pos.y << ","
               << p.vel.x << "," << p.vel.y << "," << p.mass << "," << p.radius << ","
               << (p.alive ? 1 : 0 )<< "\n";
    }
}

void Logger::logCollision(double t, const std::string& msg) {
    collOut << "[" << t << "] " << msg << "\n";
}