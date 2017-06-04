#pragma once

//#include <windows.h>
//#include <GL/gl.h>
#include <GL/glew.h>
//#include <GL/glu.h>
#include "Weapon.hpp"
#include <iostream>

class Missile : public Weapon
{
	public:
		Missile();
		~Missile();
		void fire();
		float getSurroundingSphere();
		void setSurroundingSphere();
		void collided(bool  withTerrain){alive_ = false;}
		bool isActive(){return active_;}

  	protected:
    	void privateInit();
		void privateRender();
		void privateUpdate(double dt);

	private:
		float speed_= 50.0f;
    	float life_;
    	float radius_;
    	std::vector< glm::vec3 > vertexArray_;
    
};