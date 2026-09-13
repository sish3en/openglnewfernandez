#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    float size = 0.4f;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            float x = -0.8f + col * size;
            float y = -0.8f + row * size;

            if ((row + col) % 2 == 0)
                glColor3f(1.0f, 1.0f, 1.0f);
            else
                glColor3f(0.0f, 0.0f, 0.0f);

            glBegin(GL_POLYGON);
                glVertex2f(x, y);
                glVertex2f(x, y + size);
                glVertex2f(x + size, y + size);
                glVertex2f(x + size, y);
            glEnd();
        }
    }
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q09 - 4x4 Checkerboard");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
