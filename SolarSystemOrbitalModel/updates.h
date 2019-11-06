#ifndef UPDATES_H_INCLUDED
#define UPDATES_H_INCLUDED

// header files
#include "display.h"
#include "io_handler.h"

/*
This function deals with solar system simulation timer function and all other ticking and updates
*/
void simulationUpdate(int value){

    glutPostRedisplay();                        // display has changed

    glutTimerFunc(25, simulationUpdate, 0);     // calling update() again and again in every 25 milliseconds
}

/*
This function deals with window resize
*/
void handleResize(int width, int height){

    glViewport(0, 0, width, height);        // sets the view port
    glMatrixMode(GL_PROJECTION);            // applies subsequent matrix operations to the projection matrix stack
    glLoadIdentity();                       // reset the drawing perspective

    // set up a perspective projection matrix and specifies a viewing frustum into the world coordinate system
    gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0);
}

#endif // UPDATES_H_INCLUDED
