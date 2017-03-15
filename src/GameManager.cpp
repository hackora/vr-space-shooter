#include "GameManager.hpp"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::privateInit()
{
  // Set default OpenGL states
  glEnable(GL_CULL_FACE);

  // Adding the camera to the scene
  cam_.reset(new Camera());
  //  this->addSubObject(cam_);
  //  matrix_.translate(0.0f, 0.0f, -99.0f);

  bf_.reset(new BattleField());
  this->addSubObject(bf_);

  //spaceship_.reset(new SpaceShip());
  //this->addSubObject(spaceship_);

   enemy_.reset(new Enemy());
   this->addSubObject(enemy_);

}

void GameManager::privateRender()
{
  // Nothing to render
}

void GameManager::privateUpdate()
{
  // Instead of adding alle objects in the scene as subobject to the camera they are added as subobjects
  // to the game manager. Therefore, we set the game manager matrix equal to the camera matrix.
  this->matrix_ = cam_->getMatrix();
}

std::shared_ptr<Camera> GameManager::getCam()
{
  return cam_;
}
