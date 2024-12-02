/*
 * utilities.cpp
 *
 *  Created on: Dec 2, 2024
 *      Author: jashan
 */

#include <GL/glut.h>

#include "utilities.hpp"



#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "include/stb_image_write.h"


extern GLsizei WIN_WIDTH;
extern GLsizei WIN_HEIGHT;

void updateColorArray(GLfloat colorArray[6][3]) {
    for (int i = 0; i < 6; i++) {
        colorArray[i][0] = static_cast<float>(rand()) / RAND_MAX;
        colorArray[i][1] = static_cast<float>(rand()) / RAND_MAX;
        colorArray[i][2] = static_cast<float>(rand()) / RAND_MAX;
    }
}

void renderText(float x, float y, const char* text) {
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, WIN_WIDTH, 0, WIN_HEIGHT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_LIGHTING);
}




void saveFrameAsPNG(const char* filename) {
    int width = WIN_WIDTH;
    int height = WIN_HEIGHT;
    unsigned char* pixels = new unsigned char[3 * width * height];

    // Read pixels from the framebuffer
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    // Flip the image vertically
    unsigned char* flippedPixels = new unsigned char[3 * width * height];
    for (int y = 0; y < height; ++y) {
        memcpy(&flippedPixels[y * width * 3], &pixels[(height - 1 - y) * width * 3], width * 3);
    }




    // Write the image to a PNG file
    stbi_write_png(filename, width, height, 3, flippedPixels, width * 3);

    delete[] pixels;
    delete[] flippedPixels;
}
