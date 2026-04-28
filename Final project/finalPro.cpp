#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h


float boatX = 0.0f;  // controls boat's horizontal position
float fishX = 0.0f;  // fish group position controller
int fishColorIndex = 0; // tracks current color (0, 1, or 2)

// prototype
void water();
void sky();
void buildings();
void fishes();
void streets();
void boat();
void grass();
void railway();











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
    buildings();
    grass();
    railway();
    water();
    fishes();
    streets();
    boat();






    glFlush(); // Render now (forces all OpenGL commands to execute immediately)
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



void grass() {
    glColor3f(0, 0.412, 0.008);  // Green grass
    glBegin(GL_QUADS);
    glVertex2f(-250, -20);  // Z1: Top-left corner of separator
    glVertex2f(250, -20);   // A2: Top-right corner of separator
    glVertex2f(250, -42);   // W1: Bottom-right corner of separator
    glVertex2f(-250, -42);  // V1: Bottom-left corner of separator
    glEnd();


}


void railway() {
    // background (soil)
    glColor3f(0.55, 0.28, 0.18); // Clay Soil (red/orange):
    glBegin(GL_QUADS);
    glVertex2f(-250, -47);   // Top-left corner
    glVertex2f(250, -47);    // Top-right corner
    glVertex2f(250, -75);    // Bottom-right corner
    glVertex2f(-250, -75);   // Bottom-left corner
    glEnd();




    // top separator
    glColor3f(0.5, 0.5, 0.5);  // Gray color for separator
    glBegin(GL_QUADS);
    glVertex2f(-250, -42);   // Top-left corner
    glVertex2f(250, -42);    // Top-right corner
    glVertex2f(250, -47);    // Bottom-right corner
    glVertex2f(-250, -47);   // Bottom-left corner
    glEnd();


    glColor3f(0.65, 0.35, 0.30); // cherry wood

    // Draw tilted woods from left to right
    for (float x = -240; x <= 240; x += 20) {
        glBegin(GL_QUADS);
        glVertex2f(x, -51);                // Top-left 
        glVertex2f(x + 7, -51);            // Top-right 
        glVertex2f(x + 7 - 10, -72);       // Bottom-right 
        glVertex2f(x - 10, -72);           // Bottom-left
        glEnd();
    }


    // rail lines
    glLineWidth(4);
    glColor3f(0.75, 0.75, 0.80); // Silver/gray color for rails

    // Upper rail 
    glBegin(GL_LINES);
    glVertex2f(-250, -56);   // Left end
    glVertex2f(250, -56);    // Right end
    glEnd();

    // Lower rail
    glBegin(GL_LINES);
    glVertex2f(-250, -67);   // Left end
    glVertex2f(250, -67);    // Right end
    glEnd();
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
    glVertex2f(-188, -207); // B1: Top-left corner
    glVertex2f(-68, -207);  // C1: Top-right corner
    glVertex2f(-69, -212);  // E1: Bottom-right corner
    glVertex2f(-182, -212); // D1: Bottom-left corner
    glEnd();

    // 2nd quad D1 E1 G1 F1
    glColor3f(0, 0.071, 0.659);  // Blue color
    glBegin(GL_QUADS);
    glVertex2f(-182, -212); // D1: Top-left corner
    glVertex2f(-69, -212);  // E1: Top-right corner
    glVertex2f(-70, -218);  // G1: Bottom-right corner
    glVertex2f(-176, -218); // F1: Bottom-left corner
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

    // 2 lines in window

    // Z B2
    glLineWidth(6);
    glColor3f(0.741, 0.741, 0.741);
    glBegin(GL_LINES);
    glVertex2f(-142, -174);
    glVertex2f(-143, -188);
    glEnd();

    // D2 C2
    glLineWidth(6);
    glColor3f(0.741, 0.741, 0.741);
    glBegin(GL_LINES);
    glVertex2f(-120, -178);
    glVertex2f(-121, -188);
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


void buildings() {
    // from left to right

    // building 1
    // E4 N2 F2 G2
    glColor3f(0.86, 0.08, 0.24); // Crimson Red
    glBegin(GL_QUADS);
    glVertex2f(-240, -20);  // E4: Bottom left
    glVertex2f(-240, 100); // N2: Top left
    glVertex2f(-160, 100); // F2: Top right
    glVertex2f(-160, -20);  // G2: Bottom right 
    glEnd();

    // top W2 Z2 B3 A3
    glColor3f(0.55, 0.00, 0.00); // Dark Red
    glBegin(GL_QUADS);
    glVertex2f(-244, 100);  // W2: Bottom left
    glVertex2f(-244, 106); // Z2: Top left
    glVertex2f(-156, 106); // B3: Top right
    glVertex2f(-156, 100);  // A3: Bottom right 
    glEnd();


    //door
    // Q2 D3 N3 P2
    glColor3f(0.55, 0.00, 0.00); // Pine/Natural Wood
    glBegin(GL_QUADS);     // 
    glVertex2f(-234, -20);  // Q2: Bottom left
    glVertex2f(-234, 15); // O2: Top left
    glVertex2f(-220, 15); // R2: Top right
    glVertex2f(-220, -20);  // P2: Bottom right 
    glEnd();

    // door line D3 N3
    // glLineWidth(1);
    // glColor3f(0.45, 0.47, 0.50);

    // glBegin(GL_LINES);
    // glVertex2f(-227, 15);   // Up
    // glVertex2f(-227, -20);    // Down
    // glEnd();

    // door window
    // V4 D3 N3 W4
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-232, -5);  // V4: Bottom left
    glVertex2f(-232, 11); // D3: Top left
    glVertex2f(-228, 11); // N3: Top right
    glVertex2f(-228, -5);  // W4: Bottom right 
    glEnd();



    // ground floor window
    // U2 S2 T2 V2
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-210, 0);  // U2: Bottom left
    glVertex2f(-210, 12); // S2: Top left
    glVertex2f(-170, 12); // T2: Top right
    glVertex2f(-170, 0);  // V2: Bottom right 
    glEnd();


    // rest of the windows
    // top to bottom left to right
    // T3 U3 C4 D4
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-234, 80);  // T3: Bottom left
    glVertex2f(-234, 92); // U3: Top left
    glVertex2f(-218, 92); // C4: Top right
    glVertex2f(-218, 80);  // D4: Bottom right 
    glEnd();


    // T4 R4 S4 U4
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-208, 80);  // T4: Bottom left
    glVertex2f(-208, 92); // R4: Top left
    glVertex2f(-192, 92); // S4: Top right
    glVertex2f(-192, 80);  // U4: Bottom right 
    glEnd();


    // O4 N4 F4 G4
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-182, 80);  // O4: Bottom left
    glVertex2f(-182, 92); // N4: Top left
    glVertex2f(-166, 92); // F4: Top right
    glVertex2f(-166, 80);  // G4: Bottom right 
    glEnd();

    // T7 U7 C6 D6
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-234, 55);  // T7: Bottom left
    glVertex2f(-234, 67); // U7: Top left
    glVertex2f(-218, 67); // C6: Top right
    glVertex2f(-218, 55);  // D6: Bottom right 
    glEnd();


    // T8 R6 S6 U8
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-208, 55);  // T8: Bottom left
    glVertex2f(-208, 67); // R6: Top left
    glVertex2f(-192, 67); // S6: Top right
    glVertex2f(-192, 55);  // U8: Bottom right 
    glEnd();

    // O6 N6 F6 G6
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-182, 55);  // O6: Bottom left
    glVertex2f(-182, 67); // N6: Top left
    glVertex2f(-166, 67); // F6: Top right
    glVertex2f(-166, 55);  // G6: Bottom right 
    glEnd();

    // T5 U5 C5 D5
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-234, 30);  // T5: Bottom left
    glVertex2f(-234, 42); // U5: Top left
    glVertex2f(-218, 42); // C5: Top right
    glVertex2f(-218, 30);  // D5: Bottom right 
    glEnd();

    // T6 R5 S5 U6
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-208, 30);  // T6: Bottom left
    glVertex2f(-208, 42); // R5: Top left
    glVertex2f(-192, 42); // S5: Top right
    glVertex2f(-192, 30);  // U6: Bottom right 
    glEnd();

    // O5 N5 F5 G5
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-182, 30);  // O5: Bottom left
    glVertex2f(-182, 42); // N5: Top left
    glVertex2f(-166, 42); // F5: Top right
    glVertex2f(-166, 30);  // G6: Bottom right 
    glEnd();







    // building 2
    // Z4 A5 B5 E5
    glColor3f(0.18, 0.31, 0.65); // Sapphire
    glBegin(GL_QUADS);
    glVertex2f(-151, -20);  // Z4: Bottom left
    glVertex2f(-151, 120); // A5: Top left
    glVertex2f(9, 120); // B5: Top right
    glVertex2f(9, -20);  // E5: Bottom right 
    glEnd();

    // top P5 Q5 W5 V5
    glColor3f(0.00, 0.20, 0.40); // Prussian Blue
    glBegin(GL_QUADS);
    glVertex2f(-155, 120);  // P5: Bottom left
    glVertex2f(-155, 127); // Q5: Top left
    glVertex2f(14, 127); // W5: Top right
    glVertex2f(14, 120);  // V5: Bottom right 
    glEnd();



    //door
    // I8 J8 K8 L8
    glColor3f(0.00, 0.20, 0.40); // Prussian Blue
    glBegin(GL_QUADS);     // 
    glVertex2f(-145, -20);  // I8: Bottom left
    glVertex2f(-145, 15); // J8: Top left
    glVertex2f(-131, 15); // K8: Top right
    glVertex2f(-131, -20);  // L8: Bottom right 
    glEnd();


    // door window
    // V4 D3 N3 W4
    // glColor3f(0.90, 0.92, 0.95); // Lake Water
    // glBegin(GL_QUADS);     // 
    // glVertex2f(-232, -5);  // V4: Bottom left
    // glVertex2f(-232, 11); // D3: Top left
    // glVertex2f(-228, 11); // N3: Top right
    // glVertex2f(-228, -5);  // W4: Bottom right 
    // glEnd();




    // triangles

    // Z5 Q6 A6
    glColor3f(0.00, 0.20, 0.40); // Prussian Blue
    glBegin(GL_TRIANGLES);
    glVertex2f(-151, 127);  // Z5: Bottom left
    glVertex2f(-131, 179); // Q6: Top
    glVertex2f(-111, 127); // A6: Bottom right
    glEnd();


    // A6 V6 B6
    glColor3f(0.00, 0.20, 0.40); // Prussian Blue
    glBegin(GL_TRIANGLES);
    glVertex2f(-111, 127);  // A6: Bottom left
    glVertex2f(-91, 179); // V6: Top
    glVertex2f(-71, 127); // B6: Bottom right
    glEnd();

    // B6 W6 E6
    glColor3f(0.00, 0.20, 0.40); // Prussian Blue
    glBegin(GL_TRIANGLES);
    glVertex2f(-71, 127);  // B6: Bottom left
    glVertex2f(-51, 179); // W6: Top
    glVertex2f(-30, 127); // E6: Bottom right
    glEnd();

    // E6 Z6 P6
    glColor3f(0.00, 0.20, 0.40); // Prussian Blue
    glBegin(GL_TRIANGLES);
    glVertex2f(-30, 127);  // E6: Bottom left
    glVertex2f(-11, 180); // Z6: Top
    glVertex2f(9, 127); // P6: Bottom right
    glEnd();







    // building 3
    // A7 B7 C7 D7
    glColor3f(0.93, 0.57, 0.13); // Carrot Orange
    glBegin(GL_QUADS);
    glVertex2f(20, -20);  // A7: Bottom left
    glVertex2f(20, 80); // B7: Top left
    glVertex2f(80, 80); // C7: Top right
    glVertex2f(80, -20);  // D7: Bottom right 
    glEnd();

    // top I7 J7 K7 L7
    glColor3f(0.80, 0.40, 0.15); // Burnt Orange
    glBegin(GL_QUADS);
    glVertex2f(16, 80);  // I7: Bottom left
    glVertex2f(16, 86); // J7: Top left
    glVertex2f(84, 86); // K7: Top right
    glVertex2f(84, 80);  // L7: Bottom right 
    glEnd();









    // building 4
    // Ground M7 N7 O7 P7
    glColor3f(0.60, 0.20, 0.80); // Amethyst
    glBegin(GL_QUADS);
    glVertex2f(90, -20);  // M7: Bottom left
    glVertex2f(90, 20); // N7: Top left
    glVertex2f(240, 20); // O7: Top right
    glVertex2f(240, -20);  // P7: Bottom right 
    glEnd();

    // second floor W7 Z7 H8 G8
    glColor3f(0.60, 0.20, 0.80); // Amethyst
    glBegin(GL_QUADS);
    glVertex2f(100, 20);  // W7: Bottom left
    glVertex2f(100, 54); // Z7: Top left
    glVertex2f(230, 54); // H8: Top right
    glVertex2f(230, 20);  // G8: Bottom right 
    glEnd();

    // top Q7 R7 V7 S7
    glColor3f(0.30, 0.00, 0.50); // Dark Purple
    glBegin(GL_QUADS);
    glVertex2f(96, 54);  // I7: Bottom left
    glVertex2f(96, 60); // J7: Top left
    glVertex2f(234, 60); // K7: Top right
    glVertex2f(234, 54);  // L7: Bottom right 
    glEnd();
















}