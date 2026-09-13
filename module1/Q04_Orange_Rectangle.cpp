#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.7f, -0.3f);
        glVertex2f(-0.7f, 0.3f);
        glVertex2f(0.7f, 0.3f);
        glVertex2f(0.7f, -0.3f);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q04 - Orange Rectangle");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
