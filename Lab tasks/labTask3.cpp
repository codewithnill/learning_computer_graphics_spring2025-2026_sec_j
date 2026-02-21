#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void chessBoard(); // prototype

void display() {
    glClearColor(0.361, 0.361, 0.357, 1);
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    gluOrtho2D(0, 400, 0, 400);
    // Sets up a 2D orthographic projection
    // X-axis ranges from 0 to 400
    // Y-axis ranges from 0 to 400

    chessBoard();

    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
}


void chessBoard() {
    // 50x50 box
    for (int y = 0;y < 400;y += 50) { // for y axis going up
        for (int x = 0;x < 400;x += 50) { // for x axis going right

            glBegin(GL_QUADS);
            bool isWhite = ((x / 50 + y / 50) % 2 == 0); // odd even calculation
            // odd = white 
            // even = black
            if (isWhite == true) {
                glColor3f(1, 1, 1);
            }
            else {
                glColor3f(0, 0, 0);
            }

            glVertex2f(x, y);
            glVertex2f(x + 50, y);
            glVertex2f(x + 50, y + 50);
            glVertex2f(x, y + 50);
            glEnd();
        }
    }
}

// Row 0 (y=0):
// Column 0 (x=0): (0 + 0) % 2 = 0 = White
// Column 1 (x=50): (1 + 0) % 2 = 1 = Black
// Column 2 (x=100): (2 + 0) % 2 = 0 = White
// Column 3 (x=150): (3 + 0) % 2 = 1 = Black
// Column 4 (x=200): (4 + 0) % 2 = 0 = White
// Column 5 (x=250): (5 + 0) % 2 = 1 = Black
// Column 6 (x=300): (6 + 0) % 2 = 0 = White
// Column 7 (x=350): (7 + 0) % 2 = 1 = Black

// Row 1 (y=1):
// Column 0 (x=0): (0 + 1) % 2 = 1 = Black
// Column 1 (x=50): (1 + 1) % 2 = 0 = White
// Column 2 (x=100): (2 + 1) % 2 = 1 = Black
// Column 3 (x=150): (3 + 1) % 2 = 0 = White


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    //argc = argument count (number of command-line arguments)
    //argv = argument vector (array of command-line argument strings)
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400); // Set the window's initial width & height
    glutInitWindowPosition(500, 170);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task 3"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop (keeps the program alive)
    return 0;
}