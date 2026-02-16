#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void display() {
    glClearColor(1.f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    gluOrtho2D(-250, 250, -250, 250);

    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.2f, 0.3f);
    glVertex2f(-175, 75);
    glVertex2f(-75, 75);
    glVertex2f(-75, 175);
    glVertex2f(-175, 175);
    glEnd();

    /*glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0, 0.0f);
    glVertex2f(-175, 75);
    glVertex2f(-75, 75);
    glVertex2f(-75, 175);
    glVertex2f(-175, 175);
    glEnd();*/


    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.5f, 0.1f);
    glVertex2f(100, -60);
    glVertex2f(150, -60);
    glVertex2f(190, -125);
    glVertex2f(150, -190);
    glVertex2f(100, -190);
    glVertex2f(60, -125);
    glEnd();

    glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500); // Set the window's initial width & height
    glutInitWindowPosition(200, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("Quads & Polygons"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
