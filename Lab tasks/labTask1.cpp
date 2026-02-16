#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void display() {
    glClearColor(0.361, 0.361, 0.357, 1); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    gluOrtho2D(-250, 250, -250, 250);
    // Sets up a 2D orthographic projection
    // X-axis ranges from -250 to 250
    // Y-axis ranges from -250 to 250

    glLineWidth(2); // line thickness
    glBegin(GL_LINES); // Begins drawing line primitives

    // X-axis line (horizontal)
    glColor3f(0.059, 1, 0);  // Bright green color
    glVertex2f(-250, 0);     // Left endpoint
    glVertex2f(250, 0);      // Right endpoint

    // Y-axis line (vertical)
    glColor3f(0.059, 1, 0);  // Same bright green
    glVertex2f(0, -250);     // Bottom endpoint
    glVertex2f(0, 250);      // Top endpoint
    glEnd();


    // triangle in top left quadrant
    glBegin(GL_TRIANGLES);
    glColor3f(0.961, 0.4, 0.4);
    glVertex2f(-30, 50);
    glVertex2f(-230, 50);
    glVertex2f(-130, 223.205);
    glEnd(); //  marks the end of the line drawing


    // square in bottom left quadrant
    glBegin(GL_QUADS);
    glColor3f(0.208, 0.259, 0.61);
    glVertex2f(-230, -30);
    glVertex2f(-30, -30);
    glVertex2f(-30, -230);
    glVertex2f(-230, -230);
    glEnd();

    //polygon in top right corner
    glBegin(GL_POLYGON);
    glColor3f(0.914, 0.941, 0.306);
    glVertex2f(80, 200);
    glVertex2f(200, 200);
    glVertex2f(230, 150);
    glVertex2f(200, 100);
    glVertex2f(80, 100);
    glVertex2f(45, 150);
    glEnd();

    // triangle in bottom right quadrant
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0.518, 0);
    glVertex2f(175, -220);
    glVertex2f(75, -220);
    glVertex2f(120, -26.35);
    glEnd(); //  marks the end of the line drawing



    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    //argc = argument count (number of command-line arguments)
    //argv = argument vector (array of command-line argument strings)
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500); // Set the window's initial width & height
    glutInitWindowPosition(200, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task 1"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop (keeps the program alive)
    return 0;
}