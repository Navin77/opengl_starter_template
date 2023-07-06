#include "app.hpp"
#include "rajProg.hpp"

const char *vSrc = R"**(
#version 460 core
in vec3 aPos;
void main() {
	gl_Position = vec4(aPos,1);
}
)**";

const char *fSrc = R"**(
#version 460 core
out vec4 color;
void main(){
	color = vec4(1,0,0,1);
}
)**";

class myApp : public App
{
 rajProg prog;
 GLuint vao, vbo[2];
 void makeProg();
 void makeBuff();

public:
 void init(int argc, char **argv);
 void keyboard(unsigned char, int, int);
 void display();
 ~myApp();
};

myApp::~myApp()
{
 glDeleteVertexArrays(1, &vao);
 glDeleteBuffers(2, vbo);
}

void myApp::makeProg()
{
 prog.attribute["aPos"] = -1;

 if (!prog.init(vSrc, fSrc))
  err(prog.errMsg.c_str());

 glUseProgram(prog.id);
}

void myApp::makeBuff()
{
 glGenVertexArrays(1, &vao);
 glBindVertexArray(vao);
 glGenBuffers(2, vbo);

 float pos[3] = {0, 0, 0};
 GLushort idx[1] = {0};

 glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
 glBufferData(GL_ARRAY_BUFFER, sizeof(pos), pos, GL_STATIC_DRAW);
 glEnableVertexAttribArray(prog.attribute["aPos"]);
 glVertexAttribPointer(prog.attribute["aPos"], 3, GL_FLOAT, GL_FALSE, 0, 0);

 glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
 glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(idx), idx, GL_STATIC_DRAW);

 glBindVertexArray(0);
 glBindBuffer(GL_ARRAY_BUFFER, 0);
 glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void myApp::display()
{
 glBindVertexArray(vao);
 // glUniform3f(prog.uniform["icolor"],1,0,0);
 // glDrawArrays(GL_POINTS,0,1);
 glDrawElements(GL_POINTS, 1, GL_UNSIGNED_SHORT, 0);
}

void myApp::keyboard(unsigned char key, int x, int y)
{
 switch (key)
 {
 case 27:
  glutLeaveMainLoop();
  break;
 default:
  break;
 }
}

void myApp::init(int argc, char **argv)
{
 makeProg();
 makeBuff();
 glClearColor(0, 0, 0, 0);
 glPointSize(50.0f);
}

App *getApp()
{
 return new myApp();
}