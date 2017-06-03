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
        std::vector<std::shared_ptr<Missile>> getMissiles();
        std::vector<std::shared_ptr<Laser>> getLasers();
        float getSurroundingSphere();
        void setSurroundingSphere();

  	protected:
    	void privateInit();
		void privateRender();
		void privateUpdate(double dt);
        void loadModel();

	private:
		float speed_;
    	float life_;
    	float armor_;
        float radius_ ;
        std::vector< glm::vec3 > vertexArray_;
        std::vector< unsigned int > indexArray_;
        std::vector< glm::vec3 > normalArray_;
        std::vector<std::shared_ptr<Laser>> lasers_;
        std::vector<std::shared_ptr<Missile>> missiles_;
        Shader myShader;
        GLuint textureID;

    
};