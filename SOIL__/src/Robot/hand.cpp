#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>



#include "../../include/header.hpp"


// extern float movAngle;

void hand(int side){

    glTranslatef(1.7*side , 0 , 0  );
    glRotatef(90 , 0 , 1 * side , 0);

    glPushMatrix();
        glScalef(0.5, 1, 1);
        GLUquadricObj *palm;
        palm = gluNewQuadric();
        gluQuadricNormals(palm, GLU_SMOOTH);
        glColor3f(.93, .85, .02);
        gluCylinder(palm, 0.3, 0.3, 0.6  ,MIN_SLICES, MIN_STACKS);
        gluDeleteQuadric(palm);
    glPopMatrix();



    int inclinaison = 50;

    glTranslatef( 0 , 0 , 0.2);


    for(int i = 0; i < 5; i++){       
        glPushMatrix();
            glRotatef(inclinaison, 1, 0, 0);
            glTranslatef(0, 0, 0.4);
            GLUquadricObj *finger;
            finger = gluNewQuadric();
            gluQuadricNormals(finger, GLU_SMOOTH);
            glColor3f(.93, .85, .02);
            gluCylinder(finger, 0.15, 0.05, 0.6, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(finger);
        glPopMatrix();
        inclinaison -= 20;      
          
    }

    


    
}