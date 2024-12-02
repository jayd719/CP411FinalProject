/*
 * Mode.h
 *
 *  Created on: Dec 1, 2024
 *      Author: jashan
 */

#ifndef MODEL_H_
#define MODEL_H_


#include <GL/glut.h>

// Model class to manage cube properties
class Model {
public:
    GLfloat colorArray[6][3]; // Colors for cube faces
    GLfloat rotationAngle;   // Current rotation angle
    GLfloat rotationSpeed;   // Speed of rotation
    GLfloat xTranslate, yTranslate, zTranslate; // Translation values
    GLfloat xRotation, yRotation; // Manual rotation angles
    bool isPaused;           // Animation pause state

    Model() : rotationAngle(0.0f), rotationSpeed(0.5f),
              xTranslate(0.0f), yTranslate(0.0f), zTranslate(-2.0f),
              xRotation(0.0f), yRotation(0.0f), isPaused(false) {
        generateRandomColors();
    }

    void generateRandomColors() {
        for (int i = 0; i < 6; ++i) {
            colorArray[i][0] = static_cast<float>(rand()) / RAND_MAX;
            colorArray[i][1] = static_cast<float>(rand()) / RAND_MAX;
            colorArray[i][2] = static_cast<float>(rand()) / RAND_MAX;
        }
    }
};

#endif /* MODEL_H_ */
