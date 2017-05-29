#include "../include/SpaceShip.hpp"
#include "SkyBox.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <GL/glut.h> 

#include <iostream>

SpaceShip::SpaceShip(GLuint id)
{ 
  textureID = id;
  //std::cout<<"Texture id "<<id<<std::endl;
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::privateInit()
{
  myShader.initShaders("/home/ghada/code/Space-Shooter/shaders/reflection");
  GLint texSampler;
  texSampler = glGetUniformLocation(myShader.getProg(), "reflection");
  glUniform1i(texSampler, textureID);

  // Create vertex arrays
  vertexArray_.push_back(glm::vec3(-2.5f, -2.5f, 0.0f));
  vertexArray_.push_back(glm::vec3(2.5f, -2.5f, 0.0f));
  vertexArray_.push_back(glm::vec3(2.5f, 2.5f, 0.0f));
  vertexArray_.push_back(glm::vec3(-2.5f, 2.5f,0.0f));


  auto laser = std::make_shared<Laser>();
  auto missile = std::make_shared<Missile>();

  lasers_.push_back(laser);
  missiles_.push_back(missile);

  for(unsigned int i=0;i<lasers_.size();i++)
    this->addSubObject(lasers_[i]);
  for(unsigned int i=0;i<missiles_.size();i++)
    this->addSubObject(missiles_[i]);
}

void SpaceShip::privateRender()
{
  glColor3f(1.0f, 1.0f, 1.0f);
  
  //glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
  myShader.enable();

  // Render the spaceship
  glEnableClientState(GL_VERTEX_ARRAY); // enable vertex arrays
  glVertexPointer(3, GL_FLOAT, 0, &vertexArray_[0]); // set vertex pointer
  glDrawArrays(GL_QUADS,0,4);
  glDisableClientState(GL_VERTEX_ARRAY); // disable vertex arrays

  myShader.disable();
}

void SpaceShip::privateUpdate(double dt)
{
}

void SpaceShip::moveRight()
{
  auto pos =getMatrix()[3];
  //std::cout<<pos[0]<< " "<<pos[1]<<" "<<pos[2]<<std::endl;
  if(pos[0]+ 0.5+0.1 <16)
    matrix_ = glm::translate(matrix_, glm::vec3(0.1f, 0.0f, 0.0f));
}

void SpaceShip::moveLeft()
{
  auto pos =getMatrix()[3];
  if(pos[0]+ 0.5-0.1 >-16)
    matrix_ = glm::translate(matrix_, glm::vec3(-0.1f, 0.0f, 0.0f));
}

void SpaceShip::moveUp()
{
  matrix_ = glm::translate(matrix_, glm::vec3(0.0f, 0.1f, 0.0f));
}

void SpaceShip::moveDown()
{
  auto pos =getMatrix()[3];
  //if(pos[1]-0.1>0.0)
    matrix_ = glm::translate(matrix_, glm::vec3(0.0f, -0.1f, 0.0f));
}

void SpaceShip::moveForward()
{
  matrix_ = glm::translate(matrix_, glm::vec3(0.0f, 0.0f, -0.1f));
}

void SpaceShip::moveBackward()
{
  matrix_ = glm::translate(matrix_, glm::vec3(0.0f, 0.0f, 0.1f));
}

std::vector<std::shared_ptr<Missile>> SpaceShip::getMissile()
{
  return missiles_;
}

std::vector<std::shared_ptr<Laser>> SpaceShip::getLaser()
{
  return lasers_;
}