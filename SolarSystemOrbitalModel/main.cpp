///Project Name: Solar System Orbital Model
///Members:
/// Arham Rashid Khan  -   16511005
/// Dip Bhakta   -   16511007
/// Fahad Morshed   -  16511008
/// Md.Ahsan Fuad Apu  -   16511019

#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string>

#define RADIAN 180.0/3.141592

// global scope variables
int width = 750;
int height = 750;

// function prototypes
void drawInstructions();

// header files
#include "initialization.h"
#include "updates.h"
#include "display.h"
#include "materials.h"
#include "io_handler.h"
#include "planet.h"
#include "stars.h"

using namespace std;

// main function
int main(int argc, char** argv){
    // solar system simulation
    createPlanets();
    generateRandomPosition();

    glutInit(&argc, argv);                                          // initializes the GLUT library
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);       // determines the OpenGL display mode
    glutInitWindowSize(width, height);                              // defines window size
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-width)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-height)/2); // setting the window at the middle of the screen
    glutCreateWindow("Solar System Orbital Model");                                      // creates the window

    // initializations
    init();
    initRendering();

    // handler functions
    glutDisplayFunc(display);           // sets the display callback for the current window
    // sets the reshape callback for the current window and is triggered when a window is reshaped
    glutReshapeFunc(handleResize);

    // i/o handlers
    glutKeyboardFunc(keyboardInput);

	// adding a timer function
	glutTimerFunc(25, simulationUpdate, 0);

    glutMainLoop();                        // enters the GLUT event processing loop
	return 0;
}

/*
This function will display all instruction strings to the screen
*/
void drawInstructions(){

    if(solarSystemSimulation){

        glPushMatrix();
        glRasterPos3f(-5.85, -9.2, 0.0);                                         // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_12, "i. Press L or l for Planet Labels"); // drawing instructions strings
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-5.69, -9.7, 0.0);                                        // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_12, "ii. Press ESC to terminate");    // drawing instructions strings
        glPopMatrix();
    }
}
