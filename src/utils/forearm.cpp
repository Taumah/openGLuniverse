//
// Created by thomas on 12/04/2020.
//

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../header/utils/all.h"
#include "../../header/header.h"
#include "../../header/commons/all.h"


extern GLUquadricObj *pObj;



void forearm(int side){

    double forearmBase = 0.5;    //  either opposite or adjacent seg
    double forearmTop  = 0.25;   //  either opposite or adjacent seg  MUST BE TINIER THAN forearmBase
    double forearmLength = 2;    


    double thalesCoef = forearmTop / forearmBase;
    
    double fullLength =forearmLength /( 1 - thalesCoef ) ;

    double forearmDecoOrientation = RadToDeg( atan( fullLength / forearmBase  ) ) ;


    glPushMatrix();
        if( (pObj = gluNewQuadric() ) == 0 ){
            printf("No memory when creating forearm");
            exit(1);
        }	

        glRotated( QUARTERTURN * side , 0 , 1 , 0 );
        gluQuadricNormals(pObj, GLU_SMOOTH);
        gluCylinder(pObj, forearmBase , forearmTop , forearmLength ,MIN_SLICES, MIN_STACKS);		
        gluDeleteQuadric(pObj);	
    
        for(int i = 0 ; i < 6 ; i++){
            float rotation = 60;
            glPushMatrix();
                glColor3f(.933, .909 , .666);

                if( (pObj = gluNewQuadric() ) == 0 ){
                    printf("No memory when creating cylinder on forearm");
                    exit(1);
                }	
                glRotatef(rotation*i , 0. , 0. , 1. );
                glTranslatef(forearmBase , 0. , 0.);

                glRotatef(-forearmDecoOrientation +2  , 0. ,1. , 0.);
                gluQuadricNormals(pObj, GLU_SMOOTH);
                gluCylinder(pObj, forearmBase/10 , forearmTop/10 ,  forearmLength ,MIN_SLICES, MIN_STACKS);		
                gluDeleteQuadric(pObj);	


            glPopMatrix();
        }

    glPopMatrix();

}
