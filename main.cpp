/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

static int slices = 16;
static int stacks = 16;
float angle = 0.0;
float angle2 = 0.0;
bool a=true, b=true;

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
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glTranslatef(0.0f, 0.0f, -5.0f);                      // déplacement caméra
    glColor3f(1.0f, 1.0f, 1.0f);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    glPushMatrix();

        glTranslatef(4, 0, 0);
        glTranslatef(-1, 0, 0);
        glutWireSphere(0.5, 10 , 10);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(1, 0, 0);
        //Avant Bras
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(1, 0, 0);
        glutWireSphere(0.5,10,10);
        glRotatef(angle2, 0, 0, 1);
        glTranslatef(1, 0, 0);
        //Bras
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(1.0);
        glPopMatrix();



    glPopMatrix();
    glPushMatrix();
        glTranslatef(-2, 0, 0);
        glTranslatef(1, 0, 0);
        glutWireSphere(0.5, 10 , 10);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(-1, 0, 0);
        //Avant Bras
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(-1, 0, 0);
        glutWireSphere(0.5,10,10);
        glRotatef(angle2, 0, 0, 1);
        glTranslatef(-1, 0, 0);
        //Bras
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        //Buste
        glTranslatef(1,0,0);
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(2.0);
        glPopMatrix();
        glTranslatef(0, 1.5, 0);
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(0,-3.5, 0);
        glPushMatrix();
            glScalef(2,1,1);
            glutWireCube(2.0);
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

/* Fonction de mise à jour: mouvements des objets*/
void update(int value){

if (value == 0){
    if (a){
        angle+=5;
        if (angle >=85){
            a = false;
        }
    }
    if (b){
        angle2+=5;
        if (angle2 >=85){
            b = false;
        }
    }
}else{
    angle -=5;
    if (angle <=90){
        a = true;
    }
    angle2 -=5;
    if (angle2<=0){
        b = false;
    }
}


    printf("%d", a);
    printf("%d", b);
    glutPostRedisplay();
    glutTimerFunc(10,update, 0);


}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
        case 'h':
            angle<=90?angle+=5:angle+=0;
            angle2<=90?angle2+=5:angle2+=0;
            break;
        case 'j':
            angle>=-90?angle-=5:angle+=0;
            angle2>=0?angle2-=5:angle2+=0;
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
    glutInitWindowSize(800,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
   /* if (a || b){
    glutTimerFunc (20,update, 0);
    }
    if (a == false && b == false){
        glutTimerFunc(20, update, 1);
    } */
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


