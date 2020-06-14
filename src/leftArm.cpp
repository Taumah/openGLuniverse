#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "../header/utils/all.hpp"
#include "../header/header.hpp"

void leftArm(int armAngle){

    glPushMatrix();

        glTranslatef(-2, 0, 0);
        glutWireSphere(0.5, MIN_SLICES, MIN_STACKS);
        glRotatef(armAngle, 0, 0, 1);
        
        arm(LEFT);

        
        glTranslatef(-2, 0, 0);
        elbow();
        glRotatef(10, 0, 0, 1);

        forearm(LEFT);

        hand(LEFT);

    glPopMatrix();
}
