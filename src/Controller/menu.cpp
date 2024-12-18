//============================================================================
// Project     : Render 3D Cube with Enhanced Controls
// Author      : JD
// Version     : 3.1
//============================================================================
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include "menu.hpp"
#include "../utilities.hpp"
#include "../model_loader.hpp"

extern GLfloat rotationSpeed;
extern GLfloat rotationAngle;
extern bool isPaused;
extern GLfloat xTranslate;
extern GLfloat yTranslate;
extern GLfloat zTranslate;
extern GLfloat xRotation;
extern GLfloat yRotation;

extern GLfloat cameraZ;
extern GLfloat cameraY;
extern GLfloat cameraX;

extern GLfloat zoom;
enum ShapeType {
	CUBE, PYRAMID, SPHERE, CUSTOM
};
extern ShapeType currentShape;

void initializeMenu() {
	//Initialize the menu
	GLint speedMenu = glutCreateMenu(handleSpeedSubMenu);
	glutAddMenuEntry("Increase Speed", 1);
	glutAddMenuEntry("Decrease Speed", 2);

	GLint zoomMenu = glutCreateMenu(handleZoomSubMenu);
	glutAddMenuEntry("Zoom In", 1);
	glutAddMenuEntry("Zoom Out", 2);

	glutCreateMenu(handleMainMenu);
	glutAddMenuEntry("Reset", 1);
	glutAddMenuEntry("Pause/Resume", 2);
	glutAddSubMenu("Speed", speedMenu);
	glutAddSubMenu("Zoom", zoomMenu);
	glutAddMenuEntry("Set Shape: Cube", 3);
	glutAddMenuEntry("Set Shape: Pyramid", 4);
	glutAddMenuEntry("Set Shape: Sphere", 5);
	glutAddMenuEntry("Load Custom Model", 6);
	glutAddMenuEntry("Save As PNG", 7);
	glutAddMenuEntry("Exit", 8);

}

void handleSpeedSubMenu(int option) {
	switch (option) {
	case 1:
		rotationSpeed += 0.1f;
		break;
	case 2:
		rotationSpeed = std::max(0.1f, rotationSpeed - 0.1f);
		break;
	}
}

void handleZoomSubMenu(int option) {
	switch (option) {
	case 1:
		zTranslate += 0.1f;
		break;
	case 2:
		zTranslate -= 0.1f;
		break;
	}
	glutPostRedisplay();
}

void handleMainMenu(int option) {
	switch (option) {
	case 1: // Reset
		xTranslate = 0.0f;
		yTranslate = 0.0f;
		zTranslate = -2.0f;
		xRotation = 0.0f;
		yRotation = 0.0f;
		rotationAngle = 0.0f;
		rotationSpeed = 0.5f;
		cameraX = 0.0f;
		cameraY = 0.0f;
		cameraZ = 5.0f;
		zoom = 1.5f;
		break;
	case 2: // Pause/Resume
		isPaused = !isPaused;
		break;

	case 3: // Set shape to Cube
		currentShape = CUBE;
		break;
	case 4: // Set shape to Pyramid
		currentShape = PYRAMID;
		break;
	case 5: // Set shape to Sphere
		currentShape = SPHERE;
		break;

	case 6: // load custom model
		handleSTLfile();
		currentShape = CUSTOM;
		break;
	case 7: // save as png
		saveFrameAsPNG("SaveFromMenu.png");
		break;
	case 8: // Exit
		exit(0);
		break;
	}
	glutPostRedisplay();
}

void handleSTLfile() {
	char buffer[256] = { 0 };
	openFileDialog(buffer, sizeof(buffer));
	loadSTL(buffer);
}

