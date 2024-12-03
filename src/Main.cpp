//============================================================================
// Project     : Render 3D Cube with Enhanced Controls
// Author      : JD
// Version     : 3.1
// Run         : g++ 3dCube.cpp -o 3dCube -lfreeglut -lfreeglut -lComdlg32 -lopengl32 -lglu32
// Description : Displays a rotating 3D cube with colored faces in OpenGL.
//               Includes lighting, keyboard controls, mouse controls, and
//               navigation in 3D space with interaction feedback.
//============================================================================

#include <GL/glut.h>                    // OpenGL Utility Toolkit
#include "config.hpp"                  // Configuration settings for OpenGL
#include "view.hpp"                   // View and rendering-related logic
#include "Controller/controller.hpp" // Input handling (keyboard, mouse, etc.)
#include "Controller/menu.hpp"       // Menu handling functions
#include "utilities.hpp"            // Utility functions (color management, etc.)


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    initializeOpenGL();

    updateColorArray(colorArray);

    // Register callback functions
    glutDisplayFunc(onDisplay);
    glutReshapeFunc(onReshape);

    glutIdleFunc(rotateShape);

    glutKeyboardFunc(handleKeyboard);
    glutSpecialFunc(handleSpecialKeys);

    glutMotionFunc(handleMouseMotion);
    glutMouseFunc(handleMouseScroll);

    initializeMenu(); // int menu
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}


