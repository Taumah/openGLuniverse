#include "../header/header.hpp"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "../header/utils/all.hpp"

void leftArm(float armAngle){

    glPushMatrix();
        glTranslatef(-2, 0, 0);
        glutWireSphere(0.5, 10 , 10);
        glRotatef(60, 1, 0, 1);
        
        arm(LEFT);

        
        glTranslatef(-2, 0, 0);
        elbow();
        glRotatef(10, 0, 0, 1);

        forearm(LEFT);
    glPopMatrix();
}
