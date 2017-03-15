#include "Enemy.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <GL/glut.h> 

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::privateInit(){
  list_id = glGenLists(1);
  // list_id is an integer
  glNewList(list_id, GL_COMPILE);
  glBegin(GL_TRIANGLES);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_DIFFUSE); // glColor now changes the diffuse component
  glColor3f(0.2f, 0.5f, 0.8f);
  glNormal3f(5.0f, 5.0f, 10.0f);
  glVertex3f(5.0f, 5.0f, 5.0f);
  glVertex3f(10.0f, 5.0f, 5.0f);
  glVertex3f(10.0f, 10.0f, 5.0f);
  //glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
  glColorMaterial(GL_FRONT, GL_SPECULAR); // glColor now changes the specular component
  glColor3f(0.9f, 0.0f, 0.2f);
  //glutSolidSphere (5.0, 20, 10);  
  glutSolidTorus (2.0, 4.0, 50.0, 8.0);
  //glutWireTorus (2.0, 3.0, 3.0, 8.0); //weird torus
  glDisable(GL_COLOR_MATERIAL);
  glEnd();
  glEndList();
}

void Enemy::privateRender()
{
  glCallList(list_id);
}

void Enemy::privateUpdate(){
  matrix_ = glm::translate(glm::mat4(), glm::vec3(0.0f, -5.0f, 20* std::abs(std::sin(counter))));
  counter+=0.00016;
}

