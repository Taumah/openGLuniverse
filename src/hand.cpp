#include "../header/header.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>







extern float angle , angle2;

void hand(float armAngle){



    /*--------- Global ---------------*/		//A declarer en global ou tout mettre dans la meme fonction
GLUquadricObj *pObj;		//definition du pointeur d'objet
/*--------- INIT ---------------*/		//En phase d'initialisation
pObj = gluNewQuadric();		//creation d'un objet(Retourne 0 si No Memory)

gluDeleteQuadric (pObj);		//detruit l'objet





    glPushMatrix();
        gluCylinder(pObj, 20, 20, 20, 20, 20);
    glPopMatrix();
}