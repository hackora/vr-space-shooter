#ifndef _SHADER_HPP_
#define _SHADER_HPP_

//#include <windows.h>
#include <GL/glew.h>
#include "SceneObject.hpp"
#include <vector>
#include <stdlib.h>
#include <stdio.h>



//
// Shader types
//
typedef enum {
    VertexShader,
    FragmentShader,
} ShaderType;


class Shader
{
	public:
		Shader();
		~Shader();
  
    // enable and disable program
    void enable();
    void disable();
    GLuint getProg();
    
    bool initShaders(char *fileName);


	private:
  
    GLuint vs_, fs_, prog_;
    GLchar *vertexShaderSource_, *fragmentShaderSource_;

    int shaderSize(char *fileName, ShaderType shaderType);
    int readShader(char *fileName, ShaderType shaderType, 
                   char *shaderText, int size);
    int loadShaderSource(const GLchar *vertexShader, const GLchar *fragmentShader);

};

#endif //_SHADER_HPP_