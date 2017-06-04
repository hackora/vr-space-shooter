
#include <GL/glew.h>
#include <limits>
#include "../include/BattleField.hpp"
#include "SOIL.h"
#include <iostream>

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

  // Create texture array 
  for(int z=0; z<sizeZ;z++){
    for(int x = 0; x<sizeX ; x++){
   	  textureArray_.push_back(glm::vec2((double)x/(sizeX-1), (double)z/(sizeZ-1))); //BattleField in (OXZ) plane, y=0
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

/*
	//Texture using SOIL library
  int texWidth, texHeight;

  glGenTextures(1, &BfTexture_);
  glBindTexture(GL_TEXTURE_2D, BfTexture_);

  unsigned char* image = SOIL_load_image("img/color_height/heightmap.bmp", &texWidth, &texHeight, 0, SOIL_LOAD_RGB);

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
  //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  // Load and generate the texture
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
  //glGenerateMipmap(GL_TEXTURE_2D);

  //good practice: free memory and unbind texture

  SOIL_free_image_data(image);
  glBindTexture(GL_TEXTURE_2D, 0); //unbind texture*/


  GLint texLoc;
  //initiate shader
  myShader.initShaders("/home/ghada/Desktop/game/Space-Shooter/shaders/bf");
  myShader.enable();

  //color map

  int texWidth0, texHeight0;

  unsigned char* image0 = SOIL_load_image("/home/ghada/Desktop/game/Space-Shooter/img/color_height/maps/rockandmortar_specular.png", &texWidth0, &texHeight0, 0, SOIL_LOAD_RGB);

  if(!image0){
    std::cout << "Failed to load texture: " << sizeof(image0) << std::endl;

  }
  else{
    std::cout << "Texture loaded: " << "size " << sizeof(image0) << " height " << texHeight0 << " width "<< texWidth0 << std::endl;
  }

  glActiveTexture(GL_TEXTURE0);
  glGenTextures(1, &colorMap_);
  glBindTexture(GL_TEXTURE_2D, colorMap_);

  //Texture parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER); // Set texture wrapping to GL_REPEAT (usually basic wrapping method)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
  // Set texture filtering parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth0, texHeight0, 0, GL_RGB, GL_UNSIGNED_BYTE, image0);

  //pass it to shader
  texLoc = glGetUniformLocation(myShader.getProg(), "color");
  glActiveTexture(GL_TEXTURE0);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,colorMap_);
  glUniform1i(texLoc, 0);


  //height map

  int texWidth1, texHeight1;

  unsigned char* image1 = SOIL_load_image("/home/ghada/Desktop/game/Space-Shooter/img/color_height/maps/moss-heightmap.bmp", &texWidth1, &texHeight1, 0, SOIL_LOAD_RGB);

  if(!image1){
    std::cout << "Failed to load texture: " << sizeof(image1) << std::endl;

  }
  else{
    std::cout << "Texture loaded: " << "size " << sizeof(image1) << " height " << texHeight1 << " width "<< texWidth1 << std::endl;
  }

  glActiveTexture(GL_TEXTURE1);
  glGenTextures(1, &heightMap_);
  glBindTexture(GL_TEXTURE_2D, heightMap_);

  //Texture parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); // Set texture wrapping to GL_REPEAT (usually basic wrapping method)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
  // Set texture filtering parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth1, texHeight1, 0, GL_RGB, GL_UNSIGNED_BYTE, image1);

  //pass it to shader
  texLoc = glGetUniformLocation(myShader.getProg(), "height");
  glActiveTexture(GL_TEXTURE1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,heightMap_);
  glUniform1i(texLoc, 1);

  myShader.disable();

}


void BattleField::privateRender()
{
 /* // Enable texturing before render
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, BfTexture_);

  glColor3f(1.0, 1.0, 1.0);
  glEnable(GL_PRIMITIVE_RESTART);
  // Render the battlefield
  glEnableClientState(GL_VERTEX_ARRAY); // enable vertex arrays
  glVertexPointer(3, GL_FLOAT, 0, &vertexArray_[0]); // set vertex pointer
  glDrawElements( GL_QUAD_STRIP,indexArray_.size(),GL_UNSIGNED_INT,&indexArray_[0]); //strips
  //glDrawArrays (GL_POINTS,0,vertexArray_.size());
  glDisableClientState(GL_VERTEX_ARRAY); // disable vertex arrays
  glDisable(GL_PRIMITIVE_RESTART);
  
  glBindTexture(GL_TEXTURE_2D, 0); //unbind texture
  glDisable(GL_TEXTURE_2D);*/


  myShader.enable();

  glColor3f(1.0f, 1.0f, 1.0f);

  glEnable(GL_PRIMITIVE_RESTART);

  glActiveTexture(GL_TEXTURE0);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, colorMap_);

  glActiveTexture(GL_TEXTURE1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, heightMap_);

  // Render the battlefield
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY); // enable vertex arrays
  glTexCoordPointer(2, GL_FLOAT, 0, &textureArray_[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertexArray_[0]); // set vertex pointer
  glDrawElements( GL_QUAD_STRIP,indexArray_.size(),GL_UNSIGNED_INT,&indexArray_[0]); //strips
  glDisableClientState(GL_VERTEX_ARRAY); // disable vertex arrays
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  


  glActiveTexture(GL_TEXTURE1);
  glDisable(GL_TEXTURE_2D);
  glActiveTexture(GL_TEXTURE0);
  glDisable(GL_TEXTURE_2D);

  glDisable(GL_PRIMITIVE_RESTART);

  myShader.disable();
}

void BattleField::privateUpdate(double dt)
{
}