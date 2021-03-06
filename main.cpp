/*
 * This software is the original work of Dyson Hamilton. ID: 23390662
 * This software is submitted in partial fulfilment of the
 * requirements for the degree of Information Technology.
 * Monash University
 */

#include <iostream>

#include "GL_routines.h"
#include "World.h"
using namespace std;

// because OpenGL works using eventHandlers you will need to define
// a few global variables. For example...

// YOUR_CREATURE_TYPE	gYourCreatureCollectionDataStruct;
World *g_test_world = new World(4);
std::string input_stream;

int gWinRows = 700;
int gWinCols = 700;


// Define a function which will always exit your program cleanly

void cleanQuit() {
    // put code in here to print out the message and quit the program
    exit(0);
}

int main(int argc, char **argv) {
    // Initialize OpenGL/GLUT (only do this once)
    glutInit(&argc, argv);

    // Set up OpenGL to use double buffering, RGB mode, and a depth-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Set up the window and open it
    glutInitWindowSize(gWinCols, gWinRows);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Your Window Name");

    // This routine makes the graphics window take up the whole screen
    // for when you want this to work in game mode
    // glutFullScreen();
    for (auto i : g_test_world->flower_container) {
        cout << "New Flower: \n";
        cout << i->get_flower_stats();
    }

    // Do some of your own initializations in this routine
    myInitializeOpenGL();

    // Register all of the event handlers
    glutDisplayFunc(displayWorld);
    glutVisibilityFunc(visible);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMove);
    glutPassiveMotionFunc(mousePassiveMove);
    glutIdleFunc(updateWorld);

    // Set the software looking for events in an infinite loop
    glutMainLoop();

    // ANSI C requires integer return type from main()
    return 0;
}