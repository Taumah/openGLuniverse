#include "../header/header.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

extern float angle , angle2;


//jcrois que c'est le bras gauche en fait
void leftArm(){
    glPushMatrix();
        glTranslatef(-2, 0, 0);
        glutWireSphere(0.5, 10 , 10);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(-1, 0, 0);
        //Avant Bras
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(-1, 0, 0);
        glutWireSphere(0.5,10,10);
        glRotatef(angle2, 0, 0, 1);
        glTranslatef(-1, 0, 0);
        //Bras
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();
}