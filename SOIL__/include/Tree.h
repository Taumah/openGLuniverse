#ifndef TREE_H
#define TREE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>

// #include "SOIL.h"


class Tree
{
    public:
        Tree();
        void Draw(GLfloat x , GLfloat z  , GLfloat scale );

        GLfloat shade; 
    protected:
    private:
};

void cube(GLfloat);
void trunck(GLfloat x , GLfloat z  , GLfloat scale );

#endif // MAP_H
