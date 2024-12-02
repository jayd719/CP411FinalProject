/*
 * render.h
 *
 *  Created on: Dec 2, 2024
 *      Author: jashan
 */

#ifndef VIEW_HPP_
#define VIEW_HPP_
#include <GL/glut.h>

void initializeOpenGL();
void initializeLighting();
void onDisplay();
void onReshape(GLint newWidth, GLint newHeight);
void rotateShape();
#endif /* VIEW_HPP_ */
