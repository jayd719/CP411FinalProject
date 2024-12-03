//============================================================================
// Project     : Render 3D Cube with Enhanced Controls
// Author      : JD
// Version     : 3.1
//============================================================================

#include <GL/glut.h>
#include "utilities.hpp"
#include <windows.h>
#include <cstdio>
#include <commdlg.h>
#include <iostream>


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

    unsigned char* pixels = new unsigned char[3 * WIN_WIDTH * WIN_HEIGHT];

    // Read pixels from the framebuffer
    glReadPixels(0, 0, WIN_WIDTH, WIN_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    // Flip the image vertically
    unsigned char* flippedPixels = new unsigned char[3 * WIN_WIDTH * WIN_HEIGHT];
    for (int y = 0; y < WIN_HEIGHT; ++y) {
        memcpy(&flippedPixels[y * WIN_WIDTH * 3], &pixels[(WIN_HEIGHT - 1 - y) * WIN_WIDTH * 3], WIN_WIDTH * 3);
    }

    char fullFileName[100];
    generateFileName(filename, fullFileName, sizeof(fullFileName));

    // Write the image to a PNG file
    stbi_write_png(fullFileName, WIN_WIDTH, WIN_HEIGHT, 3, flippedPixels, WIN_WIDTH * 3);

    delete[] pixels;
    delete[] flippedPixels;
}


void generateFileName(const char* baseName, char* fullFileName, size_t maxLength) {
	time_t now = time(NULL);
	tm* localTime = localtime(&now);
	char timeBuffer[20];
	strftime(timeBuffer, sizeof(timeBuffer), "%Y%m%d_%H%M%S", localTime);
	snprintf(fullFileName, maxLength, "%s_%s" , timeBuffer,baseName);
	renderText(20,20,"File Saved");
}




void openFileDialog(char* buffer, size_t bufferSize) {
    OPENFILENAME ofn = {0}; // Zero-initialize the structure
    ofn.lStructSize = sizeof(OPENFILENAME);

    ofn.lpstrFilter = "All Files\0*.*\0\0"; // Properly formatted filter
    ofn.lpstrFile = buffer;              // File path buffer
    ofn.nMaxFile = bufferSize;           // Buffer size
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY; // Flags

    // Open the file dialog
    if (!GetOpenFileName(&ofn)) {
        DWORD error = CommDlgExtendedError();
        if (error) {
            fprintf(stderr, "Error opening file dialog. Code: %lu\n", error);
        }
    }
}

