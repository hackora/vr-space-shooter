#pragma once

//#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "SceneObject.hpp"
#include "BattleField.hpp"
#include "SpaceShip.hpp"
#include "Camera.hpp"
#include "Enemy.hpp"
#include "ParticleEngine.hpp"

#include <memory>

class GameManager : public SceneObject
{
	public:
		GameManager();
		~GameManager();

    std::shared_ptr<Camera> getCam();

  protected:
    virtual void privateInit();
	virtual void privateRender();
	virtual void privateUpdate();

	private:
    std::shared_ptr<BattleField> bf_;
    std::shared_ptr<Enemy> enemy_;
    std::shared_ptr<Camera> cam_;
    std::shared_ptr<ParticleEngine> pe_;
};

