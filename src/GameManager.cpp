#include "../include/GameManager.hpp"

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

  skybox_.reset(new SkyBox(cam_));
  this->addSubObject(skybox_);

  bf_.reset(new BattleField());
  this->addSubObject(bf_);

  spaceship_.reset(new SpaceShip(skybox_->getTextureId()));
  this->addSubObject(spaceship_);

  em_.reset(new EnemyManager());
  this->addSubObject(em_);
  /*pe_.reset(new ParticleEngine());
  this->addSubObject(pe_);*/

  em_->createEnemy();

  //pe_.reset(new ParticleEngine());
  //this->addSubObject(pe_);

  // glEnable(GL_FOG);

  // GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};
  // GLfloat density = 0.3;
  // glFogfv(GL_FOG_COLOR, fogColor);
  // //specify the equation to be used
  // glFogi(GL_FOG_MODE, GL_LINEAR);
  // //specify parameters
  // glFogf(GL_FOG_START, 2.0f);
  // glFogf(GL_FOG_END, 1.0f);
  // glFogf (GL_FOG_DENSITY, density);
  // //per-pixel fog calculations
  // glHint(GL_FOG_HINT, GL_NICEST);

}

void GameManager::privateRender()
{
  // Nothing to render
  //glDisable(GL_FOG);

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

std::shared_ptr<SpaceShip> GameManager::getSpaceship()
{
  return spaceship_;
}

std::shared_ptr<EnemyManager> GameManager::getEnemyManager()
{
  return em_;
}