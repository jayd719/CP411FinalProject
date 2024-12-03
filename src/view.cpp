//============================================================================
// Project     : Render 3D Cube with Enhanced Controls
// Author      : JD
// Version     : 3.1
//============================================================================

#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "view.hpp"
#include "model.hpp"
#include "utilities.hpp"
#include "model_loader.hpp"

extern GLsizei WIN_WIDTH;
extern GLsizei WIN_HEIGHT;
extern char *WINDOW_TITLE;
extern GLfloat rotationAngle;
extern GLfloat rotationSpeed;
extern bool isPaused;
extern GLfloat xTranslate;
extern GLfloat yTranslate;
extern GLfloat zTranslate;

extern GLfloat xRotation;
extern GLfloat yRotation;
extern GLfloat zRotation;

extern GLfloat colorArray[6][3];

extern GLfloat zoom;

enum ShapeType {
	CUBE, PYRAMID, SPHERE, CUSTOM
};
extern ShapeType currentShape;

void initializeOpenGL() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutInitWindowPosition(100, 50);
	glutCreateWindow(WINDOW_TITLE);

	glClearColor(0.9, 0.9, 0.9, 0.0);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0 * zoom,
			static_cast<GLfloat>(WIN_WIDTH) / static_cast<GLfloat>(WIN_HEIGHT),
			1.0, 24.0);
	glMatrixMode(GL_MODELVIEW);

}

void initializeLighting() {
	GLfloat lightAmbient[] = { 0.9f, 0.9f, 0.9f, 1.0f };

	GLfloat lightPosition[] = { 0.0f, 0.f, 20.0f, 1.0f };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void onDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	initializeLighting();
	glLoadIdentity();
	glTranslatef(xTranslate, yTranslate, zTranslate);
	glRotatef(xRotation, 1, 0, 0);
	glRotatef(yRotation, 0, 1, 0);
	glRotatef(zRotation, 0, 0, 1);
	glRotatef(rotationAngle, 1, 1, 1);

	switch (currentShape) {
	case CUBE:
		drawCube();
		break;
	case PYRAMID:
		drawPyramid();
		break;
	case SPHERE:
		drawSphere();
		break;
	case CUSTOM:
		glColor3fv(colorArray[2]);
		drawSTL();

	}

	char info[256];
	glColor3f(0,0,0);
	snprintf(info, sizeof(info), "Rotation Speed: %.1f | %s", rotationSpeed,
			isPaused ? "Paused" : "Running");
	renderText(10, WIN_HEIGHT - 20, info);

	glutSwapBuffers();
}

void onReshape(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0 * zoom,
			static_cast<GLfloat>(newWidth) / static_cast<GLfloat>(newHeight),
			1.0, 25.0);
	glMatrixMode(GL_MODELVIEW);
	WIN_HEIGHT = newHeight;
	WIN_WIDTH = newWidth;
}
void rotateShape() {
	if (!isPaused) {
		rotationAngle += rotationSpeed;
		if (rotationAngle > 360)
			rotationAngle = 0;
		glutPostRedisplay();
	}
}

