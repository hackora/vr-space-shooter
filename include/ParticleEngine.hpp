#pragma once

#include <windows.h>
#include <GL/glew.h>
//#include <GL/gl.h>
//#include <GL/glu.h>

#include "SceneObject.hpp"
#include "Particle.hpp"
#include <memory>

class ParticleEngine : public SceneObject
{
	public:
		ParticleEngine();
		~ParticleEngine();


  protected:
    virtual void privateInit();
	virtual void privateRender();
	virtual void privateUpdate();

	private:
		int MAX_PARTICLES =100;
        float slowdown=2.0f;            // Slow Down Particles
        float xspeed;                   // Base X Speed (To Allow Keyboard Direction Of Tail)
        float yspeed;                   // Base Y Speed (To Allow Keyboard Direction Of Tail)
        float zoom=-20.0f;              // Used To Zoom Out
        GLuint col=1;
        Particle particles[100];
        GLuint texture_;
        GLfloat colors_[12][3]={       // Rainbow Of Colors
      {1.0f,0.5f,0.5f},{1.0f,0.75f,0.5f},{1.0f,1.0f,0.5f},{0.75f,1.0f,0.5f},
      {0.5f,1.0f,0.5f},{0.5f,1.0f,0.75f},{0.5f,1.0f,1.0f},{0.5f,0.75f,1.0f},
      {0.5f,0.5f,1.0f},{0.75f,0.5f,1.0f},{1.0f,0.5f,1.0f},{1.0f,0.5f,0.75f}
    };
};