#ifndef ROBOT_H
#define ROBOT_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

#include "glut.h"
#include "SOIL.h"

#define LEFT -1
#define RIGHT 1
#define MIN_SLICES 20
#define MIN_STACKS 20
#define QUARTERTURN 90
class Robot
{
    public:
        Robot();
        void Draw();

        bool walking;

        float robot_pos[3];

        float headAngle;
        float armAngle;
        float kneeAngle;
        float kneeAngle2;

    protected:

    private:
            void Walk();

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
void foot(int side);
void forearm(int side);


double degToRad(double value);

double RadToDeg(double value);

float pytagore(float a , float b , float c);
#endif
