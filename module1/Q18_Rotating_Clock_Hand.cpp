#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include <cmath>

float handAngle = 1.5707963f;
const float PI = 3.14159265f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 60; i++) {
        float angle = i / 60.0f * 2.0f * PI;
        glVertex2f(0.75f * cosf(angle), 0.75f * sinf(angle));
    }
    glEnd();

    glBegin(GL_LINES);
    for (int i = 0; i < 12; i++) {
        float angle = i / 12.0f * 2.0f * PI;
        glVertex2f(0.65f * cosf(angle), 0.65f * sinf(angle));
        glVertex2f(0.75f * cosf(angle), 0.75f * sinf(angle));
    }
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.55f * cosf(handAngle), 0.55f * sinf(handAngle));
    glEnd();
    glFlush();
}

void idle() {
    handAngle -= 0.001f;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q18 - Rotating Clock Hand");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
