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


#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))



class Robot
{
    public:
        Robot();
        void Draw();
        void LoadTextures();
        void swapWalkingState();

        bool walking;
        float speed;

        float robot_pos[3];
        float direction;

        float headAngle;
        float armAngle;

    protected:

    private:
            void Walk();
            void updatePos();

            void upperBody();
            void lowerBody();

            GLuint ListeTextures[1];

            bool raisingArms;

            bool raisingLeg;
            float kneeAngle;
            

            bool lookAround;


};


void fullArm(float armAngle , int side);
void leg(float kneeAngle, int side);
void head(float headAngle);
void eye(int side);

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
