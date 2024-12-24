#include <GL/glut.h>
#include "solar_system.h"

SolarSystem solarSystem;

float cameraX = 1.0f;
float cameraY = 1.0f;
float cameraZ = 50.0f;

void handleKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': cameraY += 5.0f; break; // Поднять камеру
        case 's': cameraY -= 5.0f; break; // Опустить камеру
        case 'a': cameraX -= 5.0f; break; // Сместить камеру влево
        case 'd': cameraX += 5.0f; break; // Сместить камеру вправо
        case 'q': cameraZ -= 5.0f; break; // Приблизить камеру
        case 'e': cameraZ += 5.0f; break; // Отдалить камеру
    }
    glutPostRedisplay(); // Обновить экран
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(cameraX, cameraY, cameraZ, 0, 0, 0, 0, 1, 0); // Камера

    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidSphere(2.0, 30, 30); // Отрисовка Солнца

    solarSystem.draw();

    glutSwapBuffers();
}

void update(int value) {
    solarSystem.update();
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45, 1.0, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Solar System");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(handleKeys);
    glutMainLoop();
    return 0;
}
