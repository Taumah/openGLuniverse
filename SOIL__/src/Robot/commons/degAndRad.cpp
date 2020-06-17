
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../../include/header.hpp"
#include "../../../include/utils/all.hpp"


double degToRad(double value){
    return value/(2*M_PI);
}

double RadToDeg(double value){
    return value* M_PI * 2;
}