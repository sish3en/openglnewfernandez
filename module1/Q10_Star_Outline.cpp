#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    glLineWidth(3.0f);

    const float PI = 3.14159265f;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 10; i++) {
        float radius;
        if (i % 2 == 0) radius = 0.7f;
        else radius = 0.3f;

        float angle = i * PI / 5.0f + PI / 2.0f;
        glVertex2f(radius * cosf(angle), radius * sinf(angle));
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q10 - Star Outline");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
