#pragma once

//#include <windows.h>
#include <GL/glew.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include <GL/freeglut.h>
#include "SceneObject.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "../soil/src/SOIL.h"

#include <vector>

class SkyBox : public SceneObject
{
    public:
        SkyBox(std::shared_ptr<Camera> cam);
        ~SkyBox();
        GLuint getTextureId(){return textureID;}

    
    protected:
        void privateInit();
        void privateRender();
        void privateUpdate(double dt);

    private:
        std::vector<const GLchar*> faces_;
        GLuint textureID;
        Shader skyboxShader;
        //GLuint skyboxVAO, skyboxVBO;
        std::shared_ptr<Camera> cam_;
  
};