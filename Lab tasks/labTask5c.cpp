#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void southafrica(); // prototype

void display() {
    glClearColor(0 / 255.0f, 119 / 255.0f, 73 / 255.0f, 1);
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    gluOrtho2D(0, 450, 0, 300);
    // Sets up a 2D orthographic projection
    // X-axis ranges from 0 to 660
    // Y-axis ranges from 0 to 480

    southafrica();

    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
}


void southafrica() {


    // region A
    // glBegin(GL_QUADS);
    // glColor3f(1 / 255.0f, 1 / 255.0f, 1 / 255.0f);
    // glVertex2f(450 * xpx, 120 * ypx);
    // glVertex2f(234 * xpx, 120 * ypx);
    // glVertex2f(54 * xpx, 0 * ypx);
    // glVertex2f(450 * xpx, 0 * ypx);
    // glEnd();
}




/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    //argc = argument count (number of command-line arguments)
    //argv = argument vector (array of command-line argument strings)
    glutInit(&argc, argv);
    glutInitWindowSize(450, 300); // Set the window's initial width & height
    glutInitWindowPosition(430, 210);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task 5c : South Africa flag"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop (keeps the program alive)
    return 0;
}