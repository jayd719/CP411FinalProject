//============================================================================
// Project     : Render 3D Cube with Enhanced Controls
// Author      : JD
// Version     : 3.1
// Run         : g++ 3dCube.cpp -o 3dCube -lfreeglut -lopengl32 -lglu32 (for windows)
//               g++ 3dCube.cpp -o 3dCube -lGL -lGLU -lglut (for mac/Linux)

// Description : Displays a rotating 3D cube with colored faces in OpenGL.
//               Includes lighting, keyboard controls, mouse controls, and
//               navigation in 3D space with interaction feedback.
//============================================================================

#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

// Global Constants and Variables
const GLsizei WIN_WIDTH = 800, WIN_HEIGHT = 800; // Initial window size
const char *WINDOW_TITLE = "Render 3D Cube with Enhanced Controls";


// Global variables for camera control
GLfloat cameraX = 0.0f, cameraY = 0.0f, cameraZ = 5.0f; // Camera position
GLfloat targetX = 0.0f, targetY = 0.0f, targetZ = 0.0f; // Point the camera looks

GLfloat colorArray[6][3]; // Color array for each face of the cube
GLfloat rotationAngle = 0.0f; // Initial rotation angle
GLfloat rotationSpeed = 0.5f; // Rotation speed
GLfloat xTranslate = 0.0f, yTranslate = 0.0f, zTranslate = -2.0f; // Cube position
GLfloat xRotation = 0.0f, yRotation = 0.0f; // Manual rotation angles
bool isPaused = false; // Animation pause state

// Function Prototypes
void initializeOpenGL();
void initializeLighting();
void updateColorArray(GLfloat colorArray[6][3]);
void onDisplay();
void onReshape(GLint newWidth, GLint newHeight);
void rotateCube();
void drawCube();
void drawFace(GLfloat vertex1[], GLfloat vertex2[], GLfloat vertex3[], GLfloat vertex4[], int colorIndex);
void handleKeyboard(unsigned char key, int x, int y);
void handleSpecialKeys(int key, int x, int y);
void handleMouseMotion(int x, int y);
void renderText(float x, float y, const char* text);
void handleMenu(int option);

// Main Function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    initializeOpenGL();
    updateColorArray(colorArray); // Randomize colors for each cube face
    glutDisplayFunc(onDisplay);
    glutReshapeFunc(onReshape);
    glutIdleFunc(rotateCube);
    glutKeyboardFunc(handleKeyboard);
    glutSpecialFunc(handleSpecialKeys);
    glutMotionFunc(handleMouseMotion); // Mouse motion handler
    glutMainLoop();
    return 0;
}

// Function Definitions

/**
 * Initializes OpenGL settings and creates a window.
 */
void initializeOpenGL() {
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 50);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow(WINDOW_TITLE);

    glClearColor(0.90, 0.90, 0.90, 0.0); // Set background color to white
    glEnable(GL_DEPTH_TEST);           // Enable depth testing for 3D rendering
    glEnable(GL_LIGHTING);             // Enable lighting
    glEnable(GL_LIGHT0);               // Enable default light source
    glEnable(GL_COLOR_MATERIAL);       // Enable coloring of materials
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    initializeLighting();
    srand(static_cast<unsigned>(time(0))); // Seed for random color generation

    // Initialize the menu
    glutCreateMenu(handleMenu);
    glutAddMenuEntry("Reset", 1);
    glutAddMenuEntry("Pause/Resume", 2);
    glutAddMenuEntry("Increase Speed", 3);
    glutAddMenuEntry("Decrease Speed", 4);
    glutAddMenuEntry("Exit", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON); // Attach menu to the right mouse button

}

/**
 * Initializes basic lighting for the scene.
 */
void initializeLighting() {
    GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightPosition[] = { 1.0f, 1.0f, 1.0f, 0.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

/**
 * Generates random colors for each face of the cube and stores them in colorArray.
 */
void updateColorArray(GLfloat colorArray[6][3]) {
    for (int i = 0; i < 6; i++) {
        colorArray[i][0] = static_cast<float>(rand()) / RAND_MAX;
        colorArray[i][1] = static_cast<float>(rand()) / RAND_MAX;
        colorArray[i][2] = static_cast<float>(rand()) / RAND_MAX;
    }
}

/**
 * Renders text on the screen at the specified coordinates.
 * @param x     X-coordinate for the text.
 * @param y     Y-coordinate for the text.
 * @param text  Text to display.
 */
void renderText(float x, float y, const char* text) {
    glDisable(GL_LIGHTING); // Disable lighting for text rendering
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, WIN_WIDTH, 0, WIN_HEIGHT); // Set orthographic projection

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_LIGHTING); // Re-enable lighting
}

/**
 * Renders the 3D scene: a rotating cube with colored faces.
 */
void onDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(xTranslate, yTranslate, zTranslate); // Apply translations
    glRotatef(xRotation, 1, 0, 0); // Apply manual rotations
    glRotatef(yRotation, 0, 1, 0);
    glRotatef(rotationAngle, 1, 1, 1); // Rotate the cube along the X, Y, Z axes
    drawCube();

    // Render interaction feedback
    char info[256];
    snprintf(info, sizeof(info), "Rotation Speed: %.1f | Translation: (%.1f, %.1f, %.1f) | %s",
             rotationSpeed, xTranslate, yTranslate, zTranslate, isPaused ? "Paused" : "Running");
    renderText(10, WIN_HEIGHT - 20, info); // Render text at top-left corner

    glutSwapBuffers();
}

/**
 * Reshapes the viewport and adjusts the projection matrix to maintain aspect ratio.
 * @param newWidth  New width of the window.
 * @param newHeight New height of the window.
 */
void onReshape(GLint newWidth, GLint newHeight) {
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, static_cast<GLfloat>(newWidth) / static_cast<GLfloat>(newHeight), 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

/**
 * Increments the rotation angle of the cube and requests a display refresh.
 */
void rotateCube() {
    if (!isPaused) {
        rotationAngle += rotationSpeed;
        if (rotationAngle > 360) {
            rotationAngle = 0; // Reset angle to avoid overflow
        }
        glutPostRedisplay();
    }
}

/**
 * Draws a 3D cube with 6 faces, each with a different color from colorArray.
 */
void drawCube() {
    GLfloat vertices[8][3] = {
        { -0.5f, 0.5f, 0.5f }, { 0.5f, 0.5f, 0.5f }, { 0.5f, -0.5f, 0.5f }, { -0.5f, -0.5f, 0.5f },
        { -0.5f, 0.5f, -0.5f }, { 0.5f, 0.5f, -0.5f }, { 0.5f, -0.5f, -0.5f }, { -0.5f, -0.5f, -0.5f }
    };

    // Define cube faces using vertices and assign a color to each face
    drawFace(vertices[0], vertices[1], vertices[2], vertices[3], 0); // Front face
    drawFace(vertices[4], vertices[5], vertices[6], vertices[7], 1); // Back face
    drawFace(vertices[0], vertices[3], vertices[7], vertices[4], 2); // Left face
    drawFace(vertices[1], vertices[2], vertices[6], vertices[5], 3); // Right face
    drawFace(vertices[0], vertices[1], vertices[5], vertices[4], 4); // Top face
    drawFace(vertices[3], vertices[2], vertices[6], vertices[7], 5); // Bottom face
}

/**
 * Draws a single face of the cube with a specified color and border.
 * @param vertex1   First vertex of the face
 * @param vertex2   Second vertex of the face
 * @param vertex3   Third vertex of the face
 * @param vertex4   Fourth vertex of the face
 * @param colorIndex Index in colorArray for the color of this face
 */
void drawFace(GLfloat vertex1[], GLfloat vertex2[], GLfloat vertex3[], GLfloat vertex4[], int colorIndex) {
    // Draw the filled face with specified color
    glBegin(GL_POLYGON);
    glColor3fv(colorArray[colorIndex]);
    glVertex3fv(vertex1);
    glVertex3fv(vertex2);
    glVertex3fv(vertex3);
    glVertex3fv(vertex4);
    glEnd();

    // Draw the black border for the face
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3fv(vertex1);
    glVertex3fv(vertex2);
    glVertex3fv(vertex3);
    glVertex3fv(vertex4);
    glEnd();
}

/**
 * Handles keyboard input for controlling the cube's animation and position.
 * @param key The key pressed.
 * @param x   X-coordinate of the mouse (not used).
 * @param y   Y-coordinate of the mouse (not used).
 */
void handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+': // Increase rotation speed
            rotationSpeed += 0.1f;
            break;
        case '-': // Decrease rotation speed
            rotationSpeed = std::max(0.1f, rotationSpeed - 0.1f); // Prevent negative speed
            break;
        case ' ': // Pause or resume animation
            isPaused = !isPaused;
            break;
        case 'w': // Move forward
            zTranslate += 0.1f;
            break;
        case 's': // Move backward
            zTranslate -= 0.1f;
            break;
        case 'a': // Move left
            xTranslate -= 0.1f;
            break;
        case 'd': // Move right
            xTranslate += 0.1f;
            break;
        case 27: // Escape key to exit
            exit(0);
            break;
    }
    glutPostRedisplay();
}

/**
 * Handles special keys for vertical movement.
 * @param key The special key pressed.
 * @param x   X-coordinate of the mouse (not used).
 * @param y   Y-coordinate of the mouse (not used).
 */
void handleSpecialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP: // Move up
            yTranslate += 0.1f;
            break;
        case GLUT_KEY_DOWN: // Move down
            yTranslate -= 0.1f;
            break;
    }
    glutPostRedisplay();
}

/**
 * Handles mouse motion for manual rotation.
 * @param x   X-coordinate of the mouse.
 * @param y   Y-coordinate of the mouse.
 */
void handleMouseMotion(int x, int y) {
    xRotation = (x % 360) - 180; // Map mouse X position to rotation
    yRotation = (y % 360) - 180; // Map mouse Y position to rotation
    glutPostRedisplay();
}

/**
 * Menu handling function for menu options.
 * @param option The selected menu option.
 */
void handleMenu(int option) {
    switch (option) {
        case 1: // Reset
            xTranslate = 0.0f;
            yTranslate = 0.0f;
            zTranslate = -2.0f;
            xRotation = 0.0f;
            yRotation = 0.0f;
            rotationAngle = 0.0f;
            rotationSpeed = 0.5f;
            isPaused = false;
            break;
        case 2: // Pause/Resume
            isPaused = !isPaused;
            break;
        case 3: // Increase Speed
            rotationSpeed += 0.1f;
            break;
        case 4: // Decrease Speed
            rotationSpeed = std::max(0.1f, rotationSpeed - 0.1f); // Prevent negative speed
            break;
        case 5: // Exit
            exit(0);
            break;
    }
    glutPostRedisplay(); // Refresh the display
}
