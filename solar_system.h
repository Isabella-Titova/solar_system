#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include "planet.h"
#include <vector>

class SolarSystem {
public:
    std::vector<Planet> planets;

    SolarSystem();
    void update();
    void draw();
};

#endif

