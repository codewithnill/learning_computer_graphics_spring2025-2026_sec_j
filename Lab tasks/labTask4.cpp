#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void lines(); // prototype
void boxes(); // prototype

void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    gluOrtho2D(0, 660, 0, 520);
    // Sets up a 2D orthographic projection
    // X-axis ranges from 0 to 400
    // Y-axis ranges from 0 to 400

    boxes();
    lines();

    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
}

void boxes() {
    // top and bottom one row for black and yellow
    // from bottom to top
    for (int y = 40; y <= 460; y += 20) {
        // row no. (0-based from bottom)
        int rowNumber = (y - 40) / 20; // 0, 1, 2, ... 21
        for (int x = 160; x <= 480; x += 20) {

            // Only draw for specific rows
            if (rowNumber == 0 || rowNumber == 1 || rowNumber == 20 || rowNumber == 19) {
                glBegin(GL_QUADS);

                // bottom black row
                if (rowNumber == 0) {
                    glColor3f(0, 0, 0); // Black
                }
                // yellow row above bottom black
                else if (rowNumber == 1) {
                    glColor3f(0.969, 0.91, 0); // Yellow
                }
                // yellow row below top black
                else if (rowNumber == 19) {
                    glColor3f(0.969, 0.91, 0); // Yellow
                }
                // top black row
                else if (rowNumber == 20) {
                    glColor3f(0, 0, 0); // Black
                }

                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 20);
                glVertex2f(x, y + 20);
                glEnd();
            }

        }
    }






    // left and right one column for black and yellow
    // from left to right
    for (int x = 20; x <= 620; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 20) / 20;
        for (int y = 180;y <= 300; y += 20) {
            // Only draw for specific column
            if (colNumber == 0 || colNumber == 1 || colNumber == 29 || colNumber == 30) {
                glBegin(GL_QUADS);

                // left black column
                if (colNumber == 0) {
                    glColor3f(0, 0, 0); // Black
                }
                // left yellow column
                else if (colNumber == 1) {
                    glColor3f(0.969, 0.91, 0); // Yellow
                }
                // right yellow column
                else if (colNumber == 29) {
                    glColor3f(0.969, 0.91, 0); // Yellow
                }
                // right black column
                else if (colNumber == 30) {
                    glColor3f(0, 0, 0); // Black
                }

                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 20);
                glVertex2f(x, y + 20);
                glEnd();
            }
        }
    }





    // central 5 rows
    // from bottom to top
    for (int y = 200; y <= 280; y += 20) {
        // row no. (0-based from bottom)
        int rowNumber = (y - 200) / 20; // 0, 1, 2, ... 21
        for (int x = 60; x <= 580; x += 20) {

            // all rows within y
            if (rowNumber >= 0 && rowNumber <= 4) {
                glBegin(GL_QUADS);
                glColor3f(0, 0, 0); // Black
                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 20);
                glVertex2f(x, y + 20);
                glEnd();
            }

        }
    }







    // top left and right corners
    // 6 rows, 2 black outer, 2 yellow inner
    for (int row = 0; row < 6; row++) {
        int y = 320 + row * 20; // Starting from y=320, going up for 6 rows

        // left black
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0); // Black
        glVertex2f(40 + row * 20, y); // 40,320
        glVertex2f(60 + row * 20, y); // 60,320
        glVertex2f(60 + row * 20, y + 20); // 60,340
        glVertex2f(40 + row * 20, y + 20); // 40, 340
        glEnd();

        // left yellow
        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0); // Yellow
        glVertex2f(60 + row * 20, y); // 
        glVertex2f(80 + row * 20, y);
        glVertex2f(80 + row * 20, y + 20);
        glVertex2f(60 + row * 20, y + 20);
        glEnd();

        // right yellow
        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0); // Yellow
        glVertex2f(580 - row * 20, y);
        glVertex2f(600 - row * 20, y);
        glVertex2f(600 - row * 20, y + 20);
        glVertex2f(580 - row * 20, y + 20);
        glEnd();

        // right black
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0); // Black
        glVertex2f(600 - row * 20, y);
        glVertex2f(620 - row * 20, y);
        glVertex2f(620 - row * 20, y + 20);
        glVertex2f(600 - row * 20, y + 20);
        glEnd();
    }






    // bottom left and right corners with zigzag pattern
    // 6 rows, 2 black outer, 2 yellow inner
    for (int row = 0; row < 6; row++) {
        int y = 60 + row * 20; // Starting from y=40, going up for 5 rows

        // Bottom-Left zigzag
        // Black outer
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0); // Black
        glVertex2f(140 - row * 20, y);
        glVertex2f(160 - row * 20, y);
        glVertex2f(160 - row * 20, y + 20);
        glVertex2f(140 - row * 20, y + 20);
        glEnd();

        // Yellow inner
        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0); // Yellow
        glVertex2f(160 - row * 20, y);
        glVertex2f(180 - row * 20, y);
        glVertex2f(180 - row * 20, y + 20);
        glVertex2f(160 - row * 20, y + 20);
        glEnd();

        // Bottom-Right zigzag
        // Yellow inner
        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0); // Yellow
        glVertex2f(480 + row * 20, y);
        glVertex2f(500 + row * 20, y);
        glVertex2f(500 + row * 20, y + 20);
        glVertex2f(480 + row * 20, y + 20);
        glEnd();

        // Black outer
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0); // Black
        glVertex2f(500 + row * 20, y);
        glVertex2f(520 + row * 20, y);
        glVertex2f(520 + row * 20, y + 20);
        glVertex2f(500 + row * 20, y + 20);
        glEnd();
    }





    // from left to right m1
    for (int x = 160; x <= 480; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 160) / 20;
        int y = 400;
        // Only draw for specific column
        if (colNumber != 6 && colNumber != 10) {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }





    // from left to right m2
    for (int x = 140; x <= 500; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 140) / 20;
        int y = 380;
        // Only draw for specific column
        if ((colNumber >= 1 && colNumber <= 3) || (colNumber >= 7 && colNumber <= 11) || (colNumber >= 15 && colNumber <= 17)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }



    // from left to right m3
    for (int x = 120; x <= 520; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 120) / 20;
        int y = 360;
        // Only draw for specific column
        if ((colNumber >= 1 && colNumber <= 3) || (colNumber >= 8 && colNumber <= 12) || (colNumber >= 17 && colNumber <= 19)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }





    // from left to right m4
    for (int x = 100; x <= 540; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 100) / 20;
        int y = 340;
        // Only draw for specific column
        if ((colNumber >= 1 && colNumber <= 4) || (colNumber >= 9 && colNumber <= 13) || (colNumber >= 18 && colNumber <= 21)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }



    // from left to right m5
    for (int x = 80; x <= 560; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 80) / 20;
        int y = 320;
        // Only draw for specific column
        if ((colNumber >= 1 && colNumber <= 5) || (colNumber >= 10 && colNumber <= 14) || (colNumber >= 19 && colNumber <= 23)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }





    // from left to right m6
    for (int x = 60; x <= 580; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 60) / 20;
        int y = 300;
        // Only draw for specific column
        if ((colNumber >= 1 && colNumber <= 7) || (colNumber >= 10 && colNumber <= 16) || (colNumber >= 19 && colNumber <= 25)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }





    // from left to right m7
    for (int x = 60; x <= 580; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 60) / 20;
        int y = 180;
        // Only draw for specific column
        if ((colNumber >= 1 && colNumber <= 25)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }






    // from left to right m8
    for (int x = 80; x <= 560; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 80) / 20;
        int y = 160;
        // Only draw for specific column
        if ((colNumber >= 1 && colNumber <= 23)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }






    // from left to right m9
    for (int x = 100; x <= 540; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 100) / 20;
        int y = 140;
        // Only draw for specific column
        if ((colNumber >= 1 && colNumber <= 7) || (colNumber >= 9 && colNumber <= 13) || (colNumber >= 15 && colNumber <= 21)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }





    // from left to right m10
    for (int x = 120; x <= 520; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 120) / 20;
        int y = 120;
        // Only draw for specific column
        if ((colNumber >= 1 && colNumber <= 5) || (colNumber >= 9 && colNumber <= 11) || (colNumber >= 15 && colNumber <= 19)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }






    // from left to right m11
    for (int x = 140; x <= 500; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 140) / 20;
        int y = 100;
        // Only draw for specific column
        if ((colNumber >= 1 && colNumber <= 3) || (colNumber >= 8 && colNumber <= 10) || (colNumber >= 15 && colNumber <= 17)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }





    // from left to right m12
    for (int x = 160; x <= 480; x += 20) {
        // col no. (0-based from left)
        int colNumber = (x - 160) / 20;
        int y = 80;
        // Only draw for specific column
        if (colNumber == 2 || colNumber == 8 || colNumber == 14) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }

        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }
}


void lines() {
    // 20 height and width box using lines

    for (int y = 0;y < 520;y += 20) { // horizontal lines (26 box)
        glBegin(GL_LINES);
        glColor3f(0.969, 0, 0.373);
        glVertex2f(0, y);
        glVertex2f(660, y);
        glEnd();
    }

    for (int x = 20;x < 660;x += 20) { // vertical lines (33 box)
        glBegin(GL_LINES);
        glColor3f(0.969, 0, 0.373);
        glVertex2f(x, 0);
        glVertex2f(x, 660);
        glEnd();
    }
}






/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    //argc = argument count (number of command-line arguments)
    //argv = argument vector (array of command-line argument strings)
    glutInit(&argc, argv);
    glutInitWindowSize(660, 520); // Set the window's initial width & height
    glutInitWindowPosition(350, 110);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task 4"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop (keeps the program alive)
    return 0;
}