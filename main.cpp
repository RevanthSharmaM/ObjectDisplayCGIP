#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <stdio.h>

//Function to Draw SUN
void drawSun() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); // Set color to yellow
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0); // Center of the sun
    int numSegments = 100;
    float angle;
    for (int i = 0; i <= numSegments; i++) {
        angle = i * 2.0f * M_PI / numSegments;
        glVertex2f(cos(angle) * 50, sin(angle) * 50); // Radius of the sun
    }
    glEnd();

    // Draw sun rays
    glColor3f(1.0, 1.0, 0.0); // Set color to yellow
    glLineWidth(2.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 12; ++i) {
        glVertex2f(0.0, 0.0); // Center of the sun
        glVertex2f(cos(angle) * 70, sin(angle) * 70); // Length of sun rays
        angle += M_PI / 6.0; // Separation angle between sun rays
    }
    glEnd();
}
//END SUN

//Draw HOUSE
// Function to draw the house
void drawHouse() {
    glClear(GL_COLOR_BUFFER_BIT);
    // House base
    glColor3f(0.6, 0.4, 0.2); // Brown color
    glBegin(GL_POLYGON);
    glVertex2f(100, 100); // Bottom-left corner
    glVertex2f(300, 100); // Bottom-right corner
    glVertex2f(300, 260); // Top-right corner
    glVertex2f(100, 260); // Top-left corner
    glEnd();

    // Roof
    glColor3f(0.8, 0.0, 0.0); // Red color
    glBegin(GL_TRIANGLES);
    glVertex2f(90, 260);  // Left vertex
    glVertex2f(310, 260); // Right vertex
    glVertex2f(200, 350); // Top vertex
    glEnd();

    // Door
    glColor3f(0.4, 0.2, 0.0); // Dark brown color
    glBegin(GL_POLYGON);
    glVertex2f(180, 100); // Bottom-left corner
    glVertex2f(220, 100); // Bottom-right corner
    glVertex2f(220, 200); // Top-right corner
    glVertex2f(180, 200); // Top-left corner
    glEnd();

    // Left Window
    glColor3f(0.5, 0.8, 1.0); // Light blue color
    glBegin(GL_POLYGON);
    glVertex2f(120, 160); // Bottom-left corner
    glVertex2f(160, 160); // Bottom-right corner
    glVertex2f(160, 200); // Top-right corner
    glVertex2f(120, 200); // Top-left corner
    glEnd();

    // Right Window
    glColor3f(0.5, 0.8, 1.0); // Light blue color
    glBegin(GL_POLYGON);
    glVertex2f(240, 160); // Bottom-left corner
    glVertex2f(280, 160); // Bottom-right corner
    glVertex2f(280, 200); // Top-right corner
    glVertex2f(240, 200); // Top-left corner
    glEnd();

    // Stairs
    glColor3f(0.5, 0.5, 0.5); // Grey color
    glBegin(GL_POLYGON);
    glVertex2f(140, 100); // Bottom-left corner
    glVertex2f(260, 100); // Bottom-right corner
    glVertex2f(260, 90);  // Top-right corner
    glVertex2f(140, 90);  // Top-left corner
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(130, 90);  // Bottom-left corner
    glVertex2f(270, 90);  // Bottom-right corner
    glVertex2f(270, 80);  // Top-right corner
    glVertex2f(130, 80);  // Top-left corner
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(120, 80);  // Bottom-left corner
    glVertex2f(280, 80);  // Bottom-right corner
    glVertex2f(280, 70);  // Top-right corner
    glVertex2f(120, 70);  // Top-left corner
    glEnd();
}
//END HOUSE

//Draw Half MOON
// Function to draw a filled circle
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 100; // Number of triangles used to draw the circle

    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

// Function to draw the half-moon
void drawHalfMoon() {

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white

    // Draw the main circle of the moon
    drawFilledCircle(200, 300, 50);

    glColor3f(0.0, 0.0, 0.0); // Set color to black to cover half
    drawFilledCircle(180, 300, 50);

    // Draw some stars
    glPointSize(4);
    glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0); // Set color to white
        glVertex2d(50, 350);
        glVertex2d(100, 380);
        glVertex2d(150, 340);
        glVertex2d(250, 370);
        glVertex2d(300, 390);
        glVertex2d(350, 360);
        glVertex2d(200, 250);
        glVertex2d(150, 280);
        glVertex2d(250, 310);
        glVertex2d(350, 300);
    glEnd();

    glFlush();
}
//END MOON

//Start VAN
// Function to draw the van
void drawVan() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Car body
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_POLYGON);
    glVertex2f(100, 150);
    glVertex2f(350, 150);
    glVertex2f(350, 200);
    glVertex2f(300, 250);
    glVertex2f(100, 250);
    glVertex2f(100, 200);
    glEnd();

    // Car windows
    glColor3f(0.5, 0.8, 1.0); // Light blue color
    glBegin(GL_POLYGON);
    glVertex2f(110, 200);
    glVertex2f(170, 200);
    glVertex2f(170, 240);
    glVertex2f(110, 240);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(180, 200);
    glVertex2f(240, 200);
    glVertex2f(240, 240);
    glVertex2f(180, 240);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(250, 200);
    glVertex2f(300, 200);
    glVertex2f(300, 240);
    glVertex2f(250, 240);
    glEnd();

    // Car tires
    glColor3f(0.0, 0.0, 0.0); // Black color
    // Front tire
    drawFilledCircle(130, 130, 20);

    // Rear tire
    drawFilledCircle(300, 130, 20);
}
//End VAN

//Start TrafficSignal
// Function to draw the traffic signal
void drawTrafficSignal() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Pole
    glColor3f(0.3, 0.3, 0.3); // Dark grey color for the pole
    glBegin(GL_POLYGON);
    glVertex2f(190, 10);
    glVertex2f(210, 10);
    glVertex2f(210, 100);
    glVertex2f(190, 100);
    glEnd();

    // Signal box
    glColor3f(0.2, 0.2, 0.2); // Dark grey color for the signal box
    glBegin(GL_POLYGON);
    glVertex2f(150, 100);
    glVertex2f(250, 100);
    glVertex2f(250, 300);
    glVertex2f(150, 300);
    glEnd();

    // Red light
    glColor3f(1.0, 0.0, 0.0); // Set the color
    drawFilledCircle(200, 260, 25); // Red color

    // Yellow light
    glColor3f(1.0, 1.0, 0.0); // Set the color
    drawFilledCircle(200, 200, 25); // Yellow color

    // Green light
    glColor3f(0.0, 1.0, 0.0); // Set the color
    drawFilledCircle(200, 140, 25); // Green color
}

//END TrafficSignal

//Start Ship
// Function to draw the Titanic ship
void drawShip() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Hull
    glColor3f(0.4, 0.2, 0.1); // Brown color for the hull
    glBegin(GL_POLYGON);
    glVertex2f(50, 100);
    glVertex2f(350, 100);
    glVertex2f(325, 60);
    glVertex2f(75, 60);
    glEnd();

    // Deck
    glColor3f(0.8, 0.8, 0.8); // Grey color for the deck
    glBegin(GL_POLYGON);
    glVertex2f(75, 135);
    glVertex2f(325, 135);
    glVertex2f(325, 100);
    glVertex2f(75, 100);
    glEnd();

    // Smokestacks
    glColor3f(0.2, 0.2, 0.2); // Black color for the smokestacks
    // First smokestack
    glBegin(GL_POLYGON);
    glVertex2f(100, 165);
    glVertex2f(135, 165);
    glVertex2f(135, 135);
    glVertex2f(100, 135);
    glEnd();
    // Second smokestack
    glBegin(GL_POLYGON);
    glVertex2f(150, 165);
    glVertex2f(175, 165);
    glVertex2f(175, 135);
    glVertex2f(150, 135);
    glEnd();
    // Third smokestack
    glBegin(GL_POLYGON);
    glVertex2f(200, 165);
    glVertex2f(225, 165);
    glVertex2f(225, 135);
    glVertex2f(200, 135);
    glEnd();
    // Fourth smokestack
    glBegin(GL_POLYGON);
    glVertex2f(250, 165);
    glVertex2f(275, 165);
    glVertex2f(275, 135);
    glVertex2f(250, 135);
    glEnd();

    // Circular windows
    glColor3f(1.0, 1.0, 0.0); // Yellow color for the circular windows
    drawFilledCircle(90, 115, 5); // Circular windows
    drawFilledCircle(110, 115, 5);
    drawFilledCircle(130, 115, 5);
    drawFilledCircle(150, 115, 5);
    drawFilledCircle(170, 115, 5);
    drawFilledCircle(190, 115, 5);
    drawFilledCircle(210, 115, 5);
    drawFilledCircle(230, 115, 5);
    drawFilledCircle(250, 115, 5);
    drawFilledCircle(270, 115, 5);
    drawFilledCircle(290, 115, 5);

    // door
    glColor3f(1.0, 1.0, 1.0); // White color for the door
    glBegin(GL_POLYGON);
    glVertex2f(305, 120);
    glVertex2f(317, 120);
    glVertex2f(317, 100);
    glVertex2f(305, 100);
    glEnd();
}
//End Ship

//Start Tree
// Function to draw a tree recursively
void drawTreefun(float x1, float y1, float angle, int depth) {
    glColor3f(0.5, 0.35, 0.05); // Brown color for tree trunk

    // Draw tree trunk
    glBegin(GL_QUADS);
    glVertex2f(195, 10);
    glVertex2f(205, 10);
    glVertex2f(205, 200);
    glVertex2f(195, 200);
    glEnd();


    if (depth == 0) return;

    float branchLength = depth * 9.0;
    float x2 = x1 + cos(angle * 0.0174533) * branchLength;
    float y2 = y1 + sin(angle * 0.0174533) * branchLength;

    // Draw branch
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    // Calculate new angles for branches
    float angle1 = angle - 20.0;
    float angle2 = angle + 20.0;
    //float branchLengthFactor = 0.7; // Factor to reduce branch length

    // Recursive calls for branches
    drawTreefun(x2, y2, angle1, depth - 1);
    drawTreefun(x2, y2, angle2, depth - 1);

    // Draw leaves (at the end of branches)
    if (depth <= 2) {
        glColor3f(0.0, 0.5, 0.0); // Green color for leaves
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i += 30) {
            float leafAngle = i * 0.0174533;
            float leafX = x2 + cos(leafAngle) * 5.0;
            float leafY = y2 + sin(leafAngle) * 5.0;
            glVertex2f(leafX, leafY);
        }
        glEnd();
    }
}

void drawtree()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Draw tree branches
    glColor3f(0.5, 0.35, 0.05); // Brown color for branches
    drawTreefun(200, 50, 90, 6);
    drawTreefun(200, 60, 100, 7);
    drawTreefun(200, 70, 80, 6);
    drawTreefun(200, 80, 110, 7);
    drawTreefun(200, 90, 70, 6);
    drawTreefun(200, 100, 60, 7);
    drawTreefun(200, 100, 95, 6);
    drawTreefun(200, 90, 85, 7);
    drawTreefun(200, 80, 100, 7);
    drawTreefun(200, 70, 60, 6);
    drawTreefun(200, 60, 75, 7);
    drawTreefun(200, 50, 105, 6);
}
//End Tree

void print(char *string,float r,float g,float b,int x,int y)
{
    glPushMatrix();
    glColor3f(r,g,b);
    glRasterPos2f(x,y);
    while(*string)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
    glPopMatrix();
}

void intro() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    print("Enter the choice:",0,0,0, 100, 300);
    print("1 - sun.",0,0,0, 100, 285);
    print("2 - house.",0,0,0, 100, 270);
    print("3 - moon.",0,0,0, 100, 255);
    print("4 - van.",0,0,0, 100, 240);
    print("5 - trafficsignal.",0,0,0, 100, 225);
    print("6 - tree.",0,0,0, 100, 210);
    print("7 - ship.",0,0,0, 100, 195);
    print("9 - exit",0,0,0, 100, 180);

    glFlush();
}

int choice = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    switch (choice) {
        case 0:intro();
                break;
        case 1: glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
                glTranslatef(200, 200, 0);
                drawSun();
                break;
        case 2:glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
            drawHouse();
            break;
        case 3:
            glClearColor(0.0, 0.0, 0.0, 1.0); // Set clear color to black
            drawHalfMoon();
            break;
        case 4:glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
            drawVan();
            break;
        case 5:glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
            drawTrafficSignal();
            break;
        case 6:glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
            drawtree();
            break;
        case 7:glClearColor(0.0, 0.5, 1.0, 1.0); // Set clear color to blue
            drawShip();
            break;
        case 9:
            exit(0);
    }
    glFlush();
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            choice = 1;
            break;
        case '2':
            choice = 2;
            break;
        case '3':
            choice = 3;
            break;
        case '4':
            choice = 4;
            break;
        case '5':
            choice = 5;
            break;
        case '6':
            choice = 6;
            break;
        case '7':
            choice = 7;
            break;
        case '9':
            choice = 9;
            break;
        default:
            choice = -1; // Undefined choice
            break;
    }
    glutPostRedisplay();
}

void userInput() {

}


void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400); // Set orthogonal projection
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600); // Set window size
    glutInitWindowPosition(100, 20); // Set window position
    glutCreateWindow("CGIP Project"); // Create window with title


    glutDisplayFunc(display); // Register display function
    glutKeyboardFunc(keyboard);
    init(); // Initialize OpenGL parameters
    glutMainLoop(); // Enter main loop

    return 0;
}
