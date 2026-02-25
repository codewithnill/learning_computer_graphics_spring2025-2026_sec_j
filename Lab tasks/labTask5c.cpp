#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void southafrica(); // prototype

void display() {
    glClearColor(0 / 255.0f, 119 / 255.0f, 73 / 255.0f, 1);
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    gluOrtho2D(0, 450, 0, 300);
    // Sets up a 2D orthographic projection
    // X-axis ranges from 0 to 450
    // Y-axis ranges from 0 to 300

    southafrica();

    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
}


void southafrica() {
    //region B
    glBegin(GL_QUADS);
    glColor3f(255 / 255.0f, 255 / 255.0f, 255 / 255.0f);
    glVertex2f(54, 0);
    glVertex2f(234, 120);
    glVertex2f(450, 120);
    glVertex2f(450, 0);
    glEnd();

    //region F
    glBegin(GL_QUADS);
    glColor3f(0 / 255.0f, 20 / 255.0f, 137 / 255.0f);
    glVertex2f(90, 0);
    glVertex2f(240, 100);
    glVertex2f(450, 100);
    glVertex2f(450, 0);
    glEnd();

    //region A
    glBegin(GL_QUADS);
    glColor3f(255 / 255.0f, 255 / 255.0f, 255 / 255.0f);
    glVertex2f(54, 300);
    glVertex2f(234, 180);
    glVertex2f(450, 180);
    glVertex2f(450, 300);
    glEnd();

    //region E
    glBegin(GL_QUADS);
    glColor3f(224 / 255.0f, 60 / 255.0f, 49 / 255.0f);
    glVertex2f(90, 300);
    glVertex2f(240, 200);
    glVertex2f(450, 200);
    glVertex2f(450, 300);
    glEnd();

    //region C
    glBegin(GL_TRIANGLES);
    glColor3f(255 / 255.0f, 184 / 255.0f, 28 / 255.0f);
    glVertex2f(0, 36);
    glVertex2f(171, 150);
    glVertex2f(0, 264);
    //glVertex2f(450, 300);
    glEnd();

    //region D
    glBegin(GL_TRIANGLES);
    glColor3f(0 / 255.0f, 0 / 255.0f, 0 / 255.0f);
    glVertex2f(0, 60);
    glVertex2f(135, 150);
    glVertex2f(0, 240);
    //glVertex2f(450, 300);
    glEnd();
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