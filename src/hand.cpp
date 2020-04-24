#include "../header/header.hpp"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>







// extern float movAngle;

void hand(float armAngle){

    int inclinaison = 50;
    

    for(int i = 0; i < 5; i++){       
        glPushMatrix();
                glRotatef(100, inclinaison, 20, 20);
                glTranslatef(0, 0, 0.5);
                GLUquadricObj *very_bottom_head;
                very_bottom_head = gluNewQuadric();
                gluQuadricNormals(very_bottom_head, GLU_SMOOTH);
                glColor3f(.93, .85, .02);
                gluCylinder(very_bottom_head, 0.15, 0.15, 1, 1024, 1024);
                gluDeleteQuadric(very_bottom_head);
            glPopMatrix();
        inclinaison -= 10;        
    }

    glPushMatrix();
                glRotatef(50, 50, 50, 20);
                glScalef(0.5, 1, 1);
                GLUquadricObj *very_bottom_head;
                very_bottom_head = gluNewQuadric();
                gluQuadricNormals(very_bottom_head, GLU_SMOOTH);
                glColor3f(.93, .85, .02);
                gluCylinder(very_bottom_head, 0.5, 0.5, 1, 1024, 1024);
                gluDeleteQuadric(very_bottom_head);
            glPopMatrix();


    
}