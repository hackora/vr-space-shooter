#pragma once

//#include <windows.h>
#include <GL/glew.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include "SceneObject.hpp"
#include "Particle.hpp"
#include "Bullet.hpp"
#include "Shader.hpp"

class Enemy : public SceneObject
{
	public:
        Enemy();
        ~Enemy();
        void setMovement(int mvt);
        void addBullet();
        glm::vec3 movePattern1(double dt);
        glm::vec3 movePattern2(double dt);
        glm::vec3 movePattern3(double dt);
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
        void moveBackward();
        void moveForward();
        float getSurroundingSphere();
        void setSurroundingSphere();
        std::vector<std::shared_ptr<Bullet>> getBullets(){return bullets_;}
        void collided(bool  withTerrain);

    protected:
        void privateInit();
        void privateRender();
        void privateUpdate(double dt);
        void loadModel();

    private:
        float speed_= 50.0f;
        float life_;
        float armor_;
        float radius_ = 0.0 ;
        bool hasWeapon=false;
        int   list_id;
        float time = 0.0f;
        GLuint texture_;
        int movement;
        std::vector<std::shared_ptr<Bullet>> bullets_;
        std::vector< glm::vec3 > vertexArray_;
        std::vector< unsigned int > indexArray_;
        std::vector< glm::vec3 > normalArray_;
        Shader myShader;
        GLuint textureID;
};

