

#include "controller.hpp"
#include <cmath>
#include<iostream>


extern GLfloat rotationSpeed;
extern bool isPaused;
extern GLfloat xTranslate;
extern GLfloat yTranslate;
extern GLfloat zTranslate;
extern GLfloat xRotation;
extern GLfloat yRotation;

extern GLfloat cameraZ;
extern GLfloat cameraY;
extern GLfloat cameraX;

void handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+': rotationSpeed += 0.1f; break;
        case '-': rotationSpeed = std::max(0.1f, rotationSpeed - 0.1f); break;
        case ' ': isPaused = !isPaused; break;
        case 'w': zTranslate += 0.1f; break;
        case 's': zTranslate -= 0.1f; break;
        case 'a': xTranslate -= 0.1f; break;
        case 'd': xTranslate += 0.1f; break;
        case 'i': cameraX += 0.1f; break;
        case 'k': cameraX -= 0.1f; break;
        case 'j': cameraY -= 0.1f; break;
        case 'l': cameraY += 0.1f; break;
        case 'o': cameraZ -= 0.1f; break;
        case 'u': cameraZ += 0.1f; break;
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

// Mouse scroll handler
void handleMouseScroll(int button, int dir, int x, int y) {
    if (button == 3) { // Scroll up
    	zTranslate += 0.1f;
    } else if (button == 4) { // Scroll down
    	zTranslate -= 0.1f;
    }
    glutPostRedisplay(); // Refresh the display
}
