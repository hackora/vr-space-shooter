#pragma once

#include <windows.h>
#include <GL/glew.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include "SceneObject.hpp"
#include "Laser.hpp"
#include "Missile.hpp"

#include <vector>

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
        std::vector<std::shared_ptr<Missile>> getMissile();
        std::vector<std::shared_ptr<Laser>> getLaser();

  	protected:
    	void privateInit();
		void privateRender();
		void privateUpdate();

	private:
		float speed_;
    	float life_;
    	float armor_;
        std::vector<std::shared_ptr<Laser>> lasers_;
        std::vector<std::shared_ptr<Missile>> missiles_;
    
};