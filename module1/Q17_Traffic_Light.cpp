#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include <cmath>

int activeLight = 0;

void drawCircle(float y, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, y);
        for (int i = 0; i <= 40; i++) {
            float angle = i / 40.0f * 2.0f * 3.14159265f;
            glVertex2f(0.0f + 0.18f * cosf(angle),
                       y + 0.18f * sinf(angle));
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.15f, 0.15f, 0.15f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.3f, -0.8f);
        glVertex2f(-0.3f, 0.8f);
        glVertex2f(0.3f, 0.8f);
        glVertex2f(0.3f, -0.8f);
    glEnd();

    drawCircle(0.5f, activeLight == 0 ? 1.0f : 0.3f, 0, 0);
    drawCircle(0.0f, activeLight == 1 ? 1.0f : 0.3f,
                     activeLight == 1 ? 1.0f : 0.3f, 0);
    drawCircle(-0.5f, 0, activeLight == 2 ? 1.0f : 0.3f, 0);
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'n') activeLight = (activeLight + 1) % 3;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 600);
    glutCreateWindow("Q17 - Press n for Next Light");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
