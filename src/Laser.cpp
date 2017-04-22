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
	if(fire_ && owner ==0){
		glLineWidth(3.5);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, -15.5, -0.2);
		glVertex3f(0.0, -15.5, -100);
		glEnd();
	}
	else if (fire_ && owner ==1){
		glLineWidth(3.5);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, -14.5, -1024);
		glVertex3f(0.0, -14.5, 100);
		glEnd();
	}
	fire_=false;
}

void Laser::privateUpdate()
{

}

void Laser::fire()
{
	fire_ =true;
}