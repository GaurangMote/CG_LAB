#include<GL/glut.h>
#include<GL/gl.h>

void displayfunc(int x,int y)
{
   glColor3f(1,1,1);
       glBegin(GL_POINTS);
           glVertex2f(x,y);
       glEnd();   
       glFlush();  
}

void eightwaysymmetric(int xc,int yc,int x,int y)
{
    displayfunc(x+xc,y+yc);
    displayfunc(x+xc,-y+yc);
    displayfunc(-x+xc,-y+yc);
    displayfunc(-x+xc,y+yc);
    displayfunc(y+xc,x+yc);
    displayfunc(-y+xc,x+yc);
    displayfunc(-y+xc,-x+yc);
    displayfunc(y+xc,-x+yc);
}

void circle(int xc,int yc,int r)
{
    int x=0,y=r,d=3-(2*r);
    eightwaysymmetric(xc,yc,x,y);
    
    while(x<=y)
    {
        if(d<=0)
        {
            d=d+(4*x)+6;
        }
        else
        {
            d=d+(4*x)-(4*y)+10;
            y=y-1;
        }
        x=x+1;
        eightwaysymmetric(xc,yc,x,y);
    }
}

void renderfunction()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    gluOrtho2D(0,1400,0,800);
    
    circle(600,300,100);
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1400,800);
    glutInitWindowPosition(100,100);
    glutCreateWindow("circle");
    glutDisplayFunc(renderfunction);
    glutMainLoop();
    return 0;
}
