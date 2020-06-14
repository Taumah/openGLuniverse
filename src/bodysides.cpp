#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>


#include "../header/header.hpp"

void leftBodySide(){
    glPushMatrix();
        glTranslatef(-1, 0.72, 0);
        glRotatef(90, 1, 0, 0);
        GLUquadricObj *cuisso;
        cuisso = gluNewQuadric();
        gluQuadricNormals(cuisso, GLU_SMOOTH);
        gluCylinder(cuisso, .7, .9, 2.5, MIN_SLICES, MIN_STACKS);
        gluDeleteQuadric(cuisso);
    glPopMatrix();
}

void rightBodySide(){
    glPushMatrix();
        glTranslatef(1, 0.72, 0);
        glRotatef(90, 1, 0, 0);
        GLUquadricObj *cuisso;
        cuisso = gluNewQuadric();
        gluQuadricNormals(cuisso, GLU_SMOOTH);
        gluCylinder(cuisso, .7, .9, 2.5, MIN_SLICES, MIN_STACKS);
        gluDeleteQuadric(cuisso);
    glPopMatrix();
}