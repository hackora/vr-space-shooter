#pragma once

//#include <windows.h>
#include <GL/glew.h>
//#include <GL/gl.h>
#include <GL/freeglut.h>
//#include <GL/glu.h>

#include "SceneObject.hpp"
#include "glm/glm.hpp"
#include "Shader.hpp"


class BattleField : public SceneObject
{
	public:
		BattleField();
		~BattleField();

    protected:
        virtual void privateInit();
		virtual void privateRender();
		virtual void privateUpdate();

	private:
        std::vector< glm::vec3 > vertexArray_; // Maybe two-dim vector and several arrays
        std::vector< unsigned int > indexArray_;
        std::vector< glm::vec2 > textureArray_; 
        // normal array.
        // texture coord array
        int sizeX = 257;
        int sizeZ = 257;
        int Y     = 100;
        GLuint BfTexture_;
        //Multitexturing
        GLuint heightMap_;
        GLuint colorMap_;
        Shader myShader;

};