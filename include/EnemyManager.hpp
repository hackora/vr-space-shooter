#pragma once

#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include <GL\glew.h>
#include "SceneObject.hpp"
#include "Enemy.hpp"

#include <vector>

class EnemyManager : public SceneObject
{
	public:
        EnemyManager();
        ~EnemyManager();
        void createEnemy();
        void destroyEnemy(Enemy enemy); 

    protected:
        void privateInit();
        void privateRender();
        void privateUpdate();

    private:
        std::vector<std::shared_ptr<Enemy>> enemies;
};