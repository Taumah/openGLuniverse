
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../header/utils/all.h"
#include "../../header/header.h"


double degToRad(double value){
    return value/(2*M_PI);
}

double RadToDeg(double value){
    return value* M_PI * 2;
}