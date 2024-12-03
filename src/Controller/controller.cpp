
#include "controller.hpp"
#include "../utilities.hpp"
#include <cmath>
#include<iostream>

extern GLfloat rotationSpeed;
extern bool isPaused;
extern GLfloat xTranslate;
extern GLfloat yTranslate;
extern GLfloat zTranslate;
extern GLfloat xRotation;
extern GLfloat yRotation;
extern GLfloat zRotation;

const GLfloat sensitivity = 0.0025f;
const GLfloat RotStep = 0.75f;

void handleKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '+':
		rotationSpeed += 0.1f;
		break;
	case '-':
		rotationSpeed = std::max(0.1f, rotationSpeed - 0.1f);
		break;
	case ' ':
		isPaused = !isPaused;
		break;
	case 'w':
		xRotation += RotStep;
		break;
	case 's':
		xRotation -= RotStep;
		break;
	case 'a':
		yRotation -= RotStep;
		break;
	case 'd':
		yRotation += RotStep;
		break;
	case 'q':
		zRotation -= RotStep;
		break;
	case 'e':
		zRotation += RotStep;
		break;
	case 'p':
		saveFrameAsPNG("output.png");
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

void handleSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		yTranslate += 0.1f;
		break;
	case GLUT_KEY_DOWN:
		yTranslate -= 0.1f;
		break;
	case GLUT_KEY_LEFT:
		xTranslate -= 0.1f;
		break;
	case GLUT_KEY_RIGHT:
		xTranslate += 0.1f;
		break;
	}
	glutPostRedisplay();
}

void handleMouseMotion(int x, int y) {
	if (abs(x) > abs(y)) {
		// Horizontal movement: determine left or right
		if (x > 0) {
			// Moving right
			xRotation += (x * sensitivity);
		} else {
			// Moving left
			xRotation += (x * sensitivity); // Negative x adjusts rotation accordingly
		}
		xRotation = fmod(xRotation, 360.0f);
		if (xRotation < 0)
			xRotation += 360.0f;
	} else {
		// Vertical movement: determine up or down
		if (y > 0) {
			// Moving down
			yRotation += (y * sensitivity);
		} else {
			// Moving up
			yRotation += (y * sensitivity); // Negative y adjusts rotation accordingly
		}
		yRotation = fmod(yRotation, 360.0f);
		if (yRotation < 0)
			yRotation += 360.0f;
	}

	glutPostRedisplay();
}

// Mouse scroll handler
void handleMouseScroll(int button, int dir, int x, int y) {
	if (button == 3) { // Scroll in
		zTranslate += 0.1f;
	} else if (button == 4) { // Scroll out
		zTranslate -= 0.1f;
	}
	glutPostRedisplay(); // Refresh the display
}
