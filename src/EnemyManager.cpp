#include "../include/EnemyManager.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/glm.hpp"
#include <random>
#include <iostream>

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::privateInit()
{
    matrix_ = glm::translate(matrix_, glm::vec3(0.0f, 0.0f,-512.0f));
}

void EnemyManager::privateRender()
{
}

void EnemyManager::privateUpdate(double dt)
{
}

void EnemyManager::createEnemy()
{

	auto enemy = std::make_shared<Enemy>();
	this->addSubObject(enemy);
	enemy->init();
	int random = rand() % 3;
	//if(random==0){
		//enemy->addBullet();
	//}	
	enemy->setMovement(random);
	enemies.push_back(enemy);
	//std::cout<<enemies.size()<<std::endl;
}

void EnemyManager::removeDead(){

  for(auto it=enemies.begin(); it!=enemies.end();){
    if(it->get()->isDead()){
		this->removeSubObject(*it);
		it = enemies.erase(it);
    }
	else
	{
		++it;
	}
  }
}