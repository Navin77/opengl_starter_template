#include "app.hpp"

App *getApp();
App *app;

void disp()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 app->display();
 glutSwapBuffers();
}

void keyb(unsigned char k, int x, int y)
{
 app->keyboard(k, x, y);
}

int main(int argc, char *argv[])
{
 glutInit(&argc, argv);
 glutInitContextVersion(4, 6);
 glutInitContextProfile(GLUT_CORE_PROFILE);
 glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
 glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
 glutInitWindowPosition(0, 0);
 glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
 glutCreateWindow("app");
 GLenum err = glewInit();
 if (err != GLEW_OK)
 {
  std::cerr << "glewInit failed\n";
  return 0;
 }
 app = getApp();
 app->winWidth = glutGet(GLUT_SCREEN_WIDTH);
 app->winHeight = glutGet(GLUT_SCREEN_HEIGHT);
 app->init(argc, argv);
 glutDisplayFunc(disp);
 glutKeyboardFunc(keyb);
 glutMainLoop();
 delete app;
 return 0;
}
