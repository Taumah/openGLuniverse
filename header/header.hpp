#include <GL/glut.h>


#define QUARTERTURN 90
#define MIN_STACKS 10
#define MIN_SLICES 10

void leftArm(float armAngle);
void rightArm(float armAngle);
void upperBody();
void leftLeg(float kneeAngle, float thigh);
void rightLeg(float kneeAngle, float thigh);
void head(float headAngle);
void eye(int side , GLUquadricObj* obj);

void leftFoot();
void rightFoot();

void lowerBody();
void leftBodySide();
void rightBodySide();

void hand(float armAngle);