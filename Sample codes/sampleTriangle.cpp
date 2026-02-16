#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void display() {
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    gluOrtho2D(0, 500, 0, 500);

    glBegin(GL_TRIANGLES);
    glColor3f(.2f, 0.3f, 1);
    glVertex2f(0, 0);
    glVertex2f(150, 0);
    glVertex2f(75, 100);

    glColor3f(1.0f, 0.2f, 0.3f);
    glVertex2f(350, 400);
    glVertex2f(500, 400);
    glVertex2f(425, 500);

    glEnd();

    glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500); // Set the window's initial width & height
    glutInitWindowPosition(200, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("Sample Triangles"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
