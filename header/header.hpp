#include <GL/glut.h>


#define QUARTERTURN 90
#define MIN_STACKS 20
#define MIN_SLICES 20

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