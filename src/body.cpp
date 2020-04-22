#include "../header/header.hpp"
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
        //Deuxième partie buste
        glTranslatef(0,-2, 0);
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(2.0);
        glPopMatrix();
    glPopMatrix();
}
