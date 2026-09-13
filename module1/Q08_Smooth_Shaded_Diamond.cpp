#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_POLYGON);
        glColor3f(1, 0, 0); glVertex2f(0.0f, 0.7f);
        glColor3f(0, 1, 0); glVertex2f(0.7f, 0.0f);
        glColor3f(0, 0, 1); glVertex2f(0.0f, -0.7f);
        glColor3f(1, 1, 0); glVertex2f(-0.7f, 0.0f);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q08 - Smooth Shaded Diamond");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
