#include "Missile.hpp"
#include "glm/gtc/matrix_transform.hpp"

Missile::Missile()
{
}

Missile::~Missile()
{
}

void Missile::privateInit()
{
}

void Missile::privateRender()
{
	if(fire_){
		glLineWidth(5.5);
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, -15.5, -0.2);
		glVertex3f(0.0, -15.5, -10);
		glEnd();
	}
}

void Missile::privateUpdate()
{
	if(fire_){
		matrix_ = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f,-10*counter));
		counter+=0.016;
	}
	if(counter>100){
		fire_ = false;
	}
}

void Missile::fire()
{
	fire_ =true;
}