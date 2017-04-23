#include "../include/ParticleEngine.hpp"
//#include "SOIL.h"
#include <iostream>
#include <GL\glew.h>
//#include <GL/glut.h> 


ParticleEngine::ParticleEngine()
{
}

ParticleEngine::~ParticleEngine()
{
}

void ParticleEngine::privateInit()
{
	/*//Texture using SOIL library
  int texWidth, texHeight;

  glGenTextures(1, &texture_);
  glBindTexture(GL_TEXTURE_2D, texture_);

  unsigned char* image = SOIL_load_image("img/Data/Particle3.bmp", &texWidth, &texHeight, 0, SOIL_LOAD_RGB);

  if(!image){
    std::cout << "Failed to load texture: " << sizeof(image) << std::endl;

  }
  else{
    std::cout << "Texture loaded: " << "size " << sizeof(image) << " height " << texHeight << " width "<< texWidth << std::endl;
  }
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

  //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

  SOIL_free_image_data(image);
  glBindTexture(GL_TEXTURE_2D, 0); //unbind texture

	for (int loop=0;loop<MAX_PARTICLES;loop++)        // Initials All The Textures
  {
    particles[loop].active=true;               // Make All The Particles Active
    particles[loop].life=1.0f;               // Give All The Particles Full Life
    particles[loop].fade=float(rand()%100)/1000.0f+0.003f; // Random Fade Speed
    particles[loop].redValue=colors_[loop*(12/MAX_PARTICLES)][0];  // Select Red Rainbow Color
    particles[loop].greenValue=colors_[loop*(12/MAX_PARTICLES)][1];  // Select Red Rainbow Color
    particles[loop].blueValue=colors_[loop*(12/MAX_PARTICLES)][2];  // Select Red Rainbow Color
    particles[loop].xi=float((rand()%50)-26.0f)*10.0f;   // Random Speed On X Axis
    particles[loop].yi=float((rand()%50)-25.0f)*10.0f;   // Random Speed On Y Axis
    particles[loop].zi=float((rand()%50)-25.0f)*10.0f;   // Random Speed On Z Axis
    particles[loop].xg=0.0f;                 // Set Horizontal Pull To Zero
    particles[loop].yg=-0.8f;                // Set Vertical Pull Downward
    particles[loop].zg=0.0f;                 // Set Pull On Z Axis To Zero
  }
  glBindTexture(GL_TEXTURE_2D, 0); //unbind texture
  glDisable(GL_TEXTURE_2D);*/

}

void ParticleEngine::privateRender()
{
	/* glShadeModel(GL_SMOOTH);              // Enable Smooth Shading
   glClearColor(0.0f,0.0f,0.0f,0.0f);          // Black Background
   glClearDepth(1.0f);                 // Depth Buffer Setup
   glDisable(GL_DEPTH_TEST);             // Disable Depth Testing
   glEnable(GL_BLEND);                 // Enable Blending
   glBlendFunc(GL_SRC_ALPHA,GL_ONE);         // Type Of Blending To Perform
   glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST); // Really Nice Perspective Calculations
   glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);       // Really Nice Point Smoothing
	glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture_);


	for (int loop=0;loop<MAX_PARTICLES;loop++)          // Loop Through All The Particles
  {
    if (particles[loop].active)              // If The Particle Is Active
    {
      float x=particles[loop].x;           // Grab Our Particle X Position
      float y=particles[loop].y;           // Grab Our Particle Y Position
      float z=particles[loop].z+zoom;          // Particle Z Pos + Zoom

      // Draw The Particle Using Our RGB Values, Fade The Particle Based On It's Life
      glColor4f(particles[loop].redValue,particles[loop].greenValue,particles[loop].blueValue,particles[loop].life);

      glBegin(GL_TRIANGLE_STRIP);           // Build Quad From A Triangle Strip
        glTexCoord2d(1,1); glVertex3f(x+0.5f,y+0.5f,z); // Top Right
        glTexCoord2d(0,1); glVertex3f(x-0.5f,y+0.5f,z); // Top Left
        glTexCoord2d(1,0); glVertex3f(x+0.5f,y-0.5f,z); // Bottom Right
        glTexCoord2d(0,0); glVertex3f(x-0.5f,y-0.5f,z); // Bottom Left
      glEnd();                    // Done Building Triangle Strip

      particles[loop].x+=particles[loop].xi/(slowdown*1000);// Move On The X Axis By X Speed
      particles[loop].y+=particles[loop].yi/(slowdown*1000);// Move On The Y Axis By Y Speed
      particles[loop].z+=particles[loop].zi/(slowdown*1000);// Move On The Z Axis By Z Speed

      particles[loop].xi+=particles[loop].xg;     // Take Pull On X Axis Into Account
      particles[loop].yi+=particles[loop].yg;     // Take Pull On Y Axis Into Account
      particles[loop].zi+=particles[loop].zg;     // Take Pull On Z Axis Into Account
      particles[loop].life-=particles[loop].fade;   // Reduce Particles Life By 'Fade'

      if (particles[loop].life<0.0f)         // If Particle Is Burned Out
      {
        particles[loop].life=1.0f;         // Give It New Life
        particles[loop].fade=float(rand()%100)/1000.0f+0.003f; // Random Fade Value
        particles[loop].x=0.0f;            // Center On X Axis
        particles[loop].y=0.0f;            // Center On Y Axis
        particles[loop].z=0.0f;            // Center On Z Axis
        particles[loop].xi=xspeed+float((rand()%60)-32.0f);  // X Axis Speed And Direction
        particles[loop].yi=yspeed+float((rand()%60)-30.0f);  // Y Axis Speed And Direction
        particles[loop].zi=float((rand()%60)-30.0f); // Z Axis Speed And Direction
        particles[loop].redValue=colors_[col][0];      // Select Red From Color Table
        particles[loop].greenValue=colors_[col][1];      // Select Green From Color Table
        particles[loop].blueValue=colors_[col][2];      // Select Blue From Color Table
      }
    }
  }
   glDisable(GL_BLEND);
   glBindTexture(GL_TEXTURE_2D, 0); //unbind texture
   glDisable(GL_TEXTURE_2D);*/
}

void ParticleEngine::privateUpdate()
{
	//col++;
}