#include "../header/header.hpp"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void head(float headAngle){
        //Tete
    glPushMatrix();
    glColor3f(.93, .85, .02);
        glTranslatef(0, 1, 0);
        glPushMatrix();
            glRotatef(-90, 1, 0, 0);
            GLUquadricObj *very_bottom_head;
            very_bottom_head = gluNewQuadric();
            gluQuadricNormals(very_bottom_head, GLU_SMOOTH);
            gluCylinder(very_bottom_head, .65, .55, .2, 1024, 1024);
            gluDeleteQuadric(very_bottom_head);
        glPopMatrix();
        
        glPushMatrix();
            glRotatef(-90, .2, 0, 0);
            GLUquadricObj *mid_bottom_head;
            mid_bottom_head = gluNewQuadric();
            gluQuadricNormals(mid_bottom_head, GLU_SMOOTH);
            gluCylinder(mid_bottom_head, .45, .45, .3, 1024, 1024);
            gluDeleteQuadric(mid_bottom_head);
        glPopMatrix();

        glTranslatef(0, .3, 0);
        glPushMatrix();
            glPushMatrix();
                glRotatef(-90, 1, 0, 0);
                GLUquadricObj *bottom_head;
                bottom_head = gluNewQuadric();
                gluQuadricNormals(bottom_head, GLU_SMOOTH);
                gluCylinder(bottom_head, .55, .7, 1, 1024, 1024);
                gluDeleteQuadric(bottom_head);
            glPopMatrix();
            
            glRotatef(headAngle, 0, 1, 0);
            glTranslatef(0, 1, 0);
            glPushMatrix();
                
                GLUquadricObj *top_head;
                top_head = gluNewQuadric();
                gluQuadricNormals(top_head, GLU_SMOOTH);
                gluSphere(top_head, .7, 1024, 1024);
                gluDeleteQuadric(top_head);
            glPopMatrix();

        glPopMatrix();
        glTranslatef(0, -1.5, 0);
        glColor3f(1, 1, 1);
    glPopMatrix();
}