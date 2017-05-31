#include "../include/Enemy.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"
#include <GL/glew.h>
#include <GL/glut.h> 
//#include "SOIL.h"
#include <iostream>

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::privateInit(){

   //list_id = glGenLists(1);
   //list_id is an integer
   //glNewList(list_id, GL_COMPILE);
   //glBegin(GL_QUADS);
   glEnable(GL_COLOR_MATERIAL);
   glColorMaterial(GL_FRONT, GL_DIFFUSE); // glColor now changes the diffuse component
   glColor3f(0.2f, 0.5f, 0.8f);
   /*glNormal3f(0.0f, 0.0f, 1.0f);
   glVertex3f(-2.5f, 0.0f-16, -1024.0f);
   glVertex3f(2.5f, 0.0f-16, -1024.0f);
   glVertex3f(2.5f, 5.0f-16, -1024.0f);
   glVertex3f(-2.5f, 5.0f-16, -1024.0f);*/
   // Create vertex arrays
  /*vertexArray_.push_back(glm::vec3(-2.5f, -2.5f, 0.0f));
  vertexArray_.push_back(glm::vec3(2.5f, -2.5f, 0.0f));
  vertexArray_.push_back(glm::vec3(2.5f, 2.5f, 0.0f));
  vertexArray_.push_back(glm::vec3(-2.5f, 2.5f,0.0f));*/
  loadModel();

  matrix_ = glm::translate(matrix_, glm::vec3(0.0f, -16.0f,-500.0f));

   //glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
   //glColorMaterial(GL_FRONT, GL_SPECULAR); // glColor now changes the specular component
   //glColor3f(0.9f, 0.0f, 0.2f);
   //glutSolidSphere (5.0, 20, 10);  
   //glutSolidTorus (2.0, 4.0, 50.0, 8.0);
   //glutWireTorus (2.0, 3.0, 3.0, 8.0); //weird torus
   glDisable(GL_COLOR_MATERIAL);
   /*glEnd();
   glEndList();*/

/*
  //Texture using SOIL library
  int texWidth, texHeight;

  glGenTextures(1, &texture_);
  glBindTexture(GL_TEXTURE_2D, texture_);

  unsigned char* image = SOIL_load_image("img/container.jpg", &texWidth, &texHeight, 0, SOIL_LOAD_RGB);

  if(!image){
    std::cout << "Failed to load texture: " << sizeof(image) << std::endl;

  }
  else{
    std::cout << "Texture loaded: " << "size " << sizeof(image) << " height " << texHeight << " width "<< texWidth << std::endl;
  }
  // Set the texture wrapping/filtering options (on the currently bound texture object)
  // Set the texture wrapping parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT (usually basic wrapping method)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  // Set texture filtering parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // Set environment mode
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  // Load and generate the texture
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
  //glGenerateMipmap(GL_TEXTURE_2D);

  //good practice: free memory and unbind texture

  SOIL_free_image_data(image);
  glBindTexture(GL_TEXTURE_2D, 0); //unbind texture*/
  

}

void Enemy::privateRender()
{

  //glCallList(list_id);
  
  /*// Enable texturing before render
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture_);

  //Draw quads with texture coordinates
  glBegin(GL_QUADS);
  // Draw the bottom left vertex
  glTexCoord2f(0,0);
  glVertex3f (0,0,-2);
  // Draw the bottom right vertex
  glTexCoord2f (1,0);
  glVertex3f (10,0,-2);
  // Draw the top right vertex
  glTexCoord2f(1,1);
  glVertex3f (10,10,-2);
  // Draw the top left vertex
  glTexCoord2f (0,1);
  glVertex3f (0,10,-2);
  glEnd();

  
  glBindTexture(GL_TEXTURE_2D, 0); //unbind texture
  glDisable(GL_TEXTURE_2D);*/

  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_DIFFUSE); // glColor now changes the diffuse component
  glColor3f(0.2f, 0.5f, 0.8f);

  // Render the battlefield
  glEnableClientState(GL_VERTEX_ARRAY); // enable vertex arrays
  glVertexPointer(3, GL_FLOAT, 0, &vertexArray_[0]); // set vertex pointer
  glDrawArrays(GL_QUADS,0,4);
  glDisableClientState(GL_VERTEX_ARRAY); // disable vertex arrays
  glDisable(GL_COLOR_MATERIAL);

}

void Enemy::privateUpdate(double dt)
{
  glm::vec3 angularVelocity;
  switch (movement){
    case 0:
      angularVelocity = movePattern1(dt);
      break;
    case 1:
      angularVelocity = movePattern2(dt);
      break;
    case 2:
      angularVelocity = movePattern3(dt);
      break;
    default:
      angularVelocity = movePattern1(dt);
      break;
  }

  glm::mat4 twistMatrix; //Screw Theory

  twistMatrix[0] = glm::vec4(0.0f,angularVelocity[2],-angularVelocity[1],0.0f);
  twistMatrix[1] = glm::vec4(-angularVelocity[2],0.0f,angularVelocity[0],0.0f);
  twistMatrix[2] = glm::vec4(angularVelocity[1],-angularVelocity[0],0.0f,0.0f);
  twistMatrix[3] = glm::vec4(glm::vec3(0.0f,0.0f,speed_),0.0f);


  auto delta_R = float(dt)*(matrix_ * twistMatrix);
  matrix_ += delta_R;
  time+=dt;


  if(hasWeapon){
    lasers_.front()->fire();
  }
     
}

void Enemy::setMovement(int mvt)
{
  movement = mvt;
}

glm::vec3 Enemy::movePattern1(double dt)
{
  return glm::vec3(0.0f,0.0f,std::cos(time+dt));
}
glm::vec3 Enemy::movePattern2(double dt)
{
  //return glm::vec3(0.0f,1.0f,0.0f);
  return glm::vec3(0.0f,std::cos(time+dt),0.0f);
}
glm::vec3 Enemy::movePattern3(double dt)
{
  return glm::vec3(std::cos(time+dt),0.0f,0.0f);
}

void Enemy::moveRight()
{
  matrix_ = glm::translate(matrix_, glm::vec3(-0.1f, 0.0f, 0.0f));
}

void Enemy::moveLeft()
{
  matrix_ = glm::translate(matrix_, glm::vec3(0.1f, 0.0f, 0.0f));
}

void Enemy::moveUp()
{
  matrix_ = glm::translate(matrix_, glm::vec3(0.0f, -0.1f, 0.0f));
}

void Enemy::moveDown()
{
  matrix_ = glm::translate(matrix_, glm::vec3(0.0f, 0.1f, 0.0f));
}

void Enemy::moveForward()
{
  matrix_ = glm::translate(matrix_, glm::vec3(0.0f, 0.0f, 0.1f));
}

void Enemy::moveBackward()
{
  matrix_ = glm::translate(matrix_, glm::vec3(0.0f, 0.0f, -0.1f));
}

void Enemy::addLaser()
{
  auto laser = std::make_shared<Laser>();
  laser->owner =1;
  this->addSubObject(laser);
  lasers_.push_back(laser);
}

void Enemy::loadModel(){
  vertexArray_.push_back(glm::vec3(-2.5f, -2.5f, 0.0f));
  vertexArray_.push_back(glm::vec3(2.5f, -2.5f, 0.0f));
  vertexArray_.push_back(glm::vec3(2.5f, 2.5f, 0.0f));
  vertexArray_.push_back(glm::vec3(-2.5f, 2.5f,0.0f));
}