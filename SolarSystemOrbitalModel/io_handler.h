#ifndef IO_HANDLER_H_INCLUDED
#define IO_HANDLER_H_INCLUDED

bool labelsActive = false;
bool solarSystemSimulation = true;

/*
This function handles all keyboard inputs
*/
void keyboardInput(unsigned char key, int x, int y){

    // this will activate all the planet name labels to the screen
    if(key == 'l' || key == 'L'){

        if(labelsActive){

            labelsActive = false;
        }else{

            labelsActive = true;
        }

        glutPostRedisplay();
    }

    // this will close the application
    if(key == 27){

        exit(0);
    }
}

#endif // IO_HANDLER_H_INCLUDED
