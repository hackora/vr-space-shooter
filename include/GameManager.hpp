#pragma once

//#include <windows.h>
#include <GL/glew.h>
//#include <GL/gl.h>
//#include <GL/glu.h>

#include "SceneObject.hpp"
#include "BattleField.hpp"
#include "SpaceShip.hpp"
#include "Camera.hpp"
#include "EnemyManager.hpp"
#include "ParticleEngine.hpp"
#include "SkyBox.hpp"
#include "Bullet.hpp"
#include "Missile.hpp"
#include "Laser.hpp"

#include <memory>
#include <vector>


struct CollisionObject{

    SceneObject* obj1;
    SceneObject* obj2;

};

class GameManager : public SceneObject
{
	public:
		GameManager();
		~GameManager();
        std::shared_ptr<Camera> getCam();
        std::shared_ptr<SpaceShip> getSpaceship();
        std::shared_ptr<EnemyManager>getEnemyManager();
		void fireMissile(glm::mat4 mat);
		void fireLaser(glm::mat4 mat);
        int enemyFreq=1;

  protected:
    virtual void privateInit();
	virtual void privateRender();
	virtual void privateUpdate(double dt);
    std::vector<SceneObject*> getDynamicObjects();
    std::vector<CollisionObject> detectCollisions(std::vector<SceneObject*>);
    void resolveCollisions(std::vector<CollisionObject>);
    bool detectCollision(SceneObject* obj1, SceneObject* obj2);
    //bool detectCollision(SceneObject* obj);
    void removeDead();

	private:
    std::shared_ptr<BattleField> bf_;
    std::shared_ptr<EnemyManager> em_;
    std::shared_ptr<Camera> cam_;
    std::shared_ptr<SpaceShip> spaceship_;
    std::shared_ptr<ParticleEngine> pe_;
    std::shared_ptr<SkyBox> skybox_;

    std::vector<std::shared_ptr<Missile>> missiles_;
    std::vector<std::shared_ptr<Laser>> lasers_;
    std::vector<std::shared_ptr<Bullet>> bullets_;


    float spaceshipRadius_;
    float enemyRadius_;
    float missileRadius_;
    float laserRadius_;
    float bulletRadius_;


};