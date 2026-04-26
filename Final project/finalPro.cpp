#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h


float boatX = 0.0f;  // controls boat's horizontal position
float fishX = 0.0f;  // fish group position controller
int fishColorIndex = 0; // tracks current color (0, 1, or 2)


void water(); // prototype
void sky(); // prototype
void fishes(); // prototype
void streets(); // prototype
void boat(); // prototype











void update(int value) {
    boatX -= 0.8;  // Move left 

    // Reset position when boat goes too far left
    if (boatX < -250) {
        boatX = 250 + 200;  // Reset to right side
    }



    fishX -= 0.5;  // Move fishes left (slower than boat)

    // When fishes go off screen, reset and change color
    if (fishX < -350) {
        fishX = 230;  // Reset to right side
        fishColorIndex = (fishColorIndex + 1) % 3;  // Cycle through 0,1,2
    }



    glutPostRedisplay();  // Redraw the scene
    glutTimerFunc(8, update, 0);  // Call again 
}







void display() {
    glClearColor(1, 1, 1, 1); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    // Set up projection matrix
    glMatrixMode(GL_PROJECTION);  // Switch to projection matrix
    glLoadIdentity();             // Reset the matrix
    gluOrtho2D(-250, 250, -250, 250);
    // Sets up a 2D orthographic projection
    // X-axis ranges from -250 to 250
    // Y-axis ranges from -250 to 250

    glMatrixMode(GL_MODELVIEW);   // Switch back to modelview matrix
    glLoadIdentity();             // Reset modelview matrix







    sky();
    water();
    fishes();
    streets();
    boat();






    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
}










void streets() {
    glLoadIdentity(); // stops the street from translating to the left


    // top separator
    glColor3f(0.5, 0.5, 0.5);  // Gray color for the separator
    glBegin(GL_QUADS);
    glVertex2f(-250, -75);  // Top-left corner of separator
    glVertex2f(250, -75);   // Top-right corner of separator
    glVertex2f(250, -80);   // Bottom-right corner of separator
    glVertex2f(-250, -80);  // Bottom-left corner of separator
    glEnd();



    glColor3f(0.169, 0.169, 0.169);  // Gray color
    glBegin(GL_QUADS);
    glVertex2f(-250, -80); // Top-left corner
    glVertex2f(250, -80); // Top-right corner
    glVertex2f(250, -150); // Bottom-right corner 
    glVertex2f(-250, -150); // Bottom-left corner
    glEnd();

    // dashed yellow center line (in the middle of the street)
    glLineWidth(4);  // Thick line
    glColor3f(1, 0.839, 0);  // Bright yellow color

    // Create dashes: 30 units long, with 20 unit gaps
    // Starting from -240 to 240 (to avoid partial dashes at edges)
    for (float x = -240; x <= 240; x += 50) { // 50 units per dash+gap cycle
        glBegin(GL_LINES);
        glVertex2f(x, -115);      // Start of dash
        glVertex2f(x + 30, -115); // End of dash
        glEnd();
    }
}

void sky() {
    glColor3f(0.529, 0.808, 0.922);  // Light blue color
    glBegin(GL_QUADS);     // rectangle (quadrilateral)
    glVertex2f(250, 250);  // Top-right corner (highest possible)
    glVertex2f(-250, 250); // Top-left corner (highest possible)
    glVertex2f(-250, 150); // Bottom-left corner 
    glVertex2f(250, 150);  // Bottom-right corner 
    glEnd();
}

void water() {
    // adding a separator between street bottom and water top
    glColor3f(0.5, 0.5, 0.5);  // Gray color for the separator
    glBegin(GL_QUADS);
    glVertex2f(-250, -150);  // Top-left corner of separator
    glVertex2f(250, -150);   // Top-right corner of separator
    glVertex2f(250, -155);   // Bottom-right corner of separator
    glVertex2f(-250, -155);  // Bottom-left corner of separator
    glEnd();


    glColor3f(0.106, 0.224, 0.749);  // Bright blue color
    glBegin(GL_QUADS);       // rectangle (quadrilateral)
    glVertex2f(250, -155);   // Top-right corner
    glVertex2f(-250, -155);  // Top-left corner
    glVertex2f(-250, -250);  // Bottom-left corner (lowest possible)
    glVertex2f(250, -250);   // Bottom-right corner (lowest possible)
    glEnd();
}



void boat() {
    glPushMatrix();
    glTranslatef(boatX, 0.0f, 0.0f);  // moves boat left

    // lower parts
    // quad N O P Q
    glColor3f(0.902, 0.902, 0.902);  // Light gray color
    glBegin(GL_QUADS);
    glVertex2f(-205, -192); // N: Top-left corner
    glVertex2f(-65, -192);  // O: Top-right corner
    glVertex2f(-72, -228);  // P: Bottom-right corner
    glVertex2f(-165, -228); // Q: Bottom-left corner
    glEnd();

    // two quad paint in boat body
    // 1st quad B1 C1 E1 D1
    glColor3f(0.929, 0, 0);  // Red color
    glBegin(GL_QUADS);
    glVertex2f(-187, -208); // B1: Top-left corner
    glVertex2f(-68, -208);  // C1: Top-right corner
    glVertex2f(-69, -212);  // E1: Bottom-right corner
    glVertex2f(-182, -212); // D1: Bottom-left corner
    glEnd();

    // 2nd quad D1 E1 G1 F1
    glColor3f(0, 0.071, 0.659);  // Blue color
    glBegin(GL_QUADS);
    glVertex2f(-182, -212); // D1: Top-left corner
    glVertex2f(-69, -212);  // E1: Top-right corner
    glVertex2f(-69, -216);  // G1: Bottom-right corner
    glVertex2f(-178, -216); // F1: Bottom-left corner
    glEnd();









    // upper part
    // quad S T U R
    glColor3f(0.741, 0.741, 0.741);  // Light gray color
    glBegin(GL_QUADS);
    glVertex2f(-145, -168); // S: Top-left corner
    glVertex2f(-85, -180);  // T: Top-right corner
    glVertex2f(-85, -192);  // U: Bottom-right corner
    glVertex2f(-174, -192); // R: Bottom-left corner
    glEnd();


    // window quad Z A1 W V
    glColor3f(0.208, 0.416, 0.702); // light blue color
    glBegin(GL_QUADS);
    glVertex2f(-142, -174); // Z: Top-left corner
    glVertex2f(-88, -182);  // A1: Top-right corner
    glVertex2f(-88, -188);  // W: Bottom-right corner
    glVertex2f(-165, -188); // V: Bottom-left corner
    glEnd();






    glPopMatrix();

}






// Function to set fish color based on index
void setFishColor(int colorIndex) {
    switch (colorIndex) {
    case 0:  // Color 1: Orange
        glColor3f(0.969, 0.376, 0);
        break;
    case 1:  // Color 2: Green
        glColor3f(0.004, 0.969, 0);
        break;
    case 2:  // Color 3: Pink
        glColor3f(0.969, 0, 0.467);
        break;
    }
}





void fishes() {

    glPushMatrix();
    glTranslatef(fishX, 0.0f, 0.0f);




    // leader fish
    // body quad H I K J
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_QUADS);
    glVertex2f(44, -201);   // H: Left
    glVertex2f(50, -197);   // I: Top
    glVertex2f(56, -200);   // K: Right
    glVertex2f(50, -204);   // J: Bottom
    glEnd();

    // tail triangle K L M
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_TRIANGLES);
    glVertex2f(56, -200);   // K: Left
    glVertex2f(60, -197);   // L: Top
    glVertex2f(60, -205);   // M: Bottom
    glEnd();




    // Top fish 1
    // body quad H1 I1 K1 J1
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_QUADS);
    glVertex2f(54, -190);   // H1: Left
    glVertex2f(60, -186);   // I1: Top
    glVertex2f(66, -190);   // K1: Right
    glVertex2f(60, -194);   // J1: Bottom
    glEnd();

    // tail triangle K1 L1 M1
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_TRIANGLES);
    glVertex2f(66, -190);   // K1: Left
    glVertex2f(70, -186);   // L1: Top
    glVertex2f(70, -194);   // M1: Bottom
    glEnd();



    // Top fish 2
    // body quad H3 I3 K3 J3
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_QUADS);
    glVertex2f(72, -190);   // H3: Left
    glVertex2f(78, -186);   // I3: Top
    glVertex2f(84, -189);   // K3: Right
    glVertex2f(78, -194);   // J3: Bottom
    glEnd();

    // tail triangle K3 L3 M3
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_TRIANGLES);
    glVertex2f(84, -189);   // K3: Left
    glVertex2f(88, -186);   // L3: Top
    glVertex2f(89, -194);   // M3: Bottom
    glEnd();





    // Middle fish 1
    // body quad H5 I5 K5 J5
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_QUADS);
    glVertex2f(62, -201);   // H5: Left
    glVertex2f(68, -197);   // I5: Top
    glVertex2f(74, -201);   // K5: Right
    glVertex2f(68, -204);   // J5: Bottom
    glEnd();

    // tail triangle K5 L5 M5
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_TRIANGLES);
    glVertex2f(74, -201);   // K5: Left
    glVertex2f(78, -197);   // L5: Top
    glVertex2f(78, -205);   // M5: Bottom
    glEnd();




    // Middle fish 3
    // body quad H4 I4 K4 J4
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_QUADS);
    glVertex2f(80, -201);   // H4: Left
    glVertex2f(86, -197);   // I4: Top
    glVertex2f(92, -201);   // K4: Right
    glVertex2f(86, -205);   // J4: Bottom
    glEnd();

    // tail triangle K5 L5 M5
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_TRIANGLES);
    glVertex2f(92, -201);   // K4: Left
    glVertex2f(96, -197);   // L4: Top
    glVertex2f(96, -205);   // M4: Bottom
    glEnd();




    // Bottom fish 1
    // body quad H2 I2 K2 J2
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_QUADS);
    glVertex2f(54, -211);   // H2: Left
    glVertex2f(60, -207);   // I2: Top
    glVertex2f(66, -211);   // K2: Right
    glVertex2f(60, -215);   // J2: Bottom
    glEnd();

    // tail triangle K1 L1 M1
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_TRIANGLES);
    glVertex2f(66, -211);   // K2: Left
    glVertex2f(70, -207);   // L2: Top
    glVertex2f(70, -215);   // M2: Bottom
    glEnd();




    // Bottom fish 2
    // body quad H6 I6 K6 J6
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_QUADS);
    glVertex2f(72, -211);   // H6: Left
    glVertex2f(78, -207);   // I6: Top
    glVertex2f(84, -211);   // K6: Right
    glVertex2f(78, -214);   // J6: Bottom
    glEnd();

    // tail triangle K6 L6 M6
    // glColor3f(0.208, 0.416, 0.702); // light blue color
    setFishColor(fishColorIndex);
    glBegin(GL_TRIANGLES);
    glVertex2f(84, -211);   // K6: Left
    glVertex2f(88, -207);   // L6: Top
    glVertex2f(89, -215);   // M6: Bottom
    glEnd();


}






/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    //argc = argument count (number of command-line arguments)
    //argv = argument vector (array of command-line argument strings)
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 600); // Set the window's initial width & height
    glutInitWindowPosition(70, 70);  // Set the window's initial position according to the monitor
    glutCreateWindow("Scene"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint

    glutTimerFunc(16, update, 0);

    glutMainLoop(); // Enter the event-processing loop (keeps the program alive)
    return 0;
}