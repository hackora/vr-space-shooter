#pragma once

//#include <windows.h>
#include <GL/glew.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include "SceneObject.hpp"

class Particle : public SceneObject
{
	public:
		Particle();
		~Particle();

  protected:
    void privateInit();
	void privateRender();
	void privateUpdate();

	public:
	  bool	active;					// Active (Yes/No)
	  float	life;					// Particle Life
	  float	fade;					// Fade Speed
	  float	redValue;			
	  float	greenValue;						
	  float	blueValue;						
	  float	x;						// X Position
	  float	y;						// Y Position
	  float	z;						// Z Position
	  float	xi;						// X Direction
	  float	yi;						// Y Direction
	  float	zi;						// Z Direction
	  float	xg;						// X Gravity
	  float	yg;						// Y Gravity
	  float	zg;						// Z Gravity
};