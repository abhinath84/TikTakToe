/*
 * game.cpp
 *
 *  Created on: 25-Mar-2016
 *      Author: abhi
 */

#include "game.h"

Game::Game()
:GLWidget()
{
}

Game::Game(int win_x, int win_y, int win_w,
            int win_h, const string &win_title)
:GLWidget(win_x, win_y, win_w, win_h, win_title)
{
}

Game::~Game()
{
}

void Game::displayGL()
{
  //  Clear the window or more specifically the frame buffer...
  //  This happens by replacing all the contents of the frame
  //  buffer by the clear color
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

  //  Set shading model
  glShadeModel(GL_FLAT);

  //drawSpiral_3D();
  //drawLines_3D();
  drawLineStripLoop_3D();

  /// swap background buffer.
  glutSwapBuffers();
}

void Game::drawLineStripLoop_3D()
{
  GLfloat angle; // Storage for coordinates and angles
  GLfloat xRot = 45.0f;
  GLfloat yRot = 0.0f;
  Point3f pt;
  Color3f pencil(1.0f, 0.0f, 0.0f);

  // Save matrix state and do the rotation
  glPushMatrix();

  glRotatef(xRot, 1.0f, 0.0f, 0.0f);
  glRotatef(yRot, 0.0f, 1.0f, 0.0f);

  // Call only once for all remaining points
  glColor3f(pencil.r, pencil.g, pencil.b);
  glBegin(GL_LINE_STRIP);

  pt.z = -50.0f;
  for(angle = 0.0f; angle <= (2.0f*GL_PI)*3.0f; angle += 0.1f)
  {
    pt.x = 50.0f*sin(angle);
    pt.y = 50.0f*cos(angle);

    // Specify the point and move the z value up a little
    glVertex3f(pt.x, pt.y, pt.z);
    pt.z += 0.5f;
  }

  // Done drawing points
  glEnd();

  // Restore transformations
  glPopMatrix();
}
