/*
 * Controller.h
 *
 *  Created on: Dec 1, 2024
 *      Author: jashan
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include<iostream>
#include "Model.h"
#include "View.h"

class Controller {
private:
	Model& model;
	View& view;

public:
	Controller(Model& m, View& v) :
			model(m), view(v) {
	}

	void onDisplay() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		view.renderCube(model);
		glutSwapBuffers();
	}

	void onIdle() {
		if (!model.isPaused) {
			model.rotationAngle += model.rotationSpeed;
			if (model.rotationAngle > 360)
				model.rotationAngle = 0;
			glutPostRedisplay();
		}
	}

	void onReshape(int width, int height) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0, (GLfloat) width / (GLfloat) height, 1.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
	}

	void onKeyboard(unsigned char key, int x, int y) {
		switch (key) {
		case '+':
			model.rotationSpeed += 0.1f;
			break;
		case '-':
			model.rotationSpeed = std::max(0.1f, model.rotationSpeed - 0.1f);
			break;
		case 'p':
			model.isPaused = !model.isPaused;
			break; // Pause/unpause
		case 27:
			exit(0);
			break; // ESC to quit
		}
	}

	void onSpecialKeys(int key, int x, int y) {
		switch (key) {
		case GLUT_KEY_UP:
			model.yTranslate += 0.1f;
			break;
		case GLUT_KEY_DOWN:
			model.yTranslate -= 0.1f;
			break;
		case GLUT_KEY_LEFT:
			model.xTranslate -= 0.1f;
			break;
		case GLUT_KEY_RIGHT:
			model.xTranslate += 0.1f;
			break;
		}
	}

	void onMouseMotion(int x, int y) {
		model.xRotation = (y - 400) / 4.0f; // Adjust these constants for sensitivity
		model.yRotation = (x - 400) / 4.0f;
	}
};
#endif /* CONTROLLER_H_ */
