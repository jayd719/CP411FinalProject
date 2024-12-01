/*
 * config.h
 *
 *  Created on: Dec 2, 2024
 *      Author: jashan
 */

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Window Configuration
GLsizei WIN_WIDTH = 800, WIN_HEIGHT = 800;
const char *WINDOW_TITLE = "Render 3D Objects with Enhanced Controls";

// Enum for Shape Selection
enum ShapeType { CUBE, PYRAMID, SPHERE };
ShapeType currentShape = CUBE;

// Camera Configuration
GLfloat cameraX = 0.0f;
GLfloat cameraY = 0.0f;
GLfloat cameraZ = 2.0f;


// Global Variables
GLfloat colorArray[6][3];
GLfloat rotationAngle = 0.0f, rotationSpeed = 0.15f;
GLfloat xTranslate = 0.0f, yTranslate = 0.0f, zTranslate = -2.0f;
GLfloat xRotation = 0.0f, yRotation = 0.0f; GLfloat zRotation =0.0f;
bool isPaused = true;

GLfloat zoom = 1.5f;




#endif /* CONFIG_HPP_ */
