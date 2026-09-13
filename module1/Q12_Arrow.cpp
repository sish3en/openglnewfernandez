#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.5f, 0.0f);

    glLineWidth(8.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(0.4f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(0.4f, 0.35f);
        glVertex2f(0.8f, 0.0f);
        glVertex2f(0.4f, -0.35f);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q12 - Arrow");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
