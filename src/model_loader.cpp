//============================================================================
// Project     : Render 3D Cube with Enhanced Controls
// Author      : JD
// Version     : 3.1
//============================================================================

#include <fstream>
#include <vector>
#include <cstring>
#include<iostream>
#include <GL/glut.h>

// Structure for storing STL triangle data
struct STLTriangle {
    GLfloat normal[3];
    GLfloat vertices[3][3];
};

// STL data storage
std::vector<STLTriangle> stlTriangles;

// Function to load STL file (supports binary STL)
bool loadSTL(const char *filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open STL file " << filename << std::endl;
        return false;
    }

    // Read header (80 bytes)
    char header[80];
    file.read(header, 80);

    // Read the number of triangles
    uint32_t numTriangles;
    file.read(reinterpret_cast<char*>(&numTriangles), sizeof(numTriangles));

    // Clear previous data
    stlTriangles.clear();
    stlTriangles.reserve(numTriangles);

    // Read each triangle
    for (uint32_t i = 0; i < numTriangles; ++i) {
        STLTriangle triangle;

        // Read normal
        file.read(reinterpret_cast<char*>(triangle.normal), sizeof(triangle.normal));

        // Read vertices
        for (int v = 0; v < 3; ++v) {
            file.read(reinterpret_cast<char*>(triangle.vertices[v]), sizeof(triangle.vertices[v]));
        }

        // Skip attribute byte count (2 bytes)
        file.ignore(2);

        // Add to the STL data vector
        stlTriangles.push_back(triangle);
    }

    file.close();
    return true;
}

void drawSTL() {
    glBegin(GL_TRIANGLES);
    for (size_t i = 0; i < stlTriangles.size(); ++i) {
        glNormal3fv(stlTriangles[i].normal);
        for (int v = 0; v < 3; ++v) {
            glVertex3fv(stlTriangles[i].vertices[v]);
        }
    }
    glEnd();
}

