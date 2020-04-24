#include "../header/header.hpp"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>


void lowerBody(){
    glPushMatrix();
        glColor3f(.93, .85, .02);
        glTranslatef(0, -2, 0);
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *low_lowpart;
            low_lowpart = gluNewQuadric();
            gluQuadricNormals(low_lowpart, GLU_SMOOTH);
            gluCylinder(low_lowpart, 2, .8, 2.5, 1024, 1024);
            gluDeleteQuadric(low_lowpart);
        glPopMatrix();
    glPopMatrix();
}