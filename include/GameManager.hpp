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

#include <memory>

class GameManager : public SceneObject
{
	public:
		GameManager();
		~GameManager();

    std::shared_ptr<Camera> getCam();
    std::shared_ptr<SpaceShip> getSpaceship();
    std::shared_ptr<EnemyManager>getEnemyManager();
    int enemyFreq=1;

  protected:
    virtual void privateInit();
	virtual void privateRender();
	virtual void privateUpdate();

	private:
    std::shared_ptr<BattleField> bf_;
    std::shared_ptr<EnemyManager> em_;
    std::shared_ptr<Camera> cam_;
    std::shared_ptr<SpaceShip> spaceship_;
    std::shared_ptr<ParticleEngine> pe_;

};