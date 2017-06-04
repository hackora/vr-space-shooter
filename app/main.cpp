//#include <pthread.h>
#include <windows.h>
#include <GL/glew.h>
//#include <GL/gl.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "../include/Input.hpp"
//#include "../include/FpsCounter.hpp"
#include "../include/Clock.hpp"
#include "../include/GameManager.hpp"
#include "../glm/glm.hpp"

#include <iostream>
#include <memory>
#include <random>

std::shared_ptr<GameManager> gm;
//siut::FpsCounter counter;
siut::Clock timer;

int window;

bool keyPressed[30];
int mousePosX, mousePosY;
float moveX, moveY;
static bool _initialized;

/*//Getting around Segmentation fault (core dumped) when launching application in Ubuntu 
void* simpleFunc(void*) { return NULL; } 
void forcePThreadLink() { pthread_t t1; pthread_create(&t1, NULL, &simpleFunc, NULL); }*/

void init()
{

  assert(!_initialized);
  _initialized = true;
  // Init GLEW
  glewExperimental = true;
  GLenum glewErr = glewInit();
  if( glewErr == GLEW_OK )
    std::cout << "GLEW Init OK - using GLEW version " << glewGetString(GLEW_VERSION) << std::endl;
  else
    std::cout << "GLEW Init FAILED!!" << std::endl;
  std::cout << std::flush;

  //OpenGl Version
  char *buff = (char*)glGetString(GL_VERSION);
  std::cout << buff << std::endl;

  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);

  //counter.start();
  timer.start();


  gm.reset(new GameManager());
  gm->init();

  for(int i=0; i<30; i++)
    keyPressed[i]=false;
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  double dt = timer.stop();
  //std::cout<<dt<<'\n';
  timer.reset();
  gm->update(dt);
  timer.start();
  gm->render();
  //PlaySound("C:/Users/gbo013/Documents/Visual Studio 2017/Projects/space_shooter/space_shooter/nebula.mp3", NULL, SND_ASYNC|SND_LOOP);

  if(keyPressed[KEY_ID_W]==true)      gm->getSpaceship()->moveUp();
  if(keyPressed[KEY_ID_A]==true)      gm->getSpaceship()->moveLeft();
  if(keyPressed[KEY_ID_D]==true)      gm->getSpaceship()->moveRight();
  if(keyPressed[KEY_ID_S]==true)      gm->getSpaceship()->moveDown();
  if(keyPressed[KEY_ID_F]==true){
  if(gm->getSpaceship()->getMissiles() > 0 || gm->getSpaceship()->getMissiles() == -1){
	  gm->fireMissile(gm->getSpaceship()->getMatrix());
	  gm->getSpaceship()->fireMissile();
    }
    keyPressed[KEY_ID_F]=false;
  }
  if(keyPressed[KEY_ID_SPACE]==true){
    if(gm->getSpaceship()->getLasers() > 0 || gm->getSpaceship()->getLasers() == -1){
      gm->fireLaser(gm->getSpaceship()->getMatrix());
	  gm->getSpaceship()->fireLaser();
    }
    keyPressed[KEY_ID_SPACE]=false;
  }
  //if(keyPressed[KEY_ID_C]==true)      gm->getSpaceship()->moveDown();

  if(gm->enemyFreq % 90 ==0)
    gm->getEnemyManager()->createEnemy();

  gm->enemyFreq++;

  glutSwapBuffers();
  //counter.frame();
  glutPostRedisplay();


}

void keyDown(unsigned char key, int x, int y)
{
  switch (key)
  {
    case 'q':
    case 27:
      glutDestroyWindow(window);
#ifndef _WIN32
      // Must use this with regular glut, since it never returns control to main().
      exit(0);
#endif
      break;

      case 'w':
      keyPressed[KEY_ID_W] = true;
      break;
    case 'a':
      keyPressed[KEY_ID_A] = true;
      break;
    case 's':
      keyPressed[KEY_ID_S] = true;
      break;
    case 'd':
      keyPressed[KEY_ID_D] = true;
      break;
    case 'f':
      keyPressed[KEY_ID_F] = true;
      break;
    case ' ':
      keyPressed[KEY_ID_SPACE] = true;
      break;
    case 'c':
      keyPressed[KEY_ID_C] = true;
      break;

    default:
      glutPostRedisplay();
  }
}

void keyUp(unsigned char key, int x, int y)
{
  switch (key)
  {
      case 'w':
      keyPressed[KEY_ID_W] = false;
      break;
    case 'a':
      keyPressed[KEY_ID_A] = false;
      break;
    case 's':
      keyPressed[KEY_ID_S] = false;
      break;
    case 'd':
      keyPressed[KEY_ID_D] = false;
      break;
    case 'f':
      keyPressed[KEY_ID_F] = false;
      break;
    case ' ':
      keyPressed[KEY_ID_SPACE] = false;
      break;
    case 'c':
      keyPressed[KEY_ID_C] = false;
      break;

  }
}

void mousePressed(int button, int state, int posX, int posY)
{
  if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
  {
    mousePosX = posX;
    mousePosY = posY;
    keyPressed[MOUSE_LEFT_BUTTON_DOWN] = true;
  }
  if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
    keyPressed[MOUSE_LEFT_BUTTON_DOWN] = false;
}

void mouseMoved(int posX, int posY)
{
  if(keyPressed[MOUSE_LEFT_BUTTON_DOWN])
  {
    int diffX = posX - mousePosX;
    mousePosX = posX;
    int diffY = posY - mousePosY;
    mousePosY = posY;

    // Implement quaternion based mouse move

  }
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
//  glOrtho(-50, 700, -50, 700, -50, 50);
  gluPerspective(60.0f, float(w)/float(h) ,1.0f, 3000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
//  gluLookAt(0.0, 0.0, 10.0,     0.0, 0.0, 0.0,    0.0, 1.0, 0.0);
}

static void NextClearColor(void)
{
    static int color = 0;

    switch( color++ )
    {
        case 0:  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
             break;
        case 1:  glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
             break;
        default: glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
             color = 0;
             break;
    }
}

//
// Rotation defines
//
#define INERTIA_THRESHOLD       1.0f
#define INERTIA_FACTOR          0.5f
#define SCALE_FACTOR            0.01f
#define SCALE_INCREMENT         0.5f
#define TIMER_FREQUENCY_MILLIS  20

GLfloat RotL = 1 * 3.14f / 180;
int LastTime = 0;

void getGlVersion( int *major, int *minor )
{
    const char* verstr = (const char*)glGetString( GL_VERSION );
    if( (verstr == NULL) || (sscanf( verstr, "%d.%d", major, minor ) != 2) )
    {
        *major = *minor = 0;
        fprintf( stderr, "Invalid GL_VERSION format!!!\n" );
    }
}

/*public*/
int printOglError(char *file, int line)
{
    //
    // Returns 1 if an OpenGL error occurred, 0 otherwise.
    //
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    while (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s\n", file, line, gluErrorString(glErr));
        retCode = 1;
        glErr = glGetError();
    }
    return retCode;
}


int main(int argc, char** argv)
{
  srand (time(NULL));
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
  glutInitWindowSize(700, 700);
  glutInitWindowPosition(10, 10);
  window = glutCreateWindow("Space Shooter");
  init();
  glutKeyboardFunc(keyDown);
  glutKeyboardUpFunc(keyUp);
  glutReshapeFunc(reshape); //glutReshapeFunc sets the reshape callback for the current window
  glutDisplayFunc(display);
  glutMouseFunc(mousePressed);
  glutMotionFunc(mouseMoved);

  // Add other callback functions here..

  glutMainLoop(); // Enters the GLUT event processing loop. This routine should be called at most once in a GLUT program. 
  //Once called, this routine will never return. It will call as necessary any callbacks that have been registered.
  return 0;
}