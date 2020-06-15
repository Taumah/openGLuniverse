#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../include/header.hpp"
#include "../../include/utils/all.hpp"

void rightArm(int armAngle){
   
    glPushMatrix();
        
        glTranslatef(2, 0, 0);
        glutWireSphere(0.5,MIN_SLICES, MIN_STACKS);
        glRotatef(-armAngle, 0, 0, 1);


        arm(RIGHT);

        glTranslatef(2, 0, 0);
        elbow();
        glRotatef(10, 0, 0, 1);
        // glTranslatef(1, 0, 0);
        
        forearm(RIGHT);
        
        hand(RIGHT);

    glPopMatrix();}
