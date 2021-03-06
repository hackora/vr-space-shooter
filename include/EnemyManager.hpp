#pragma once

//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include <GL/glew.h>
#include "SceneObject.hpp"
#include "Enemy.hpp"

#include <vector>

class EnemyManager : public SceneObject
{
	public:
        EnemyManager();
        ~EnemyManager();
        void createEnemy();
        void removeDead();
        std::vector<std::shared_ptr<Enemy>> getEnemies(){return enemies;}


    protected:
        void privateInit();
        void privateRender();
        void privateUpdate(double dt);

    private:
        std::vector<std::shared_ptr<Enemy>> enemies;
};