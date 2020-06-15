#include "Robot.h"

Robot::Robot()
{
    
    for (int i = 0; i < 3; i++)
    {
        robot_pos[i] = 0;
    }
    

    headAngle = 0.0;
    armAngle = 0.0;
    kneeAngle = 0.0;
    kneeAngle2 = 0.0;

}

void Robot::Draw()
{
    glPushMatrix();
        
        glTranslatef(this->robot_pos[0] , this->robot_pos[1] , this->robot_pos[2]);

        upperBody(this->headAngle);
        leftArm(this->armAngle);
        rightArm(this->armAngle);

        lowerBody();
        
        rightLeg(this->kneeAngle);
        leftLeg(this->kneeAngle2);

    glPopMatrix();
}




void upperBody(float headAngle){
    glPushMatrix();
        glTranslatef(0. , -0.5 , 0.);
    

        glColor3f(.93 , .85 , .02);

        glBegin(GL_QUADS);
                //front face
            glNormal3f( 0.0f, 0.0f, 0.65f);      
            
            glVertex3f(-1.0f, -1.25f,  1.0f);  // Bottom Left 
            glVertex3f( 1.0f, -1.25f,  1.0f);  // Bottom Right 
            glVertex3f( 1.0f,  1.25f,  0.65f);  // Top Right 
            glVertex3f(-1.0f, 1.25f, 0.65f);  //Top Left


                // Back Face
            glNormal3f( 0.0f, 0.0f,-0.65f);      

            glVertex3f( 1.0f, -1.25f,  -1.0f);  // Bottom Left 
            glVertex3f(-1.0f, -1.25f,  -1.0f);  // Bottom Right 
            glVertex3f(-1.0f, 1.25f,   -0.65f);  //Top Right
            glVertex3f( 1.0f,  1.25f,  -0.65f);  // Top Left 

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

        head(headAngle);
    
        glPushMatrix();
            glTranslatef(0,0.5,0);

            leftBodySide();
            rightBodySide();
        glPopMatrix();
    glPopMatrix();


}


void head(float headAngle){
        //Tete
    glPushMatrix();
        glColor3f(.93, .85, .02);
        glTranslatef(0, 1.3, 0);


        glPushMatrix();
            glRotatef(-90, 1, 0, 0);
            GLUquadricObj *very_bottom_head;
            very_bottom_head = gluNewQuadric();
            gluQuadricNormals(very_bottom_head, GLU_SMOOTH);
            gluCylinder(very_bottom_head, .65, .55, .2,MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(very_bottom_head);
        glPopMatrix();
        
        glPushMatrix();
            glRotatef(-90, .2, 0, 0);
            GLUquadricObj *mid_bottom_head;
            mid_bottom_head = gluNewQuadric();
            gluQuadricNormals(mid_bottom_head, GLU_SMOOTH);
            gluCylinder(mid_bottom_head, .45, .45, .3,MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(mid_bottom_head);
        glPopMatrix();

        glTranslatef(0, .3, 0);
        glPushMatrix();
            glPushMatrix();
                glRotatef(-90, 1, 0, 0);
                GLUquadricObj *bottom_head;
                bottom_head = gluNewQuadric();
                gluQuadricNormals(bottom_head, GLU_SMOOTH);
                gluCylinder(bottom_head, .55, .7, 1,MIN_SLICES, MIN_STACKS);
                gluDeleteQuadric(bottom_head);
            glPopMatrix();
            
            glRotatef(headAngle, 0, 1, 0);
            glTranslatef(0, 1, 0);
            glPushMatrix();
                
                GLUquadricObj *top_head;
                top_head = gluNewQuadric();
                gluQuadricNormals(top_head, GLU_SMOOTH);
                gluSphere(top_head, .7, MIN_SLICES, MIN_STACKS);
                gluDeleteQuadric(top_head);


                glTranslatef(0,0,.67);

                glPushMatrix();
                
                    eye(LEFT);
                    
                    eye(RIGHT);

                glPopMatrix();

            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
}


void eye(int side){
    glPushMatrix();

        glColor3f( .04f , .04f , .04f );
        GLUquadricObj *eyes;
        eyes = gluNewQuadric();
        // gluQuadricNormals(eyes, GLU_SMOOTH);
        
        glTranslatef(0.24 * side,0,0);
        gluSphere(eyes, .18, MIN_SLICES, MIN_STACKS);
    
        gluDeleteQuadric(eyes);
        
        glColor3f(.93, .85, .02);
    glPopMatrix();
}

void leftBodySide(){
    glPushMatrix();
        glTranslatef(-1, 0.72, 0);
        glRotatef(90, 1, 0, 0);
        GLUquadricObj *cuisso;
        cuisso = gluNewQuadric();
        gluQuadricNormals(cuisso, GLU_SMOOTH);
        gluCylinder(cuisso, .7, .9, 2.5, MIN_SLICES, MIN_STACKS);
        gluDeleteQuadric(cuisso);
    glPopMatrix();
}

void rightBodySide(){
    glPushMatrix();
        glTranslatef(1, 0.72, 0);
        glRotatef(90, 1, 0, 0);
        GLUquadricObj *cuisso;
        cuisso = gluNewQuadric();
        gluQuadricNormals(cuisso, GLU_SMOOTH);
        gluCylinder(cuisso, .7, .9, 2.5, MIN_SLICES, MIN_STACKS);
        gluDeleteQuadric(cuisso);
    glPopMatrix();
}

void leftArm(int armAngle){

    glPushMatrix();

        glTranslatef(-2, 0, 0);
        glutWireSphere(0.5, MIN_SLICES, MIN_STACKS);
        glRotatef(armAngle, 0, 0, 1);
        
        arm(LEFT);

        
        glTranslatef(-2, 0, 0);
        elbow();
        glRotatef(10, 0, 0, 1);

        forearm(LEFT);

        hand(LEFT);

    glPopMatrix();
}

void rightArm(int armAngle){
   
    glPushMatrix();
        
        glTranslatef(2, 0, 0);
        glutWireSphere(0.5,MIN_SLICES, MIN_STACKS);
        glRotatef(-armAngle, 0, 0, 1);


        arm(RIGHT);

        glTranslatef(2, 0, 0);
        elbow();
        glRotatef(10, 0, 0, 1);
        // glTranslatef(1, 0, 0);
        
        forearm(RIGHT);
        
        hand(RIGHT);

    glPopMatrix();
}



void arm(int direction){
    glPushMatrix();
        
        GLUquadricObj *pObj;

        glColor3f(.93 , .85 , .02);
        if( (pObj = gluNewQuadric() ) == 0 ){
            exit(1);
        }
        glRotated( QUARTERTURN * direction , 0 , 1 , 0 );
        gluQuadricNormals(pObj, GLU_SMOOTH);
        gluCylinder(pObj, .5 , .5 , 2 ,MIN_SLICES, MIN_STACKS);		
        gluDeleteQuadric(pObj);	
        glColor3f(.93, .85, .02);

    glPopMatrix();   
}


void elbow(){

    glutWireSphere(0.5,12,12);

}


void forearm(int side){

    GLUquadricObj *pObj;

    double forearmBase = 0.5;    //  either opposite or adjacent seg
    double forearmTop  = 0.25;   //  either opposite or adjacent seg  MUST BE TINIER THAN forearmBase
    double forearmLength = 2;    


    double thalesCoef = forearmTop / forearmBase;
    
    double fullLength =forearmLength /( 1 - thalesCoef ) ;

    double forearmDecoOrientation = RadToDeg( atan( fullLength / forearmBase  ) ) ;


    glPushMatrix();
        if( (pObj = gluNewQuadric() ) == 0 ){
            exit(1);
        }	

        glRotated( QUARTERTURN * side , 0 , 1 , 0 );
        gluQuadricNormals(pObj, GLU_SMOOTH);
        gluCylinder(pObj, forearmBase , forearmTop , forearmLength ,MIN_SLICES, MIN_STACKS);		
        gluDeleteQuadric(pObj);
        	

        glPushMatrix();
            glTranslatef(0. , 0. , forearmLength);
            if( (pObj = gluNewQuadric() ) == 0 ){
                exit(1);
            }
            gluQuadricNormals(pObj, GLU_SMOOTH);
            
            
            gluDisk(pObj, 0.0 , forearmTop, MIN_SLICES , MIN_STACKS);
            glRotatef(180. , 1. , 0. , 0.);                                    //DOUBLE SIDED DISK , I'm not THAT dumb :)
            gluDisk(pObj , 0.0 , forearmTop  , MIN_SLICES , MIN_STACKS );


            gluDeleteQuadric(pObj);	
        glPopMatrix();

    
        for(int i = 0 ; i < 6 ; i++){
            float rotation = 60;
            glPushMatrix();
                glColor3f(.933, .909 , .666);

                if( (pObj = gluNewQuadric() ) == 0 ){
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


void hand(int side){

    glTranslatef(1.7*side , 0 , 0  );
    glRotatef(90 , 0 , 1 * side , 0);

    glPushMatrix();
        glScalef(0.5, 1, 1);
        GLUquadricObj *palm;
        palm = gluNewQuadric();
        gluQuadricNormals(palm, GLU_SMOOTH);
        glColor3f(.93, .85, .02);
        gluCylinder(palm, 0.3, 0.3, 0.6  ,MIN_SLICES, MIN_STACKS);
        gluDeleteQuadric(palm);
    glPopMatrix();

    int inclinaison = 50;

    glTranslatef( 0 , 0 , 0.2);


    for(int i = 0; i < 5; i++){       
        glPushMatrix();
            glRotatef(inclinaison, 1, 0, 0);
            glTranslatef(0, 0, 0.4);
            GLUquadricObj *finger;
            finger = gluNewQuadric();
            gluQuadricNormals(finger, GLU_SMOOTH);
            glColor3f(.93, .85, .02);
            gluCylinder(finger, 0.15, 0.05, 0.6, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(finger);
        glPopMatrix();
        inclinaison -= 20;      
          
    }   
}

void lowerBody(){
    glPushMatrix();

        glColor3f(.93, .85, .02);
        glTranslatef(0, -2, 0);

        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *low_lowpart;
            low_lowpart = gluNewQuadric();
            gluQuadricNormals(low_lowpart, GLU_SMOOTH);
            gluCylinder(low_lowpart, 2, .8, 2.5,MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(low_lowpart);
        glPopMatrix();

        glTranslatef(0, -2.3, 0);
        glPushMatrix();
            GLUquadricObj *bottom_sphere;
            bottom_sphere = gluNewQuadric();
            gluQuadricNormals(bottom_sphere, GLU_SMOOTH);
            gluSphere(bottom_sphere, .8, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(bottom_sphere);
        glPopMatrix();

    glPopMatrix();
}


void rightLeg(float kneeAngle){


    glPushMatrix();

    glRotatef(-kneeAngle*0.4 , 1 , 0 , 0 );


    glColor3f(.93, .85, .02);

        glTranslatef(1, -3, 0);
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *cuisso;
            cuisso = gluNewQuadric();
            gluQuadricNormals(cuisso, GLU_SMOOTH);
            gluCylinder(cuisso, 0.8, .6, 2.5,MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(cuisso);
        glPopMatrix();

        glTranslatef(-0.8, -2.8, 0);
        glPushMatrix();
            glRotatef(90, 0, 1, 0);
            GLUquadricObj *genoux;
            genoux = gluNewQuadric();
            gluQuadricNormals(genoux, GLU_SMOOTH);
            gluCylinder(genoux, .5, .5, 1.6,MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(genoux);
        glPopMatrix();

        glPushMatrix();
            glRotatef(-90, 0, 1, 0);
            GLUquadricObj *leftdisk;
            leftdisk = gluNewQuadric();
            gluQuadricNormals(leftdisk, GLU_SMOOTH);
            gluDisk(leftdisk, 0, .5, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(leftdisk);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(1.6, 0, 0);
            glRotatef(90, 0, 1, 0);
            GLUquadricObj *rightdisk;
            rightdisk = gluNewQuadric();
            gluQuadricNormals(rightdisk, GLU_SMOOTH);
            gluDisk(rightdisk, 0, .5, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(rightdisk);
        glPopMatrix();
        
        glRotatef(kneeAngle , 1 , 0 , 0);


        glTranslatef(0.8, -.3, 0);
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *tibia;
            tibia = gluNewQuadric();
            gluQuadricNormals(tibia, GLU_SMOOTH);
            gluCylinder(tibia, .65, .45, 2.5, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(tibia);
        glPopMatrix();


        foot(RIGHT);
        
    glPopMatrix();
}


void leftLeg(float kneeAngle){
    


    glPushMatrix();

    glRotatef(-kneeAngle*0.4 , 1 , 0 , 0 );

    glColor3f(.93, .85, .02);
        glTranslatef(-1, -3, 0);
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *cuisso;
            cuisso = gluNewQuadric();
            gluQuadricNormals(cuisso, GLU_SMOOTH);
            gluCylinder(cuisso, 0.8, .6, 2.5, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(cuisso);
        glPopMatrix();

        glTranslatef(-0.8, -2.8, 0);
        glPushMatrix();
            glRotatef(90, 0, 1, 0);
            GLUquadricObj *genoux;
            genoux = gluNewQuadric();
            gluQuadricNormals(genoux, GLU_SMOOTH);
            gluCylinder(genoux, .5, .5, 1.6, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(genoux);
        glPopMatrix();
        
        glPushMatrix();
            glRotatef(-90, 0, 1, 0);
            GLUquadricObj *leftdisk;
            leftdisk = gluNewQuadric();
            gluQuadricNormals(leftdisk, GLU_SMOOTH);
            gluDisk(leftdisk, 0, .5, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(leftdisk);
        glPopMatrix();


        glPushMatrix();
            glTranslatef(1.6, 0, 0);
            glRotatef(90, 0, 1, 0);
            GLUquadricObj *rightdisk;
            rightdisk = gluNewQuadric();
            gluQuadricNormals(rightdisk, GLU_SMOOTH);
            gluDisk(rightdisk, 0, .5, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(rightdisk);
        glPopMatrix();


        glRotatef(kneeAngle , 1 , 0 , 0);


        glTranslatef(0.8, -.3, 0);
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *tibia;
            tibia = gluNewQuadric();
            gluQuadricNormals(tibia, GLU_SMOOTH);
            gluCylinder(tibia, .65, .45, 2.5, MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(tibia);
        glPopMatrix();


        foot(LEFT);

    glPopMatrix();
}


void foot(int side ){
    
    glPushMatrix();
        glColor3f(.93, .85, .02);
        glTranslatef(0, -2.6, 0);

        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            GLUquadricObj *talon;
            talon = gluNewQuadric();
            gluQuadricNormals(talon, GLU_SMOOTH);
            gluCylinder(talon, .5, .5, .5, MIN_SLICES, MIN_STACKS);
        glPopMatrix();

        glTranslatef(0, -.5, -.2);
        glPushMatrix();
        glRotatef(10, 1, 0, 0);
            GLUquadricObj *pied;
            pied = gluNewQuadric();
            gluQuadricNormals(pied, GLU_SMOOTH);
            gluCylinder(pied, .5, .3, 2,MIN_SLICES, MIN_STACKS);
            gluDeleteQuadric(pied);
        glPopMatrix();
    glPopMatrix();
}



double degToRad(double value){
    return value/(2*M_PI);
}

double RadToDeg(double value){
    return value* M_PI * 2;
}