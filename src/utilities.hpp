/*
 * utilities.h
 *
 *  Created on: Dec 2, 2024
 *      Author: jashan
 */

#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#include <iostream>
#include <ctime>
#include <string>

using namespace std;


#include <GL/glut.h>

void updateColorArray(GLfloat colorArray[6][3]);
void renderText(float x, float y, const char* text);
void saveFrameAsPNG(const char* filename);
string generateFileName(const char* baseName);

#endif /* UTILITIES_HPP_ */
