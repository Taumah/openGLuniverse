#ifndef MAP_H
#define MAP_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>

// #include "SOIL.h"

#include "Camera.h"

class Map
{
    public:
        Map();
        // Stockage des r�f�rences aux textures
        GLuint ListeTextures[20];
        GLuint Skybox[6];
        void LoadTextures(void);
        void DrawGround(void);
        void DrawSkybox(Camera *cam);
        void DrawDecoration();
    protected:
    private:
};

#endif // MAP_H
