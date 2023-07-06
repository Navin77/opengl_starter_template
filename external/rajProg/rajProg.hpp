#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <map>
#include <string>
using namespace std;

class rajProg
{
 bool compileShader(GLenum shaderType,const char* src);
public:
 string errMsg;
 GLuint id;
 map<const char*,GLint> attribute;
 map<const char*,GLint> uniform;
 bool init(const char* vSrc, const char* fSrc);
 ~rajProg();
};
