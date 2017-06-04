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
        virtual void fire(){}

  	protected:
    	void privateInit();
		void privateRender();
		void privateUpdate(double dt);
		bool active_ = false;

	private:
    	float life_;
    
};