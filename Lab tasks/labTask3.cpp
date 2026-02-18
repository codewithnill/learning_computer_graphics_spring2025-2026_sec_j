#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void display() {
    glClearColor(0.361, 0.361, 0.357, 1); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    gluOrtho2D(0, 400, 0, 400);
    // Sets up a 2D orthographic projection
    // X-axis ranges from -250 to 250
    // Y-axis ranges from -250 to 250


    for () {
        for () {

        }
    }

    
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(-230, -30);
    glVertex2f(-30, -30);
    glVertex2f(-30, -230);
    glVertex2f(-230, -230);
    glEnd();





    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    //argc = argument count (number of command-line arguments)
    //argv = argument vector (array of command-line argument strings)
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500); // Set the window's initial width & height
    glutInitWindowPosition(200, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task 3"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop (keeps the program alive)
    return 0;
}