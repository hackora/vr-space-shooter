#include "../include/EnemyManager.hpp"
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
  	int random=rand()%3;
  	if(random==0){
  		enemy->addLaser();
  		enemy->hasWeapon=true;
  	}	
  	enemy->setMovement(random);
  	enemies.push_back(enemy);
  	//std::cout<<enemies.size()<<std::endl;
}

void EnemyManager::destroyEnemy(Enemy enemy)
{
	
}