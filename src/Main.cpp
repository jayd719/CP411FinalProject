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

#include "config.hpp"
#include "controller.hpp"
#include "utilities.hpp"
#include "view.hpp"


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

    glutMainLoop();
    return 0;
}


