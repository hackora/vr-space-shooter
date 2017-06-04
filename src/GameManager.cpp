#include "../include/GameManager.hpp"
#include <iostream>

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

  em_.reset(new EnemyManager());
  this->addSubObject(em_);
  /*pe_.reset(new ParticleEngine());
  this->addSubObject(pe_);*/

  spaceship_.reset(new SpaceShip(skybox_->getTextureId()));
  this->addSubObject(spaceship_);

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

void GameManager::privateUpdate(double dt)
{
  // Instead of adding alle objects in the scene as subobject to the camera they are added as subobjects
  // to the game manager. Therefore, we set the game manager matrix equal to the camera matrix.
  this->matrix_ = cam_->getMatrix();


  auto dynamicObjects = getDynamicObjects();
  auto collisions = detectCollisions(dynamicObjects);
  resolveCollisions(collisions);
  removeDead();
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

std::vector<std::shared_ptr<SceneObject>> GameManager::getDynamicObjects(){

  std::vector<std::shared_ptr<SceneObject>> dynamicObjects;

  dynamicObjects.push_back(spaceship_);
  auto missiles = spaceship_->getMissiles();
  for(auto it=missiles.begin(); it!=missiles.end();it++){
    if(it->get()->isActive()){
      dynamicObjects.push_back(*it);
      missiles_.push_back(*it);
    }
  }
  auto lasers = spaceship_->getLasers();
  for(auto it=lasers.begin(); it!=lasers.end();it++){
    if(it->get()->isActive()){
      dynamicObjects.push_back(*it);
      lasers_.push_back(*it);
    }
  }
  auto enemies = em_->getEnemies();
  for(auto it=enemies.begin(); it!=enemies.end();it++){
    dynamicObjects.push_back(*it);
    /*auto bullets = (*it)->getBullets();
    for(auto it1=bullets.begin(); it1!=bullets.end();it1++){
      if(it1->get()->isActive()){
        dynamicObjects.push_back(*it1);
        bullets.push_back(*it1);
      }
    }*/
  }

  return dynamicObjects;

}


std::vector<CollisionObject> GameManager::detectCollisions(std::vector<std::shared_ptr<SceneObject>> dynamicObjects){

  std::vector<CollisionObject> collisions;

  for(auto it1=dynamicObjects.begin(); it1!=dynamicObjects.end();it1++){

    for(auto it2=it1+1; it2!=dynamicObjects.end();it2++){

      if (detectCollision(it1->get(),it2->get())){

        CollisionObject c = {it1->get(),it1->get()}; //collision with other dynamic scene object
        collisions.push_back(c);
      }
    }
  }

  /*for(auto it=children.begin(); it!=children.end();it++){

    if(detectCollision(**it)){

        CollisionObject c = {**it,**it}; //collision with terrain
        collisions.push_back(&c);
      }
  }*/
  return collisions;

}

bool GameManager::detectCollision(SceneObject* obj1, SceneObject* obj2){

    auto pos1 = obj1->getMatrix()[3];
    auto pos2 = obj2->getMatrix()[3];
    float r = obj1->getSurroundingSphere() + obj2->getSurroundingSphere();
    float d = std::sqrt((pos2[0]-pos1[0]) * (pos2[0]-pos1[0]) +
                      (pos2[1]-pos1[1]) * (pos2[1]-pos1[1])+
                      (pos2[2]-pos1[2])  * (pos2[2]-pos1[2]));

    
    if(d<r)
      return true;
    else 
      return false;

}

bool GameManager::detectCollision(SceneObject* obj){

  /*auto pos = obj.getMatrix()[3];

  if (obj.y <= bf_->getHeight(obj.x,obj.z))
    return true;
  else 
    return false;*/
}

void GameManager::resolveCollisions(std::vector<CollisionObject> c){

  while(!c.empty()){

    auto it=c.begin();
    c.erase(it);
    auto obj1 = it->obj1;
    auto obj2 = it->obj2;

    if(obj1 == obj2) //collision with Terrain
      obj1->collided(true);

    else{ //collision with other dynamic obj
      obj1->collided(false);
      obj2->collided(false);
    }
  }
}

void GameManager::removeDead(){

  em_->removeDead(); //remove dead enemies

  for(auto it=missiles_.begin(); it!=missiles_.end();it++){
    if(it->get()->isDead()){
      it->reset();
    }
  }

  for(auto it=lasers_.begin(); it!=lasers_.end();it++){
    if(it->get()->isDead()){
      it->reset();
    }
  }
}