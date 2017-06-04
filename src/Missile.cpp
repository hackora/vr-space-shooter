#include "../include/Missile.hpp"
#include "glm/gtc/matrix_transform.hpp"

Missile::Missile()
{
}

Missile::~Missile()
{
}

void Missile::privateInit()
{
	alive_ = true;
	vertexArray_.push_back(glm::vec3(0.0, 0.0, 0.0));
	vertexArray_.push_back(glm::vec3(0.0, 0.0, -7.0));
	setSurroundingSphere();
}

void Missile::privateRender()
{
	if(active_){
		glLineWidth(5.5);
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, -7.0);
	 	glEnd();
	}
}

void Missile::privateUpdate(double dt)
{
	if(active_){
		
		auto angularVelocity = glm::vec3(0.0f,0.0f,0.0f); //move laser in a straight line

		glm::mat4 twistMatrix; //Screw Theory
	    twistMatrix[0] = glm::vec4(0.0f,angularVelocity[2],-angularVelocity[1],0.0f);
	    twistMatrix[1] = glm::vec4(-angularVelocity[2],0.0f,angularVelocity[0],0.0f);
	    twistMatrix[2] = glm::vec4(angularVelocity[1],-angularVelocity[0],0.0f,0.0f);
	    twistMatrix[3] = glm::vec4(glm::vec3(0.0f,0.0f,-speed_),0.0f);

	    auto delta_R = float(dt)*(matrix_ * twistMatrix);
	    matrix_ += delta_R;
  	}
}

void Missile::fire()
{
	active_ =true;
}

void Missile::setSurroundingSphere(){

  float radius = 0.0;
  glm::vec3 pos = matrix_[0];
  for(int i=0;i<vertexArray_.size();i++){

    float distance = std::sqrt(vertexArray_[i].x * vertexArray_[i].x +
                              vertexArray_[i].y * vertexArray_[i].y+
                              vertexArray_[i].z  * vertexArray_[i].z);

    if (distance > radius)
      radius = distance;
  }

  radius_ = radius;

}

float Missile::getSurroundingSphere(){

	return radius_;
}