#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.8f, -0.4f);
        glVertex2f(-0.5f, 0.4f);
        glVertex2f(-0.2f, -0.4f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.2f, -0.4f);
        glVertex2f(0.5f, 0.4f);
        glVertex2f(0.8f, -0.4f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q07 - Two Triangles");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
