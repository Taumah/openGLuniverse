#include "../header/header.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void rightLeg(float kneeAngle, float thigh){

    glPushMatrix();
    glColor3f(.93, .85, .02);
        glTranslatef(1, -3, 0);
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *cuisso;
            cuisso = gluNewQuadric();
            gluQuadricNormals(cuisso, GLU_SMOOTH);
            gluCylinder(cuisso, 1, .8, 2.5, 1024, 1024);
            gluDeleteQuadric(cuisso);
        glPopMatrix();

        glTranslatef(-0.8, -2.8, 0);
        glPushMatrix();
            glRotatef(90, 0, 1, 0);
            GLUquadricObj *genoux;
            genoux = gluNewQuadric();
            gluQuadricNormals(genoux, GLU_SMOOTH);
            gluCylinder(genoux, .5, .5, 1.6, 1024, 1024);
            gluDeleteQuadric(genoux);
        glPopMatrix();

        glTranslatef(0.8, -.3, 0);
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *tibia;
            tibia = gluNewQuadric();
            gluQuadricNormals(tibia, GLU_SMOOTH);
            gluCylinder(tibia, .7, .5, 2.5, 1024, 1024);
            gluDeleteQuadric(tibia);
        glPopMatrix();
    glPopMatrix();
}