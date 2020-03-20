#include "../header/header.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void head(float headAngle){
        //Tete
        glRotatef(headAngle, 0, 1, 0);
        glTranslatef(0, 2, 0);
        glPushMatrix();
            glColor3f(0.9373, .8471, 0.0275);
            GLUquadricObj *top_head;
            top_head = gluNewQuadric();
            gluQuadricNormals(top_head, GLU_SMOOTH);
            gluSphere(top_head, 1, 1024, 1024);
            gluDeleteQuadric(top_head);
        glPopMatrix();
        glRotatef(90, 1, 0, 0);
        glPushMatrix();
            GLUquadricObj *bottom_head;
            bottom_head = gluNewQuadric();
            gluQuadricNormals(bottom_head, GLU_SMOOTH);
            gluCylinder(bottom_head, 1, .8, 1, 1024, 1024);
        glPopMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(0, -1.5, 0);
}