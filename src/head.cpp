#include "../header/header.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void head(float headAngle){
        //Tete
        glRotatef(headAngle, 0, 1, 0);
        glTranslatef(0, 1.5, 0);
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(1.0);
        glPopMatrix();
        glTranslatef(0, -1.5, 0);
}