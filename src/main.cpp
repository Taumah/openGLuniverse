#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "../header/header.hpp"
#include <math.h>

float angle = 0.0;

float camera_pos[] = {0.0 , 0.0 , -15.0 };
float R = 25, alpha = 0 , beta = 0; 

float armAngle = 0.0;
float armAngle2 = 0.0;
float headAngle= 0.0;
float kneeAngle=0.0;
float thigh = 0.0;
float kneeAngle2=0.0;
float thigh2 = 0.0;
float cameraAngle = 0.0;
float movAngle =0.0;
bool a=true, b=true, c=true, d=true, leftLegW = true, rightLegW = false;

const uint16_t WIN_WIDTH= 800 , WIN_HEIGHT = 500;
GLUquadricObj *pObj;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);


    glLoadIdentity();

    camera_pos[0] = R * cos(beta) * sin(alpha);
	camera_pos[1] = R * sin(beta);
	camera_pos[2] = R * cos(beta) * cos(alpha);

	gluLookAt(camera_pos[0] , camera_pos[1] , camera_pos[2] , 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    // glTranslatef(0.0f, 0.0f, -15.0f);
    glRotatef(0, 0,1,0);                      // déplacement caméra
    glColor3f(1.0f, 1.0f, 1.0f);
    

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    // glRotatef(0, 0,1,0);                      // déplacement caméra
    
    glPushMatrix();
       glPushMatrix();
           head(headAngle);
       glPopMatrix();
       glPushMatrix();
            leftArm(armAngle);
           rightArm(armAngle);
       glPopMatrix();
       glPushMatrix();
        // glTranslatef(0, -1, 0);
        glPushMatrix();
                upperBody();
                leftBodySide();
                rightBodySide();
                lowerBody();
        glPopMatrix();
        glPushMatrix();
            rightLeg(kneeAngle, thigh);
            leftLeg(kneeAngle2, thigh2);
        glPopMatrix();
    glPopMatrix();
       glPushMatrix();
           leftFoot();
           rightFoot();
       glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}

/* Fonction de mise à jour: mouvements des objets*/
void update(int value){
    
    // if (a==false) {
    //      headAngle>=-90?headAngle-=5:a=true;
    // }
    // if (a==true){
    //     headAngle<=90?headAngle+=5:a=false;
    // }
    // if (leftLegW == true){
    //     if (thigh >=-20){
    //         thigh-=5;
    //         thigh2<0?thigh2+=5:thigh2+=0;
    //     }
    //     if (kneeAngle<=20){
    //         kneeAngle+=5;
    //         kneeAngle2>0?kneeAngle2-=5:kneeAngle2+=0;
    //     }else{
    //         rightLegW=true;
    //         leftLegW=false;
    //     }
    // }
    // if (rightLegW == true){
    //     if (thigh2>=-20){
    //         thigh2-=5;
    //         thigh<0?thigh+=5:thigh+=0;
    //     }
    //     if (kneeAngle2 <= 20){
    //         kneeAngle2 +=5;
    //         kneeAngle>0?kneeAngle-=5:kneeAngle2+=0;
    //     }else{
    //         leftLegW = true;
    //         rightLegW = false;
    //     }
    // }
    // armAngle +=40;
    // movAngle +=-2;
    //cameraAngle+=5;
    glutPostRedisplay();
    glutTimerFunc(10,update, 0);

}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case '$':
            exit(0);
            break;
        case 'h':
            headAngle>=-90?headAngle-=5:headAngle+=0;
            break;
        case 'H':
            headAngle<=90?headAngle+=5:headAngle-=0;
            break;



        case 'k':
            kneeAngle<=140?kneeAngle+=5:kneeAngle+=0;
            break;
        case 'K':
            kneeAngle>=0?kneeAngle-=5:kneeAngle+=0;
            break;
        case 't':
            thigh>=-100?thigh-=5:thigh+=0;
            break;
        case 'T':
            thigh<=45?thigh+=5:thigh+=0;
            break;


            
        //MOVING CAMERA    
        case 's':
            beta -= 0.05;
            break;
        case 'z':		
            beta += 0.05;
            break;
        case 'q':
            alpha += 0.05;
            break;
        case 'd':
            alpha -= 0.05;
            break;
        //Zoom
        case 'I': //in
            R -= 0.2;
            break;
        case 'O': //out
            R += 0.2;
            break;    
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(WIN_WIDTH,WIN_HEIGHT);
    glutInitWindowPosition(2000,150);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    //glutTimerFunc(20, update, 1);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    //glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}


