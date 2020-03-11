#include "../header/header.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void leftArm(float armAngle){
   
    glPushMatrix();

        glTranslatef(2, 0, 0);
        glutWireSphere(0.5, 10 , 10);
        glRotatef(armAngle, 1, 0, 1);
        glTranslatef(1, 0, 0);
        //Avant Bras
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(1, 0, 0);
        glutWireSphere(0.5,10,10);
        glRotatef(10, 0, 0, 1);
        glTranslatef(1, 0, 0);
        //Bras
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();
}