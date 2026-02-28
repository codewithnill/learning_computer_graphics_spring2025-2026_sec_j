#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void togo(); // prototype

void display() {
    glClearColor(255 / 255.0f, 206 / 255.0f, 0 / 255.0f, 1);
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    gluOrtho2D(0, 660, 0, 480);
    // Sets up a 2D orthographic projection
    // X-axis ranges from 0 to 660
    // Y-axis ranges from 0 to 480

    togo();

    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
}


void togo() {
    // region A
    glBegin(GL_QUADS);
    glColor3f(0 / 255.0f, 106 / 255.0f, 74 / 255.0f);
    glVertex2f(0, 384);
    glVertex2f(0, 480);
    glVertex2f(660, 480);
    glVertex2f(660, 384);
    glEnd();

    // region B
    glBegin(GL_QUADS);
    glColor3f(0 / 255.0f, 106 / 255.0f, 74 / 255.0f);
    glVertex2f(0, 192);
    glVertex2f(0, 288);
    glVertex2f(660, 288);
    glVertex2f(660, 192);
    glEnd();

    // region C
    glBegin(GL_QUADS);
    glColor3f(0 / 255.0f, 106 / 255.0f, 74 / 255.0f);
    glVertex2f(0, 0);
    glVertex2f(0, 96);
    glVertex2f(660, 96);
    glVertex2f(660, 0);
    glEnd();

    // region D
    glBegin(GL_QUADS);
    glColor3f(210 / 255.0f, 16 / 255.0f, 52 / 255.0f);
    glVertex2f(0, 192);
    glVertex2f(0, 480);
    glVertex2f(264, 480);
    glVertex2f(264, 192);
    glEnd();

    //region E
    glBegin(GL_TRIANGLES);
    glColor3f(255 / 255.0f, 255 / 255.0f, 255 / 255.0f);
    glVertex2f(70, 380);
    glVertex2f(190, 380);
    glVertex2f(135, 290);
    glEnd();

    //region E
    // glBegin(GL_QUADS);
    // glColor3f(255 / 255.0f, 255 / 255.0f, 255 / 255.0f);
    // glVertex2f(135, 450);
    // glVertex2f(90, 250);
    // glVertex2f(135, 290);
    // glVertex2f(170, 250);
    // glEnd();

    // region E
    glBegin(GL_TRIANGLES);
    glColor3f(255 / 255.0f, 255 / 255.0f, 255 / 255.0f);
    glVertex2f(135, 450);
    glVertex2f(90, 250);
    glVertex2f(135, 290);
    glEnd();


    // region E
    glBegin(GL_TRIANGLES);
    glColor3f(255 / 255.0f, 255 / 255.0f, 255 / 255.0f);
    glVertex2f(135, 450);
    glVertex2f(135, 290);
    glVertex2f(170, 250);
    glEnd();






}




/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    //argc = argument count (number of command-line arguments)
    //argv = argument vector (array of command-line argument strings)
    glutInit(&argc, argv);
    glutInitWindowSize(660, 480); // Set the window's initial width & height
    glutInitWindowPosition(380, 150);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task 5d : Togo flag"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop (keeps the program alive)
    return 0;
}