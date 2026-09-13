#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include <cmath>

void drawSun() {
    glColor3f(1.0f, 0.9f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.6f, 0.55f);
        for (int i = 0; i <= 40; i++) {
            float angle = i / 40.0f * 2.0f * 3.14159265f;
            glVertex2f(0.6f + 0.15f * cosf(angle),
                       0.55f + 0.15f * sinf(angle));
        }
    glEnd();
}

void display() {
    glClearColor(0.6f, 0.8f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.7f, 0.2f);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(-1.0f, -0.3f);
        glVertex2f(1.0f, -0.3f);
        glVertex2f(1.0f, -1.0f);
    glEnd();

    drawSun();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Q14 - Simple Landscape");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
