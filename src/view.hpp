//============================================================================
// Project     : Render 3D Cube with Enhanced Controls
// Author      : JD
// Version     : 3.1
//============================================================================

#ifndef VIEW_HPP_
#define VIEW_HPP_
#include <GL/glut.h>

void initializeOpenGL();
void initializeLighting();
void onDisplay();
void onReshape(GLint newWidth, GLint newHeight);
void rotateShape();

#endif /* VIEW_HPP_ */
