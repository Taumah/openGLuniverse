#include "Tree.h"


Tree::Tree(){

    shade = 0;
}

void Tree::Draw(GLfloat x , GLfloat z  , GLfloat scale ){

    trunck(x , z , scale);
}

void trunck(GLfloat x , GLfloat z , GLfloat scale){

    glPushMatrix();
        glScaled(scale , scale , scale);

        const float trunck_height = 6.0;

        glTranslatef( x, trunck_height/2 , z);

        glColor3f(0.15 , 0.102 , 0.051);
        glRotatef(90 , 1 , 0 , 0);

        GLUquadricObj *trunck;
        trunck = gluNewQuadric();
        gluQuadricNormals(trunck, GLU_SMOOTH);
        gluCylinder(trunck,  0.3 , 0.3 , trunck_height , 30 , 30 );
        gluDeleteQuadric(trunck);

        glRotatef(45, 1 , 1 , 1 );

        cube(0.7);

        glRotatef(45, 1 , 0 , 1 );

        cube(0.9);

        glRotatef(45, 0 , 1 , 0 );

        cube(0.8);


    glPopMatrix();
}



void cube(GLfloat shade){

    glPushMatrix();
    
        glColor3f(0 , shade , 0);

        glBegin(GL_QUADS);
                
                //bottom face
            glNormal3f( 0.0f, 1, 0.0f);      
            
            glVertex3f( -1.0f,  0,  -1.0f );  // Bottom Left 
            glVertex3f( -1.0f,  0,   1.0f );  // Bottom Right 
            glVertex3f(  1.0f,  0,   1.0f);  // Top Right 
            glVertex3f(  1.0f,  0,  -1.0f);  //Top Left


            // Top Face
            glNormal3f( 0.0f, 1.0f, 0.0f); 

            glVertex3f( -1,  1, -1);  // Top Left 
            glVertex3f( -1,  1,  1);  // Bottom Left 
            glVertex3f(  1,  1,  1);  // Bottom Right 
            glVertex3f(  1,  1, -1);  // Top Right 


                // Back Face
            glNormal3f( 0.0f, 0.0f,-1);      

            glVertex3f( -1, -1,  -1);  // Bottom Left 
            glVertex3f( -1 , 1,  -1);  // Bottom Right 
            glVertex3f(  1,  1,  -1);  //Top Right
            glVertex3f(  1, -1,  -1);  // Top Left 


            // Front Face
            glNormal3f( 0.0f, 0.0f,1);      

            glVertex3f( -1, -1,  1);  // Bottom Left 
            glVertex3f( -1 , 1,  1);  // Bottom Right 
            glVertex3f(  1,  1,  1);  //Top Right
            glVertex3f(  1, -1,  1);  // Top Left 


            // Right face
            glNormal3f( 1.0f, 0.0f, 0.0f);      

            glVertex3f( 1.0f, -1, -1);  // Bottom Right 
            glVertex3f( 1.0f, -1,  1);  // Top Right 
            glVertex3f( 1.0f,  1,  1);  // Top Left
            glVertex3f( 1.0f,  1, -1);  // Bottom Left 


            // Left Face
            glNormal3f(-1.0f, 0.0f, 0.0f);      

            glVertex3f( -1.0f, -1, -1);  // Bottom Right 
            glVertex3f( -1.0f, -1,  1);  // Top Right 
            glVertex3f( -1.0f,  1,  1);  // Top Left
            glVertex3f( -1.0f,  1, -1);  // Bottom Left 
        glEnd(); 

    glPopMatrix();

}
