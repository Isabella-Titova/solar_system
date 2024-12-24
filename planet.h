#ifndef PLANET_H
#define PLANET_H

#include <GL/glut.h>
#include <vector>

class Planet {
public:
    std:: vector<Planet> sputniks;
    float r,g,b;
    float distance; // ������ ������
    float orbitSpeed; // �������� ��������
    float size; // ������ �������
    float angle; // ������� ���� ������

    Planet(float distance, float orbitSpeed, float size, float r, float g, float b);

    void update(); // ���������� �������
    void draw();   // ��������� �������
};

#endif

