#include "SceneObject.hpp"

//#include <windows.h>
//#include <GL/gl.h> //glew has it
#include <GL/glew.h>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

// NB! Check matrix mult and scoped_ptr

SceneObject::SceneObject()
{
  //setIdentity(matrix_);
  matrix_ = glm::mat4();
}

SceneObject::~SceneObject()
{
}

void SceneObject::render()
{
  glPushMatrix();
    //this->matrix_.multMatrix();
    glMultMatrixf(glm::value_ptr(matrix_));
    this->privateRender();
    for(std::vector<std::shared_ptr<SceneObject> >::iterator it = children_.begin();
        it != children_.end(); it++)
        (*it)->render();
  glPopMatrix();
}

void SceneObject::update(double fps)
{
  this->fps_ = fps;
  this->privateUpdate();
  for(std::vector<std::shared_ptr<SceneObject> >::iterator it = children_.begin();
      it != children_.end(); it++)
      (*it)->update(fps);
}

void SceneObject::init()
{
  this->privateInit();
  for(std::vector<std::shared_ptr<SceneObject> >::iterator it = children_.begin();
      it != children_.end(); it++)
      (*it)->init();
}

void SceneObject::addSubObject(std::shared_ptr<SceneObject> newchild)
{
  children_.push_back(newchild);
}

void SceneObject::removeSubObject(const std::shared_ptr<SceneObject> child)
{
  for(std::vector<std::shared_ptr<SceneObject> >::iterator it = children_.begin();
      it != children_.end(); it++)
    if(*it == child)
    {
      children_.erase(it);
      break;
    }
}