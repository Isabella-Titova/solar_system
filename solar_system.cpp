#include "solar_system.h"

void SolarSystem::draw() {
    for (auto &planet : planets) {
        planet.draw();
    }
}

void SolarSystem::update() {
    for (auto &planet : planets) {
        planet.update();
    }
}

SolarSystem::SolarSystem() {
    Planet earth(10.0f, 0.1f, 0.1f, 0.0f, 0.0f, 1.0f);
    earth.sputniks.emplace_back(5.0f,0.8f,0.5f, 0.8f,0.8f,0.8f);
    planets.emplace_back(earth);
    planets.emplace_back(5.0f, 1.07f, 1.2f,0.5f,0.1f,0.1f);
    planets.emplace_back(5.0f, 1.07f, 1.2f,0.5f,0.1f,0.1f);
    planets.emplace_back(10.0f, 0.1f, 1.4f,0.2f,0.16f,0.1f);
    planets.emplace_back(20.0f, 0.9f, 1.6f,0.8f,0.25f,0.1f);
    planets.emplace_back(30.0f, 0.6f, 1.8f,0.5f,0.19f,0.1f);
    planets.emplace_back(40.0f, 0.3f, 1.1f,0.2f,0.7f,0.1f);
    planets.emplace_back(80.0f, 0.2f, 1.4f,0.2f,0.5f,0.1f);
    planets.emplace_back(60.0f, 1.1f, 1.0f,0.1f,0.1f,0.1f);
}

