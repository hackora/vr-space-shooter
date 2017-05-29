#pragma once

//#include <windows.h>
//#include <GL/gl.h>
#include <GL/glew.h>
//#include <GL/glu.h>
#include "Weapon.hpp"

class Laser : public Weapon
{
	public:
		Laser();
		~Laser();
		void fire();
		int owner = 0;

  	protected:
    	void privateInit();
		void privateRender();
		void privateUpdate(double dt);

	private:
    	float life_;
    	bool fire_ = false;
    
};