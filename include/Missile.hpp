#pragma once

//#include <windows.h>
//#include <GL/gl.h>
#include <GL/glew.h>
//#include <GL/glu.h>
#include "Weapon.hpp"

class Missile : public Weapon
{
	public:
		Missile();
		~Missile();
		void fire();

  	protected:
    	void privateInit();
		void privateRender();
		void privateUpdate();

	private:
    	float life_;
    	float counter = 0.016;
    	bool fire_ = false;
    
};