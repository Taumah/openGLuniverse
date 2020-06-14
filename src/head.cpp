#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "../header/header.hpp"


#define LEFT 1
#define RIGHT -1

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
            gluCylinder(very_bottom_head, .65, .55, .2,MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(very_bottom_head);
        glPopMatrix();
        
        glPushMatrix();
            glRotatef(-90, .2, 0, 0);
            GLUquadricObj *mid_bottom_head;
            mid_bottom_head = gluNewQuadric();
            gluQuadricNormals(mid_bottom_head, GLU_SMOOTH);
            gluCylinder(mid_bottom_head, .45, .45, .3,MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(mid_bottom_head);
        glPopMatrix();

        glTranslatef(0, .3, 0);
        glPushMatrix();
            glPushMatrix();
                glRotatef(-90, 1, 0, 0);
                GLUquadricObj *bottom_head;
                bottom_head = gluNewQuadric();
                gluQuadricNormals(bottom_head, GLU_SMOOTH);
                gluCylinder(bottom_head, .55, .7, 1,MIN_SLICES, MIN_STACKS);
                gluDeleteQuadric(bottom_head);
            glPopMatrix();
            
            glRotatef(headAngle, 0, 1, 0);
            glTranslatef(0, 1, 0);
            glPushMatrix();
                
                GLUquadricObj *top_head;
                top_head = gluNewQuadric();
                gluQuadricNormals(top_head, GLU_SMOOTH);
                gluSphere(top_head, .7, MIN_SLICES, MIN_STACKS);
                gluDeleteQuadric(top_head);

                
                glPushMatrix();
                    glTranslatef(0,0,.67);
                    
                    glColor3f( .04f , .04f , .04f );
                    GLUquadricObj *eyes;
                    eyes = gluNewQuadric();
                    // gluQuadricNormals(eyes, GLU_SMOOTH);
                    
                    eye(LEFT , eyes);
                    eye(RIGHT , eyes);

                    gluDeleteQuadric(eyes);

                glPopMatrix();

            glPopMatrix();

        glPopMatrix();
        glTranslatef(0, -1.5, 0);
        glColor3f(1, 1, 1);
    glPopMatrix();
}


void eye(int side , GLUquadricObj* eyes){
    glPushMatrix();
        glTranslatef(0.2 * side,0,0);
        gluSphere(eyes, .12, MIN_SLICES, MIN_STACKS);
    glPopMatrix();
}