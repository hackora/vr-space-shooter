#pragma once

//#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "SceneObject.hpp"
#include "Particle.hpp"

class Enemy : public SceneObject
{
	public:
        Enemy();
        ~Enemy();
        void moveSinus();
        void moveStraight();
        void moveZigzag();
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
        int   list_id;
        float counter=0.016;
        GLuint texture_;
        int movement;
};

