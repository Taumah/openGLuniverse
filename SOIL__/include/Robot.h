#ifndef ROBOT_H
#define ROBOT_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#include <SOIL/SOIL.h>

// #include "SOIL.h"

#define LEFT -1
#define RIGHT 1
#define MIN_SLICES 20
#define MIN_STACKS 20
#define QUARTERTURN 90

#define X_GRID 0
#define Y_GRID 1
#define Z_GRID 2

#define WALKING_GAP 0.1



#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))



class Robot
{
    public:
        Robot();
        void Draw();
        void LoadTextures();

        bool walking;
        // bool locked;

        float robot_pos[3];
        float direction;

        float headAngle;
        float armAngle;

    protected:

    private:
            void Walk();
            void updatePos();

            GLuint ListeTextures[1];

            bool raisingArms;

            bool raisingLegL;
            bool raisingLegR;
            float kneeAngleL;
            float kneeAngleR;
            

            bool lookAround;

};


void leftArm(int armAngle);
void rightArm(int armAngle);
void upperBody(float headAngle);
void leftLeg(float kneeAngle);
void rightLeg(float kneeAngle);
void head(float headAngle);
void eye(int side);

void lowerBody();
void leftBodySide();
void rightBodySide();

void hand(int side);
void arm(int direction);
void elbow(void);
void foot(/*int side*/);
void forearm(int side);


double degToRad(double value);

double RadToDeg(double value);

float pytagore(float a , float b , float c);
#endif
