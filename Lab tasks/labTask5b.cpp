#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void palestine(); // prototype

void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    gluOrtho2D(0, 660, 0, 480);
    // Sets up a 2D orthographic projection
    // X-axis ranges from 0 to 660
    // Y-axis ranges from 0 to 480

    palestine();

    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
}


void palestine() {
    // region A
    glBegin(GL_QUADS);
    glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
    glVertex2f(0, 480);
    glVertex2f(660, 480);
    glVertex2f(660, 320);
    glVertex2f(0, 320);
    glEnd();

    // region B
    glBegin(GL_QUADS);
    glColor3f(20 / 255.0f, 153 / 255.0f, 84 / 255.0f);
    glVertex2f(0, 160);
    glVertex2f(660, 160);
    glVertex2f(660, 0);
    glVertex2f(0, 0);
    glEnd();

    // region C
    glBegin(GL_TRIANGLES);
    glColor3f(228 / 255.0f, 49 / 255.0f, 43 / 255.0f);
    glVertex2f(0, 0);
    glVertex2f(220, 240);
    glVertex2f(0, 480);
    glEnd();
}




/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    //argc = argument count (number of command-line arguments)
    //argv = argument vector (array of command-line argument strings)
    glutInit(&argc, argv);
    glutInitWindowSize(660, 480); // Set the window's initial width & height
    glutInitWindowPosition(380, 150);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task 5b : Palestine flag"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop (keeps the program alive)
    return 0;
}