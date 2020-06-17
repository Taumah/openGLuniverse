

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../include/header.hpp"
#include "../../include/utils/all.hpp"

extern float headAngle;
extern int armAngle;
extern float kneeAngle;
extern float kneeAngle2;


void robot(float* pos){

    glPushMatrix();
        
        glTranslatef(pos[0] , pos[1] , pos[2]);

        upperBody(headAngle);
        leftArm(armAngle);
        rightArm(armAngle);

        lowerBody();
        
        rightLeg(kneeAngle);
        leftLeg(kneeAngle2);

    glPopMatrix();
}