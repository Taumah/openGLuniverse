#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "../header/header.hpp"
#include "../header/utils/all.hpp"

void rightLeg(float kneeAngle){


    glPushMatrix();

    glRotatef(-kneeAngle*0.3 , 1 , 0 , 0 );


    glColor3f(.93, .85, .02);

        glTranslatef(1, -3, 0);
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *cuisso;
            cuisso = gluNewQuadric();
            gluQuadricNormals(cuisso, GLU_SMOOTH);
            gluCylinder(cuisso, 0.8, .6, 2.5,MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(cuisso);
        glPopMatrix();

        glTranslatef(-0.8, -2.8, 0);
        glPushMatrix();
            glRotatef(90, 0, 1, 0);
            GLUquadricObj *genoux;
            genoux = gluNewQuadric();
            gluQuadricNormals(genoux, GLU_SMOOTH);
            gluCylinder(genoux, .5, .5, 1.6,MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(genoux);
        glPopMatrix();

        glPushMatrix();
            glRotatef(-90, 0, 1, 0);
            GLUquadricObj *leftdisk;
            leftdisk = gluNewQuadric();
            gluQuadricNormals(leftdisk, GLU_SMOOTH);
            gluDisk(leftdisk, 0, .5, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(leftdisk);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(1.6, 0, 0);
            glRotatef(90, 0, 1, 0);
            GLUquadricObj *rightdisk;
            rightdisk = gluNewQuadric();
            gluQuadricNormals(rightdisk, GLU_SMOOTH);
            gluDisk(rightdisk, 0, .5, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(rightdisk);
        glPopMatrix();
        
        glRotatef(kneeAngle , 1 , 0 , 0);


        glTranslatef(0.8, -.3, 0);
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *tibia;
            tibia = gluNewQuadric();
            gluQuadricNormals(tibia, GLU_SMOOTH);
            gluCylinder(tibia, .65, .45, 2.5, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(tibia);
        glPopMatrix();


        foot(RIGHT);
        
    glPopMatrix();
}