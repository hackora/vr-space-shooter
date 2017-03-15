#include <GL/glew.h>
#include <limits>
#include "BattleField.hpp"

BattleField::BattleField()
{
}

BattleField::~BattleField()
{
}

void BattleField::privateInit()
{
  // Create vertex arrays
	for(int z=0; z<sizeZ;z++){
		for(int x = -sizeX*0.5; x<sizeX*0.5 ; x++){
			vertexArray_.push_back(glm::vec3(x,Y,-z)); //BattleField in (OXZ) plane, y=0
		}
	}

  // Set PRIMITIVE RESTART value
	unsigned int restartPrimiveValue = std::numeric_limits<unsigned int>::max();
	glPrimitiveRestartIndex(restartPrimiveValue);

  // Create index arrays
	for(int i=0; i<sizeZ-1;i++){
		for(int j = 0; j<sizeX ; j++){
			indexArray_.push_back( j + sizeX + i*sizeX );
			indexArray_.push_back( j + i*sizeX );
		}
		indexArray_.push_back(restartPrimiveValue);
	}	
}


void BattleField::privateRender()
{
	glEnable(GL_PRIMITIVE_RESTART);
  // Render the battlefield
	glEnableClientState(GL_VERTEX_ARRAY); // enable vertex arrays
	glVertexPointer(3, GL_FLOAT, 0, &vertexArray_[0]); // set vertex pointer
	glDrawElements( GL_QUAD_STRIP,indexArray_.size(),GL_UNSIGNED_INT,&indexArray_[0]); //strips
    //glDrawArrays (GL_POINTS,0,vertexArray_.size());
    glDisableClientState(GL_VERTEX_ARRAY); // disable vertex arrays
    glDisable(GL_PRIMITIVE_RESTART);
}

void BattleField::privateUpdate()
{
}