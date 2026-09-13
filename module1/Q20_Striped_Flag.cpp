#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include <cmath>

const int STRIPE_COUNT = 6;
const float PI = 3.14159265f;

void drawStar() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 10; i++) {
        float radius;
        if (i % 2 == 0) radius = 0.22f;
        else radius = 0.09f;
        float angle = i * PI / 5.0f + PI / 2.0f;
        glVertex2f(-0.65f + radius * cosf(angle),
                    0.60f + radius * sinf(angle));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    float stripeHeight = 2.0f / STRIPE_COUNT;

    for (int i = 0; i < STRIPE_COUNT; i++) {
        if (i % 2 == 0) glColor3f(0.8f, 0.0f, 0.0f);
        else glColor3f(0.0f, 0.2f, 0.7f);

        float top = 1.0f - i * stripeHeight;
        float bottom = top - stripeHeight;
        glBegin(GL_POLYGON);
            glVertex2f(-1.0f, bottom);
            glVertex2f(-1.0f, top);
            glVertex2f(1.0f, top);
            glVertex2f(1.0f, bottom);
        glEnd();
    }

    drawStar();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Q20 - Striped Flag with Star");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
