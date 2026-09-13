#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>

float squareX = 0.0f;
float squareY = 0.0f;
const float size = 0.15f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.7f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(squareX - size, squareY - size);
        glVertex2f(squareX - size, squareY + size);
        glVertex2f(squareX + size, squareY + size);
        glVertex2f(squareX + size, squareY - size);
    glEnd();
    glFlush();
}

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT)  squareX -= 0.05f;
    if (key == GLUT_KEY_RIGHT) squareX += 0.05f;
    if (key == GLUT_KEY_UP)    squareY += 0.05f;
    if (key == GLUT_KEY_DOWN)  squareY -= 0.05f;

    if (squareX > 1.0f - size) squareX = 1.0f - size;
    if (squareX < -1.0f + size) squareX = -1.0f + size;
    if (squareY > 1.0f - size) squareY = 1.0f - size;
    if (squareY < -1.0f + size) squareY = -1.0f + size;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q15 - Move Square with Arrow Keys");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
