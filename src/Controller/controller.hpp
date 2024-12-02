/*
 * input.h
 *
 *  Created on: Dec 2, 2024
 *      Author: jashan
 */

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_
#include <GL/glut.h>

void handleKeyboard(unsigned char key, int x, int y);
void handleSpecialKeys(int key, int x, int y);
void handleMouseMotion(int x, int y);
void handleMouseScroll(int button, int dir, int x, int y);


#endif /* CONTROLLER_HPP_ */
