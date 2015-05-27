/*
 * This software is the original work of Dyson Hamilton. ID: 23390662
 * This software is submitted in partial fulfilment of the
 * requirements for the degree of Information Technology.
 * Monash University
 */

#ifndef GL_ROUTINES
#define GL_ROUTINES

#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>

// -- GL routines
void myInitializeOpenGL(void);

void displayWorld(void);

void reshape(int w, int h);

void updateWorld(void);

void keyboard(unsigned char key, int x, int y);

void mouse(int button, int state, int x, int y);

void mouseMove(int x, int y);

void mousePassiveMove(int x, int y);

void visible(int vis);

void null_select(int mode);

void menu_select(int mode);

void glutMenu(void);

#endif