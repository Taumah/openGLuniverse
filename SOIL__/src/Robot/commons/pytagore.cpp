//
// Created by thomas on 12/04/2020.
//

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../../include/header.hpp"
#include "../../../include/utils/all.hpp"


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
