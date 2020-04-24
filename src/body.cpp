#include "../header/header.hpp"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
extern GLUquadricObj *pObj;

void drawUpperBody();

void upperBody(){
    glPushMatrix();
        drawUpperBody();

    glPopMatrix();
}


void drawUpperBody(){

    glTranslatef(0. , -0.5 , 0.);
    pObj = gluNewQuadric();

    glColor3f(.93 , .85 , .02);
    gluQuadricNormals(pObj, GLU_SMOOTH);   // Create Smooth Normals ( NEW )
    gluQuadricTexture(pObj, GL_TRUE);

    glBegin(GL_QUADS);
            //front face
        glNormal3f( 0.0f, 0.0f, 0.65f);      
        
        glVertex3f(-1.0f, -1.25f,  1.0f);  // Bottom Left 
        glVertex3f( 1.0f, -1.25f,  1.0f);  // Bottom Right 
        glVertex3f( 1.0f,  1.25f,  0.65f);  // Top Right 
        glVertex3f(-1.0f, 1.25f, 0.65f);  //Top Left


            // Back Face
        glNormal3f( 0.0f, 0.0f,-0.65f);      

        glVertex3f(-1.0f, -1.25f, -1.0f);  // Bottom Right 
        glVertex3f( 1.0f, -1.25f, -1.0f);  // Top Right 
        glVertex3f( 1.0f, 1.25f,  -0.65f);  // Top Left 
        glVertex3f(-1.0f, 1.25f,  -0.65f);  // Bottom Left 

        // Top Face
        glNormal3f( 0.0f, 1.0f, 0.0f); 

        glVertex3f(-1.0f,  1.25f, -0.65f);  // Top Left 
        glVertex3f(-1.0f,  1.25f,  0.65f);  // Bottom Left 
        glVertex3f( 1.0f,  1.25f,  0.65f);  // Bottom Right 
        glVertex3f( 1.0f,  1.25f, -0.65f);  // Top Right 


        // Bottom Face
        glNormal3f( 0.0f,-1.0f, 0.0f);     

        glVertex3f(-1.0f, -1.25f,  1.0f);  // Top Right 
        glVertex3f(-1.0f, -1.25f, -1.0f);  // Top Left 
        glVertex3f( 1.0f, -1.25f, -1.0f);  // Bottom Left 
        glVertex3f( 1.0f, -1.25f,  1.0f);  // Bottom Right 


        // Right face
        glNormal3f( 1.0f, 0.0f, 0.0f);      

        glVertex3f( 1.0f, -1.25f, -1.0f);  // Bottom Right 
        glVertex3f( 1.0f,  1.25f, -0.65f);  // Top Right 
        glVertex3f( 1.0f,  1.25f,  0.65f);  // Top Left
        glVertex3f( 1.0f, -1.25f,  1.0f);  // Bottom Left 


        // Left Face
        glNormal3f(-1.0f, 0.0f, 0.0f);      

        glVertex3f( -1.0f, -1.25f,  1.0f);  // Bottom Right 
        glVertex3f( -1.0f,  1.25f,  0.65f);  // Top Right 
        glVertex3f( -1.0f,  1.25f, -0.65f);  // Top Left
        glVertex3f( -1.0f, -1.25f, -1.0f);  // Bottom Left 
    glEnd(); 
}