#include<GL/freeglut.h>
#include<GL/gl.h>
#include<bits/stdc++.h>

struct Color
{
 float r;
 float g;
 float b;
};

void display(int x, int y, Color newc)
{
 glColor3f(newc.r, newc.g, newc.b);
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
 glFlush();
}

void floodfill(int x, int y, Color newc, Color oldc)
{
  Color curc=getpixel(x,y);
  
  if(curc.r == oldc.r && curc.g == oldc.g && curc.b == oldc.b)
  {
    display(x,y,newc);
    floodfill(x+1,y, newc,oldc);
    floodfill(x,y+1,newc,oldc);
    floodfill(x-1,y,newc,oldc);
    floodfill(x,y-1,newc,oldc);
  }
  
 return; 
}

void boundaryfill(int x, int y, Color newc, Color bc)
{
 Color curc=getpixel(x,y);
 
 if(curc.r != bc.r && curc.g != bc.g && curc.b != bc.b)
 {
   display(x,y,newc);
   boundaryfill(x+1,y,newc,bc);
   boundaryfill(x,y+1,newc,bc);
   boundaryfill(x-1,y,newc,bc);
   boundaryfill(x,y-1,newc,bc); 
 }

 return;
}

void drawpolygon()
{
 glColor3f(1,1,1);
 glBegin(GL_LINES);
 glVertex2i(200,100);
 glVertex2i(200,200);
 glVertex2i(100,200);
 glVertex2i(100,300);
 glVertex2i(200,300);
 glVertex2i(200,400);
 glVertex2i(300,400);
 glVertex2i(300,300);
 glVertex2i(100,200);
 glVertex2i(200,200);
 glVertex2i(100,300);
 glVertex2i(200,300);
 glVertex2i(200,400);
 glVertex2i(300,400);
 glVertex2i(300,300);
 glVertex2i(400,300);
 glVertex2i(400,200);
 glVertex2i(400,300);
 glVertex2i(200,100);
 glVertex2i(300,100);
 glVertex2i(300,200);
 glVertex2i(300,100);
 glVertex2i(400,200);
 glVertex2i(300,200);
 
 glEnd();
 
}

void renderfunc()
{
 gluOrtho2D(0,500,0,500);
 glClearColor(0,0,0,0);
 glClear(GL_COLOR_BUFFER_BIT);
 Color oldc={1.0f,1.0f,1.0f};
 Color newc={0.0f, 0.0f, 1.0f};
 
 drawpolygon();
 boundaryfill(200,200,newc,oldc);
 
 glFlush();
}

/*void onMouseclick(int button , int state, int x, int y)
{
 Color oldc={1.0f,1.0f,1.0f};
 Color newc={0.0f, 0.0f, 1.0f};
 boundaryfill(200,200,newc,oldc);
}*/

int main(int argc, char ** argv)
{
 glutInit(&argc, argv);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(400,150);
 glutInitDisplayMode(GLUT_SINGLE);
 glutCreateWindow("Polygon filling algorithm");
 glMatrixMode(GL_PROJECTION);
 glutDisplayFunc(renderfunc);
 //glutMouseFunc(onMouseclick);//
 glutMainLoop();
 return 0;
}
