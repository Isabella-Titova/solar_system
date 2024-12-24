#include "planet.h"
#include <GL/glut.h>
#include <cmath>

Planet::Planet(float distance, float orbitSpeed, float size, float r, float g, float b)
    : distance(distance), orbitSpeed(orbitSpeed), size(size), angle(0.0f), r(r),g(g),b(b) {}

void Planet::update() {
    angle += orbitSpeed;
    if (angle >= 360.0f) {
        angle -= 360.0f;
    }
    for (auto& sput : sputniks) {
        sput.update();
    }
}

void Planet::draw() {
    glColor3f(r,g,b);
    glPushMatrix();
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glTranslatef(distance, 0.0f, 0.0f);
    glutSolidSphere(size, 30, 30);
    glPopMatrix();
    for (auto& sput : sputniks) {
        glPushMatrix();
        glRotatef(sput.angle, 0.0f, 1.0f, 0.0f);

        sput.draw();
        glPopMatrix();

    }
}
