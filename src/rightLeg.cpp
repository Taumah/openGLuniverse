#include "../header/header.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void rightLeg(float kneeAngle, float thigh){

    glPushMatrix();

        glTranslatef(1, -3, 0);
        glutWireSphere(0.5, 10, 10);
        glRotatef(thigh, 1, 0, 0);
        glTranslatef(0, -1, 0);
        //Cuisseau
        glPushMatrix();
            glScalef(1.5, 2, 1);
            glutWireCube(1.0);
        glPopMatrix();
        
        glTranslatef(0, -1, 0);
        glutWireSphere(0.5, 10, 10);
        glRotatef(kneeAngle, 1, 0, 0);
        glTranslatef(0, -1, 0);
        //Tibia
        glPushMatrix();
            glScalef(1.5, 2, 1);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();
}