#ifndef PLANET_H
#define PLANET_H

#include <GL/glut.h>
#include <vector>

class Planet {
public:
    std:: vector<Planet> sputniks;
    float r,g,b;
    float distance; // Радиус орбиты
    float orbitSpeed; // Скорость вращения
    float size; // Размер планеты
    float angle; // Текущий угол орбиты

    Planet(float distance, float orbitSpeed, float size, float r, float g, float b);

    void update(); // Обновление позиции
    void draw();   // Отрисовка планеты
};

#endif

