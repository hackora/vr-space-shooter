#include "../include/SpaceShip.hpp"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../soil/src/SOIL.h"

#include <iostream>

SpaceShip::SpaceShip()
{ 
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::privateInit()
{
  auto laser = std::make_shared<Laser>();
  auto missile = std::make_shared<Missile>();

  lasers_.push_back(laser);
  missiles_.push_back(missile);

  for(unsigned int i=0;i<lasers_.size();i++)
    this->addSubObject(lasers_[i]);
  for(unsigned int i=0;i<missiles_.size();i++)
    this->addSubObject(missiles_[i]);
  //myShader.initShaders("shaders/red");

  int texWidth, texHeight;

  glGenTextures(1, &BfTexture_);
  glBindTexture(GL_TEXTURE_2D, BfTexture_);

  unsigned char* image = SOIL_load_image("img/maps/colorMap2012.bmp", &texWidth, &texHeight, 0, SOIL_LOAD_RGB);

  if (!image) {
	  std::cout << "Failed to load texture: " << sizeof(image) << std::endl;

  }
  else {
	  std::cout << "Texture loaded: " << "size " << sizeof(image) << " height " << texHeight << " width " << texWidth << std::endl;
  }
  // Set the texture wrapping/filtering options (on the currently bound texture object)
  // Set the texture wrapping parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT (usually basic wrapping method)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  // Set texture filtering parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // Set environment mode
  //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  // Load and generate the texture
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
  //glGenerateMipmap(GL_TEXTURE_2D);

  //good practice: free memory and unbind texture

  SOIL_free_image_data(image);
  glBindTexture(GL_TEXTURE_2D, 0); //unbind texture
}

void SpaceShip::privateRender()
{
  glActiveTexture(GL_TEXTURE0);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, BfTexture_);
  glColor3f(1.0f, 1.0f, 1.0f);
  //myShader.enable();

  float size = 1.0f;
  glBegin(GL_QUADS);
    // Near Face
    glNormal3f( 0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size-16+size,  0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( size, -size-16+size,  0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( size,  size-16+size,  0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size,  size-16+size,  0);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, 0); //unbind texture
  glDisable(GL_TEXTURE_2D);
 // myShader.disable();
}

void SpaceShip::privateUpdate()
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