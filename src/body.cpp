#include "../header/header.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>


void body(){
    
    glPushMatrix();
        //Buste
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(2.0);
        glPopMatrix();
        //Tete
        glTranslatef(0, 1.5, 0);
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(1.0);
        glPopMatrix();
        //Deuxième partie buste
        glTranslatef(0,-3.5, 0);
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(2.0);
        glPopMatrix();
    glPopMatrix();
}