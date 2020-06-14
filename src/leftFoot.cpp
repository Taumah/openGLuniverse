#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "../header/header.hpp"

void leftFoot(){
    
    glPushMatrix();
    glColor3f(.93, .85, .02);
        glTranslatef(-1, -8.6, 0);
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *talon;
            talon = gluNewQuadric();
            gluQuadricNormals(talon, GLU_SMOOTH);
            gluCylinder(talon, .5, .5, .5, MIN_SLICES, MIN_STACKS);
        glPopMatrix();

        glTranslatef(0, -.5, -.2);
        glPushMatrix();
        glRotatef(10, 1, 0, 0);
            GLUquadricObj *pied;
            pied = gluNewQuadric();
            gluQuadricNormals(pied, GLU_SMOOTH);
            gluCylinder(pied, .5, .3, 2,MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(pied);
        glPopMatrix();
    glPopMatrix();
}