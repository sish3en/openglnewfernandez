#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include <cmath>

void drawCircleOutline(float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 60; i++) {
        float angle = i / 60.0f * 2.0f * 3.14159265f;
        glVertex2f(radius * cosf(angle), radius * sinf(angle));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);
    drawCircleOutline(0.3f, 1, 0, 0);
    drawCircleOutline(0.5f, 0, 1, 0);
    drawCircleOutline(0.7f, 0, 0, 1);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q11 - Concentric Circles");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
