#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    //gluOrtho2D(-250,250,-250,250);
    //gluOrtho2D(0,500,0,500);
    //gluOrtho2D(0,100,0,100);
    /**//* if we do not call gluOrtho2D function, by default coordinates will be within -1,0,1 range*/

    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(0, 0);

    glColor3f(0, 0, 1); // blue
    glVertex2f(.96, .96);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(-.5, -.5);

    glEnd();

    glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500); // Set the window's initial width & height
    glutInitWindowPosition(200, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("Sample Points"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
