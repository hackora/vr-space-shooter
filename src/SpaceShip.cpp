#include "SpaceShip.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

SpaceShip::SpaceShip()
{
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::privateInit()
{

}

void SpaceShip::privateRender()
{
  glColor3f(1.0f, 0.0f, 0.0f);
  float size = 1.0f;
  glBegin(GL_QUADS);
    // Near Face
    glNormal3f( 0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size-16+size,  0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( size, -size-16+size,  0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( size,  size-16+size,  0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size,  size-16+size,  0);
  glEnd();
}

void SpaceShip::privateUpdate()
{

}

void SpaceShip::moveRight()
{
  matrix_ = glm::translate(matrix_, glm::vec3(0.1f, 0.0f, 0.0f));
}

void SpaceShip::moveLeft()
{
  matrix_ = glm::translate(matrix_, glm::vec3(-0.1f, 0.0f, 0.0f));
}

void SpaceShip::moveUp()
{
  matrix_ = glm::translate(matrix_, glm::vec3(0.0f, 0.1f, 0.0f));
}

void SpaceShip::moveDown()
{
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