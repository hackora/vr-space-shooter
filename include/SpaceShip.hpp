#pragma once

//#include <windows.h>
#include <GL/gl.h>
//#include <GL/glew.h>
#include <GL/glu.h>
#include "SceneObject.hpp"

class SpaceShip : public SceneObject
{
	public:
		SpaceShip();
		~SpaceShip();
		void moveRight();
    	void moveLeft();
    	void moveUp();
    	void moveDown();
    	void moveBackward();
    	void moveForward();

  	protected:
    	void privateInit();
		void privateRender();
		void privateUpdate();

	private:
		float speed_;
    	float life_;
    	float armor_;
    
};

