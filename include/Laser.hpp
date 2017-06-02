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

  	protected:
    	void privateInit();
		void privateRender();
		void privateUpdate(double dt);

	private:
    	float speed_= 50.0f;
    	float life_;
    	bool active_ = false;
    
};