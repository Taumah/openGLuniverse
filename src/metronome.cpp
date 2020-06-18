#include "Metronome.h"


void metronome(float time){
    glPushMatrix();

        glScalef(2 , 2 ,2);

        glTranslatef( 4. , 0. , 0.);    

        glColor3f( 1 , 1 , 1);

        glBegin(GL_QUADS);
                //front face
            glNormal3f( 0.0f, 0.0f, 1);      
            
            glVertex3f(-1.0f, -1.25f,  1.0f );  // Bottom Left 
            glVertex3f( 1.0f, -1.25f,  1.0f );  // Bottom Right 
            glVertex3f( 1.0f,  1.25f,  1);  // Top Right 
            glVertex3f(-1.0f,  1.25f,  1);  //Top Left


                // Back Face
            glNormal3f( 0.0f, 0.0f,-1);      

            glVertex3f( 1.0f, -1.25f,  -1.0f);  // Bottom Left 
            glVertex3f(-1.0f, -1.25f,  -1.0f);  // Bottom Right 
            glVertex3f(-1.0f, 1.25f,   -1);  //Top Right
            glVertex3f( 1.0f,  1.25f,  -1);  // Top Left 

            // Top Face
            glNormal3f( 0.0f, 1.0f, 0.0f); 

            glVertex3f(-1.0f,  1.25f, -1);  // Top Left 
            glVertex3f(-1.0f,  1.25f,  1);  // Bottom Left 
            glVertex3f( 1.0f,  1.25f,  1);  // Bottom Right 
            glVertex3f( 1.0f,  1.25f, -1);  // Top Right 


            // Bottom Face
            glNormal3f( 0.0f,-1.0f, 0.0f);     

            glVertex3f(-1.0f, -1.25f,  1.0f);  // Top Right 
            glVertex3f(-1.0f, -1.25f, -1.0f);  // Top Left 
            glVertex3f( 1.0f, -1.25f, -1.0f);  // Bottom Left 
            glVertex3f( 1.0f, -1.25f,  1.0f);  // Bottom Right 


            // Right face
            glNormal3f( 1.0f, 0.0f, 0.0f);      

            glVertex3f( 1.0f, -1.25f, -1.0f);  // Bottom Right 
            glVertex3f( 1.0f,  1.25f, -1);  // Top Right 
            glVertex3f( 1.0f,  1.25f,  1);  // Top Left
            glVertex3f( 1.0f, -1.25f,  1.0f);  // Bottom Left 


            // Left Face
            glNormal3f(-1.0f, 0.0f, 0.0f);      

            glVertex3f( -1.0f, -1.25f,  1.0f);  // Bottom Right 
            glVertex3f( -1.0f,  1.25f,  1);  // Top Right 
            glVertex3f( -1.0f,  1.25f, -1);  // Top Left
            glVertex3f( -1.0f, -1.25f, -1.0f);  // Bottom Left 
        glEnd(); 

        ticker(time);
       
    glPopMatrix();


}

void ticker(float time){

    glRotatef(10 , 0 , 0  , 1);
    glTranslatef( 0 , 0 , 1.001);    

    glPushMatrix();

        glBegin(GL_QUADS);

            glColor3f(  0.7f , 0.3f , 0.5f );

            glNormal3f( 0.0f, 0.0f, 0.0f);      
        
            glVertex3f(-0.25f, -1.20f,  0 );  // Bottom Left 
            glVertex3f( 0.25f, -1.20f,  0 );  // Bottom Right 
            glVertex3f( 0.25f,  1.20f,  0);  // Top Right 
            glVertex3f( -0.25f,  1.20f,  0);  //Top Left


        glEnd();
    glPopMatrix();
}