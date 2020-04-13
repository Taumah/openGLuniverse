#include "../header/header.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "../header/utils/all.h"

void rightArm(float armAngle){
   
    glPushMatrix();
        glTranslatef(2, 0, 0);
        glutWireSphere(0.5, 10 , 10);
        glRotatef(armAngle, 1, 0, 1);


        arm(RIGHT);

        glTranslatef(2, 0, 0);
        elbow();
        glRotatef(10, 0, 0, 1);
        // glTranslatef(1, 0, 0);
        
        forearm(RIGHT);
        
    glPopMatrix();}
