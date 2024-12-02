/*
 * render.cpp
 *
 *  Created on: Dec 2, 2024
 *      Author: jashan
 */

#include <GL/glut.h>
#include "view.hpp"
#include "model.hpp"
#include "utilities.hpp"

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

extern GLfloat zoom;

enum ShapeType {
	CUBE, PYRAMID, SPHERE
};
extern ShapeType currentShape;

void initializeOpenGL() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);

	glClearColor(0.9, 0.9, 0.9, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	initializeLighting();
}

void initializeLighting() {
	GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat lightPosition[] = { 1.0f, 1.0f, 1.0f, 0.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void onDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(xTranslate, yTranslate, zTranslate);
	glRotatef(xRotation, 1, 0, 0);
	glRotatef(yRotation, 0, 1, 0);
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
	}
	glutSwapBuffers();
}

void onReshape(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0 * zoom,
			static_cast<GLfloat>(newWidth) / static_cast<GLfloat>(newHeight),
			1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}
void rotateShape() {
	if (!isPaused) {
		rotationAngle += rotationSpeed;
		if (rotationAngle > 360)
			rotationAngle = 0;
		glutPostRedisplay();
	}
}

