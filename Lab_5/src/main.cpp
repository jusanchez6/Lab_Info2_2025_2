#include <iostream>
#include "Simulation.hpp"

int main() {
    Simulation sim;
    sim.setBounds(0, 400, 0, 300);
    sim.setTimeParams(0.02, 15.0);
    sim.setRestitution(0.6);

    sim.addObstacle({150, 100, 40, 40});
    sim.addObstacle({250, 160, 50, 50});
    sim.addObstacle({50, 200, 60, 30});
    sim.addObstacle({320, 40, 50, 60});

    sim.addParticle({1, {50,50}, {70,70}, 1.0, 6.0});
    sim.addParticle({2, {100,60}, {70,-70}, 1.2, 7.0});
    sim.addParticle({3, {200,250}, {-20,-40}, 1.5, 8.0});
    sim.addParticle({4, {300,80}, {-70,20}, 0.9, 5.5});
    sim.addParticle({5, {120,120}, {5,-30}, 1.0, 6.0});

    std::cout << "Simulando... salida: positions.csv, collisions.log\n";
    sim.run();
    std::cout << "Simulación completada.\n";
}
