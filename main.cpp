#include <GL/glut.h>
#include "solar_system.h"

SolarSystem solarSystem;

float cameraX = 1.0f;
float cameraY = 1.0f;
float cameraZ = 50.0f;

void handleKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': cameraY += 5.0f; break; // ������� ������
        case 's': cameraY -= 5.0f; break; // �������� ������
        case 'a': cameraX -= 5.0f; break; // �������� ������ �����
        case 'd': cameraX += 5.0f; break; // �������� ������ ������
        case 'q': cameraZ -= 5.0f; break; // ���������� ������
        case 'e': cameraZ += 5.0f; break; // �������� ������
    }
    glutPostRedisplay(); // �������� �����
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(cameraX, cameraY, cameraZ, 0, 0, 0, 0, 1, 0); // ������

    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidSphere(2.0, 30, 30); // ��������� ������

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
