#include<iostream>
#include<cstdlib>
#include<string.h>
#include<stdlib.h>
#include <GL/glut.h>

int npunti;

void myinit()
{
 glClearColor(0., 0., 0., 1.);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-0.1, 1.1, -0.1, 1.1);
 glMatrixMode(GL_MODELVIEW);
}

void display() 
{
 typedef GLdouble point2[2];
 int k;
 point2 p;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.,1.,1.);
 glRectf(0.,0.,1.,1.);

 glColor3f(1., 0., 0.);

 size_t cnt = 0;
 for (size_t i = 0; i < npunti; i++)		
   {
      double x = drand48();
      double y = drand48();
      if (x * x + y * y <= 1) 
      {
         cnt++;
         glBegin(GL_POINTS);
           glVertex2f(x,y);
         glEnd();  
       }
   }
      std::cout << "pi = " << 4 * (double)(cnt)/npunti 
	        << "   std-err = " << (std::sqrt((double)(cnt)))/npunti
                << std::endl;

 glFlush();
}
//
//  Il main
//
int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  if (argc >= 2)
  {
    npunti=atoi(argv[1]);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Sierpinski Gasket");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
  }
  else
  {
   cerr << " No npoints for Sierp" << endl;
  }
 return 0;
}








