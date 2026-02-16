#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void display() {
    glClearColor(0.361, 0.361, 0.357, 1); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    gluOrtho2D(0, 500, 0, 700);


    glLineWidth(1); // line thickness

    glBegin(GL_QUADS);
    glColor3f(0.58, 0, 0.827);
    glVertex2f(0, 0);
    glVertex2f(0, 100);
    glVertex2f(500, 100);
    glVertex2f(500, 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.294, 0, 0.51);
    glVertex2f(0, 100);
    glVertex2f(0, 200);
    glVertex2f(500, 200);
    glVertex2f(500, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex2f(0, 200);
    glVertex2f(0, 300);
    glVertex2f(500, 300);
    glVertex2f(500, 200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0, 300);
    glVertex2f(0, 400);
    glVertex2f(500, 400);
    glVertex2f(500, 300);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    glVertex2f(0, 400);
    glVertex2f(0, 500);
    glVertex2f(500, 500);
    glVertex2f(500, 400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0.498, 0);
    glVertex2f(0, 500);
    glVertex2f(0, 600);
    glVertex2f(500, 600);
    glVertex2f(500, 500);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(0, 600);
    glVertex2f(0, 700);
    glVertex2f(500, 700);
    glVertex2f(500, 600);
    glEnd();

    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    //argc = argument count (number of command-line arguments)
    //argv = argument vector (array of command-line argument strings)
    glutInit(&argc, argv);
    glutInitWindowSize(500, 700); // Set the window's initial width & height
    glutInitWindowPosition(400, 0);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task 2"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop (keeps the program alive)
    return 0;
}