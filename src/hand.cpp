#include "../header/header.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>







// extern float movAngle;

void hand(float armAngle){

    

    glPushMatrix();
            glRotatef(-90, 1, 1, 2);
            GLUquadricObj *very_bottom_head;
            very_bottom_head = gluNewQuadric();
            gluQuadricNormals(very_bottom_head, GLU_SMOOTH);
            glColor3f(0.8, 0.8 , 0.7);
            gluCylinder(very_bottom_head, 0.50, 0.50, 1, 1024, 1024);
            gluDeleteQuadric(very_bottom_head);
        glPopMatrix();

    
}