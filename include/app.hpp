#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

class App
{
public:
 int winWidth = 0, winHeight = 0;
 virtual void init(int argc, char **argv){};
 virtual void display(){};
 virtual void keyboard(unsigned char, int, int){};
 void err(const char *msg)
 {
  perror(msg);
  glutLeaveMainLoop();
 }
};
