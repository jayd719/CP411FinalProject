

#include "controller.hpp"

#include<iostream>


extern GLfloat rotationSpeed;
extern bool isPaused;
extern GLfloat xTranslate;
extern GLfloat yTranslate;
extern GLfloat zTranslate;
extern GLfloat xRotation;
extern GLfloat yRotation;
extern GLfloat zoom;

void handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+': rotationSpeed += 0.1f; break;
        case '-': rotationSpeed = std::max(0.1f, rotationSpeed - 0.1f); break;
        case ' ': isPaused = !isPaused; break;
        case 'w': zTranslate += 0.1f; break;
        case 's': zTranslate -= 0.1f; break;
        case 'a': xTranslate -= 0.1f; break;
        case 'd': xTranslate += 0.1f; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

void handleSpecialKeys(int key, int x, int y) {
    switch (key) {
		case GLUT_KEY_UP: yTranslate += 0.1f;break;
		case GLUT_KEY_DOWN:yTranslate -= 0.1f;break;
		case GLUT_KEY_LEFT: xTranslate -= 0.1f;break;
		case GLUT_KEY_RIGHT:xTranslate += 0.1f;break;
    }
    glutPostRedisplay();
}

void handleMouseMotion(int x, int y) {
    xRotation = (x % 360) - 180;
    yRotation = (y % 360) - 180;
    glutPostRedisplay();
}

void handleMouseScroll(int button, int dir, int x, int y) {
    if (dir > 0) zoom = std::max(0.5f, zoom - 0.05f);
    else zoom = std::min(2.0f, zoom + 0.05f);
    glutPostRedisplay();
}
