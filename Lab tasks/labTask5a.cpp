#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void norway(); // prototype

void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    gluOrtho2D(0, 660, 0, 480);
    // Sets up a 2D orthographic projection
    // X-axis ranges from 0 to 660
    // Y-axis ranges from 0 to 480

    norway();

    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
}


void norway() {
    // region B
    glBegin(GL_QUADS);
    glColor3f(186 / 255.0f, 12 / 255.0f, 47 / 255.0f);
    glVertex2f(0, 480);
    glVertex2f(180, 480);
    glVertex2f(180, 300);
    glVertex2f(0, 300);
    glEnd();

    // glBegin(GL_POLYGON);
    // glColor3f(0.3f, 0.5f, 0.1f);
    // glVertex2f(180, 480);
    // glVertex2f(210, 480);
    // glVertex2f(210, 270);
    // glVertex2f(0, 270);
    // glVertex2f(0, 300);
    // glVertex2f(180, 300);
    // glEnd();

    // region D
    glBegin(GL_QUADS);
    glColor3f(186 / 255.0f, 12 / 255.0f, 47 / 255.0f);
    glVertex2f(300, 480);
    glVertex2f(660, 480);
    glVertex2f(660, 300);
    glVertex2f(300, 300);
    glEnd();

    // region H
    glBegin(GL_QUADS);
    glColor3f(186 / 255.0f, 12 / 255.0f, 47 / 255.0f);
    glVertex2f(300, 180);
    glVertex2f(660, 180);
    glVertex2f(660, 0);
    glVertex2f(300, 0);
    glEnd();

    // region F
    glBegin(GL_QUADS);
    glColor3f(186 / 255.0f, 12 / 255.0f, 47 / 255.0f);
    glVertex2f(0, 180);
    glVertex2f(180, 180);
    glVertex2f(180, 0);
    glVertex2f(0, 0);
    glEnd();

    // region I
    // glBegin(GL_QUADS);
    // glColor3f(186 / 255.0f, 12 / 255.0f, 47 / 255.0f);
    // glVertex2f(0, 180);
    // glVertex2f(180, 180);
    // glVertex2f(180, 0);
    // glVertex2f(0, 0);
    // glEnd();


}




/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    //argc = argument count (number of command-line arguments)
    //argv = argument vector (array of command-line argument strings)
    glutInit(&argc, argv);
    // from 440x320 
    // 1.5x
    // 30 pixels
    glutInitWindowSize(660, 480); // Set the window's initial width & height
    glutInitWindowPosition(380, 150);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task 5a : Norway flag"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop (keeps the program alive)
    return 0;
}