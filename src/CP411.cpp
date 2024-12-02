#include "Model.h"
#include "View.h"
#include "Controller.h"
#include <cstdlib>
#include <ctime>

Model model;
View view;
Controller controller(model, view);

void displayCallback() { controller.onDisplay(); }
void reshapeCallback(int w, int h) { controller.onReshape(w, h); }
void idleCallback() { controller.onIdle(); }
void keyboardCallback(unsigned char key, int x, int y) { controller.onKeyboard(key, x, y); }
void specialKeysCallback(int key, int x, int y) { controller.onSpecialKeys(key, x, y); }
void mouseMotionCallback(int x, int y) { controller.onMouseMotion(x, y); }

int main_1(int argc, char** argv) {
    srand(static_cast<unsigned>(time(0))); // Initialize random seed

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("MVC 3D Cube");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glutDisplayFunc(displayCallback);
    glutReshapeFunc(reshapeCallback);
    glutIdleFunc(idleCallback);
    glutKeyboardFunc(keyboardCallback);
    glutSpecialFunc(specialKeysCallback);
    glutMotionFunc(mouseMotionCallback);

    glutMainLoop();
    return 0;
}
