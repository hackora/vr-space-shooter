#include "../include/Laser.hpp"
#include <iostream>

Laser::Laser()
{
}

Laser::~Laser()
{
}

void Laser::privateInit()
{

}

void Laser::privateRender()
{
	if(active_){
		glLineWidth(3.5);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, -7.0);
		glEnd();
	}
}

void Laser::privateUpdate(double dt)
{
	if(active_){
		
		auto angularVelocity = glm::vec3(0.0f,0.0f,0.0f); //move missile is straight line

		glm::mat4 twistMatrix; //Screw Theory
	    twistMatrix[0] = glm::vec4(0.0f,angularVelocity[2],-angularVelocity[1],0.0f);
	    twistMatrix[1] = glm::vec4(-angularVelocity[2],0.0f,angularVelocity[0],0.0f);
	    twistMatrix[2] = glm::vec4(angularVelocity[1],-angularVelocity[0],0.0f,0.0f);
	    twistMatrix[3] = glm::vec4(glm::vec3(0.0f,0.0f,-speed_),0.0f);

	    auto delta_R = float(dt)*(matrix_ * twistMatrix);
	    matrix_ += delta_R;
  	}

}

void Laser::fire()
{
	active_ =true;
}