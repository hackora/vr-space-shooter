#include "Enemy.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <GL/glut.h> 
#include "SOIL.h"
#include <iostream>

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::privateInit(){

  // list_id = glGenLists(1);
  // // list_id is an integer
  // glNewList(list_id, GL_COMPILE);
  // glBegin(GL_TRIANGLES);
  // glEnable(GL_COLOR_MATERIAL);
  // glColorMaterial(GL_FRONT, GL_DIFFUSE); // glColor now changes the diffuse component
  // glColor3f(0.2f, 0.5f, 0.8f);
  // glNormal3f(5.0f, 5.0f, 10.0f);
  // glVertex3f(5.0f, 5.0f, 5.0f);
  // glVertex3f(10.0f, 5.0f, 5.0f);
  // glVertex3f(10.0f, 10.0f, 5.0f);
  // //glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
  // glColorMaterial(GL_FRONT, GL_SPECULAR); // glColor now changes the specular component
  // glColor3f(0.9f, 0.0f, 0.2f);
  // //glutSolidSphere (5.0, 20, 10);  
  // //glutSolidTorus (2.0, 4.0, 50.0, 8.0);
  // //glutWireTorus (2.0, 3.0, 3.0, 8.0); //weird torus
  // glDisable(GL_COLOR_MATERIAL);
  // glEnd();
  // glEndList();

  //Texture using SOIL library
  int texWidth, texHeight;

  glGenTextures(1, &texture_);
  glBindTexture(GL_TEXTURE_2D, texture_);

  unsigned char* image = SOIL_load_image("img/container.jpg", &texWidth, &texHeight, 0, SOIL_LOAD_RGB);

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
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  // Load and generate the texture
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
  //glGenerateMipmap(GL_TEXTURE_2D);

  //good practice: free memory and unbind texture

  SOIL_free_image_data(image);
  glBindTexture(GL_TEXTURE_2D, 0); //unbind texture
  

}

void Enemy::privateRender()
{

  // //glCallList(list_id);
  
  // // Enable texturing before render
  // glEnable(GL_TEXTURE_2D);
  // glBindTexture(GL_TEXTURE_2D, texture_);

  // //Draw quads with texture coordinates
  // glBegin(GL_QUADS);
  // // Draw the bottom left vertex
  // glTexCoord2f(0,0);
  // glVertex3f (0,0,-2);
  // // Draw the bottom right vertex
  // glTexCoord2f (1,0);
  // glVertex3f (10,0,-2);
  // // Draw the top right vertex
  // glTexCoord2f(1,1);
  // glVertex3f (10,10,-2);
  // // Draw the top left vertex
  // glTexCoord2f (0,1);
  // glVertex3f (0,10,-2);
  // glEnd();

  
  // glBindTexture(GL_TEXTURE_2D, 0); //unbind texture
  // glDisable(GL_TEXTURE_2D);



}

void Enemy::privateUpdate(){
  // matrix_ = glm::translate(glm::mat4(), glm::vec3(0.0f, -5.0f, 20* std::abs(std::sin(counter))));
  // counter+=0.00016;
}

