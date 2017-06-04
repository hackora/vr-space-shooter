#pragma once

//#include <windows.h>
#include <GL/glew.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include "SceneObject.hpp"
#include "Laser.hpp"
#include "Missile.hpp"
#include "Shader.hpp"

#include <vector>

class SpaceShip : public SceneObject
{
	public:
		SpaceShip(GLuint textureID);
		~SpaceShip();
		void moveRight();
    	void moveLeft();
    	void moveUp();
    	void moveDown();
    	void moveBackward();
    	void moveForward();
        int getMissiles();
        int getLasers();
		void fireMissile();
		void fireLaser();
        float getSurroundingSphere();
        void setSurroundingSphere();
        void collided(bool withTerrain);

  	protected:
    	void privateInit();
		void privateRender();
		void privateUpdate(double dt);
        void loadModel();

	private:
		float speed_;
    	int life_ ;
    	float armor_;
        float radius_ ;
        float health_;
        std::vector< glm::vec3 > vertexArray_;
        std::vector< unsigned int > indexArray_;
        std::vector< glm::vec3 > normalArray_;
        int lasers_;
        int missiles_;
        Shader myShader;
        GLuint textureID;

    
};