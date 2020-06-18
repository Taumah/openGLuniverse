#include "Robot.h"
#include <stdio.h>

Robot::Robot()
{
    
    robot_pos[X_GRID] = 0.0;
    robot_pos[Y_GRID] = 6;
    robot_pos[Z_GRID] = 0.0;

    
    walking = false;
    raisingArms = false;
    lookAround = false;

    raisingLeg = false;

    // locked = true;

    headAngle = 0.0;
    armAngle = 0.0;
    kneeAngle = 0.0;

    direction = 0.0;

    speed = 0.1;

}

void Robot::Draw()
{



    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    // Face
    glBindTexture(GL_TEXTURE_2D, this->ListeTextures[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // glBegin(GL_QUADS);
    //     glTexCoord2f(0, 0);
    //     glVertex3f( 200 , -200 , -200);
    //     glTexCoord2f(1, 0);
    //     glVertex3f(-200, -200 , -200 );
    //     glTexCoord2f(1, 1);
    //     glVertex3f(-200 , 200 , -200 );
    //     glTexCoord2f(0, 1);
    //     glVertex3f( 200 , 200, -200);
    // glEnd();

    if(this->walking ){
        this->Walk();
    }

    glPushMatrix();
        
        glScalef(0.25,0.25,0.25);
        glTranslatef(this->robot_pos[X_GRID] , this->robot_pos[Y_GRID] , this->robot_pos[Z_GRID]);
        glRotatef(this->direction , 0 , 1 , 0);

        upperBody();
        // leftArm(this->armAngle);
        // rightArm(-this->armAngle);

        fullArm(-this->armAngle , LEFT);
        fullArm(this->armAngle , RIGHT);
        lowerBody();
        

    glPopMatrix();
}

void Robot::Walk(){
    

    const int maxAngleLeg = 35;
    const int minAngleLeg = -20;
    const int step = 10; 

    //mouvement jambes
    if( !this->raisingLeg){
        this->kneeAngle <= maxAngleLeg ? this->kneeAngle += step*this->speed : this->raisingLeg = true ;

    }else{
        this->kneeAngle >= minAngleLeg  ? this->kneeAngle -= step*this->speed : this->raisingLeg = false ;        

    }


    //pivot de tête
    if (this->lookAround==false) {
         this->headAngle>=-75?this->headAngle-=5:this->lookAround=true;
    }
    else{
        this->headAngle<=75?this->headAngle+=5:this->lookAround=false;
    }


    //mouvement bras
    if (this->raisingArms==false) {
        this->armAngle>=-75?this->armAngle-=3:this->raisingArms=true;
    }
    else{
        this->armAngle<=75?this->armAngle+=3:this->raisingArms=false;
    }

    this->updatePos();
}

void Robot::updatePos(){
    double rad = degToRad(direction);

    robot_pos[X_GRID] += this->speed* sin(rad )  ; 
    // robot_pos[Y_GRID] += WALKING_GAP
    robot_pos[Z_GRID] += this->speed * cos( rad) ;

}

void Robot::LoadTextures(){
    this->ListeTextures[0] = SOIL_load_OGL_texture("img/c3poBody.jpg",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
}

void Robot::swapWalkingState(){

    if(  !(this->walking = !this->walking)   ){ //  = ends up standing still
        this->headAngle = 0.0,
        this->armAngle = 0.0,
        this->kneeAngle = 0.0;
    }
}

void Robot::upperBody(){
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

        head(this->headAngle);
    
        glPushMatrix();
            glTranslatef(0,0.5,0);

            leftBodySide();
            rightBodySide();
        glPopMatrix();
    glPopMatrix();


}

void Robot::lowerBody(){
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

        // rightLeg(this->kneeAngle);
        // leftLeg(-this->kneeAngle);

        leg(this->kneeAngle , RIGHT);
        leg(-this->kneeAngle , LEFT);

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
        GLUquadricObj *shoulder;
        shoulder = gluNewQuadric();
        gluQuadricNormals(shoulder, GLU_SMOOTH);
        gluCylinder(shoulder, .7, .9, 2.5, MIN_SLICES, MIN_STACKS);
        gluDeleteQuadric(shoulder);
    glPopMatrix();
}

void rightBodySide(){
    glPushMatrix();
        glTranslatef(1, 0.72, 0);
        glRotatef(90, 1, 0, 0);
        GLUquadricObj *shoulder;
        shoulder = gluNewQuadric();
        gluQuadricNormals(shoulder, GLU_SMOOTH);
        gluCylinder(shoulder, .7, .9, 2.5, MIN_SLICES, MIN_STACKS);
        gluDeleteQuadric(shoulder);
    glPopMatrix();
}

void fullArm(float armAngle , int side){
    glPushMatrix();
        
        glTranslatef(2 * side, 0, 0);
        glutSolidSphere(0.5,MIN_SLICES, MIN_STACKS);

        glRotatef(-QUARTERTURN * side, 0, 0, 1);
        glRotatef(armAngle * side, 0, 1, 0);


        arm(side);

        glTranslatef(2 * side, 0, 0);
        elbow();
        glRotatef(10, 0, 0, 1);
        // glTranslatef(1, 0, 0);
        
        forearm(side);
        
        hand(side);

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

    glutSolidSphere(0.5,12,12);

}


void forearm(int side){

    GLUquadricObj *pObj;

    const double forearmBase = 0.5;    //  either opposite or adjacent seg
    const double forearmTop  = 0.25;   //  either opposite or adjacent seg  MUST BE TINIER THAN forearmBase
    const double forearmLength = 2;    


    // double thalesCoef = forearmTop / forearmBase;
    
    // double fullLength =forearmLength /( 1 - thalesCoef ) ;

    // double forearmDecoOrientation = RadToDeg( atan( fullLength / forearmBase  ) ) ;


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

                glRotatef(  -7  , 0. ,1. , 0.);
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

void leg(float kneeAngle, int side){
    glPushMatrix();

    glRotatef(-kneeAngle, 1 , 0 , 0 );
    // glRotatef(40 , 1 , 0 , 0 );


    glColor3f(.93, .85, .02);

        glTranslatef(1* side, 1  , 0); //
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


        foot();
        
    glPopMatrix();
}


void foot(){
    
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
    return value * M_PI / 180 ;
}

double RadToDeg(double value){
    return value / M_PI * 180;
}


float pytagore(float a , float b , float c){
    
    if( (!a + !b + !c) > 1 ){ //hope this one can be removed later :D
        return 0;
    }

    if(c == 0){
        return sqrt(pow(a, 2) + pow(b,2));
    }else
    {
        return sqrt( (pow(c, 2) - pow(a+b , 2)  )  );
    }
    
}