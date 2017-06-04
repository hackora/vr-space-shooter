#pragma once

//#include <windows.h>
//#include <GL/gl.h>
#include <GL/glew.h>
//#include <GL/glu.h>
#include "SceneObject.hpp"


class Weapon : public SceneObject
{
	public:
		Weapon();
		~Weapon();

  	protected:
    	void privateInit();
		void privateRender();
		void privateUpdate(double dt);

	private:
    	float life_;
    
};