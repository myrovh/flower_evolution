/*
 * This software is the original work of Dyson Hamilton. ID: 23390662
 * This software is submitted in partial fulfilment of the
 * requirements for the degree of Information Technology.
 * Monash University
 */

#include <iostream>
#include "GL_routines.h"
#include "World.h"

extern World *g_test_world;

extern std::string input_stream;

extern void cleanQuit();

void myInitializeOpenGL(void) {
    // Set the background/clear-the-screen colour
    glClearColor(0.02, 0.02, 0.02, 0.0);

    // These routines ensure that objects further away from
    // the viewpoint will be drawn on top of by closer objects (using a "depth-buffer" or "z-buffer")
    glDepthMask(GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    std::cerr << "\nIn myInitializeOpenGL(void)";
}

void displayWorld(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    int draw_call_count = 0;
    for (auto f : g_test_world->flower_container) {
        //START Render flower petal
        glPushMatrix();
        std::pair<int, int> grid_location = g_test_world->get_flower_location(draw_call_count);
        glTranslated(grid_location.first, grid_location.second, 0);
        f->draw_petal_ring();
        glPopMatrix();
        //END

        //START render flower number
        std::stringstream stream;
        stream << draw_call_count;
        glPushMatrix();
        glTranslated(grid_location.first, grid_location.second - 18, 0);
        glScalef(0.03, 0.03, 0.03);
        for (auto character = stream.str().begin(); character < stream.str().end(); character++) {
            glutStrokeCharacter(GLUT_STROKE_ROMAN, (*character));
        }
        glPopMatrix();
        //END

        draw_call_count++;
    }

    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    std::cerr << "\nIn reshape(w,h)";

    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // lookAt from, to, up
    /* gluLookAt (0, -10, 0,
                      0, 0, 0,
                          0, 0, 1);
        */
    gluOrtho2D(-100, +100, -100, 100);

    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    // extern gYourCreatureCollectionDataStruct here

    switch (key) {
        // character 27 is the escape key. Use this or Q/q to quit the program
        case 27:
        case 'q':
        case 'Q':
            // Call your cleanQuit routine to quit neatly
            cleanQuit();
            break;
        case '1':
            input_stream += '1';
            break;
        case '2':
            input_stream += '2';
            break;
        case '3':
            input_stream += '3';
            break;
        case '4':
            input_stream += '4';
            break;
        case '5':
            input_stream += '5';
            break;
        case '6':
            input_stream += '6';
            break;
        case '7':
            input_stream += '7';
            break;
        case '8':
            input_stream += '8';
            break;
        case '9':
            input_stream += '9';
            break;
        case '0':
            input_stream += '0';
            break;
        case 13: //Enter key
            g_test_world->selection_check(input_stream);
            input_stream = "";
            break;
        case 'm': {
            if (g_test_world->parent_2 != nullptr && g_test_world->parent_1 != nullptr) {
                g_test_world->generate_new_world(g_test_world, g_test_world->mate_flowers());
            }
            break;
        }
        case 'r':
            g_test_world->generate_new_world(g_test_world);
            break;
        default:
            break;
    }
}

void mouse(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                glutPostRedisplay();
            }
            break;

        default:

            break;
    }
}

void mouseMove(int x, int y) {
    // Sometimes its useful to keep track of the old mouse
    // position so that you can compare it to new mouse positions.
    // You'll need static variables to do this... why?
    static int oldX = 0;
    static int oldY = 0;
    static bool firstCall = true;

    // What is the use of this if statement?
    if (firstCall) {
        oldX = x;
        oldY = y;
        firstCall = false;
        return;
    }

    // Do things in here with the difference b/n the new mouse x,y and oldX,oldY
    // to make your program's behaviour respond to mouse movements.

    // Then set the old mouse position to the current mouse position
    // for next time around...
    oldX = x;
    oldY = y;
}

void mousePassiveMove(int x, int y) {
    // What might you write in here?
    // What is this event handler for?
}

void visible(int vis) {
    if (vis == GLUT_VISIBLE) glutIdleFunc(updateWorld);
    else glutIdleFunc(NULL);
}

void updateWorld(void) {
    glutPostRedisplay();
}

void null_select(int mode) {    /* nothing */ }

void menu_select(int mode) {
    switch (mode) {
        case 1:
            // Put code in here to handle the first menu item
            break;

        case 2:
            // Code to handle the menu quit...
        {
            cleanQuit();
        }
            break;
        default:
            return;
    }
}

void glutMenu(void) {
    int glut_menu;

    glut_menu = glutCreateMenu(menu_select);

    glutAddMenuEntry("Do Nothing", 1);
    glutAddMenuEntry("Quit", 2);

    glutAttachMenu(GLUT_LEFT_BUTTON);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}