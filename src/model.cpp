//============================================================================
// Project     : Render 3D Cube with Enhanced Controls
// Author      : JD
// Version     : 3.1
//============================================================================

#include "model.hpp"


extern GLfloat colorArray[6][3];

void drawFace(GLfloat vertex1[], GLfloat vertex2[], GLfloat vertex3[],
		GLfloat vertex4[], int colorIndex) {
	// Draw the filled face with specified color
	glBegin(GL_POLYGON);
	glColor3fv(colorArray[colorIndex]);
	glVertex3fv(vertex1);
	glVertex3fv(vertex2);
	glVertex3fv(vertex3);
	glVertex3fv(vertex4);
	glEnd();
}

void drawCube() {
    GLfloat vertices[8][3] = { { -0.5f, 0.5f, 0.5f }, { 0.5f, 0.5f, 0.5f },
                               { 0.5f, -0.5f, 0.5f }, { -0.5f, -0.5f, 0.5f },
                               { -0.5f, 0.5f, -0.5f }, { 0.5f, 0.5f, -0.5f },
                               { 0.5f, -0.5f, -0.5f }, { -0.5f, -0.5f, -0.5f } };

    drawFace(vertices[0], vertices[1], vertices[2], vertices[3], 0);
    drawFace(vertices[4], vertices[5], vertices[6], vertices[7], 1);
    drawFace(vertices[0], vertices[3], vertices[7], vertices[4], 2);
    drawFace(vertices[1], vertices[2], vertices[6], vertices[5], 3);
    drawFace(vertices[0], vertices[1], vertices[5], vertices[4], 4);
    drawFace(vertices[3], vertices[2], vertices[6], vertices[7], 5);
}

void drawPyramid() {
    GLfloat vertices[5][3] = {
        { 0.0f, 0.5f, 0.0f },
        { -0.5f, -0.5f, 0.5f },
        { 0.5f, -0.5f, 0.5f },
        { 0.5f, -0.5f, -0.5f },
        { -0.5f, -0.5f, -0.5f }
    };

    glBegin(GL_TRIANGLES);
    for (int i = 1; i <= 4; ++i) {
        glColor3fv(colorArray[i - 1]);
        glVertex3fv(vertices[0]);
        glVertex3fv(vertices[i]);
        glVertex3fv(vertices[i % 4 + 1]);
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3fv(colorArray[4]);
    for (int i = 1; i <= 4; ++i) {
        glVertex3fv(vertices[i]);
    }
    glEnd();
}

void drawSphere() {
    glColor3fv(colorArray[0]);
    glutSolidSphere(0.5, 30, 30);
}





