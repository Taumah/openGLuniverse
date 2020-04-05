#include "../header/header.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

    /*--------- Global ---------------*/		//A declarer en global ou tout mettre dans la meme fonction
GLUquadricObj *pObj;		//definition du pointeur d'objet


extern float angle , angle2;

void rightHand(float handAngle){


/*--------- INIT ---------------*/		//En phase d'initialisation
pObj = gluNewQuadric();		//creation d'un objet(Retourne 0 si No Memory)

gluDeleteQuadric (pObj);		//detruit l'objet




    glPushMatrix();
        glTranslatef(-2, 0, 0);
        gluCylinder(pObj, 20, 20, 20, 20, 20);
        glRotatef(handAngle, 1, 0, 1);
        glTranslatef(-2, 0, 0);
        //Avant Bras


    glPopMatrix();
}