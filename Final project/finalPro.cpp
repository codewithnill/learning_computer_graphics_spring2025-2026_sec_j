#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <cmath>




float boatX = 0.0f;  // controls boat's horizontal position
float fishX = 0.0f;  // fish group position controller
int fishColorIndex = 0; // tracks current color (0, 1, or 2)
float cloudX = 0.0f;  // controls cloud offset position
float trainX = 0.0f;  //  controls train position
float trainSpeed = 1.0f; // for train speed control
float carAX = 0.0f;   // controls car A position
float carBX = 0.0f;   //  ontrols car B position
float cloudDirection = -1.0f;  // -1 = left, 1 = right




bool isNight = false;
bool vehiclesMoving = true;



// prototype
void circle(float r, float g, float b, float radius, float xc, float yc);
void water();
void sky();
void cloudset();
void sun();
void buildings();
void fishes();
void streets();
void carA();     // first car below street
void carB();     // second car below street
void boat();
void grass();
void railway();
void train();
void drawWindow(float x1, float y1, float x2, float y2);
void keyboard(unsigned char key, int x, int y);
void update(int value);
void display();
void setFishColor(int colorIndex);











void update(int value) {

    if (!isNight) { // Only move vehicles if not in night mode

        boatX -= 0.7;  // Move left 

        // Reset position when boat goes too far left
        if (boatX < -250) {
            boatX = 250 + 200;  // Reset to right side
        }

        //  Train movement
        trainX -= trainSpeed;

        // Reset train when it goes off screen
        if (trainX < -400) {
            trainX = 550;
        }

        // Car A movement 
        carAX -= 1.2;

        // Reset car A when it goes off screen
        if (carAX < -500) {
            carAX = 400;
        }

        // Car B movement 
        carBX -= 1.2;

        // Reset car B when it goes off screen
        if (carBX < -500) {
            carBX = 400;
        }
    }



    fishX -= 0.5;  // Move fishes left (slower than boat)

    // When fishes go off screen, reset and change color
    if (fishX < -350) {
        fishX = 230;  // Reset to right side
        fishColorIndex = (fishColorIndex + 1) % 3;  // Cycle through 0,1,2
    }


    // Cloud movement
    //cloudX -= 0.1;  // Move left

    cloudX += cloudDirection * 0.1;  // Move based on direction

    // Reset when offset exceeds cloud width
    // if (cloudX < -500) {
    //     cloudX = 0;
    // }

    // Reset when offset exceeds cloud width (works for both directions)
    if (cloudX < -500) {
        cloudX = 0;
    }
    else if (cloudX > 500) {
        cloudX = 0;
    }





    glutPostRedisplay();  // Redraw the scene
    glutTimerFunc(8, update, 0);  // Call again 
}



void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'c':
    case 'C':
        cloudDirection *= -1;  // Flip direction
        glutPostRedisplay();
        break;

    case 'n':
    case 'N':
        isNight = true;
        vehiclesMoving = false;
        glutPostRedisplay();
        break;
    case 'd':
    case 'D':
        isNight = false;
        vehiclesMoving = true;
        glutPostRedisplay();
        break;

    case 's':
    case 'S':
        if (trainSpeed == 1.0f) {
            trainSpeed = 2.5f;  // Fast speed
        }
        else {
            trainSpeed = 1.0f;  // Normal speed
        }
        glutPostRedisplay();
        break;
    }


}




void circle(float r, float g, float b, float radius, float xc, float yc)
{
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 180;
        float x = radius * cos(A);
        float y = radius * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}







void display() {
    glClearColor(1, 1, 1, 1); // set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background) (fills the screen with this color)

    // set up projection matrix
    glMatrixMode(GL_PROJECTION);  // Switch to projection matrix
    glLoadIdentity();             // Reset the matrix
    gluOrtho2D(-250, 250, -250, 250);
    // sets up a 2D orthographic projection
    // X-axis ranges from -250 to 250
    // Y-axis ranges from -250 to 250

    glMatrixMode(GL_MODELVIEW);   // Switch back to modelview matrix
    glLoadIdentity();             // Reset modelview matrix







    sky();
    sun();
    cloudset();
    buildings();
    grass();
    railway();
    train();
    water();
    fishes();
    streets();
    carA();
    carB();
    boat();






    //glFlush(); // Render now (forces all OpenGL commands to execute immediately)
    glutSwapBuffers();
}




void sky() {
    //glColor3f(0.529, 0.808, 0.922);  // Light blue color
    if (isNight) {
        glColor3f(0.05, 0.05, 0.15);  // Deep blue/night sky
    }
    else {
        glColor3f(0.529, 0.808, 0.922);  // Light blue day sky
    }
    glBegin(GL_QUADS);     // rectangle (quadrilateral)
    glVertex2f(250, 250);  // Top-right corner (highest possible)
    glVertex2f(-250, 250); // Top-left corner (highest possible)
    glVertex2f(-250, -20); // Bottom-left corner 
    glVertex2f(250, -20);  // Bottom-right corner 
    glEnd();
}

void cloudset() {
    glPushMatrix();
    glTranslatef(cloudX, 0.0f, 0.0f);

    //  set -2 (far left, for rightward movement) 
    // A-2
    circle(248, 250, 252, 5, -200 - 1000, 205);
    circle(248, 250, 252, 8, -210 - 1000, 210);
    circle(248, 250, 252, 9, -198 - 1000, 217);
    circle(248, 250, 252, 8, -185 - 1000, 221);
    circle(248, 250, 252, 8, -190 - 1000, 208);
    circle(248, 250, 252, 8, -180 - 1000, 208);
    circle(248, 250, 252, 8, -170 - 1000, 205);
    circle(248, 250, 252, 8, -173 - 1000, 218);
    circle(248, 250, 252, 8, -163 - 1000, 212);

    // B-2
    circle(248, 250, 252, 5, -120 - 1000, 198);
    circle(248, 250, 252, 8, -130 - 1000, 203);
    circle(248, 250, 252, 9, -118 - 1000, 210);
    circle(248, 250, 252, 8, -105 - 1000, 214);
    circle(248, 250, 252, 8, -110 - 1000, 201);
    circle(248, 250, 252, 8, -100 - 1000, 201);
    circle(248, 250, 252, 8, -90 - 1000, 198);
    circle(248, 250, 252, 8, -93 - 1000, 211);
    circle(248, 250, 252, 8, -83 - 1000, 205);

    // C-2
    circle(248, 250, 252, 6, -40 - 1000, 190);
    circle(248, 250, 252, 9, -52 - 1000, 195);
    circle(248, 250, 252, 10, -38 - 1000, 203);
    circle(248, 250, 252, 9, -22 - 1000, 207);
    circle(248, 250, 252, 8, -28 - 1000, 195);
    circle(248, 250, 252, 8, -15 - 1000, 195);
    circle(248, 250, 252, 8, -5 - 1000, 193);
    circle(248, 250, 252, 8, -10 - 1000, 205);
    circle(248, 250, 252, 8, 2 - 1000, 200);

    // D-2
    circle(248, 250, 252, 5, 60 - 1000, 192);
    circle(248, 250, 252, 8, 50 - 1000, 197);
    circle(248, 250, 252, 9, 62 - 1000, 205);
    circle(248, 250, 252, 8, 75 - 1000, 209);
    circle(248, 250, 252, 8, 70 - 1000, 196);
    circle(248, 250, 252, 8, 80 - 1000, 196);
    circle(248, 250, 252, 8, 90 - 1000, 193);
    circle(248, 250, 252, 8, 87 - 1000, 206);
    circle(248, 250, 252, 8, 97 - 1000, 200);

    // E-2
    circle(248, 250, 252, 5, 130 - 1000, 178);
    circle(248, 250, 252, 8, 122 - 1000, 183);
    circle(248, 250, 252, 9, 132 - 1000, 189);
    circle(248, 250, 252, 8, 148 - 1000, 195);
    circle(248, 250, 252, 8, 142 - 1000, 182);
    circle(248, 250, 252, 8, 155 - 1000, 182);
    circle(248, 250, 252, 8, 165 - 1000, 180);
    circle(248, 250, 252, 8, 160 - 1000, 192);
    circle(248, 250, 252, 8, 172 - 1000, 187);

    // F-2
    circle(248, 250, 252, 4, 235 - 1000, 190);
    circle(248, 250, 252, 6, 230 - 1000, 194);
    circle(248, 250, 252, 7, 237 - 1000, 200);
    circle(248, 250, 252, 6, 247 - 1000, 202);
    circle(248, 250, 252, 6, 243 - 1000, 192);
    circle(248, 250, 252, 6, 250 - 1000, 193);
    circle(248, 250, 252, 5, 255 - 1000, 190);
    circle(248, 250, 252, 5, 252 - 1000, 199);
    circle(248, 250, 252, 5, 257 - 1000, 193);

    //  set -1 (left, for rightward movement) 
    // A-1
    circle(248, 250, 252, 5, -200 - 500, 205);
    circle(248, 250, 252, 8, -210 - 500, 210);
    circle(248, 250, 252, 9, -198 - 500, 217);
    circle(248, 250, 252, 8, -185 - 500, 221);
    circle(248, 250, 252, 8, -190 - 500, 208);
    circle(248, 250, 252, 8, -180 - 500, 208);
    circle(248, 250, 252, 8, -170 - 500, 205);
    circle(248, 250, 252, 8, -173 - 500, 218);
    circle(248, 250, 252, 8, -163 - 500, 212);

    // B-1
    circle(248, 250, 252, 5, -120 - 500, 198);
    circle(248, 250, 252, 8, -130 - 500, 203);
    circle(248, 250, 252, 9, -118 - 500, 210);
    circle(248, 250, 252, 8, -105 - 500, 214);
    circle(248, 250, 252, 8, -110 - 500, 201);
    circle(248, 250, 252, 8, -100 - 500, 201);
    circle(248, 250, 252, 8, -90 - 500, 198);
    circle(248, 250, 252, 8, -93 - 500, 211);
    circle(248, 250, 252, 8, -83 - 500, 205);

    // C-1
    circle(248, 250, 252, 6, -40 - 500, 190);
    circle(248, 250, 252, 9, -52 - 500, 195);
    circle(248, 250, 252, 10, -38 - 500, 203);
    circle(248, 250, 252, 9, -22 - 500, 207);
    circle(248, 250, 252, 8, -28 - 500, 195);
    circle(248, 250, 252, 8, -15 - 500, 195);
    circle(248, 250, 252, 8, -5 - 500, 193);
    circle(248, 250, 252, 8, -10 - 500, 205);
    circle(248, 250, 252, 8, 2 - 500, 200);

    // D-1
    circle(248, 250, 252, 5, 60 - 500, 192);
    circle(248, 250, 252, 8, 50 - 500, 197);
    circle(248, 250, 252, 9, 62 - 500, 205);
    circle(248, 250, 252, 8, 75 - 500, 209);
    circle(248, 250, 252, 8, 70 - 500, 196);
    circle(248, 250, 252, 8, 80 - 500, 196);
    circle(248, 250, 252, 8, 90 - 500, 193);
    circle(248, 250, 252, 8, 87 - 500, 206);
    circle(248, 250, 252, 8, 97 - 500, 200);

    // E-1
    circle(248, 250, 252, 5, 130 - 500, 178);
    circle(248, 250, 252, 8, 122 - 500, 183);
    circle(248, 250, 252, 9, 132 - 500, 189);
    circle(248, 250, 252, 8, 148 - 500, 195);
    circle(248, 250, 252, 8, 142 - 500, 182);
    circle(248, 250, 252, 8, 155 - 500, 182);
    circle(248, 250, 252, 8, 165 - 500, 180);
    circle(248, 250, 252, 8, 160 - 500, 192);
    circle(248, 250, 252, 8, 172 - 500, 187);

    // F-1
    circle(248, 250, 252, 4, 235 - 500, 190);
    circle(248, 250, 252, 6, 230 - 500, 194);
    circle(248, 250, 252, 7, 237 - 500, 200);
    circle(248, 250, 252, 6, 247 - 500, 202);
    circle(248, 250, 252, 6, 243 - 500, 192);
    circle(248, 250, 252, 6, 250 - 500, 193);
    circle(248, 250, 252, 5, 255 - 500, 190);
    circle(248, 250, 252, 5, 252 - 500, 199);
    circle(248, 250, 252, 5, 257 - 500, 193);

    // set 0 (original positions) 
    // A
    circle(248, 250, 252, 5, -200, 205);
    circle(248, 250, 252, 8, -210, 210);
    circle(248, 250, 252, 9, -198, 217);
    circle(248, 250, 252, 8, -185, 221);
    circle(248, 250, 252, 8, -190, 208);
    circle(248, 250, 252, 8, -180, 208);
    circle(248, 250, 252, 8, -170, 205);
    circle(248, 250, 252, 8, -173, 218);
    circle(248, 250, 252, 8, -163, 212);

    // B
    circle(248, 250, 252, 5, -120, 198);
    circle(248, 250, 252, 8, -130, 203);
    circle(248, 250, 252, 9, -118, 210);
    circle(248, 250, 252, 8, -105, 214);
    circle(248, 250, 252, 8, -110, 201);
    circle(248, 250, 252, 8, -100, 201);
    circle(248, 250, 252, 8, -90, 198);
    circle(248, 250, 252, 8, -93, 211);
    circle(248, 250, 252, 8, -83, 205);

    // C
    circle(248, 250, 252, 6, -40, 190);
    circle(248, 250, 252, 9, -52, 195);
    circle(248, 250, 252, 10, -38, 203);
    circle(248, 250, 252, 9, -22, 207);
    circle(248, 250, 252, 8, -28, 195);
    circle(248, 250, 252, 8, -15, 195);
    circle(248, 250, 252, 8, -5, 193);
    circle(248, 250, 252, 8, -10, 205);
    circle(248, 250, 252, 8, 2, 200);

    // D
    circle(248, 250, 252, 5, 60, 192);
    circle(248, 250, 252, 8, 50, 197);
    circle(248, 250, 252, 9, 62, 205);
    circle(248, 250, 252, 8, 75, 209);
    circle(248, 250, 252, 8, 70, 196);
    circle(248, 250, 252, 8, 80, 196);
    circle(248, 250, 252, 8, 90, 193);
    circle(248, 250, 252, 8, 87, 206);
    circle(248, 250, 252, 8, 97, 200);

    // E
    circle(248, 250, 252, 5, 130, 178);
    circle(248, 250, 252, 8, 122, 183);
    circle(248, 250, 252, 9, 132, 189);
    circle(248, 250, 252, 8, 148, 195);
    circle(248, 250, 252, 8, 142, 182);
    circle(248, 250, 252, 8, 155, 182);
    circle(248, 250, 252, 8, 165, 180);
    circle(248, 250, 252, 8, 160, 192);
    circle(248, 250, 252, 8, 172, 187);

    // F
    circle(248, 250, 252, 4, 235, 190);
    circle(248, 250, 252, 6, 230, 194);
    circle(248, 250, 252, 7, 237, 200);
    circle(248, 250, 252, 6, 247, 202);
    circle(248, 250, 252, 6, 243, 192);
    circle(248, 250, 252, 6, 250, 193);
    circle(248, 250, 252, 5, 255, 190);
    circle(248, 250, 252, 5, 252, 199);
    circle(248, 250, 252, 5, 257, 193);

    // set +1 (right, for leftward movement) 
    // A2
    circle(248, 250, 252, 5, -200 + 500, 205);
    circle(248, 250, 252, 8, -210 + 500, 210);
    circle(248, 250, 252, 9, -198 + 500, 217);
    circle(248, 250, 252, 8, -185 + 500, 221);
    circle(248, 250, 252, 8, -190 + 500, 208);
    circle(248, 250, 252, 8, -180 + 500, 208);
    circle(248, 250, 252, 8, -170 + 500, 205);
    circle(248, 250, 252, 8, -173 + 500, 218);
    circle(248, 250, 252, 8, -163 + 500, 212);

    // B2
    circle(248, 250, 252, 5, -120 + 500, 198);
    circle(248, 250, 252, 8, -130 + 500, 203);
    circle(248, 250, 252, 9, -118 + 500, 210);
    circle(248, 250, 252, 8, -105 + 500, 214);
    circle(248, 250, 252, 8, -110 + 500, 201);
    circle(248, 250, 252, 8, -100 + 500, 201);
    circle(248, 250, 252, 8, -90 + 500, 198);
    circle(248, 250, 252, 8, -93 + 500, 211);
    circle(248, 250, 252, 8, -83 + 500, 205);

    // C2
    circle(248, 250, 252, 6, -40 + 500, 190);
    circle(248, 250, 252, 9, -52 + 500, 195);
    circle(248, 250, 252, 10, -38 + 500, 203);
    circle(248, 250, 252, 9, -22 + 500, 207);
    circle(248, 250, 252, 8, -28 + 500, 195);
    circle(248, 250, 252, 8, -15 + 500, 195);
    circle(248, 250, 252, 8, -5 + 500, 193);
    circle(248, 250, 252, 8, -10 + 500, 205);
    circle(248, 250, 252, 8, 2 + 500, 200);

    // D2
    circle(248, 250, 252, 5, 60 + 500, 192);
    circle(248, 250, 252, 8, 50 + 500, 197);
    circle(248, 250, 252, 9, 62 + 500, 205);
    circle(248, 250, 252, 8, 75 + 500, 209);
    circle(248, 250, 252, 8, 70 + 500, 196);
    circle(248, 250, 252, 8, 80 + 500, 196);
    circle(248, 250, 252, 8, 90 + 500, 193);
    circle(248, 250, 252, 8, 87 + 500, 206);
    circle(248, 250, 252, 8, 97 + 500, 200);

    // E2
    circle(248, 250, 252, 5, 130 + 500, 178);
    circle(248, 250, 252, 8, 122 + 500, 183);
    circle(248, 250, 252, 9, 132 + 500, 189);
    circle(248, 250, 252, 8, 148 + 500, 195);
    circle(248, 250, 252, 8, 142 + 500, 182);
    circle(248, 250, 252, 8, 155 + 500, 182);
    circle(248, 250, 252, 8, 165 + 500, 180);
    circle(248, 250, 252, 8, 160 + 500, 192);
    circle(248, 250, 252, 8, 172 + 500, 187);

    // F2
    circle(248, 250, 252, 4, 235 + 500, 190);
    circle(248, 250, 252, 6, 230 + 500, 194);
    circle(248, 250, 252, 7, 237 + 500, 200);
    circle(248, 250, 252, 6, 247 + 500, 202);
    circle(248, 250, 252, 6, 243 + 500, 192);
    circle(248, 250, 252, 6, 250 + 500, 193);
    circle(248, 250, 252, 5, 255 + 500, 190);
    circle(248, 250, 252, 5, 252 + 500, 199);
    circle(248, 250, 252, 5, 257 + 500, 193);

    // set +2 (far right, for leftward movement) 
    // A3
    circle(248, 250, 252, 5, -200 + 1000, 205);
    circle(248, 250, 252, 8, -210 + 1000, 210);
    circle(248, 250, 252, 9, -198 + 1000, 217);
    circle(248, 250, 252, 8, -185 + 1000, 221);
    circle(248, 250, 252, 8, -190 + 1000, 208);
    circle(248, 250, 252, 8, -180 + 1000, 208);
    circle(248, 250, 252, 8, -170 + 1000, 205);
    circle(248, 250, 252, 8, -173 + 1000, 218);
    circle(248, 250, 252, 8, -163 + 1000, 212);

    // B3
    circle(248, 250, 252, 5, -120 + 1000, 198);
    circle(248, 250, 252, 8, -130 + 1000, 203);
    circle(248, 250, 252, 9, -118 + 1000, 210);
    circle(248, 250, 252, 8, -105 + 1000, 214);
    circle(248, 250, 252, 8, -110 + 1000, 201);
    circle(248, 250, 252, 8, -100 + 1000, 201);
    circle(248, 250, 252, 8, -90 + 1000, 198);
    circle(248, 250, 252, 8, -93 + 1000, 211);
    circle(248, 250, 252, 8, -83 + 1000, 205);

    // C3
    circle(248, 250, 252, 6, -40 + 1000, 190);
    circle(248, 250, 252, 9, -52 + 1000, 195);
    circle(248, 250, 252, 10, -38 + 1000, 203);
    circle(248, 250, 252, 9, -22 + 1000, 207);
    circle(248, 250, 252, 8, -28 + 1000, 195);
    circle(248, 250, 252, 8, -15 + 1000, 195);
    circle(248, 250, 252, 8, -5 + 1000, 193);
    circle(248, 250, 252, 8, -10 + 1000, 205);
    circle(248, 250, 252, 8, 2 + 1000, 200);

    // D3
    circle(248, 250, 252, 5, 60 + 1000, 192);
    circle(248, 250, 252, 8, 50 + 1000, 197);
    circle(248, 250, 252, 9, 62 + 1000, 205);
    circle(248, 250, 252, 8, 75 + 1000, 209);
    circle(248, 250, 252, 8, 70 + 1000, 196);
    circle(248, 250, 252, 8, 80 + 1000, 196);
    circle(248, 250, 252, 8, 90 + 1000, 193);
    circle(248, 250, 252, 8, 87 + 1000, 206);
    circle(248, 250, 252, 8, 97 + 1000, 200);

    // E3
    circle(248, 250, 252, 5, 130 + 1000, 178);
    circle(248, 250, 252, 8, 122 + 1000, 183);
    circle(248, 250, 252, 9, 132 + 1000, 189);
    circle(248, 250, 252, 8, 148 + 1000, 195);
    circle(248, 250, 252, 8, 142 + 1000, 182);
    circle(248, 250, 252, 8, 155 + 1000, 182);
    circle(248, 250, 252, 8, 165 + 1000, 180);
    circle(248, 250, 252, 8, 160 + 1000, 192);
    circle(248, 250, 252, 8, 172 + 1000, 187);

    // F3
    circle(248, 250, 252, 4, 235 + 1000, 190);
    circle(248, 250, 252, 6, 230 + 1000, 194);
    circle(248, 250, 252, 7, 237 + 1000, 200);
    circle(248, 250, 252, 6, 247 + 1000, 202);
    circle(248, 250, 252, 6, 243 + 1000, 192);
    circle(248, 250, 252, 6, 250 + 1000, 193);
    circle(248, 250, 252, 5, 255 + 1000, 190);
    circle(248, 250, 252, 5, 252 + 1000, 199);
    circle(248, 250, 252, 5, 257 + 1000, 193);

    glPopMatrix();
}

void sun() { // -> changes to moon when N or n is pressed to bring night mode

    //glPushMatrix();
    //glTranslatef(x, y, 0);
    //glRotatef(angle1, 0, 0, 1);
    //circle(255, 255, 200, 20, 180, 200);  // Outer glow
    //circle(255, 220, 140, 17, -200, 210);   // Main sun
    //circle(255, 200, 0, 8, 180, 200);     // Inner core
    //glPopMatrix();

    if (isNight) {
        // Moon (bluish-white)
        circle(206, 220, 255, 22, -200, 210);  // Pale bluish-white moon
    }
    else {
        // Sun (orange-yellow)
        circle(255, 220, 140, 22, -200, 210);  // Main sun
    }
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




    // top separator R1 V1 W1 S1
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

void train() {
    glPushMatrix();
    glTranslatef(trainX, 0.0f, 0.0f);
    // wheels
    // first body
    circle(40, 42, 45, 10, -195, -59);
    circle(40, 42, 45, 10, -170, -59);

    // second body
    circle(40, 42, 45, 10, -80, -59);
    circle(40, 42, 45, 10, -55, -59);

    circle(40, 42, 45, 10, -80 + 90, -59);
    circle(40, 42, 45, 10, -55 + 90, -59);






    // first body
    glColor3f(0, 0.125, 0.251);
    glBegin(GL_POLYGON);
    glVertex2f(-211, 22); // C13: top left 
    glVertex2f(-107, 22); // F13: top right
    glVertex2f(-107, -58); // G13: bottom right
    glVertex2f(-217, -58); // E13: bottom left
    glVertex2f(-235, -29); // D13: left sharp point
    glEnd();

    // second body
    glColor3f(0, 0.125, 0.251);
    glBegin(GL_POLYGON);
    glVertex2f(-104, 22); // H13: top left 
    glVertex2f(70, 22); // J13: top right
    glVertex2f(70, -44); // L13: bottom right
    glVertex2f(58, -58); // K13: 
    glVertex2f(-104, -58); // I13: bottom left
    glEnd();

    // windows in first body
    // M13 P13 O13 N13
    glColor3f(0.569, 0.58, 0.58);
    glBegin(GL_QUADS);
    glVertex2f(-209, 18);   // M13: Top-left corner
    glVertex2f(-185, 18);    // P13: Top-right corner
    glVertex2f(-185, -10);    // O13: Bottom-right corner
    glVertex2f(-222, -10);   // N13: Bottom-left corner
    glEnd();

    // Q13 S13 T13 R13
    glColor3f(0.569, 0.58, 0.58);
    glBegin(GL_QUADS);
    glVertex2f(-183, 18);   // Q13: Top-left corner
    glVertex2f(-136, 18);    // S13: Top-right corner
    glVertex2f(-136, -10);    // T13: Bottom-right corner
    glVertex2f(-183, -10);   // R13: Bottom-left corner
    glEnd();

    // windows in second body
    // Q16 S16 T16 R16
    glColor3f(0.569, 0.58, 0.58);
    glBegin(GL_QUADS);
    glVertex2f(-102, 18);   // Q16: Top-left corner
    glVertex2f(-66, 18);    // S16: Top-right corner
    glVertex2f(-66, -10);    // T16: Bottom-right corner
    glVertex2f(-102, -10);   // R16: Bottom-left corner
    glEnd();

    // Q13 S13 T13 R13
    glColor3f(0.569, 0.58, 0.58);
    glBegin(GL_QUADS);
    glVertex2f(-37, 18);   // Q13: Top-left corner
    glVertex2f(-1, 18);    // S13: Top-right corner
    glVertex2f(-1, -10);    // T13: Bottom-right corner
    glVertex2f(-37, -10);   // R13: Bottom-left corner
    glEnd();

    // Q15 S15 T15 R15
    glColor3f(0.569, 0.58, 0.58);
    glBegin(GL_QUADS);
    glVertex2f(2, 18);   // Q15: Top-left corner
    glVertex2f(38, 18);    // S15: Top-right corner
    glVertex2f(38, -10);    // T15: Bottom-right corner
    glVertex2f(2, -10);   // R15: Bottom-left corner
    glEnd();

    // A14 C14 D14 B14
    glColor3f(0.569, 0.58, 0.58);
    glBegin(GL_QUADS);
    glVertex2f(41, 18);   // A14: Top-left corner
    glVertex2f(65, 18);    // C14: Top-right corner
    glVertex2f(65, -10);    // D14: Bottom-right corner
    glVertex2f(41, -10);   // B14: Bottom-left corner
    glEnd();



    // design quads
    // E14 F14 G13 E13
    glColor3f(0.69, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-229, -40);   // E14: Top-left corner
    glVertex2f(-107, -40);    // F14: Top-right corner
    glVertex2f(-107, -58);    // G13: Bottom-right corner
    glVertex2f(-217, -58);   // E13: Bottom-left corner
    glEnd();

    // polygon for 2nd body
    // G14 H14 L13 K13 I13
    glColor3f(0.69, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-104, -40);   // G14: Top-left corner
    glVertex2f(70, -40);    // H14: Top-right corner
    glVertex2f(70, -44);    // L13:
    glVertex2f(58, -58);   // K13: Bottom-left corner
    glVertex2f(-104, -58);   // I13: Bottom-left corner
    glEnd();


    // doors
    // first body door
    glLineWidth(2);
    glColor3f(0.29, 0.29, 0.29);

    //U14 V14 W14 Z14
    glBegin(GL_LINE_LOOP);
    glVertex2f(-134, 18); // U14: Top-left corner
    glVertex2f(-109, 18); // V14: Top-left corner
    glVertex2f(-109, -50); // W14: Top-left corner
    glVertex2f(-134, -50); // Z14: Top-left corner
    glEnd();

    // first body door
    glLineWidth(2);
    glColor3f(0.29, 0.29, 0.29);

    //U13 V13 W13 Z13
    glBegin(GL_LINE_LOOP);
    glVertex2f(-64, 18); // U13: Top-left corner
    glVertex2f(-39, 18); // V13: Top-left corner
    glVertex2f(-39, -50); // W13: Top-left corner
    glVertex2f(-64, -50); // Z13: Top-left corner
    glEnd();



    // door windows
    // window in first body
    // I14 J14 L14 K14
    glColor3f(0.569, 0.58, 0.58);
    glBegin(GL_QUADS);
    glVertex2f(-131, 13);   // I14: Top-left corner
    glVertex2f(-112, 13);    // J14: Top-right corner
    glVertex2f(-112, -10);    // L14: Bottom-right corner
    glVertex2f(-131, -10);   // K14: Bottom-left corner
    glEnd();

    // window in second body
    // M14 N14 P14 O14 
    glColor3f(0.569, 0.58, 0.58);
    glBegin(GL_QUADS);
    glVertex2f(-61, 13);   // M14: Top-left corner
    glVertex2f(-42, 13);    // N14: Top-right corner
    glVertex2f(-42, -10);    // P14: Bottom-right corner
    glVertex2f(-61, -10);   // O14: Bottom-left corner
    glEnd();


    // connecting object
    // A15 B15 D15 C15 
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-107, 0);   // A15: Top-left corner
    glVertex2f(-104, 0);    // B15: Top-right corner
    glVertex2f(-104, -36);    // D15: Bottom-right corner
    glVertex2f(-107, -36);   // C15: Bottom-left corner
    glEnd();







    glPopMatrix();





}



void streets() {
    glLoadIdentity(); // stops the street from translating to the left


    // top separator N1 A13 B13 O1

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



void carA() {
    glPushMatrix();
    glTranslatef(carAX, 0.0f, 0.0f);
    // body
    // E15 F15 G15 I15 J15 K15 L15 M15
    glColor3f(1, 0.486, 0); // orange
    glBegin(GL_POLYGON);
    glVertex2f(88, -133);  // E15
    glVertex2f(89, -103);   // F15
    glVertex2f(116, -98);   // G15
    glVertex2f(135, -71);  // I15
    glVertex2f(164, -75);  // J15
    glVertex2f(171, -98);  // K15
    glVertex2f(200, -100);  // L15
    glVertex2f(202, -132);  // M15
    glEnd();

    // tyre
    circle(10, 12, 14, 13, 105, -131); // front
    circle(10, 12, 14, 13, 180, -131); // back

    // rims
    circle(160, 162, 165, 7, 105, -131); // front rim
    circle(160, 162, 165, 7, 180, -131); // rear rim

    // door
    glLineWidth(1);
    glColor3f(0.29, 0.29, 0.29);
    glBegin(GL_LINE_LOOP);
    glVertex2f(120, -129); // V15
    glVertex2f(119, -99); // O15
    glVertex2f(136, -75); // N15
    glVertex2f(162, -79); // P15
    glVertex2f(165, -99); // W15
    glVertex2f(162, -129); // U15
    glEnd();

    // door window
    glColor3f(0.271, 0.271, 0.271);
    glBegin(GL_QUADS);
    glVertex2f(123, -98);   // Z15
    glVertex2f(136, -78);    // A16
    glVertex2f(160, -82);    // B16
    glVertex2f(163, -99);   // C16
    glEnd();

    // back
    glColor3f(1, 0.486, 0);
    glBegin(GL_QUADS);
    glVertex2f(189, -99);   // D16
    glVertex2f(193, -85);    // E16
    glVertex2f(200, -85);    // F16
    glVertex2f(200, -100);   // L16
    glEnd();

    glPopMatrix();
}

void carB() {
    glPushMatrix();
    glTranslatef(carBX, 0.0f, 0.0f);
    // body
    // H16 G16 I16 J16 K16 L16 M16 N16
    glColor3f(0.345, 0.706, 0.741); // orange
    glBegin(GL_POLYGON);
    glVertex2f(-147, -133);  // H16
    glVertex2f(-145, -100);   // G16
    glVertex2f(-112, -93);   // I16
    glVertex2f(-93, -65);  // J16
    glVertex2f(-56, -65);  // K16
    glVertex2f(-56, -95);  // L16
    glVertex2f(-12, -96);  // M16
    glVertex2f(-12, -133);  // N16
    glEnd();

    // tyre
    circle(10, 12, 14, 13, -125, -131); // front
    circle(10, 12, 14, 13, -35, -131); // back

    // rims
    circle(160, 162, 165, 7, -125, -131); // front rim
    circle(160, 162, 165, 7, -35, -131); // rear rim

    // door
    glLineWidth(1);
    glColor3f(0.29, 0.29, 0.29);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-107, -128); // U16
    glVertex2f(-109, -92); // P16
    glVertex2f(-92, -69); // O16
    glVertex2f(-58, -70); // V16
    glVertex2f(-58, -94); // W16
    glVertex2f(-66, -128); // Z16
    glEnd();

    // door window
    glColor3f(0.271, 0.271, 0.271);
    glBegin(GL_QUADS);
    glVertex2f(-105, -92);   // A17
    glVertex2f(-92, -73);    // B17
    glVertex2f(-61, -73);    // C17
    glVertex2f(-61, -92);   // D17
    glEnd();

    glPopMatrix();
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 600); // set the window's initial width & height
    glutInitWindowPosition(70, 70);  // set the window's initial position according to the monitor
    glutCreateWindow("Scene"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint

    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(keyboard);
    glutMainLoop(); // Enter the event-processing loop (keeps the program alive)
    return 0;
}





void drawWindow(float x1, float y1, float x2, float y2) {
    if (isNight) {
        glColor3f(1.0, 0.9, 0.4);  // Warm yellow glow at night
    }
    else {
        glColor3f(0.90, 0.92, 0.95);  // Day color (Lake Water)
    }
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x1, y2);
    glVertex2f(x2, y2);
    glVertex2f(x2, y1);
    glEnd();
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

    // Door window
    drawWindow(-232, -5, -228, 11);

    // Ground floor window
    drawWindow(-210, 0, -170, 12);

    // Top row windows
    drawWindow(-234, 80, -218, 92);
    drawWindow(-208, 80, -192, 92);
    drawWindow(-182, 80, -166, 92);

    // Middle row windows
    drawWindow(-234, 55, -218, 67);
    drawWindow(-208, 55, -192, 67);
    drawWindow(-182, 55, -166, 67);

    // Lower row windows
    drawWindow(-234, 30, -218, 42);
    drawWindow(-208, 30, -192, 42);
    drawWindow(-182, 30, -166, 42);



























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
    // M8 N8 O8 P8
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);
    glVertex2f(-143, -5);  // M8: Bottom left
    glVertex2f(-143, 11); // N8: Top left
    glVertex2f(-139, 11); // O8: Top right
    glVertex2f(-139, -5);  // P8: Bottom right 
    glEnd();


    // ground floor window
    // V8 Q8 W8 Z8
    glColor3f(0.90, 0.92, 0.95); // Lake Water
    glBegin(GL_QUADS);     // 
    glVertex2f(-120, 0);  // V8: Bottom left
    glVertex2f(-120, 12); // Q8: Top left
    glVertex2f(-80, 12); // W8: Top right
    glVertex2f(-80, 0);  // Z8: Bottom right 
    glEnd();


    // garage door
    // V9 B9 D9 C9
    glColor3f(0.74, 0.76, 0.80); // darker lake water
    glBegin(GL_QUADS);
    glVertex2f(-70, -20);  // A9: Bottom left
    glVertex2f(-70, 15); // B9: Top left
    glVertex2f(3, 15); // D9: Top right
    glVertex2f(3, -20);  // C9: Bottom right 
    glEnd();

    // horizontal lines on garage door
    glLineWidth(1);
    glColor3f(0.50, 0.52, 0.56);

    for (float y = -15; y <= 15; y += 6) {
        glBegin(GL_LINES);
        glVertex2f(-70, y);   // Left edge of garage door
        glVertex2f(3, y);     // Right edge of garage door
        glEnd();
    }




    // windows
    // Door window
    drawWindow(-143, -5, -139, 11);

    // Ground floor window
    drawWindow(-120, 0, -80, 12);

    // Top row windows
    drawWindow(-140, 92, -120, 104);
    drawWindow(-100, 92, -80, 104);
    drawWindow(-60, 92, -40, 104);
    drawWindow(-20, 92, 0, 104);

    // Middle row windows
    drawWindow(-140, 60, -120, 72);
    drawWindow(-100, 60, -80, 72);
    drawWindow(-60, 60, -40, 72);
    drawWindow(-20, 60, 0, 72);

    // Lower row windows
    drawWindow(-140, 28, -120, 40);
    drawWindow(-100, 28, -80, 40);
    drawWindow(-60, 28, -40, 40);
    drawWindow(-20, 28, 0, 40);















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

    // door E7 G7 H7 F7
    glColor3f(0.80, 0.40, 0.15); // Burnt Orange
    glBegin(GL_QUADS);
    glVertex2f(26, -20);  // E7: Bottom left
    glVertex2f(26, 15); // G7: Top left
    glVertex2f(40, 15); // H7: Top right
    glVertex2f(40, -20);  // F7: Bottom right 
    glEnd();


    // Door window
    drawWindow(28, -5, 32, 11);

    // Ground floor window
    drawWindow(46, 0, 74, 12);

    // Windows
    drawWindow(26, 28, 46, 40);
    drawWindow(54, 28, 74, 40);
    drawWindow(26, 60, 46, 72);
    drawWindow(54, 60, 74, 72);








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


    // garage door 1
    // G12 H12 K12 M12
    glColor3f(0.74, 0.76, 0.80); // darker lake water
    glBegin(GL_QUADS);
    glVertex2f(100, -20);  // G12: Bottom left
    glVertex2f(100, 15); // H12: Top left
    glVertex2f(160, 15); // K12: Top right
    glVertex2f(160, -20);  // M12: Bottom right 
    glEnd();

    // horizontal lines on garage door 1
    glLineWidth(1);
    glColor3f(0.50, 0.52, 0.56);

    for (float y = -15; y <= 15; y += 6) {
        glBegin(GL_LINES);
        glVertex2f(100, y);   // Left edge of garage door
        glVertex2f(160, y);   // Right edge of garage door
        glEnd();
    }


    // garage door 2
    // N12 L12 J12 I12
    glColor3f(0.74, 0.76, 0.80); // darker lake water
    glBegin(GL_QUADS);
    glVertex2f(170, -20);  // N12: Bottom left
    glVertex2f(170, 15); // L12: Top left
    glVertex2f(230, 15); // J12: Top right
    glVertex2f(230, -20);  // I12: Bottom right 
    glEnd();




    // horizontal lines on garage door 2
    glLineWidth(1);
    glColor3f(0.50, 0.52, 0.56);

    for (float y = -15; y <= 15; y += 6) {
        glBegin(GL_LINES);
        glVertex2f(170, y);   // Left edge of garage door
        glVertex2f(230, y);   // Right edge of garage door
        glEnd();
    }


    // Windows
    drawWindow(110, 28, 150, 40);
    drawWindow(180, 28, 220, 40);

}