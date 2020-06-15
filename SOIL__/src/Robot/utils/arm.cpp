//
// Created by thomas on 12/04/2020.
//

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../../include/header.hpp"
#include "../../../include/utils/all.hpp"

void arm(int direction){
    glPushMatrix();
        
        GLUquadricObj *pObj;

        glColor3f(.93 , .85 , .02);
        if( (pObj = gluNewQuadric() ) == 0 ){
            printf("No memory when creating forearm");
            exit(1);
        }
        glRotated( QUARTERTURN * direction , 0 , 1 , 0 );
        gluQuadricNormals(pObj, GLU_SMOOTH);
        gluCylinder(pObj, .5 , .5 , 2 ,MIN_SLICES, MIN_STACKS);		
        gluDeleteQuadric(pObj);	
        glColor3f(.93, .85, .02);

    glPopMatrix();   
}