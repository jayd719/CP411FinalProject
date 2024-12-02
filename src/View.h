/*
 * View.h
 *
 *  Created on: Dec 1, 2024
 *      Author: jashan
 */

#ifndef VIEW_H_
#define VIEW_H_

#include "Model.h"

// View class to handle rendering
class View {
public:
	void renderCube(const Model& model) {
		glLoadIdentity();
		glTranslatef(model.xTranslate, model.yTranslate, model.zTranslate); // Apply translations
		glRotatef(model.xRotation, 1, 0, 0); // Apply manual rotations
		glRotatef(model.yRotation, 0, 1, 0);
		glRotatef(model.rotationAngle, 1, 1, 1); // Rotate cube along X, Y, Z axes

		GLfloat vertices[8][3] = { { -0.5f, 0.5f, 0.5f }, { 0.5f, 0.5f, 0.5f },
				{ 0.5f, -0.5f, 0.5f }, { -0.5f, -0.5f, 0.5f }, { -0.5f, 0.5f,
						-0.5f }, { 0.5f, 0.5f, -0.5f }, { 0.5f, -0.5f, -0.5f },
				{ -0.5f, -0.5f, -0.5f } };

		// Draw each face with its respective color
		drawFace(vertices[0], vertices[1], vertices[2], vertices[3],
				model.colorArray[0]); // Front
		drawFace(vertices[4], vertices[5], vertices[6], vertices[7],
				model.colorArray[1]); // Back
		drawFace(vertices[0], vertices[3], vertices[7], vertices[4],
				model.colorArray[2]); // Left
		drawFace(vertices[1], vertices[2], vertices[6], vertices[5],
				model.colorArray[3]); // Right
		drawFace(vertices[0], vertices[1], vertices[5], vertices[4],
				model.colorArray[4]); // Top
		drawFace(vertices[3], vertices[2], vertices[6], vertices[7],
				model.colorArray[5]); // Bottom
	}

	void drawFace(GLfloat v1[], GLfloat v2[], GLfloat v3[], GLfloat v4[],
			const GLfloat* color) {
		glBegin(GL_POLYGON);
		glColor3fv(color);
		glVertex3fv(v1);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glVertex3fv(v4);
		glEnd();

		// Draw borders
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0);
		glVertex3fv(v1);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glVertex3fv(v4);
		glEnd();
	}
};

#endif /* VIEW_H_ */
